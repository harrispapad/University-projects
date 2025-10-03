#define F_CPU 16000000UL

#include<avr/io.h>
#include<avr/interrupt.h>
#include<util/delay.h>
#include <stdio.h>
#include <string.h>
#include <xc.h>

#include "setup_LCD_PEX.h"
#include "setup_TWI.h"
#include "setup_OWI.h"
#include "setup_USART.h"
#include "setup_KEYBOARD.h"

static uint8_t temp_l, temp_h;
extern uint16_t pressed_keys;


typedef enum {
    Success,
    Fail,
    OK_200,
    ERROR_400        
} comm_status;

const char *reply[] = {
    [Success] = "\"Success\"",
    [Fail] = "\"Fail\"",
    [OK_200] = "200 OK",
    [ERROR_400] = "400 ERROR"
};


typedef enum {
    NURSE_CALL,         // 0
    OK,                 // 1
    CHECK_TEMP,         // 2
    CHECK_PRESSURE      // 3
} STATUS_t;

const char *patient_status[] = {
    [NURSE_CALL] = "NURSE CALL",
    [OK] = "OK",
    [CHECK_TEMP] = "CHECK TEMP",
    [CHECK_PRESSURE] = "CHECK PRESSURE"
};

const char *message[] = {
    "ESP:connect",
    "ESP:url:\"http://192.168.1.250:5000/data\"",
    "ESP:transmit"
};


void string_to_lcd(const char *s);
void transmit_string(const char *s);
void esp_setup();
void state_to_lcd(double temperature, double pressure, STATUS_t status);
void transmit_payload(double temperature, double pressure, int team, STATUS_t status);
STATUS_t check_button();
double measure_temp();
double read_adc();
void transmit_esp();

void setup() {  
    twi_init();
    _delay_ms(50);  // Delay 500 ms for better stability
    PCA9555_0_write(REG_CONFIGURATION_0, 0x00); // Set as output
    lcd_init();
    _delay_ms(50);
    lcd_clear_display();
    _delay_us(100);
    usart_init(103);
    ADMUX = 0b01000000;   // ADC right-adjusted, select ADC0
    ADCSRA = 0b10000111;  // Enable ADC with a prescaler of 128
    setup_keyboard();
    _delay_ms(50);  // Delay 500 ms for better stability

}

int main()
{
    setup();    
    double pressure;
    STATUS_t status = OK;
    double temperature;
    int team = 20;
    int check_temp = 0; 
    int check_press = 0;
    
    
    
    while(1){
        lcd_clear_display();
        lcd_set_cursor(0, 0);
        
        esp_setup();

        status = check_button();
        pressure = read_adc();
        temperature = measure_temp();        
        
        if(pressure < 4) check_press = 1;
        else if(pressure > 12) check_press = 1;
        
        if(temperature < 34) check_temp = 1;
        else if(temperature > 37) check_temp = 1;
        
        if(status == NURSE_CALL) {
            check_press = 0;
            check_temp = 0;
        }
        
        if(check_press) {
            status = CHECK_PRESSURE;
        }
        else if (check_temp) {
            status = CHECK_TEMP;
        }
        
        state_to_lcd(temperature, pressure, status);
        transmit_payload(temperature, pressure, team, status);
        transmit_esp();
        
    }
}

double measure_temp()
{
    int16_t temperature = 0;
    if(one_wire_reset()) {
        one_wire_transmit_byte(0xCC);
        one_wire_transmit_byte(0x44);
        while(!one_wire_receive_bit()) {
            //busy waiting
        }
        if(one_wire_reset()) {
            one_wire_transmit_byte(0xCC);
            one_wire_transmit_byte(0xBE);
            temp_l = one_wire_receive_byte();
            temp_h = one_wire_receive_byte();
        }
        else {
            temp_l = 0x00;
            temp_h = 0x80;
        }
    }
    else {
        temp_l = 0x00;
        temp_h = 0x80;
    }   
       
    temperature = (temp_h & 0b00000111) << 8;
    temperature |= temp_l;
    double result = ((double)temperature * 0.0625) + 12.0;
        
    
    return result;
}

double read_adc() 
{
    double adc;
    double output;
    ADCSRA |= (1 << ADSC);
    while (ADCSRA & (1 << ADSC));  
    adc = ADC;
    output = (adc * 20) / 1024;
    return output; 
}

void esp_setup()
{
    char c;
    comm_status s = Fail; 
    transmit_string(message[0]);
        
    lcd_data('1');
    lcd_data('.');
    do { 
        c = usart_receive();
        if(c == 'S') {
            s = Success;
        }
        else if(c == 'F'){ 
            s = Fail;
        }
    } while(c != '\n');
    
    string_to_lcd(reply[s]);
    
    lcd_set_cursor(1, 0);

    transmit_string(message[1]);
    s = Fail;
    lcd_data('2');
    lcd_data('.');
    do { 
        c = usart_receive();

        if(c == 'S') {
            s = Success;
        }
        else if(c == 'F'){ 
            s = Fail;
        }      
    } while(c != '\n');        

    string_to_lcd(reply[s]);
}


void state_to_lcd(double temperature, double pressure, STATUS_t status)
{   char pres_out[5];     
    char temp_out[5];
    lcd_clear_display();
    lcd_data('T');
    lcd_data(':');
    sprintf(temp_out, "%.2f", temperature);
    
    string_to_lcd(temp_out);
    
    lcd_data(' ');
    
    lcd_data('P');
    lcd_data(':');
    snprintf(pres_out, 5, "%.2f", pressure);
    string_to_lcd(pres_out);
        
    lcd_set_cursor(1, 0); 
    string_to_lcd(patient_status[status]);
    
    _delay_ms(2000);
}

void transmit_payload(double temperature, double pressure, int team, STATUS_t status)
{
    char payload[256] = {0};
    char c;
    comm_status s = Fail;
    snprintf(payload, 256,
            "ESP:payload:[{\"name\": \"temperature\",\"value\": \"%.2f\"},"
            "{\"name\": \"pressure\",\"value\": \"%.2f\"},"
            "{\"name\": \"team\",\"value\": \"%d\"},"
            "{\"name\": \"status\",\"value\": \"%s\"}]",
            temperature, pressure, team, patient_status[status]); 
    
    transmit_string(payload);
    
    lcd_clear_display();
    lcd_data('3');
    lcd_data('.');
    do { 
        c = usart_receive();
        if(c == 'S') {
            s = Success;
        }
        else if(c == 'F')
            s = Fail;      
    } while(c != '\n');  
    
    string_to_lcd(reply[s]);
    
    _delay_ms(2000);
    return;
}

void transmit_esp()
{
    char c;
    comm_status s = ERROR_400;
    
    transmit_string(message[2]);
    
    lcd_set_cursor(1, 0);
    lcd_data('4');
    lcd_data('.');
    do { 
        c = usart_receive();
        if(c == '2') {
            s = OK_200;
        }           
    } while(c != '\n'); 
  
    string_to_lcd(reply[s]);
    
    _delay_ms(1000);
}

STATUS_t check_button()
{
    int num = 0;
    STATUS_t status_temp = OK;
    int del = 0;
    while(del < 500) {
        scan_keypad_rising_edge();
        if (pressed_keys != 0) {
            num = keypad_to_ascii();
            if( num == 48) 
                status_temp = NURSE_CALL;
                else if(num == 35)
                status_temp = OK;
            }
        _delay_us(100);
        del++;
    }

    return status_temp;
}

void transmit_string(const char *s) {
    int len = strlen(s);
    for(int i = 0; i < len; i++) {
        usart_transmit(s[i]);
        _delay_us(10);
    }
    usart_transmit('\n');
}

void string_to_lcd(const char *s) {
    int len = strlen(s);
    for(int i = 0; i < len; i++) {
            lcd_data(s[i]);
            _delay_us(10);
        }
}