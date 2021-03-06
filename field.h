#include <stdint.h>
#include <stdlib.h> 
#include "frac.h"
#include "polynomial.h"

// #include <iostream>
#define MAXCOEFF 4
#define MAXIRR 4

// using namespace std;
#define RATIONAL 0
#define ROOT_TYPE 1
#define TRI 2 //trigonometry


//number Field 
class Field{
    private:
    public:
       Field();
       ~Field();
};

class field_num{
    public:
        int type;
        Frac frac_num;
        field_num();
        field_num(Frac frac, int type_);
        ~field_num();

};


class Number_field : Field{
    private:
        // Number_field();
        // ~Number_field();
        int discriminant;
        // int 
    public:
        field_num f_num;
        // field_type type;
        Poly poly;
        // Number_field(field_num input_num){
        Number_field(field_num field_num);//need to implement
        Number_field(Poly min_poly);
        Number_field();
        ~Number_field();
        void print_info();

        void cal_discriminant();
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