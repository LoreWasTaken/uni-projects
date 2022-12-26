#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

// Read a sequence of integers from the user
vector<int> readSequence() {
  cout << "Enter a sequence of integers, followed by 0: ";

  vector<int> sequence;
  int n;
  cin >> n;

  while (n != 0) {
    sequence.push_back(n);
    cin >> n;
  }

  return sequence;
}

// Write the sequence to the screen
void writeSequence(vector<int> sequence) {
  cout << "The sequence is: ";
  for (int n : sequence) {
    cout << n << " ";
  }
  cout << endl;
}

// Calculate the maximum value in the sequence
int maxValue(vector<int> sequence) {
  return *max_element(sequence.begin(), sequence.end());
}

// Calculate the minimum value in the sequence
int minValue(vector<int> sequence) {
  return *min_element(sequence.begin(), sequence.end());
}

// Calculate the average value of the sequence
double avgValue(vector<int> sequence) {
  int sum = 0;
  for (int n : sequence) {
    sum += n;
  }
  return (double)sum / sequence.size();
}

// Check if the sequence is composed only of even values
bool allEven(vector<int> sequence) {
  for (int n : sequence) {
    if (n % 2 != 0) {
      return false;
    }
  }
  return true;
}

// Search the sequence for a given value
bool search(vector<int> sequence, int value) {
  return find(sequence.begin(), sequence.end(), value) != sequence.end();
}

int main() {
    // Vector to store the sequence of numbers
    vector<int> seq;
    // Menu option
    int option = 0;
    // Flag to indicate if the program should end
    bool end = false;
    // Read user input and perform requested actions
    while (!end) {
        cout << "Analysis of a sequence of integer numbers" << endl;
        cout << "1 - Read a sequence" << endl;
        cout << "2 - Write the sequence in the screen" << endl;
        cout << "3 - Calculate the maximum value" << endl;
        cout << "4 - Calculate the minimum value" << endl;
        cout << "5 - Calculate the average value" << endl;
        cout << "6 - Detect if the sequence is constituted by only even values" << endl;
        cout << "7 - Order the sequence in ascending order" << endl;
        cout << "8 - Order the sequence in descending order" << endl; // New option added here
        cout << "9 - Search the sequence for a value" << endl;
        cout << "10 - End program" << endl;
        cout << "Option -> ";

        // Read user input
        cin >> option;

        switch (option) {
            case 1:
                // Read the sequence of numbers
                readSequence();
                break;
            case 2:
                // Write the sequence of numbers to the screen
                writeSequence(seq);
                break;
            case 3:
                // Calculate and print the maximum value in the sequence
                cout << "The maximum value is: " << maxValue(seq) << endl;
                break;
            case 4:
                // Calculate and print the minimum value in the sequence
                cout << "The minimum value is: " << minValue(seq) << endl;
                break;
            case 5:
                // Calculate and print the average value of the sequence
                cout << "The average value is: " << avgValue(seq) << endl;
                break;
            case 6:
                // Print whether the sequence consists only of even numbers
                cout << "The sequence is constituted by only even values? " << allEven(seq) << endl;
                break;
            case 7:
                // Order the sequence in ascending order
                sort(seq.begin(), seq.end());
                cout << "The sequence has been ordered in ascending order." << endl;
                break;
            case 8:
                // Order the sequence in descending order
                sort(seq.rbegin(), seq.rend()); // Use reverse iterators to sort in descending order
                cout << "The sequence has been ordered in descending order." << endl;
                break;
            case 9:
                // Search the sequence for a value
                int n; // Number to search for
                cout << "What number you want to search for in the sequence? " << endl;
                cout << "-> ";
                cin >> n;
                cout << "The number " << n << (search(seq, n) ? " was" : " was not") << " found in the sequence." << endl;
                break;
            case 10:
                // End the program
                end = true;
                break;
            default:
                cout << "Invalid option." << endl;
                break;
        }
    }
}