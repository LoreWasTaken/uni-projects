// denis: Program that asks user to insert a positive integer and determines if the number is a prime number
#include <valarray>
#include "iostream"
using namespace std;

int main()
{
    int x; // Variable to store number inserted by user
    do
    {
        cout << "Insert a positive number: ";
        cin >> x;
    } while (x <= 0);
    bool prime = true;
    for (int n = 2; n <= sqrt(x); n++){
    if (x % n == 0)
        {
        cout << "The number is not prime.";
        prime = false;
        break;
        }
    }
    if (prime)
        cout << "The number is prime.";
}