// denis: Change of the program F4E6, using only functions.
// 4 functions: Reading with validation of the N value, validated reading of the grades values into an array,
// counting calculation, histogram printing
#include "iostream"
#include "iomanip"
using namespace std;

// Reading with validation of the N value
int NumberOfStudents(){
    int students;
    do{
        cout << "Number of students? ";
        cin >> students;
        if (students <= 0) cout << "Must be a positive number!" << endl;
    } while (students <= 0);
    return students;
}

// Validated reading of the grades values into an array & calculation of the counting
void WriteGrades(int array[], int n){
    while (n--){
        int grade;
        cout << "Grade? ";
        do {
            cin >> grade;
            if (grade > 20 || grade <= 0) cout << "Must be a valid grade!" << endl;
        } while (grade > 20 || grade <= 0);
        array[grade] += 1;
    }
}

// Prints histogram of the grades
void PrintGradesHistogram(int array[]){
    for (int i = 20; i >= 0; --i) {
        cout << setw(2) << setfill('0') << i << " | " << setw(array[i]) << setfill('*') << "" << endl;
    }
}

int main(){
    // Asking for number of students
    int students = NumberOfStudents();

    // Initialize grades array
    int grades[21];
    for (int i = 0; i < 21; i++) grades[i] = 0;

    // Ask each student grade, and increase the counter
    WriteGrades(grades, students);

    // Show students' grades histogram
    PrintGradesHistogram(grades);

    return 0;
}