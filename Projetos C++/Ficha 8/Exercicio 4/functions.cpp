#include "iostream"
#include "iomanip"
#include "functions.h"
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
/* Histogram */

// Reading with validation of the N value
int Number(){
    int number;
    do{
        cout << "Number of students? ";
        cin >> number;
        if (number <= 0) cout << "Must be a positive number!" << endl;
    } while (number <= 0);
    return number;
}

// Validated reading of the numbers into an array & calculation of the counting
void WriteNumbers(int seq[], int n){
    while (n--){
        int num;
        cout << "Number? ";
        do {
            cin >> num;
            if (num > 20 || num <= 0) cout << "Must be a valid number!" << endl;
        } while (num > 20 || num <= 0);
        seq[num] += 1;
    }
}

// Prints histogram 
void histogram(const int* sequence, int size, int numBars) {
    // Calculate the range of values for each bar
    int maxVal = INT_MIN;
    int minVal = INT_MAX;
    for (int i = 0; i < size; i++) {
        maxVal = max(maxVal, sequence[i]);
        minVal = min(minVal, sequence[i]);
    }
    int range = (maxVal - minVal) / numBars;

    // Initialize the bar counts
    int* barCounts = new int[numBars]{0};

    // Count the number of elements in each bar
    for (int i = 0; i < size; i++) {
        int bar = (sequence[i] - minVal) / range;
        if (bar == numBars) {
            bar--;  // Make sure the maximum value is included in the last bar
        }
        barCounts[bar]++;
    }

    // Print the histogram
    for (int i = 0; i < numBars; i++) {
        cout << "[" << minVal + i * range << "-" << minVal + (i + 1) * range << "]: ";
        for (int j = 0; j < barCounts[i]; j++) {
            cout << "*";
        }
        cout << endl;
    }

    // Free the memory for the bar counts array
    delete[] barCounts;
}
