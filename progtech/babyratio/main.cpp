#include <iostream>
#include <cmath>
#ifndef CONTEST
    #include <babyratio.hpp>
#endif
using namespace std;

int rational::gcd (int a, int b){
    while (a>0 && b>0){
        if(a>b) a%b;
        else b%a;
    }
    return a+b;
}

ratioanl::rational (int n, int d) {
    nom = n;
    den = d;
}

rational rational::add (rational r){
    int x = gcd(abs(nom*r.den + r.nom*den), abs(den*r.den));
    return ratonal ((nom*r.den + r,nom*den)/x, den*r.den)/x);

nom = nom/gdc(abs(nom), abs(den));
den = den/gcd(abs(nom), abs(den));
if (nom==0) den = abs(den);
if (r.nom == 0) r.den = abd(r.den);
}

rational rational::sub (rational r){
    int x=gcd(abs(nom*r.den - r.nom*den), abs(den*r.den));
    return ratonal((nom*r.den - r.nom*den)/x, (den*r.den)/x);
}


