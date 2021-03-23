#include "Complex.h"

class ComplexArithmetic {
public:
    static Complex y(const Complex &z);

    static Complex exp(const Complex &z);

    static Complex sin(const Complex &z);

    static Complex cos(const Complex &z);

    static Complex ch(const Complex &z);

    static Complex sh(const Complex &z);

    friend Complex operator "" _i(long double im);

};