#include "iostream"
#include "cmath"
using namespace std;

// Function to calculate the BMI
double BMI(double weight, double height)
{
    return weight / pow(height, 2.0);
}

// Function to determine the BMI
const char * BMI_Category(double bmi)
{
    if (bmi < 18.5)
    {
        return "Underweight";
    }
    else if (bmi < 25)
    {
        return "Normal";
    }
    else if (bmi < 30)
    {
        return "Overweight";
    }
    else
        return "Obese";
}

int main() {
    double a; double p; // a = Altura p = Peso
    cout << "Body Mass Index" << endl;
    cout << "Altura (m): ";
    cin >> a;
    if (a < 0) {
        cout << "Error: Invalid height!";
        return 1;
    }
    cout << "Peso (kg): ";
    cin >> p;
    if (p < 0){
        cout << "Error: Invalid weight!";
        return 1;
    }

    double imc = BMI(p, a); // Calculate BMI
    const char *categoria = BMI_Category(imc); // Determine BMI

    cout << "BMI: " << imc << " kg/m2" << endl;
    cout << "BMI category: " << categoria << endl;

    return 0;
}