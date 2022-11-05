// Practice Test 1, but now only using functions for each question
#include <iostream>
#include <iomanip>
using namespace std;

// b) Request number input
int RequestNumber()
{
    int N;
    do
    {
        cout << "Please input an integer in the interval [3, 15]: ";
        cin >> N;
    } while (N < 3 || N > 15);
    return N;
}

// c) Sum of integers between 3 and number
int sumIntegers(int N)
{
    return (3 + N) * (N - 3 + 1) / 2;
}

// d) Print divisors of number
unsigned Divisors(int N)
{
    unsigned divisors = 0;
    for (int i = 2; i <= N / 2; i++)
        if (N % i == 0)
        {
            cout << "; " << i;
            divisors++;
        }
    return divisors;
}

// e) Times the number appears in the array numbers[]
unsigned Array(int numbers[10], int N)
{
    unsigned count = 0;
    for (size_t i = 0; i < 10; i++)
        if (numbers[i] == N)
            count++;
    return count;
}

// f) Comparison of the elements of the two arrays
void moreNumbers(int numbers1[10], int numbers2[10])
{
    for (size_t i = 0; i < 10; i++)
        cout << left << setw(4) << numbers1[i] << '|'
            << right << setw(4) << numbers2[i] << "| "
                << ((numbers1[i] > numbers2[i]) ? "greater" : (numbers1[i] < numbers2[i]) ? "lesser"
                                                                                         : "equal")
                << "\n";
    }

int main()
{
    // Would print divisors too early
    // unsigned divisors = Divisors(N);
    int numbers[]{2, 11, 5, 7, 14, 11, 7, 3, 11, 14};
    int more_numbers[]{1, 12, 4, 5, 15, 5, 13, 7, 12, 4};

    // a) Identification
    cout << "a)" << endl;
    cout << "Denis Sukhachev - Nº Mec.: 114862\n";
    cout << endl;

    // b) Request number input
    cout << "b)" << endl;
    int N = RequestNumber();
    cout << "N=" << N << endl;
    cout << endl;

    // c) Sum of integers between 3 and number
    cout << "c)" << endl;
    cout << "Sum of all integers between 3 and " << N
         << ": " << sumIntegers(N) << "\n";
    cout << endl;

    // d) Print divisors of number
    cout << "d)" << endl;
    cout << "Divisors of " << N << ": 1";
    unsigned divisors = Divisors(N);
    cout << endl;
    cout << N << " is ";
    if (divisors > 0)
        cout << "not ";
    cout << "prime.\n";
    cout << endl;

    // e) Times the number appears in the array numbers[]
    unsigned count = Array(numbers, N);
    cout << "e)" << endl;
    cout << "The number " << N
         << " appears in the array {2, 11, 5, 7, 14, 11, 7, 3} "
         << count << " time(s).\n";
    cout << endl;

    // f) Comparison of the elements of the two arrays
    cout << "f) Comparison of same index elements of two arrays.\n";
    moreNumbers(numbers, more_numbers);

    return 0;
}