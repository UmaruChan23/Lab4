#include "Complex.h"
#include <cmath>
#include <iostream>

Complex::Complex() {
    this->re = 0;
    this->im = 0;
}

Complex::Complex(double z) {
    this->re = z;
    this->im = 0;
}

Complex::Complex(double re, double im) {
    this->re = re;
    this->im = im;
}

Complex::~Complex() {
}

double Complex::Re() const {
    return this->re;
}

double Complex::Im() const {
    return this->im;
}

double Complex::R() const {
    return sqrt(std::pow(re, 2) + std::pow(im, 2));
}

double Complex::Phi() const {
    if ((re > 0 && im > 0) || (re > 0 && im < 0)) {
        return atan(std::abs((double) im / re));
    } else if (re < 0 && im > 0) {
        return atan(std::abs((double) im / re)) + M_PI;
    } else if (re < 0 && im < 0) {
        return atan(std::abs((double) im / re)) - M_PI;
    } else {
        return 0;
    }
}

Complex Complex::y(const Complex &z) {
    const Complex imOne(0, 1);
    Complex res = z * sh(z + 1) + imOne;
    return res;
}

Complex Complex::sh(const Complex &z) {
    Complex res((std::exp(z.Re()) * std::cos(z.Im()) - std::exp(-z.Re()) * std::cos(z.Im())) / 2.,
                (std::exp(z.Re()) * std::sin(z.Im()) + std::exp(-z.Re()) * std::sin(z.Im())) / 2.);
    return res;
}

Complex Complex::ch(const Complex &z) {
    Complex res(cosh(z.Re()) * std::cos(z.Im()), sinh(z.Re()) * std::sin(z.Im()));
    return res;
}

Complex Complex::sin(const Complex &z) {
    Complex res(std::sin(z.Re()) * cosh(z.Im()), std::cos(z.Re()) * sinh(z.Im()));
    return res;
}

Complex Complex::cos(const Complex &z) {
    Complex res(std::cos(z.Re()) * cosh(z.Im()), -1 * std::sin(z.Re()) * sinh(z.Im()));
    return res;
}

Complex Complex::exp(const Complex &z) {
    Complex res(std::cos(z.Im()) * std::exp(z.Re()), std::sin(z.Im()) * std::exp(z.Re()));
    return res;
}

Complex Complex::operator+(const Complex &z) const {
    Complex res(this->re + z.re, this->im + z.im);
    return res;
}

Complex Complex::operator-(const Complex &z) const {
    Complex res(this->re - z.re, this->im - z.im);
    return res;
}

Complex Complex::operator*(const Complex &z) const {
    Complex res(this->re * z.re - this->im * z.im, this->re * z.im + this->im * z.re);
    return res;
}

Complex Complex::operator/(const Complex &z) const {
    Complex res((this->re * z.re + this->im * z.im) / (z.re * z.re + z.im * z.im),
                (this->im * z.re - this->re * z.im) / (z.re * z.re + z.im * z.im));
    return res;
}

Complex::operator double() const {
    return this->re;
}

std::string Complex::toString() const {
    char buffer[50];
    if (this->im >= 0) {
        sprintf(buffer, "%4.3f+%4.3fi", this->re, this->im);
    } else {
        sprintf(buffer, "%4.3f%4.3fi", this->re, this->im);
    }
    return buffer;
}

std::ostream& operator<< (std::ostream &out, const Complex &z) {
    if (z.Im() >= 0) {
        out << z.Re() << "+" << z.Im() << "i";
    } else {
        out << z.Re() << z.Im() << "i";
    }
    return out;
}

std::istream& operator>> (std::istream &in, Complex &z){
    in >> z.re;
    in >> z.im;
    return in;
}
