#ifndef __COMPLEX_H__
#define __COMPLEX_H__
#include <iostream>
#include <cmath>
using Real = float;
struct Complex
{
    Real re = 0;
    Real im = 0;
};
Complex operator+(const Complex &, const Complex &);
Complex operator*(const Complex &, const Complex &);
Complex operator-(const Complex &);
Complex operator-(const Complex &, const Complex &);
Complex abs(const Complex &);
Complex inv(const Complex &);
Complex operator/(const Complex &, const Complex &);
Complex exp(const Complex &);
Complex sin(const Complex &);
Complex cos(const Complex &);
Complex ln(const Complex &);
std::ostream &operator<<(std::ostream &os, const Complex &C);
#endif