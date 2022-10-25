// denis: Program that asks user to input two catheti values and calculates the hypotenuse and
// the value of the angle (in degrees) between A side and the hypotenuse
#include "iostream"
#include "cmath"
#define _USE_MATH_DEFINES
using namespace std;

int main()
{
    double A, B; // Catheti A and B
    cout << "Insert the value of cathi A: ";
    cin >> A;
    cout << "Insert the value of cathi B: ";
    cin >> B;
    double C = sqrt(pow(A, 2) + pow(B, 2)); // C = Hypotenuse
    double ang = asin(B / C) * (180/M_PI); // ang = Angle between A side and the hypotenuse, in degrees

    cout << "The hypotenuse is: " << C << "\n" << "The angle between the A side and the hypotenuse is: " << ang << "º";

    return 0;
}