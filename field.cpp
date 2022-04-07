#include <stdio.h>
#include <iostream>
#include <cmath>
// using namespace std;

#include "field.h"



// template <class T1>
// template <class T2>
// Algebraic_num::Algebraic_num(Root root){
//     degrees = 1;
//     coeffs[0].num = 0;
//     coeffs[0].den = 1;
    
//     coeffs[1].num = 1;
//     coeffs[1].den = 1;
    
//     for (int i=2;i<MAXCOEFF;i++){
//         coeffs[i].num = 0;
//         coeffs[i].den = 1;
//     }
//     irr_num[1] = root.get_num();
//     irr_type = Root_type;
// }



// Algebraic_num Root::operator+(int n){

//     // get_num();

//     Algebraic_num temp(get_num());

//     // temp.set_coeff(n, 0);

//     return temp;

// }


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


