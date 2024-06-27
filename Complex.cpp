#include "Complex.hpp"

Complex::Complex(double re, double im) : _re(re), _im(im)
{
}

bool Complex::operator==(const Complex &other) const
{
    return _re == other._re && _im == other._im;
}