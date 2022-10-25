#include "iostream"
using namespace std;

int main(){
    float fuel;

    cout << "Enter the quantity of fuel (liters): ";
    cin >> fuel;

    if (fuel < 40) {
        float price = fuel * 1.40;
        cout << "Price: " << price << endl;
    }
    else {
        float price = (fuel * 0.10) * 1.40;
        cout << "Price: " << price << endl;
    }
    return 0;
}