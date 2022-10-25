// denis: Program that attempts to guess a secret bi-dimensional position, selected by the user.
// The selected bi-dimensional position needs to be an integer that belongs to the interval [1, 100].
// After each guess made by the program, the user must indicate the relative position of the guess respectfully to the secret coordinate by the user
#include "iostream"
using namespace std;

int main()
{
    cout << "Think about a point in the plane (100, 100)" << endl;
    int minX = 1; int maxX = 100; int minY = 1; int maxY = 100; // Initialize the variables to store the coordinates of the bi-dimensional position

    int x = (minX + maxX) / 2;
    int y = (minY + maxY) / 2;
    int relative = (x, y);
    bool guess_correct = false;

    do
    {
        cout << "Where is your point relative to " << x << ", " << y << "?" << endl;

        cin >> relative;
        switch (relative) {
            case 0:                 // NW
                x = (minX + x) / 2;
                y = (maxY + y) / 2;
                break;
            case 1:                 // N
                y = (maxY + y) / 2;
                break;
            case 2:                 // NE
                x = (maxX + x) / 2;
                y = (maxY + y) / 2;
                break;
            case 3:                 // W
                x = (minX + x) / 2;
                break;
            case 4:                 // Correct
                cout << "yay, i got it right!" << endl;
                guess_correct = true;
                return 0;
            case 5:                 // E
                x = (maxX + x) / 2;
                break;
            case 6:                 // SW
                x = (minX + x) / 2;
                y = (minY + y) / 2;
                break;
            case 7:                 // S
                y = (minY + y) / 2;
                break;
            case 8:                 // SE
                x = (maxX + x) / 2;
                y = (maxY + y) / 2;
                break;
        }
    } while ((guess_correct = true));

}