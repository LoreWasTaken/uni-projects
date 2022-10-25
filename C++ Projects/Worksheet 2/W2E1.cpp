// denis: Change of the first programs of Worksheet1 (W1E1, W1E2, W1E3, W1E4) printing also a message stating if the student passed or failed
#include "iostream"
using namespace std;

int main()
{
    int p, tp;
    double weightp, weighttp;

    cout << "Insert your grade weight (P, TP): ";
    cin >> weightp >> weighttp;

    cout << "Insert your grades (P, TP): ";
    cin >> p >> tp;
    double final = weightp * p + weighttp * tp;

// Prints if the student passed or failed
    cout << "Final grade: " << final << endl;
    if (final >= 6.5)
        cout << "Passed" << endl;
    else
        cout << "Failed" << endl;

    return 0;
}