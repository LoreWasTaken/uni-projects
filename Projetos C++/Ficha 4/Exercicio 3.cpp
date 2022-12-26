// denis: Program that asks the user to insert numbers in a sequence of positive integers.
// Reading stops when user inserts 100 numbers or a non-positive number
// After that, prints the number of times a given integer, indicated by the user, appears in the sequence
#include "iostream"
using namespace std;

int main()
{
    int n; // Initialize variable to store the size of the sequence (1 - 10)
    int x; // Initialize variable to store the number that the user wants to know how many times appeared in the sequence
    int y = 0; // Initialize variable to store how many times the chosen number showed in the sequence
    int numbers = 0; // Initialize variable to store the numbers, chosen by the user, in the sequence
    int seq[100]; // Initialize array to store a sequence of maximum 100 numbers

// Store numbers into the sequence until reached 100 numbers or inserted a non-positive number
    do{
        cout << "Numbers?? ";
        cin >> n;
        if (n > 0)
        {
            seq[numbers] = n;
            numbers++;
        }
    } while((numbers < 100) && (n > 0));

// Other way to do the same thing:
/*
     cout << "Numbers?? ";
     cin >> n; // Ler o primeiro n

     while ((n > 0) && (numbers < 100))
     {
        seq[numbers] = n;
        numbers++;

        cin >> n;
     }
*/

// Ask user what integer they want to know how many times showed in the sequence
    cout << "Integer? ";
    cin >> x;
    for (int i = 0; i < numbers; i++)
    {
        if (seq[i] == x)
        {
            y++;
        }
    }

    cout << x << " apareceu " << y << " vezes";

    return 0;
}
