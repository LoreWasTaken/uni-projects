// denis: Create a function that allows to calculate the value of any second degree polynomial g(x) = ax²+bx+c

#include "iostream"
#include "cmath"
using namespace std;

double polynomial(double x, double c, double b, double a){
    double y = a * pow(x, 2) + b * x + c;
    return y;
}

int main (){
    double x, a, b, c;
    cout << "Calculation of any second degree polynomial" << "\n" << "g(x) = ax² + bx + c" << endl;
    cout << "What's the value of x: ";
    cin >> x;
    cout << "What's the value of a: ";
    cin >> a;
    cout << "What's the value of b: ";
    cin >> b;
    cout << "What's the value of c: ";
    cin >> c;
    cout << "Answer: " << polynomial(x, c, b, a);

    return 0;
}