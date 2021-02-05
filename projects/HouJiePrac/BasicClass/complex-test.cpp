#include "complex.h"
#include <iostream>



std::ostream & operator << (std::ostream &os, const Complex &r)
{
    os << '(' << r.real() << ',' << r.imag() << ')';
    return os;
}


int main(int argc, char ** argv)
{
    Complex c1(1, 2);
    Complex c2(3, 4);
    Complex c3(2,2);
    c1 += c2; //c1: (4,6)
    std::cout << c1 << std::endl;
    c1 += c2 += c3; // c2: (5,6) c1:(9, 12)
    std::cout << c1 << c2 << std::endl;
    c1 -= c2;  //c1: (4, 6)
    std::cout << c1 << std::endl;
    c1 -= c2 -= c3; // c2: (3, 4) c1: (1,2)
    std::cout << c1 << c2 << std::endl;

    std::cout << c1 * c2 << std::endl; // (1*3 - 2*4) + (2*3 + 1*4)i = -5 + 10i
    c1 *= c2;
    std::cout << c1 << std::endl;

    Complex* complexs = new Complex[3]{Complex(1,2), Complex(2,3), Complex(3,4)};

    std::cout << complexs[0] << complexs[1] << complexs[2];
    delete[] complexs;

    return 0;
}