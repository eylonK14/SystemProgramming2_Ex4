//@author eylony1403@gmail.com

#pragma once

#include <iostream>
#include <sstream>
#include <cmath>

class Complex
{
public:
    Complex(double, double);
    double normal() const;
    bool operator==(const Complex &) const;
    bool operator>(const Complex &) const;
    std::string string_rep() const;

private:
    double _re;
    double _im;
};

std::string to_string(const Complex &other);
std::ostream &operator<<(std::ostream &stream, const Complex &other);

