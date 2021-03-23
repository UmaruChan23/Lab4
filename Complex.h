#include <string>

class Complex {
public:
    Complex();
    Complex(double z);
    Complex(double re, double im);
    ~Complex();

    double Re() const;
    double Im() const;
    double R() const;
    double Phi() const;

    static Complex y(const Complex &z);

    explicit operator double() const;

    std::string toString() const;

    friend std::ostream& operator<< (std::ostream &out, const Complex &z);
    friend std::istream& operator>> (std::istream &in, Complex &z);

private:
    double re;
    double im;

    Complex operator +(const Complex &z) const;
    Complex operator -(const Complex &z) const;
    Complex operator *(const Complex &z) const;
    Complex operator /(const Complex &z) const;

    static Complex exp(const Complex &z);
    static Complex sin(const Complex &z);
    static Complex cos(const Complex &z);
    static Complex ch(const Complex &z);
    static Complex sh(const Complex &z);
};