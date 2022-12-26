// denis: Program to convert Celsius to Fahrenheit
#include "iostream"
using namespace std;

int main()
{
    double C;

    cout << "Insert temperature (ºC): ";
    cin >> C;

    double F = 1.8 * C + 32;
    cout << C << "ºC" << " = " << F << "ºF";

    return 0;
}
