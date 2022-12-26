// denis: Program that asks the user to insert numbers in a sequence of N integers
// N must be at least 1 and cannot be greater than 10, the size of the sequence is chosen by the user too
// After that, prints the integers that were read in reverse order
#include <iostream>
using namespace std;

int main()
{
    int n; // Initialize variable to store the size of the sequence (1 - 10)
    do
    {
        cout << "How many numbers??? ";
        cin >> n;
    } while ((n < 1) || (n > 10));

    int integers[n]; // Initialize array to store the numbers in the sequence
    for (int i = 0; i < n; i++)
    {
        int number; // Initialize variable to store the numbers in the sequence
        cout << "Number? ";
        cin >> number;
        integers[i] = number; // Adds the chosen numbers by the user to the array
    }

// Prints the integers, that were inserted by the user, in reverse order
    for (int i = 0; i < n; i++) {
        cout << integers[n - i - 1] << ' ';
    }
    cout << endl;
    return 0;
}
