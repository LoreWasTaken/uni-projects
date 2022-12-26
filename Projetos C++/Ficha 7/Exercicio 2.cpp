// denis: Program that is able to perform complex number arithmetic
// denis: This program isn't working like it's asked to work, made another file named Exercicio 2.1 working, i think.
#include "iostream"
#include "iomanip"
#include "cmath"
using namespace std;

// a) Defining a data structure, named Complex, to represent a complex number as a
//pair of two real numbers, "re" and "im" (the first holding the real part of the complex number, and the second holding the imaginary part.)
typedef struct Complex{
    double re;
    double im;
} Complex_t ;

// b) Function that asks the user for a complex number
Complex_t ask_number(){
    Complex_t tmp;
    cout << "Choose the real part of the complex number: ";
    cin >> tmp.re;
    cout << "Choose the imaginary part of the complex number: ";
    cin >> tmp.im;

    return tmp;
}

// c) Function that prints a complex number according to the following format:
// +#.###+#.###i.  (+ represents a sign (+ or -) and # represents a digit (0 to 9))
void print_number(Complex_t n1){
    cout << showpos << setprecision(3) << fixed << n1.re << n1.im << "i" << "\n";
}

// d) Function for each of the following arithmetic operations:
void A_O(Complex_t n1, Complex_t n2){
    // n1.re = a | n1.im = b | n2.re = c | n2.im = d
//double add1, add2, sub, multi, div;
    // i. Addition: (a+bi)+(c+di) = (a+c)+(b+d)i
    cout << showpos << setprecision(3) << fixed << (n1.re+n2.re) << (n1.im+n2.im) << "i" << "\n";
    // ii. Subtraction: (a+bi)-(c+di) = (a-c)+(b-d)i
    cout << showpos << setprecision(3) << fixed << (n1.re-n2.re) << (n1.im-n2.im) << "i" << "\n";
    // iii. Multiplication: (a+bi)*(c+di) = (ac-bd)+(ad+bc)i
    cout << showpos << setprecision(3) << fixed << ((n1.re*n2.re)-(n1.im*n2.im)) << ((n1.re*n2.im)+(n1.im*n2.re)) << "i" << "\n";
    // Division: (a+bi)/(c+di) = ((ac+bd)/(c^2+d^2))+((bc-ad)/(c^2+d^2))i
    cout << showpos << setprecision(3) << fixed << (((n1.re*n2.re)+(n1.im*n2.im)) / pow(n2.re, 2)+pow(n2.im,2)) << (((n1.im*n2.re)-(n1.re*n2.im)) / (pow(n2.re, 2)+pow(n2.im, 2))) << "i" << "\n";
}


int main(){
    struct Complex number1;
    Complex_t number2;
    number1 = ask_number();
    number2 = ask_number();
    print_number(number1);
    A_O(number1, number2);
}

