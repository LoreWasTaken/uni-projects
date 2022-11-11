// denis: Program that asks user to input two real points (x, y) and calculate the distance between those two points
#include "iostream"
#include "cmath"
using namespace std;

int main()
{
    double x1, y1, x2, y2;
    cout << "Insert value of x1: ";
    cin >> x1;
    cout << "Insert value of y1: ";
    cin >> y1;
    cout << "Insert value of x2: ";
    cin >> x2;
    cout << "Insert value of y2: ";
    cin >> y2;

    double d = sqrt(pow((x1-x2), 2) + pow((y1-y2), 2));

    cout << "The distance between those points are: " << d;

    return 0;
}