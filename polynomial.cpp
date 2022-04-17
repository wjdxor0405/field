#include "polynomial.h"
#include <iostream>
#include <stdio.h>//printf

Poly Poly::operator+(Poly p){

    p.degree=0;
    for(int i=0;i<MAX_DEG;i++){
        p.c[i] = p.c[i] + c[i];

        if(p.c[i].num != 0){ 
            p.degree = i;
        }
    }


    return p;
}

Poly Poly::operator-(Poly p){

    p.degree=0;

    for(int i=0;i<MAX_DEG;i++){
        p.c[i] = c[i] - p.c[i];
        // printf("%d ", p.c[i].num);
        if(p.c[i].num != 0){ 
            p.degree = i;
        }
    }
    // printf("\n");


    return p;
}

Poly Poly::operator*(Poly P){

    Frac r[MAX_DEG];

    for(int i=0;i<=degree;i++){
        for(int j=0;j<=P.degree;j++){

            r[i+j] = r[i+j] + c[i] * P.c[j];
        }
    }
    P.degree = 0;

    for(int i=0;i<MAX_DEG;i++){
        P.c[i] = r[i];
        if(r[i].num !=0){
            P.degree = i;
        }
    }

    return P;
}


Poly Poly::operator/(Poly P){
    
    if ( degree <P.degree){
        for(int i=0;i<MAX_DEG;i++){
            P.c[i] = c[i];
        }
        return P;
    }

    Poly R;
    Poly Q;
    for(int i=0;i<MAX_DEG;i++){
        Q.c[i] = c[i];
    }
    Q.degree = degree;
  
    int deg = degree - P.degree;
    int i = degree;
    int j = P.degree;
    R.degree = deg;
  
    while(deg>-1){
        R.c[deg] = Q.c[i]/P.c[j];
        Frac t = R.c[deg];
        Poly T = Poly(t, deg);
        Poly S = T*P;
        Q = Q - S;
        i--;
        deg--;
    }

    return R;
}

Poly Poly::operator%(Poly P){
    Poly A;
    A.degree = degree;
    for(int i=0;i<MAX_DEG;i++){
        A.c[i] = c[i];
    }

    return A - (A/P)*P;
}

void Poly::init(){
    degree = 0;
    for(int i=0;i<MAX_DEG;i++){
        c[i].den = 1;
        c[i].num = 0;
    }
}

Poly::Poly(){
    init();
}

Poly::Poly(int a){
    init();
    // c[0].den = 1;
    c[0].num = a;
}

Poly::Poly(Frac r){
    // printf("--deg%d\n", degree);
    // printf("inti\n");
    init();
    // printf("-deg%d\n", degree);
    // degree = 0;
    // c[0].den = r.den;
    c[0].num = r.num;
}

Poly::Poly(int a, int deg){
    init();
    degree = deg;
    // c[deg].den = 1;
    c[deg].num = a;
}

Poly::Poly(Frac r, int deg){
    init();
    degree = deg;
    c[deg].den = r.den;
    c[deg].num = r.num;
}

void Poly::val(){
    int i=degree;
    deg_val(c[i], i);
    for(i=degree-1;i>-1;i--){
        one_val(c[i], i);
    }
    printf("\n");

}

void Poly::deg_val(Frac r, int deg){
    if(deg > 1){
        if(r.num == 0){
            printf("0x^%d", r.num, deg);//?? error?
        }
        else if(r.den == 1){
            if(r.num == 1){
                printf("x^%d", deg);
            }
            else{
                printf("%dx^%d", r.num, deg);
            }
        }
        else{
            printf("(%d/%d)x^%d", r.num, r.den, deg);
        }
    }
    else if(deg == 1){
        if(r.num == 0){
            printf("0x", r.num);//?? error?
        }
        else if(r.den == 1){
            if(r.num == 1){
                printf("x");
            }
            else{
                printf("%dx", r.num);
            }
        }
        else{
            printf("(%d/%d)x", r.num, r.den);
        }
    }
    else if(deg == 0){
        if(r.den == 1){
            printf("%d", r.num);
        }
        else{
            printf("(%d/%d)", r.num, r.den);
        }
    }
}

void Poly::one_val(Frac r, int deg){

    char plus_minus = '+';
    int rnum = r.num;
    if (r.num < 0){
        plus_minus = '-';
        rnum = (-1)*r.num;
    }

    if(deg > 1){
        if(r.num == 0){
            //nothing to print
        }
        else if(r.den == 1){
            if(rnum == 1){
                printf(" %c x^%d", plus_minus, deg);
            }
            else{
                printf(" %c %dx^%d", plus_minus, rnum, deg);
            }
        }
        else{
            printf(" %c (%d/%d)x^%d", plus_minus, rnum, r.den, deg);
        }
    }
    else if(deg == 1){
        if(r.num == 0){
            //nothing
        }
        else if(r.den == 1){
            if(rnum == 1){
                printf(" %c x", plus_minus);
            }
            else{
                printf(" %c %dx", plus_minus, rnum);
            }
        }
        else{
            printf(" %c (%d/%d)x", plus_minus, rnum, r.den);
        }
    }
    else if(deg == 0){
        if(r.den == 1){
            if(rnum == 0){
                //nothing
            }
            else{
                printf(" %c %d", plus_minus, rnum);
            }
        }
        else{
            printf(" %c (%d/%d)",plus_minus, rnum, r.den);
        }
    }
}