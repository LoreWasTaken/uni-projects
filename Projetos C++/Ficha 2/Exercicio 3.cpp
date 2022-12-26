// denis: Program that asks user to insert two numbers and prints the largest of them in the terminal. If both are equal prints they are equal.
#include "iostream"
using namespace std;

int main(){
    double a, b; // Two random numbers inserted by the user
    cout << "Insert two numbers: ";
    cin >> a >> b;

    if (a > b)
        cout << a << " is greater than " << b << endl;
    else if (a == b)
        cout << a << " is equal to " << b << endl;
    else
        cout << a << " is less than " << b << endl;

    return 0;
}