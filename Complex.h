#include <string>
#ifndef Complex_H
#define Complex_H

class Complex {
public:
    Complex();
    Complex(double z);
    Complex(double re, double im);

    Complex(Complex *pComplex);

    ~Complex();

    double Re() const;
    double Im() const;
    double R() const;
    double Phi() const;

    explicit operator double() const;

    std::string toString() const;

    friend std::ostream& operator<< (std::ostream &out, const Complex &z);
    friend std::istream& operator>> (std::istream &in, Complex &z);

    Complex operator +(const Complex &z) const;
    Complex operator -(const Complex &z) const;
    Complex operator *(const Complex &z) const;
    Complex operator /(const Complex &z) const;

private:
    double re;
    double im;

};
#endif