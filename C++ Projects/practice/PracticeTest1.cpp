// Practice test 1
#include <iostream>
#include <iomanip>
using namespace std;

int main(void)
{
    // a) Identification
    cout << "a) Denis Sukhachev, 114862\n";

    // b) Request number input
    int number;
    cout << "b) Please input an integer in the interval [3, 15]: ";
    do
    {
        cin >> number;
    } while (number < 3 || number > 15);

    // c) Sum of integers between 3 and number
    int sum = (3 + number) * (number - 3 + 1) / 2;
    cout << "c) Sum of all integers between 3 and " << number
              << ": " << sum << "\n";

    // d) Print divisors of number
    cout << "d) Divisors of " << number << ": 1";
    unsigned divisors_count = 0;
    for (int i = 2; i <= number / 2; i++)
        if (number % i == 0)
        {
            cout << ' ' << i;
            divisors_count++;
        }
    cout << "\n";

    if (divisors_count == 0)
        cout << "The number is prime.\n";
    else
        cout << "The number is not prime.\n";
    cout << "\n";

    // e) Times the number appears in the array numbers[]
    int numbers[]{2, 11, 5, 7, 14, 11, 7, 3, 11, 14};
    unsigned count = 0;
    for (int value : numbers)
        if (number == value)
            count++;

    cout << "e) The number " << number
              << " appears in the array {2, 11, 5, 7, 14, 11, 7, 3} "
              << count << " times.\n";

    // f) Comparison of the elements of the two arrays
    int more_numbers[]{1, 12, 4, 5, 15, 5, 13, 7, 12, 4};
    cout << "f) Comparison of same index elements of two arrays.\n";
    for (size_t i = 0; i < 10; i++)
        cout << setw(2) << numbers[i] << ' '
                  << (numbers[i] > more_numbers[i] ? ">" : (numbers[i] < more_numbers[i]) ? "<"
                                                                                          : "=")
                  << ' ' << setw(2) << more_numbers[i]
                  << "\n";

    return 0;
}