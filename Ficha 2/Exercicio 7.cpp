// denis: Program that given a date (mm/yyyy) by the user, calculates and prints in the terminal the number of days of that month
#include "iostream"
using namespace std;

int main()
{
    int days, month, year;
    cout << "Insert a date (m yyyy): ";
    cin >> month >> year;

// Condition to check if a year is a leap year or not
    if (month == 2)
    {
        if ((year % 4 == 0 && (year % 100 != 0 || year % 400 == 0)))
            days = 29;
        else
            days = 28;
    }
    else if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
        days = 31;
    else
        days = 30;

    cout << "Number of Days: " << days;

    return 0;
}