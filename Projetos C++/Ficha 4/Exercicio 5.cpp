// denis: Program that reads the number of times that each element occurs in the sequence chosen by the user
// Reading ends after getting 100 numbers or a non-positive number
#include <iostream>
using namespace std;

int main()
{
    // Initialize array to store a sequence of maximum 100 numbers
    int numbers[100];
    for (int i = 0; i < 100; i++) numbers[i] = 0;

    // Ask for numbers to fill the array from the user
    int counter = 0;
    for (int i = 0; i < 100; i++, counter++)
    {
        int number;
        cout << "Input numbers in the sequence(enter 0 to stop): ";
        cin >> number;
        if (number <= 0) break;
        numbers[i] = number;
    }

    // Create list to track numbers already tracked
    int already_tracked[100];
    for (int i = 0; i < 100; i++) already_tracked[i] = -1;


    for (int track = 0; track < counter; track++)
    {
        int tracked = numbers[track];
        if (tracked == already_tracked[track]) continue;

        int caught = 0; // Initialize variable to store number of times has seen elements in sequence
        for (int i = track; i < counter; i++) if (numbers[i] == tracked)
        {
            caught += 1;
            already_tracked[i] = tracked;
        }
        cout << "The number " << tracked << " was found " << caught << " times in the sequence." << endl;
    }

    return 0;
}