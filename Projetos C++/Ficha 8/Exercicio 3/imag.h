#ifndef PROGRAMACAO_IMAG_H
#define PROGRAMACAO_IMAG_H
// Define a data structure to represent a complex number as a pair of two real
// numbers, re and im, the first holding the real part of the complex number,
// and the second holding the imaginary part.
struct Complex;
// Ask the user for a complex number and return it.
Complex askForComplexNumber(Complex& c);
// Print the real and imaginary parts of the complex number
// using the specified format
void printComplexNumber(Complex& c);
// Addition: (a+bi)+(c+di) = (a+c)+(b+d)i
Complex addition(Complex& c1, Complex& c2);
// Subtraction: (a+bi)-(c+di) = (a-c)+(b-d)i
Complex subtraction(Complex& c1, Complex& c2);
// Multiplication: (a+bi)*(c+di)=(ac-bd)+(ad+bc)i
Complex multiplication(Complex& c1, Complex& c2);
// Division: (a+bi)/(c+di)=((ac+bd)/(c^2+d^2))+((bc-ad)/(c^2+d^2))i
Complex division(Complex& c1, Complex& c2);

#endif //PROGRAMACAO_IMAG_H