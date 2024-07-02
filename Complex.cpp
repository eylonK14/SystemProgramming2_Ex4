#include "Complex.hpp"

Complex::Complex(double re, double im) : _re(re), _im(im)
{
}

double Complex::normal() const
{
    return sqrt(_re * _re + _im * _im);
}

bool Complex::operator==(const Complex &other) const
{
    return _re == other._re && _im == other._im;
}

bool Complex::operator>(const Complex &other) const
{
    return this->normal() > other.normal();
}

std::string Complex::string_rep() const
{
    double ima = _im;
    std::ostringstream oss;
    std::string re = std::to_string(_re);
    re.erase(re.find_last_not_of('0') + 1, std::string::npos);
    re.erase(re.find_last_not_of('.') + 1, std::string::npos);

    if(_im < 0)
        ima *= -1;

    std::string im = std::to_string(ima);
    im.erase(im.find_last_not_of('0') + 1, std::string::npos);
    im.erase(im.find_last_not_of('.') + 1, std::string::npos);
    std::string sign = _im < 0 ? " - " : " + ";
    oss << "(" + re + sign + im + "i)";
    return oss.str();
}

std::string to_string(const Complex &other)
{
    std::ostringstream oss;
    oss << other.string_rep();
    return oss.str();
}

std::ostream &operator<<(std::ostream &stream, const Complex &other)
{
    stream << other.string_rep();
    return stream;
}
