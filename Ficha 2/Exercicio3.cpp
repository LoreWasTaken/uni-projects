#include "iostream"
using namespace std;

int main(){
    double a, b;
    cout << "Insert two numbers: ";
    cin >> a >> b;

    if(a>b)
        cout << a << " is larger than " << b << endl;
    else if(a == b)
        cout << a << " is equal to " << b << endl;
    else
        cout << a << " is lower than " << b << endl;
}
