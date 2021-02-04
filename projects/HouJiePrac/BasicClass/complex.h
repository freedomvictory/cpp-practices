#include <iostream>

class Complex;
Complex&
__doapl (Complex* ths, const Complex& r);
Complex&
__doami (Complex* ths, const Complex& r);
Complex&
__doaml (Complex* ths, const Complex& r);

class Complex 
{
public:
    Complex(double r = 0, double i = 0)
        : re(r), im(i)
    {}

    double real() const {return re;}
    double imag() const {return im;}

    Complex& operator += (const Complex&);
    Complex& operator -= (const Complex&);
    Complex& operator *= (const Complex&);
//    Complex& operator /= (const Complex&);

private:
    double re,im;
    //why it's private !
    friend Complex& __doapl(Complex*, const Complex&);
    friend Complex& __doami (Complex* ths, const Complex& r);
    friend Complex& __doaml (Complex* ths, const Complex& r);

};

inline Complex& Complex::operator += (const Complex& r)
{
    return __doapl(this, r);
}

inline Complex& __doapl(Complex* ths, const Complex &r)
{
    ths->re += r.re;
    ths->im += r.im;
    return *ths;
}
inline double
imag (const Complex& x)
{
    return x.imag ();
}

inline double
real (const Complex& x)
{
    return x.real ();
}

inline Complex& __doami (Complex* ths, const Complex& r)
{
    ths->re -= r.re;
    ths->im -= r.im;
    return *ths;
}
inline Complex& Complex::operator -= (const Complex& r)
{
    return __doami(this, r);
}

inline Complex& __doaml (Complex* ths, const Complex& r)
{
    double f = ths->re * r.re - ths->im * r.im;
    ths->im = ths->im * r.re + ths->re * r.im;
    ths->re = f;
    return *ths;
}

inline Complex& Complex::operator *= (const Complex & r)
{
    return __doaml(this, r);
}

inline Complex operator + (const Complex &l, const Complex &r)
{
    return Complex(l.real() + r.real(), l.imag() + r.imag());
}

inline Complex operator + (const Complex &l, double r)
{
    return Complex(l.real() + r, l.imag());
}

inline Complex operator + (double l, const Complex& r)
{
    return Complex(l + r.real(), r.imag());
}


inline Complex operator - (const Complex &l, const Complex &r)
{
    return Complex(l.real() - r.real(), l.imag() - r.imag());
}

inline Complex operator - (const Complex &l, double r)
{
    return Complex(l.real() - r, l.imag());
}

inline Complex operator - (double l, const Complex &r)
{
    return Complex(l - r.real(), 0 - r.imag());
}




inline Complex operator * (const Complex &l, const Complex &r)
{
    return Complex(l.real() * r.real() - l.imag() * r.imag(),
                   l.imag() * r.real() + l.real() * r.imag());
}

inline Complex
operator * (const Complex& x, double y)
{
    return Complex (real (x) * y, imag (x) * y);
}

inline Complex
operator * (double x, const Complex& y)
{
    return Complex (x * real (y), x * imag (y));
}

inline Complex
operator + (const Complex& x)
{
    return x;
}

inline Complex
operator - (const Complex& x)
{
    return Complex (-real (x), -imag (x));
}

inline bool
operator == (const Complex& x, double y)
{
    return real (x) == y && imag (x) == 0;
}

inline bool
operator == (double x, const Complex& y)
{
    return x == real (y) && imag (y) == 0;
}

inline bool
operator != (const Complex& x, const Complex& y)
{
    return real (x) != real (y) || imag (x) != imag (y);
}

inline bool
operator != (const Complex& x, double y)
{
    return real (x) != y || imag (x) != 0;
}

inline bool
operator != (double x, const Complex& y) {
    return x != real(y) || imag(y) != 0;
}