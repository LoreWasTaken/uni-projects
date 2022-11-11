// denis: Program to ask user for the evaluation grades and their respective weight
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
    cout << "Final grade: " << final << endl;

    return 0;
}