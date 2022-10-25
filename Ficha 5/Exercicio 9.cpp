// denis: Create a function which calculates the greatest common divisor between two integer positive numbers
// using Euclidean algorithm. The values are introduced by the user
#include "iostream"
using namespace std;

int Euclidean(int a, int b){
    int r = a%b;
    return (r == 0) ? b : Euclidean(b, r);
}

int main(){
    int a, b;
    do {
        cout << "Insert two numbers, and I'll calculate their Greatest Common Divisor: " << endl;
        cout << "Number 1: ";
        cin >> a;
        cout << "Number 2: ";
        cin >> b;
    } while ((a <= 0) || (b <= 0));
    cout << "GCD: " << Euclidean(a, b);

    return 0;
}