// denis: Create a function which calculates the sum of all integers between two integer numbers passed as arguments
// Ex: sumAll(1, 10) => sum of all numbers between 1 and 10, including
// Integer numbers introduced by the user
#include "iostream"
using namespace std;

int sumAll(int a, int b){
    int sum = 0;
    for (; a <= b; a++) sum += a;
    return sum;
}

int main(){
    int a, b;
    do {
        cout << "Insert two numbers, the sum of all the numbers from one to the other will be calculated: " << endl;
        cout << "Number 1: ";
        cin >> a;
        cout << "Number 2: ";
        cin >> b;
    } while ((a <= 0) || (b <= 0));
    cout << "The sum of all the numbers are: " << sumAll(a, b);

    return 0;
}