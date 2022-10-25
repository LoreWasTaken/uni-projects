// denis: Changes the program F4E2, using functions now.
// 4 functions, at least: reading with validation of the N value, reading of the keyboard values into an array, average calculation,
// standard deviation calculation.
// After that, prints the values greater than the average.
// Values as well as the length of sequence will be introduced by the user.

#include "iostream"
#include "cmath"
using namespace std;

// Reading with validation of the N value (Length of the sequence)
int SizeOfSequence(){
    int N;
    do{
        cout << "What is the length of the sequence(1-10)? ";
        cin >> N;
    } while (N < 1 || N > 10);
    return N;
}

// Reading the values introduced by the user into the sequence
void ReadingValuesSequence(int seq[], int N = 0){
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

int main(){
    int N = SizeOfSequence();
    int Sequence[N];
    ReadingValuesSequence(Sequence, N);

    double average = AverageSequence(Sequence, N);
    cout << "Average of the sequence: " << average << endl;

    double standard_deviation = StandardDeviation(Sequence, N);
    cout << "Standard deviation of the sequence: " << standard_deviation << endl;

    cout << "Values above the average: ";
    PrintValuesAboveAverage(Sequence, N, average);
    cout << endl;

    return 0;
}