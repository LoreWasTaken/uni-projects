// denis: Program that reads a sequence of students grades entered by the user (integer value from 0 to 20)
// After that, calculates and draws the respective histogram
#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    int students;
    cout << "Number of students? ";
    cin >> students;

    int grades[20];
    for (int i = 0; i < 20; i++) grades[i] = 0;

    for (int i = 0; i < students; i++)
    {
        int grade;
        cout << "Grade? ";
        cin >> grade;
        grades[grade-1] += 1;
    }
    for (int grade = 20; grade > 0; grade--)
    {
        cout << setw(2) << setfill('0') << grade << " | " << setw(grades[grade-1]) << setfill('*') << "" << endl;
    }
    return 0;
}