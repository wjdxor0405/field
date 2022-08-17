#include "frac.h"

class field_num{
    public:
        int type;
        Frac frac_num;
        field_num();
        field_num(Frac frac, int type_);
        ~field_num();

};