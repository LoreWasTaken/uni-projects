// bmi.cpp was given in the worksheet
#include<iostream>
#include <cmath>
using namespace std;

int main(){
	double height, weight;

	cout << "Height (m) and weight (kg)? ";
	cin >> height >> weight;

	double bmi = weight / pow(height, 2.0);

	cout << "BMI: " << bmi << endl;

	if(bmi < 18.5) {
        cout << "Underweight" << endl;
    }
	else if(bmi < 25){
		cout << "Normal" << endl;
	}
    else if(bmi < 35){
        cout << "Overweight" << endl;
    }
    else {
        cout << "Obese" << endl;
    }
	return 0;
}