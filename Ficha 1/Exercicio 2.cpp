// denis: Program to ask user to insert the evaluation grades
#include "iostream"
using namespace std;

int main()
{
    int p, tp;
    cout << "Insert your grades (P, TP): ";
    cin >> p >> tp;

    double final = 0.75 * p + 0.25 * tp;
    cout << "Final grade: " << final << endl;

    return 0;
}