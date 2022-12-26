#include "imag.h"
using namespace std;

// Define a data structure to represent a complex number as a pair of two real
// numbers, re and im, the first holding the real part of the complex number,
// and the second holding the imaginary part.
struct Complex
{
    double re;
    double im;
};

// Ask the user for a complex number and return it.
Complex askForComplexNumber(Complex& c)
{
    //Complex c;
    cout << "Real part: ";
    cin >> c.re;
    cout << "Imaginary part: ";
    cin >> c.im;
    return c;
}

// Print the real and imaginary parts of the complex number
// using the specified format
void printComplexNumber(Complex& c)
{
    cout << showpos << setprecision(3) << fixed
         << "(" << c.re /*<< "+" */<< c.im << "i)";
}

// Addition: (a+bi)+(c+di) = (a+c)+(b+d)i
Complex addition(Complex& c1, Complex& c2)
{
    Complex result;
    result.re = c1.re + c2.re;
    result.im = c1.im + c2.im;
    return result;
}

// Subtraction: (a+bi)-(c+di) = (a-c)+(b-d)i
Complex subtraction(Complex& c1, Complex& c2)
{
    Complex result;
    result.re = c1.re - c2.re;
    result.im = c1.im - c2.im;
    return result;
}

// Multiplication: (a+bi)*(c+di)=(ac-bd)+(ad+bc)i
Complex multiplication(Complex& c1, Complex& c2)
{
    Complex result;
    result.re = c1.re * c2.re - c1.im * c2.im;
    result.im = c1.re * c2.im + c1.im * c2.re;
    return result;
}

// Division: (a+bi)/(c+di)=((ac+bd)/(c^2+d^2))+((bc-ad)/(c^2+d^2))i
Complex division(Complex& c1, Complex& c2)
{
    Complex result;
    result.re = (c1.re * c2.re + c1.im * c2.im) / (c2.re * c2.re + c2.im * c2.im);
    result.im = (c1.im * c2.re - c1.re * c2.im) / (c2.re * c2.re + c2.im * c2.im);
    return result;
}