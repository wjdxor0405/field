#include "frac.h"
#include <stdio.h>//printf

Frac::Frac(){
    num = 0;
    den = 1;
}

Frac::Frac(int n, unsigned int d){
    int m = n;
    if (n  < 0){
        m = (-1)*n;
    }

    // printf("-----------------gcd(%d,%d)\n", m,d);
    int g = gcd(m,d);
    //  printf("-----------------gcd(%d,%d)=", m,d);
    // printf("g : %d\n", g);
    // printf("n : %d\n", n);
    // printf("m : %d\n", m);
    // printf("d : %d\n", d);

    if (g == 0){
        num = n;
        den = d;
    }
    else{
        num = n/g;
        den = d/g;
    }
}

Frac Frac::operator+(Frac r){

    //need gcd
    return Frac(num* r.den + den * r.num, den * r.den);

}

Frac Frac::operator-(Frac r){

    //need gcd
    return Frac(num* r.den - den * r.num, den * r.den);

}



Frac Frac::operator*(Frac r){

    //need gcd
    return Frac(num * r.num, den * r.den);

}

Frac Frac::operator/(Frac r){

    //need gcd
    // if(den == 1 && r.den == 1){

    // }
    return Frac(num * r.den, den *r.num );

}


int Frac::gcd(int a, int b){

    if( a < b){
        int t = a;
        a = b;
        b = t;
    }
    // printf("a : %d, b: %d ", a, b);
    
    
    // if(b==1){
    //     printf("b==1\n");
    //     return 1;
    // }
    // else 
    if(b==0){
        // printf("b==0\n");
        return a;
    }
    if(a%b == 0){
        return b;   
    }
    else{
        // printf("else");
        return gcd(a%b,b);
    }  
}