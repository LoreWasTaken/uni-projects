#ifndef PROGRAMACAO_EXERCICIO_1_H
#define PROGRAMACAO_EXERCICIO_1_H

// Including necessaries libraries
#include "iostream"
#include "cmath"

// Reading with validation of the N value (Length of the sequence)
int SizeOfSequence();
// Reading the values introduced by the user into the sequence
void ReadingValuesSequence(int seq[]/* (int* array[] )*/, int N = 0);
// Calculation of the average number
double AverageSequence(int seq[], int N);
// Calculation of the standard deviation
double StandardDeviation(int seq[], int N);
// Prints the values above the average
void PrintValuesAboveAverage(int seq[], int N, double limit);

#endif //PROGRAMACAO_EXERCICIO_1_H