#ifndef FRAC_H
#define FRAC_H

struct Frac{
  private:
    // Frac(int n, unsigned int d);
    // int numerator;
    // unsigned int denominator;
    int gcd(int a, int b);
  public:
    Frac();
    Frac(int n, unsigned int d);
    int num;//numerator
    unsigned int den;//denominator
    Frac operator+(Frac r);
    Frac operator-(Frac r);
    Frac operator*(Frac r);
    Frac operator/(Frac r);
};

#endif