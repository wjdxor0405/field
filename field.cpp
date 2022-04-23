#include <stdio.h>
#include <iostream>
#include <cmath>

#include "field.h"




Number_field::Number_field(field_num input_num){
    f_num.type = input_num.type;
    f_num.frac_num = input_num.frac_num;
}


Number_field::Number_field(Poly min_poly){
    poly = min_poly;

    if(min_poly.degree < 2){
      //Q
    } 
    else if(min_poly.degree == 2){
        //...
    }

}

void Algebraic_num::sef_coeff(Frac coeff, int index){

    coeffs[0].num = coeff.num;
    coeffs[0].den = coeff.den;
    
}


void Algebraic_num::sef_coeff(int coeff, int index){

    coeffs[0].num = coeff;
    coeffs[0].den = 1;
    
}




// template <class T>
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


