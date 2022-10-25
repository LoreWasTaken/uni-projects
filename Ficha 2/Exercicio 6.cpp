// denis: Program that asks for the quantity of fuel(L) in a car and prints the price that has to be paid
#include <iostream>
using namespace std;

int main()
{
    double fuel;
    cout << "Insert Fuel (liters): ";
    cin >> fuel;

    double price = fuel > 40 ? fuel * 1.26 : fuel * 1.40; // If the fuel value is more than 40 liters, have a 10% discount (1.40 - (1.40 * 0.10) = 1.26)
    cout << price << "€";

    return 0;
}