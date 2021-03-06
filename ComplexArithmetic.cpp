#include "ComplexArithmetic.h"
#include "Complex.h"
#include <cmath>

Complex operator"" _i(long double im){
    Complex res(0,im);
    return res;
}

Complex y(const Complex &z) {
    const Complex imOne = 1.0_i;
    Complex res = z * sh(z + 1) + imOne;
    return res;
}

Complex sh(const Complex &z) {
    Complex res((std::exp(z.Re()) * std::cos(z.Im()) - std::exp(-z.Re()) * std::cos(z.Im())) / 2.,
                (std::exp(z.Re()) * std::sin(z.Im()) + std::exp(-z.Re()) * std::sin(z.Im())) / 2.);
    return res;
}

Complex ch(const Complex &z) {
    Complex res(cosh(z.Re()) * std::cos(z.Im()), sinh(z.Re()) * std::sin(z.Im()));
    return res;
}

Complex sin(const Complex &z) {
    Complex res(std::sin(z.Re()) * cosh(z.Im()), std::cos(z.Re()) * sinh(z.Im()));
    return res;
}

Complex cos(const Complex &z) {
    Complex res(std::cos(z.Re()) * cosh(z.Im()), -1 * std::sin(z.Re()) * sinh(z.Im()));
    return res;
}

Complex exp(const Complex &z) {
    Complex res(std::cos(z.Im()) * std::exp(z.Re()), std::sin(z.Im()) * std::exp(z.Re()));
    return res;
}