// denis: Create a function countdown(N) which prints a countdown starting from a positive number N
// N is introduced by the user
#include "iostream"
using namespace std;

int countdown(int N){               // More optimized way of doing this function is:
    while(N != 0) {                 // void printcountdown(unsigned n) {
        cout << N << endl;          //	do std::cout << n << std::endl; while (n--);
        N -= 1;                     //}
    }
    return N;
}

/*
void countdown(int N)
{
    for (int i = N; i >= 0; i--)
        cout << i << endl;
}
*/

int main(){
    int N;
    do {
        cout << "Choose any positive number to countdown from: ";
        cin >> N;
    } while (N <= 0);
    cout << countdown(N) << endl;

    return 0;
}