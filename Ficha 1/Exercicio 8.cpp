// denis: Program that asks user to input seconds and converts it into hours, minutes and seconds in hh:mm:ss format
#include "iostream"
#include "cmath"
using namespace std;

int main()
{
    int t;
    cout << "Insert time (s): ";
    cin >> t;

    int h = t / 3600;
    int m = (t % 3600) / 60;
    int s = (t % 3600) % 60;

    cout << t << "s" << " = " << round(h) << "h" << round(m) << "min" << round(s) << "s";

    return 0;
}