// denis: Program that asks user for real number, until entered number zero, and prints the maximum value, the minimum value
// the average and the number of elements entered (Doesn't count the stop value (0))
#include "iostream"
#include "cfloat"
using namespace std;

int main()
{
    double number; // Initialize variable to store the numbers entered by the user
    double soma = 0; // Initialize variable to store the sum
    int n = 0; // Initialize variable to store the number of elements
    auto max = DBL_MIN; auto min = DBL_MAX; // Initialize variables to store the min and max value
    do
    {
        cout << "Enter real numbers until you enter the number 0: ";
        cin >> number;

        if (number > max)
            max = number;
        if (number < min && number != 0)
            min = number;

        soma = soma + number; // Sum
        if (number != 0)
            n++;
    }
    while (number != 0);
    double media = soma / n; // Average

    cout << "Maximum value: " << max << endl;
    cout << "Minimum value: " << min << endl;
    cout << "Average = " << media << endl;
    cout << "Number of elements entered: " << n;

    return 0;
}