#include <stdio.h>
// #include "field.h"
#include "polynomial.h"
#include "number_field.h"

int main(){

    printf("test\n");

    Poly P1 = Poly(1) + Poly(2,1) + Poly(1,3);
    Poly P2 = Poly(1) + Poly(2,1);
    Poly P3 = P1 / P2;
    Poly P4 = P1 % P2;
    P1.val();
    P2.val();
    P3.val();
    P4.val();
    
    Number_field N = Number_field(Poly(1,2) - Poly(2));
    N.print_info();

    printf("testaa\n");


    return 0;
}
