// denis: Program that reads a sequence of positive integers and allows executing a number of operations over the sequence
// Reading ends after getting 50 numbers or when a zero is entered
// Interaction with the program is done through a menu
#include <iostream>
using namespace std;

int main()
{
    int choice = 0; // Initialize variable to store users choice (1 - 6) or 10 to end the program
    int n = 0; // Initialize variable to store the size of the array (How many numbers user inserted into the sequence)
    int numbers[50]; // Initialize array to store sequence of maximum 50 numbers

// Prints the menu until 10 is inserted in the "Choice -> "
    do
    {
        cout << "Analysis of a sequence of integers" << endl
                  << " 1 - Read a sequence" << endl
                  << " 2 - Write a sequence" << endl
                  << " 3 - Calculate the maximum value" << endl
                  << " 4 - Calculate the minimum value" << endl
                  << " 5 - Calculate the mean value" << endl
                  << " 6 - Test if the sequence includes only even numbers" << endl
                  << "10 - End the program" << endl
                  << "Choice -> ";
        cin >> choice;
        switch (choice)
        {
            case 1:                        // Read the sequence that the user inserts
                n = 0;
                for (int i = 0; i < 50; i++)
                {
                    int number;
                    cout << "Number? (Set 0 to stop) ";
                    cin >> number;
                    if (not number) break; // (not number) -> number == 0
                    numbers[i] = number;
                    n++;
                }
                break;
            case 2:                        // Write the sequence chosen by the user
                for (int i = 0; i < n; i++)
                {
                    cout << numbers[i] << ' ';
                }
                cout << endl;
                break;
            case 3: {                      // Calculate the max value of the sequence
                int max = 0;
                for (int i = 0; i < n; i++)
                {
                    if (numbers[i] > max) max = numbers[i];
                }
                cout << "Max: " << max << endl;
                break;
            }
            case 4: {                      // Calculate the min value of the sequence
                int min = n ? numbers[0] : 0; // <=> int min; if (n == 0) min = 0; else min = numbers[0];
                for (int i = 0; i < n; i++)
                {
                    if (numbers[i] < min) min = numbers[i];
                }
                cout << "Min: " << min << endl;
                break;
            }
            case 5: {                      // Calculate the average of the sequence
                double average = 0;
                for (int i = 0; i < n; i++)
                {
                    average += numbers[i];
                }
                average /= n ? n : 1; // <=> if (n != 0) average = average / n;
                cout << "Average: " << average << endl;
                break;
            }
            case 6: {                      // Test if sequence has only even numbers
                bool thereIsOdd = false;
                for (int i = 0; i < n and not thereIsOdd; i++)
                {
                    thereIsOdd = numbers[i] % 2;
                }
                if (not n) cout << "The sequence contains no numbers.";
                else if (thereIsOdd) cout << "The sequence includes odd numbers.";
                else cout << "The sequence is composed of only even numbers.";
                cout << endl;
            }
        }
    } while (choice != 10);
    cout << "Adeus!";

    return 0;
}
