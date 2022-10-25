// denis: Create a series of overloaded functions with the same name that, in addition to double, also work with types
// char, short, int, long and float
// Program should print all overloaded functions with all argument types
#include "iostream"
using namespace std;

double power(char n, unsigned p = 2){
    double result = 1.0;
    while (p--) result *= n;
    cout << "Type: char = ";
    return result;
}

double power(short n, unsigned p = 2){
    double result = 1.0;
    while (p--) result *= n;
    cout << "Type: short = ";
    return result;
}

double power(int n, unsigned p = 2){
    double result = 1.0;
    while (p--) result *= n;
    cout << "Type: int = ";
    return result;
}

double power(long n, unsigned p = 2){
    double result = 1.0;
    while (p--) result *= n;
    cout << "Type: long = ";
    return result;
}

double power(float n, unsigned p = 2){
    double result = 1.0;
    while (p--) result *= n;
    cout << "Type: float = ";
    return result;
}

double power(double n, unsigned p = 2){
    double result = 1.0;
    while (p--) result *= n;
    cout << "Type: double = ";
    return result;
}

int main(){
    //int a, b;
    //cout << "Overloaded power function: " << endl;
    //cout << "Insert value for n: ";
    //cin >> a;
    //cout << "Insert value for p: ";
    //cin >> b;
    //cout << "Result: " << power(a,b);

    //Examples
    short s=6; int i=4; long l=8; float f=6.5;  double d=9.2; char c='a';
    cout << "6² -> " << power(s) << endl; // short
    cout << "4³ -> " << power(i, 3) << endl; // int
    cout << "8⁵ -> " << power(l, 5) << endl; // long
    cout << "6.5⁴ -> " << power(f, 4) << endl; // float
    cout << "9.2⁶ -> " << power(d, 6) << endl; // double
    cout << "a³ -> " << power(c, 3) << endl; // char  / 'a' => decimal 97 => 97³ = 912673
    cout << endl;

    return 0;
}