// denis: Program that should be able to perform complex number arithmetic but now the functions are separated using a header

#include <iostream>
#include <iomanip>
#include <cmath>
#include "imag.h"
using namespace std;

int main(){
    Complex c1, c2; // Defining variables to store complex numbers
    char op; // Defining variable to store arithmetic operator

    while(true){
        // Asking the user for the arithmetic operation
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

        // Performing the arithmetic operation and print the result
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