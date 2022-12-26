// Functions: Read a sequence, Write a sequence, Calculate the maximum value, Calculate the minimum value
// Calculate average value, Test if the sequence includes only even numbers

// denis: The histogram option isn't working properly, might fix.

#include "functions.h"
#include "iostream"
using namespace std;

int main() {
    int choice = 0;
    int N = 0;
    int NBars = 0;
    // Static array
    //int numbers[50];
    // Dynamic array
    int *numbers = NULL;
    numbers = new int[N];

    do {
        cout << "Analysis of a sequence of integers" << endl
             << " 1 - Read a sequence" << endl
             << " 2 - Write a sequence" << endl
             << " 3 - Calculate the maximum value" << endl
             << " 4 - Calculate the minimum value" << endl
             << " 5 - Calculate the mean value" << endl
             << " 6 - Histogram" << endl
             << "10 - End the program" << endl
             << "Choice -> ";
        cin >> choice;
        switch (choice) {
            case 1:
                N = ReadSequence(numbers);
                break;
            case 2:
                WriteSequence(numbers, N);
                cout << endl;
                break;
            case 3: {
                if (N) {
                    int max = MaxValueSequence(numbers, N);
                    cout << "Maximum value of the sequence: " << max;
                }
                else cout << "The sequence does not have elements.";
                cout << endl;
                break;
            }
            case 4: {
                if (N) {
                    int min = MinValueSequence(numbers, N);
                    cout << "Minimum value of the sequence: " << min;
                }
                else cout << "The sequence does not have elements.";
                cout << endl;
                break;
            }
            case 5: {
                if (N) {
                    double average = AverageSequence(numbers, N);
                    cout << "Mean number of the sequence: " << average;
                }
                else cout << "The sequence does not have elements.";
                cout << endl;
                break;
            }
            case 6: {
                cout << "How many number of bars? ";
                cin >> NBars;
                histogram(numbers, N, NBars);
                break;
            }
        }
    } while (choice != 10);
    delete[] numbers;
    cout << "Bye!";

    return 0;
}