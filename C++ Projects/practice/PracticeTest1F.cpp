// Practice Test 1, but now only using functions for each question
#include <iostream>
#include <iomanip>
using namespace std;

// b) Request number input
int RequestNumber(int N){
    do
    {
        cin >> N;
    } while (N < 3 || N > 15);
    return N;
}
// c) Sum of integers between 3 and number
int sumIntegers(int N){
    int sum = 0;
    return sum = (3 + N) * (N - 3 + 1) / 2;
}

// d) Print divisors of number
int Divisors(int N){
    unsigned divisors = 0;
    for (int i = 2; i <= N / 2; i++)
        if (N % i == 0)
        {
            cout << ' ' << i;
            divisors++;
        }
    return divisors;
}

// e) Times the number appears in the array numbers[]
int Array(int numbers[10], int N)
{
    unsigned count = 0;
    for (int i = 0; i < 10; i++)
        if (numbers[i] == N)
            count++;
    return count;
}

// f) Comparison of the elements of the two arrays

void moreNumbers(int moreNumbers[10], int N[15]){
    for (size_t i = 0; i < 10; i++)
        cout << setw(2) << N[i] << ' '
             << (N[i] > moreNumbers[i] ? ">" : (N[i] < moreNumbers[i]) ? "<"
                                                                       : "=")
             << ' ' << setw(2) << moreNumbers[i];
}

int main()
{
    int N = RequestNumber(N);
    int divisors = Divisors(N);
    int numbers[]{2, 11, 5, 7, 14, 11, 7, 3, 11, 14};
    unsigned count = Array(numbers, N);
    int more_Numbers[]{1, 12, 4, 5, 15, 5, 13, 7, 12, 4};
    int compare[10];

    // a) Identification
    cout << "a) Denis Sukhachev, 114862\n";

    // b) Request number input
    int number;
    cout << "b) Please input an integer in the interval [3, 15]: ";
    cout << "N=" << RequestNumber(N);

    // c) Sum of integers between 3 and number
    cout << "c) Sum of all integers between 3 and " << N
         << ": " << sumIntegers(N) << "\n";

    // d) Print divisors of number
    cout << "d) Divisors of " << N << ": 1";
    divisors;
    (divisors == 0) ? cout << "The number is prime.\n" : cout << "The number is not prime.\n";
    cout << endl;

    // e) Times the number appears in the array numbers[]
    cout << "e) The number " << N
         << " appears in the array {2, 11, 5, 7, 14, 11, 7, 3} "
         << count << " times.\n";

    // f) Comparison of the elements of the two arrays
    cout << "f) Comparison of same index elements of two arrays.\n";
    moreNumbers(more_Numbers, compare);

    return 0;
}