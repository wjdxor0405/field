#include <stdio.h>//printf
#include "number_field.h"

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
    else if(min_poly.degree == 3){
        //TODO
        Frac d = min_poly.c[0];
        Frac c = min_poly.c[1];
        Frac b = min_poly.c[2];
        Frac a = min_poly.c[3];
        
        Poly poly_1 = Poly(1,1) - Poly(b*Frac(1,3)/a);

        Poly poly_q = min_poly % poly_1;
        // print_info();
        // f_num.frac_num = poly_q.c[0];
        // f_num.frac_num.num *= -1;

    }
    cal_discriminant();

}
Number_field::Number_field(){

}
Number_field::~Number_field(){

}
void Number_field::print_info(){

    if(f_num.type == ROOT_TYPE){
        printf("field : Q(root(");
    }
    if(f_num.frac_num.den == 1){

        if(f_num.frac_num.num < 0){
            printf("%d", (-1)*f_num.frac_num.num);
        }
        else{
            printf("%d", f_num.frac_num.num);
        }
    }
    else{
        if(f_num.frac_num.num < 0){
            printf("(%d/%d)", (-1)*f_num.frac_num.num, f_num.frac_num.den);
        }
        else{
          printf("(%d/%d)", f_num.frac_num.num, f_num.frac_num.den);
        }

    }

    if(f_num.frac_num.num < 0){
        printf(")i\n");
    }
    else{
        printf("))\n");
    }
    printf("minimal poly : ");
    poly.val();
    printf("discriminant : %d\n", discriminant);

}

void Number_field::cal_discriminant(){

    if(f_num.type == ROOT_TYPE){
        if(f_num.frac_num.den == 1){

            //TODO : check square free
            int d = f_num.frac_num.num;
            if(d % 4 == 2 || d % 4 == 3){
                discriminant = d;
            }
            else if(d % 4 == 1){
                discriminant = 4*d;
            }
            else{
                //TODO
            }

        }
    }

}
