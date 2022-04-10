#include <stdint.h>
#include <stdlib.h> 
#include "frac.h"
// #include <iostream>
#define MAXCOEFF 4
#define MAXIRR 4

// using namespace std;


//number Field 
class Field{
    private:
    public:
       Field();
       ~Field();
};

class Number_field : Field{

};


class ID{

};




enum Irr_type{
    None,
    Root_type    
};


//rational in number fields field
//c0 + a1*c1 + a2*c2 + ...
class Algebraic_num{
    private:
        unsigned int degrees;
        Frac coeffs[MAXCOEFF];
        int irr_num[MAXIRR];
        int irr_type;
    public:
        // Rational();
        // Algebraic_num();
        // template <class T2>
        // Algebraic_num(Root root);
        void sef_coeff(Frac coeff, int index);
        void sef_coeff(int coeff, int index);
        // ~Algebraic_num();
        void val();

};