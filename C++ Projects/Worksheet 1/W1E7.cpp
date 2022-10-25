// denis: Program to calculate and print the final average speed given speed in two stages
#include "iostream"
using namespace std;

int main()
{
    double v1, v2;
    cout << "Insert the values of average speed in both stages: ";
    cin >> v1 >> v2;

    double t1 = 1 / v1;
    double t2 = 1 / v2;
    double vm = 2 / (t1+t2);

    cout << "The final average speed value is: " << vm;

    return 0;
}