#include <iostream>
#include <sstream>
#include "complex.h"
using namespace std;

Complex operator+(const Complex &C1, const Complex &C2)
{
    return Complex{C1.re + C2.re, C1.im + C2.im};
}

Complex operator-(const Complex &C1, const Complex &C2)
{
    return C1 + (-C2);
}
Complex operator-(const Complex &C)
{
    return Complex{-C.re, -C.im};
}

Complex operator*(const Complex &C1, const Complex &C2)
{
    return Complex{C1.re * C2.re - C1.im * C2.im, C1.re * C2.im + C1.im * C2.re};
}

Complex abs(const Complex &C)
{
    return Complex{sqrt(C.re * C.re + C.im * C.im), 0};
}

Complex inv(const Complex &C)
{
    Real abs2 = C.re * C.re + C.im * C.im;
    return Complex{C.re / (abs2), -C.im / (abs2)};
}

Complex operator/(const Complex &C1, const Complex &C2)
{
    return (C1 * inv(C2));
}

Complex exp(const Complex &C)
{
    return Complex{{exp(C.re) * cos(C.im)}, {exp(C.re) * sin(C.im)}};
}
Complex sin(const Complex &C)
{
    return (exp(Complex{0, 1} * C) - exp(Complex{0, -1} * C)) / Complex{0, 2};
}
Complex cos(const Complex &C)
{
    return (exp(Complex{0, 1} * C) + exp(Complex{0, -1} * C)) / Complex{2, 0};
}
Complex ln(const Complex &C)
{
    return Complex{log(C.re), 0};
}

ostream &operator<<(ostream &os, const Complex &C)
{
    ostringstream outtext;
    outtext << C.re;
    if (C.im > 0)
        outtext << "+";
    if (C.im != 0)
    {
        outtext << C.im << "*i";
    }
    os << outtext.str();
    return os;
}