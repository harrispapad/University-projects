#include <iostream>


int factorial(int z) {
    int x = 1;
    for (int i = 1; i<z+1; i++)
        x *= i;
    return x;
}

int binomial(int x, int y) {
    int z = factorial(x)/(factorial(x-y)*factorial(y));
    return z;
}

int power(int x, int y){
    int z = 1;
    for (int i=0; i<y; i++)
        z *= x;
    return z;
}

int main() {
    float c = 0 ;
    for (int i = 9; i < 21; i++)
        c += binomial(20, i)*power(0.2, i)*power(0.8, (20-i));
    std::cout<<c;
}
