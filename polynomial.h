#ifndef POLY_H_
#define POLY_H_
#include "frac.h"
#define MAX_DEG 8

struct Poly{
    private:
        void init();
    public:
        int degree;//0 ~ MAX_DEG-1
        Poly();
        Poly(int a);
        Poly(Frac r);
        Poly(int a, int deg);
        Poly(Frac r, int deg);
        Frac c[MAX_DEG];//coeff
        Poly operator+(Poly P);
        Poly operator-(Poly P);
        Poly operator*(Poly P);
        Poly operator/(Poly P);
        Poly operator%(Poly P);

        // Poly operator/(Poly p);
        void val();
        void deg_val(Frac r, int deg);
        void one_val(Frac r, int deg);
};

#endif