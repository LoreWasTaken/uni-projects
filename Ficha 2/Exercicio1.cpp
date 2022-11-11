#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Number? ";
    cin >> n;

    if(n%2 == 0)
        cout << "Even";
    else
        cout << "Odd";
/*
Bitwise option to test if a number is even or odd
    if ((n&1) == 0)
        cout << "Even";
    else
        cout << "Odd";
*/
    return 0;
}
