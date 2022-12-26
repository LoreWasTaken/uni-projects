#include <iostream>
#include <cmath>
#include "Exercicio 1.h"

using namespace std;

int main(){
    int N = SizeOfSequence();
    // Static array
    //int Sequence[N];

    // Initializing dynamic array
    int *Sequence = NULL;
    Sequence = new int[N];

    ReadingValuesSequence(Sequence, N);

    double average = AverageSequence(Sequence, N);
    cout << "Average of the sequence: " << average << endl;

    double standard_deviation = StandardDeviation(Sequence, N);
    cout << "Standard deviation of the sequence: " << standard_deviation << endl;

    cout << "Values above the average: ";
    PrintValuesAboveAverage(Sequence, N, average);
    cout << endl;

    delete [] Sequence;
    return 0;
}