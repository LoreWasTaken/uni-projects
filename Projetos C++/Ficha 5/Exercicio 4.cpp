// denis: Create a function that returns the greatest of its two parameters.
#include "iostream"
using namespace std;

double max(double x, double y){
    return (x > y) ? x : y;
}

int main(){
    double x, y;
    cout << "Insert two random values: ";
    cin >> x >> y;
    cout << "Greatest value of " << "(" << x << "," << y << ")" << " is " << max(x,y) << endl;

    return 0;
}