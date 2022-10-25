// denis: Create a function which determines how many digits has an integer positive number
// Integer inserted by the user
#include "iostream"
#include "cmath"
using namespace std;

int digits(int n){
    return log10(n) +1;
}

// Another way to do it
/*
int num_digits (int n){
    int ndigs = 0;
    while (n != 0){
        ndigs++; // 1+1+1
        n = n/10; // n = 0
    }
    return ndigs;
}
*/

int main(){
    int number;
    do{
        cout << "Insert a positive number, and I shall tell you it's number of digits! ";
        cin >> number;
    } while (number <= 0);
    cout << number << " has a decimal size of " << digits(number) << endl;

    return 0;
}