/*
denis: This program uses a vector from the C++ standard library to store the numbers read from the file.
The "average" and "stddev" functions use a reference to this vector to calculate the average and standard deviation of the numbers.
The main function prompts the user for the name of the file, opens the file, reads the numbers from the file and stores them in the vector,
and then calls the average and stddev functions to calculate the average and standard deviation.
Finally, it prints the numbers that are larger than the average.
*/
#include <iostream>
#include <fstream>
#include <cmath>
#include <vector>

using namespace std;

// function to calculate the average of a vector of numbers
double calculateAverage(vector<double>& numbers)
{
    double sum = 0;
    for (int i = 0; i < numbers.size(); i++)
    {
        sum += numbers[i];
    }
    return sum / numbers.size();
}

// function to calculate the standard deviation of a vector of numbers
double calculateStddev(vector<double>& numbers, double average)
{
    double sum = 0;
    for (int i = 0; i < numbers.size(); i++)
    {
        sum += pow(numbers[i] - average, 2);
    }
    return sqrt(sum / numbers.size());
}

int main()
{
    // ask user for the name of the file
    cout << "Enter the name of the file: ";
    string filename;
    cin >> filename;

    // open the file
    ifstream file(filename);

    // check if the file was opened successfully
    if (!file.is_open())
    {
        cout << "Error opening file " << filename << endl;
        return 1;
    }

    // read numbers from the file and store them in a vector
    vector<double> numbers;
    double x;
    while (file >> x)
    {
        numbers.push_back(x);
    }

    // calculate the average and standard deviation of the numbers
    double average = calculateAverage(numbers);
    double stddev = calculateStddev(numbers, average);

    // print the average and standard deviation
    cout << "Average: " << average << endl;
    cout << "Standard deviation: " << stddev << endl;

    // print the numbers that are larger than the average
    cout << "Numbers larger than the average: " << endl;
    for (int i = 0; i < numbers.size(); i++)
    {
        if (numbers[i] > average)
        {
            cout << numbers[i] << endl;
        }
    }

    return 0;
}