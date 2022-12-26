// denis: This program asks the user for the student information (number and name), and the time the student entered and left the DETI building.
// It then calculates the duration the student was inside the building, and prints the student information and duration in the format HH:MM:SS.
// If the duration is negative (i.e., the student left the building before they entered it), the program adds 24 hours to the duration.
#include <iostream>
#include <string>
using namespace std;

// Defining the Time structure
struct Time {
    int hour;
    int minute;
    int second;
};

// Function to print the time in the format HH:MM:SS
void printTime(Time time) {
    cout << time.hour << "h " << " : " << time.minute << "m " << " : " << time.second << "s";
}

// Function to ask the user for a valid time
Time askTime() {
    Time time;

    // Keep asking until a valid time is entered
    while (true) {
        cout << "Enter a time (HH:MM:SS): ";
        char colon1, colon2; // :
        cin >> time.hour >> colon1 >> time.minute >> colon2 >> time.second;

        // Validating the input
        if (colon1 == ':' && colon2 == ':' && time.hour >= 0 && time.hour < 24 && time.minute >= 0 && time.minute < 60 && time.second >= 0 && time.second < 60) {
            break;
        } else {
            cout << "Invalid time, please try again." << endl;
        }
    }

    return time;
}

// Defining the Student structure
struct Student {
    int studentNumber;
    string studentName;
};

// Function to ask the user for the information about a student
Student askStudent() {
    Student student;

    cout << "Enter the student number: ";
    cin >> student.studentNumber;
    cout << endl;
    cin.ignore();
    cout << "Enter the student name: ";
    getline(cin,student.studentName);

    return student;
}

int main() {
    // Asking for the student information
    Student student = askStudent();

    // Asking for the time the student entered the building
    cout << "Enter the time the student entered the building: " << endl;
    Time entered = askTime();

    // Asking for the time the student left the building
    cout << "Enter the time the student left the building: " << endl;
    Time left = askTime();

    // Calculating the duration the student was inside the building
    int duration = (left.hour - entered.hour) * 3600 + (left.minute - entered.minute) * 60 + (left.second - entered.second);

    // If the duration is negative, add 24 hours to it
    if (duration < 0) {
        duration += 24 * 3600;
    }

    // Printing the student information and duration
    cout << endl << "Student Information:" << endl;
    cout << "  Number: " << student.studentNumber << endl;
    cout << "  Name: " << student.studentName << endl;
    cout << "  Duration: ";
    printTime(Time { duration / 3600, (duration % 3600) / 60, duration % 60 });
    cout << endl;

    return 0;
}