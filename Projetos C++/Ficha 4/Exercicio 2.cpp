// denis: Program that asks the user to insert numbers in a sequence of N integers
// N must be at least 1 and cannot be greater than 10, the size of the sequence is chosen by the user too
// After that, prints the average and standard deviation of the sequence and prints the values above the average
#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int n; // Initialize variable to store the size of the sequence (1 - 10)
    do
    {
        cout << "How many numbers??? ";
        cin >> n;
    } while (n < 1 || n > 10);

    int integers[n]; // Initialize array to store the numbers in the sequence
    int sum = 0; // Initialize variable to store the sum of numbers
    for (int i = 0; i < n; i++)
    {
        int number; // Initialize variable to store the numbers in the sequence
        cout << "Number? ";
        cin >> number;
        integers[i] = number;
        sum += number; // Adds the chosen numbers by the user to the array
    }

    double average = (double)sum / n; // Calculates the average

    double average_deviation = 0; // Initialize the variable to store the average deviation
    // Calculates the average deviation
    for (int i = 0; i < n; i++)
    {
        double deviation = pow((float)integers[i] - average, 2);
        average_deviation += deviation;
    }

    double standard_deviation = sqrt(average_deviation / n); // Calculates the standard deviation

    // Prints the values above average
    for (int i = 0; i < n; i++)
    {
        if ((double)integers[i] > average) cout << integers[i] << endl;
    }
    return 0;
}
