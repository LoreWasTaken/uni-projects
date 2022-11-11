// denis: Create a function, Fibonacci(n), to calculate the nᵗʰ Fibonacci number.
// Calculating the value of F₄₀
#include "iostream"
using namespace std;

// Fibonacci sequence
int Fibonacci(int n){
    int a = 0;
    int b = 1;
    while (n--){
        int tmp = b;
        b = b + a;
        a = tmp;
    }
    return b;
}

int main(){
    int n;
    cout << "Fibonacci sequence" << endl;
    cout << "Insert a number: ";
    cin >> n;
    cout << "The " << n << "ᵗʰ term of the Fibonacci sequence is " << Fibonacci(n) << endl;
    cout << "(The 40ᵗʰ term of the Fibonacci sequence is " << Fibonacci(40) << ")" << endl;

    return 0;
}
