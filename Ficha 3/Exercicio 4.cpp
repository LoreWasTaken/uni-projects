// denis: Program that asks user to insert a positive integer and prints the list of all its own proper divisors
// Also prints if the positive integer is deficient, perfect or abundant
#include "iostream"
using namespace std;

int main()
{
    int N; // Variable to store positive integer
    int sum = 1;
    do
    {
        cout << "Insert a positive number: ";
        cin >> N;
    } while (N <= 0);
// Prints the list of its own proper divisors
    for (int n = 2; n <= N/2; n++){
        if (N % n == 0 && n != N)
        {
            cout << n << endl;
            sum = sum + n;
        }
    }

// Prints if the number is deficient, abundant or perfect based on the sum of all its own divisors
    if (sum < N)
        cout << "Deficient number" << endl;
    if (sum > N)
        cout << "Abundant number" << endl;
    if (sum == N)
        cout << "Perfect number" << endl;
}