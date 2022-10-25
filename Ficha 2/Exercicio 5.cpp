// denis: Program that asks user to insert a number and prints if the number is even or odd
#include <iostream>
using namespace std;

int main()
{
    int n; // Number inserted by user
    cout << "Insert a number: ";
    cin >> n;

    if(n % 2 == 0)
        cout << "Even";
    else
        cout << "Odd";
/*
Option to test if a number is even or odd, bitwise
    if ((n&1) == 0)
        cout << "Even";
    else
        cout << "Odd";
*/

    return 0;
}
