// denis: Modified W2E3, Program that asks user to input three numbers and prints the largest in the terminal.
#include <iostream>
using namespace std;

int main()
{
    double a, b, c; // Three random numbers inserted by the user

    cout << "Enter three numbers: ";
    cin >> a >> b >> c;

    if (a > b && a > c)
        cout << "Largest number: " << a;
    else if (b > a && b > c)
        cout << "Largest number: " << b;
    else
        cout << "Largest number: " << c;

    return 0;
}