.include "m328PBdef.inc"
.def counter = r16

.org 0x0
    rjmp reset

.org 0x4
    rjmp interrupt1

reset:
    ldi r24, LOW(RAMEND)
    out SPL, r24
    ldi r24, HIGH(RAMEND)
    out SPH, r24

    ser r24
    out DDRB, r24            ; Initialize PORTB as output

    clr r24
    out DDRD, r24            ; Initialize PORTD as input

enable_interrupt:
    ; Interrupt on rising edge of INT1 pin
    ldi r24, (1<<ISC11) | (1<<ISC10)
    sts EICRA, r24

    ; Enable the INT1 interrupt
    ldi r24, (1<<INT1)
    out EIMSK, r24

    sei                      ; Enable general flag of interrupts

    clr r24
    out PORTB, r24           ; Clear all pins of PORTB

main:
    in r17, PIND
    sbrc r17, 7
    rjmp disable_interrupt
    OUT PORTB, counter
    rjmp main

interrupt1:
    push counter
    push r23
    push r24
    push r25
    in r25, SREG             ; Save registers to stack
    push r25

	
	ldi r24, (1<<INTF1)
    out EIFR, r24            ; Clear external interrupt 1 flag

    inc counter
	ldi r20,0x10
	cp counter,r20
	brne delay
	clr counter

delay:
    reti

disable_interrupt:
    ldi r24, (0<<INT1)
    out EIMSK, r24
    clr r18
    OUT PORTB, r18
    in r17, PIND
    sbrc r17, 7
    rjmp disable_interrupt
    rjmp enable_interrupt