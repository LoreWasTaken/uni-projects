#include "iostream"
using namespace std;

int main()
{
    int p, tp;
    double weightp = 0.75, weighttp = 0.25;

    cout << "Insert your grades (P, TP): ";
    cin >> p >> tp;

    double final = weightp * p + weighttp * tp;
    cout << "Final grade: " << final;

    return 0;
}