// Create a function called power() that takes a double value for n and an int value for p, and returns the result
// as a double value
// default argument for p will be 2, so that if this is argument is omitted, the number n will be squared.
// Values introduced by the user
#include "iostream"
using namespace std;

double power(double n, int p = 2){
    double result = 1.0;
    while (p--) result *= n;
    return result;
}

int main(){
    int n, p;
    cout << "Power template test" << endl;
    cout << "Insert value for n: ";
    cin >> n;
    cout << "Insert value for p: ";
    cin >> p;
    cout << "Result: " << power(n,p);

    return 0;
}