#include "Exercicio 1.h"
using namespace std;
// Reading with validation of the N value (Length of the sequence)
int SizeOfSequence(){
    int N;
    do{
        cout << "What is the length of the sequence (positive numbers only)? ";
        cin >> N;
    } while (N < 1);
    return N;
}

// Reading the values introduced by the user into the sequence
void ReadingValuesSequence(int seq[]/* (int* array[] )*/, int N = 0){
    for (int i = 0; i < N; i++) {
        int number;
        cout << "Insert numbers into the sequence: ";
        cin >> number;
        seq[i] = number;
    }
}

// Calculation of the average number
double AverageSequence(int seq[], int N){
    int sum = 0;
    for (int i = 0; i < N; i++) sum += seq[i];
    return sum / N;
}

// Calculation of the standard deviation
double StandardDeviation(int seq[], int N){
    double average_deviation = 0;
    for (int i = 0; i < N; i++){
        double deviation = pow((float)seq[i] - AverageSequence(seq, N), 2);
        average_deviation += deviation;
    }
    return sqrt(average_deviation / N);
}

// Prints the values above the average
void PrintValuesAboveAverage(int seq[], int N, double limit){
    for (int i = 0; i < N; i++){
        if ((double)seq[i] > limit) cout << seq[i];
    }
}

// Initializing dynamic array
//int *parray = NULL;
//parray = new int[N];

//delete [] parray;