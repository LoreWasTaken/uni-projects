// denis: Create a function to calculate the polynomial p(x) = x² + 2x + 3 and make a table of its values for x
// in the [0, 2] interval, incrementing x by 0.1
#include "iostream"
#include "cmath"
using namespace std;

double polynomial(double x){
    return pow(x, 2) + 2 * x + 3;
}

int main(){
    cout << "Calculation of the polynomial p(x) = x² + 2x + 3: ";
    for (double x = -0.1; x < 2.1; x += 0.1){                       // for (int i = 0; i <= 20; i++){
        cout << "x = " << x << " => f(x) = " << polynomial(x) << endl; // cout << "x = " << fixed << setprecision(2) << (double i / 20 << " f(x) = " << polynomial(x) << endl;
    }

    return 0;
}