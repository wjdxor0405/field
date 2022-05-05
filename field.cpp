#include <stdio.h>
#include <iostream>
#include <cmath>

#include "field.h"


Field::Field(){}
Field::~Field(){}


field_num::field_num(Frac frac, int type_){

    frac_num = frac;
    type = type_;
}

field_num::field_num(){

}

field_num::~field_num(){

}

Number_field::Number_field(Poly min_poly){
    poly = min_poly;

    if(min_poly.degree < 2){
      //Q
      f_num.type = RATIONAL;
      f_num.frac_num.den = 1;
      f_num.frac_num.num = 1;
    } 
    else if(min_poly.degree == 2){
        //...
        f_num.type = ROOT_TYPE;
        Frac c = min_poly.c[0];
        Frac b = min_poly.c[1];
        Frac a = min_poly.c[2];

        Poly poly_1 = Poly(1,1) - Poly(b*Frac(1,2)/a);
        
        Poly poly_q = min_poly % poly_1;
        f_num.frac_num = poly_q.c[0];
        f_num.frac_num.num *= -1;


    }

}
Number_field::Number_field(){

}
Number_field::~Number_field(){

}
void Number_field::print_info(){

    if(f_num.type == ROOT_TYPE){
        printf("root(");    

    }
    if(f_num.frac_num.den == 1){
            printf("%d", f_num.frac_num.num);
        }
        else{
            printf("(%d/%d)", f_num.frac_num.num, f_num.frac_num.den);
        }
    printf(")\n");
    poly.val();

}

void Algebraic_num::sef_coeff(Frac coeff, int index){

    coeffs[0].num = coeff.num;
    coeffs[0].den = coeff.den;
    
}


void Algebraic_num::sef_coeff(int coeff, int index){

    coeffs[0].num = coeff;
    coeffs[0].den = 1;
    
}

void Algebraic_num::val(){
    int i = 0;
    printf("(%d/%d)", coeffs[i].num, coeffs[i].den);
    
    if(irr_type == Root_type){
        for(i=1;i<degrees+1;i++){
            printf("+");
            printf("(%d/%d)", coeffs[i].num, coeffs[i].den);
            printf("root(%d)", irr_num[i]);
        }
    }
    

    printf("\n");
}


