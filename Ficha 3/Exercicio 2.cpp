// denis: Program that makes the user guess a generated pseudo-random integer >= to 1 and <= to 100 and
// says the number of attempts took the user to guess the correct number
#include "iostream"
#include "random"
using namespace std;

int main()
{
    std::random_device rd;
    std::uniform_int_distribution<int> dist(1, 100);
    int number = dist(rd), guess = 0; int attempts = 0;
    do
    {
        cout << "Insert a number: ";
        cin >> guess;
        attempts++;
        if (guess == number) break;
        cout << "Guess too " << ((guess > number) ? "high" : "low") << endl; // Prints if the guess inserted by the user is too low or too high
    } while (number != guess);

    cout << "Correct guess!" << endl;
    cout << "Attempts: " << attempts;

    return 0;
}