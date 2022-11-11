// denis: Program that asks the user for a date in dd:mm:yyyy format and prints the date of the next date, the date and previous date
#include <iostream>
using namespace std;

int main() {
    int prevd, prevm, prevy, day, month, year, nextd, nextm, nexty;
    prevd = 0;
    prevm = 0;
    prevy = 0;
    nextd = 0;
    nextm = 0;
    nexty = 0;

    cout << "Insert a date (d m yyyy): ";
    cin >> day >> month >> year;

// Next day code
    if (day > 0 && day < 28)
        nextd = day + 1;
    nextm = month;
    nexty = year;
    if (day == 28) {
        if (month == 2) {
            if ((year % 4 == 0 && (year % 100 != 0 || year % 400 == 0)))
            {
                nextd = 29;
            }
            else
            {
                nextd = 1;
                nextm = 3;
            }
        }
        else
            nextd = day + 1;
    }
    if (day == 30) {
        if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
            nextd = day + 1;
        else {
            nextd = 1;
            nextm = month + 1;
        }
    }
    if (day == 31)
    {
        nextd = 1;
        if (month == 12)
        {
            nexty = year + 1;
            nextm = 1;
        }
        else
            nextm = month + 1;
    }

// Previous day code
    if (day == 1)
    {
        if (month == 4 || month == 6 || month == 9 || month == 11)
        {
            prevd = 31;
            prevm = month - 1;
            prevy = year;
        }
        else if (month == 3)
        {
            if (year % 4 == 0)
            {
                prevd = 29;
                prevm = month;
                prevy = year;
            }
            else
                prevd = 28;
            prevm = month - 1;
            prevy = year;
        }
        else if (month == 1)
        {
            prevd = 31;
            prevm = 12;
            prevy = year - 1;
        }
        else if (month == 2)
        {
            prevd = 31;
            prevm = month - 1;
        }
        else
        {
            prevd = 30;
            prevm = month - 1;
            prevy = year;
        }
    }
    else
    {
        prevd = day - 1;
        prevm = month;
        prevy = year;
    }

    cout << "Date: " << day << "/" << month << "/" << year << endl;
    cout << "Previous date: " << prevd << "/" << prevm << "/" << prevy << endl;
    cout << "Next date: " << nextd << "/" << nextm << "/" << nexty;

    return 0;
}