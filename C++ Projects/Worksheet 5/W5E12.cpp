// Change of the program F4E4, using only functions.
// Will be used a function for each option of the menu
// Functions: Read a sequence, Write a sequence, Calculate the maximum value, Calculate the minimum value
// Calculate average value, Test if the sequence includes only even numbers
#include "iostream"
using namespace std;

//Read the sequence
int ReadSequence(int seq[]){
    int N = 0;
    for (int i = 0; i < 50; i++){
        int number;
        cout << "Insert numbers into the sequence (maximum 50)" << endl;
        cout << "(Press 0 to stop)" << endl;
        cin >> number;
        if (not number) break; // (not number) => number == 0
        seq[i] = number;
        N++;
    }
    return N;
}

// Write the sequence
void WriteSequence(int seq[], int N){
    for (int i = 0; i < N; i++){
        cout << seq[i] << ' ';
    }
}

// Calculation of the maximum number of the sequence
int MaxValueSequence(int seq[], int N){
    int max = seq[0];
    for (int i = 1; i < N; i++){
        if (seq[i] > max) max = seq[i];
    }
    return max;
}

// Calculation of the minimum number of the sequence
int MinValueSequence(int seq[], int N){
    int min = seq[0];
    for (int i = 1; i < N; i++){
        if (seq[i] < min ) min = seq[i];
    }
    return min;
}

// Calculation of the average number of the sequence
double AverageSequence(int seq[], int N){
    double average = seq[0];
    for (int i = 0; i < N; i++){
        average += seq[i];
    }
    average /= N ? N : 1;
    return average;
}

// Evaluate if the sequence has only even numbers
bool ContainsOddNumber(int seq[], int N){
    for (int i = 0; i < N; i++){
        if (seq[i] % 2) return true;
    }
    return false;
}

int main() {
    int choice = 0;
    int N = 0;
    int numbers[50];
    do {
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
                if (not N) cout << "The sequence does not have elements.";
                else if (ContainsOddNumber(numbers, N)) cout << "The sequence has, at least, one odd number.";
                else cout << "The sequence is composed of only even numbers.";
                cout << endl;
                break;
            }
        }
    } while (choice != 10);
    cout << "Bye!";

    return 0;
}