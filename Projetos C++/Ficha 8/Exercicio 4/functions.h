#ifndef PROGRAMACAO_FUNCTIONS_H
#define PROGRAMACAO_FUNCTIONS_H

//Read the sequence
int ReadSequence(int seq[]);
// Write the sequence
void WriteSequence(int seq[], int N);
// Calculation of the maximum number of the sequence
int MaxValueSequence(int seq[], int N);
// Calculation of the minimum number of the sequence
int MinValueSequence(int seq[], int N);
// Calculation of the average number of the sequence
double AverageSequence(int seq[], int N);
// Histogram
void histogram(const int* sequence, int size, int numBars);

#endif //PROGRAMACAO_FUNCTIONS_H
