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