#include "frac.h"

enum Irr_type{
    None,
    Root_type    
};

#define MAXCOEFF 4
#define MAXIRR 4

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