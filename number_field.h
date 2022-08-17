#include "field.h"
#include "field_num.h"
#include "polynomial.h"

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
