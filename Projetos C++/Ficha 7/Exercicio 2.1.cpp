// denis: Program that should be able to perform complex number arithmetic
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

// Defining a data structure to represent a complex number as a pair of two real
// numbers, "re" and "im", the first holding the real part of the complex number,
// and the second holding the imaginary part.
struct Complex
{
    double re;
    double im;
};

// Asking the user for a complex number and return it.
Complex askForComplexNumber(Complex& c)
{
    //Complex c;
    cout << "Real part: ";
    cin >> c.re;
    cout << "Imaginary part: ";
    cin >> c.im;
    return c;
}

// Printing the real and imaginary parts of the complex number
// using the specified format in the sheet
void printComplexNumber(Complex& c)
{
    cout << showpos << setprecision(3) << fixed
         << "(" << c.re /*<< "+" */ << c.im << "i)";
}

// Arithmetic operators
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

int main(){
    Complex c1, c2; // Defining variables to store the complex numbers
    char op; // Defining variable to store arithmetic operation

    while(true){
        // Asking the user for the arithmetic operator
        cout << "Enter an operation (+, -, *, /): ";
        cin >> op;

        // Checking if the operation is valid
        if (op != '+' && op != '-' && op != '*' && op != '/') {
            cout << "Illegal operation. Good bye!" << endl;
            break;
        }

        // Asking the user for the first complex number
        cout << "Complex number #1 ? ";
        askForComplexNumber(c1);

        // Asking the user for the second complex number
        cout << "Complex number #2 ? ";
        askForComplexNumber(c2);

        // Printing the operands
        cout << "(";
        printComplexNumber(c1);
        cout << ") " << op << " (";
        printComplexNumber(c2);
        cout << ") = ";

        // Performing the arithmetic operation and printing the result
        Complex result;
        if (op == '+') {
            result = addition(c1, c2);
        } else if (op == '-') {
            result = subtraction(c1, c2);
        } else if (op == '*') {
            result = multiplication(c1, c2);
        } else if (op == '/') {
            result = division(c1, c2);
        }

        // Printing the result
        cout << "(";
        printComplexNumber(result);
        cout << ")" << endl;
    }

    return 0;
}