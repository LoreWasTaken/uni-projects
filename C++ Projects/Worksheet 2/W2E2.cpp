// denis: Modified BMI (bmi.cpp) program that beside of computing the BMI of a person, also classifies the person into one of the 4 categories
#include<iostream>
#include <cmath>
using namespace std;

int main(){
    double height, weight;

    cout << "Height (m) and weight (kg)? ";
    cin >> height >> weight;

    double bmi = weight / pow(height, 2.0);

    cout << "BMI: " << bmi << endl;

// Classifies the person in 4 categories: ]18.5] - Underweight ; [18.5, 25[ - Normal ; [25,30[ - Overweight ; [30[ - Obese
    if (bmi < 18.5) {
        cout << "Underweight" << endl;
    }
    else if ( 18.5 <= bmi && bmi < 25){
        cout << "Normal" << endl;
    }
    else if ( 25 <= bmi && bmi < 35){
        cout << "Overweight" << endl;
    }
    else {
        cout << "Obese" << endl;
    }
    return 0;
}