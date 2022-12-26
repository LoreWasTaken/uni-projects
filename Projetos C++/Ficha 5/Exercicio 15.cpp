// denis: Create a function, aproxPi (n), which returns the sum of the first n terms of the Leibniz series
// The value n is introduced by the user
#include "iostream"
#include "cmath"
using namespace std;

// Pi approximation using the Leibniz series
double aproxPi(double n){
    double sum = 1;
    for (int i = 1; i <= n; i++){
        sum += pow(-1, i) / (2*i + 1);
        return sum * 4;
    }
}

int main(){
    int n;
    cout << "Approximation to Pi, which returns the sum of the first n terms" << endl;
    cout << "Insert a number: ";
    cin >> n;
    cout << "Pi approximated " << n << " times = " << aproxPi(n) << endl;

    return 0;
}