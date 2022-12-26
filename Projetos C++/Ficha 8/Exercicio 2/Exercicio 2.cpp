// denis: Repeating Exercicio 3 from practical work 7, but now reading and storing information about several students. 
// Information about the students must be kept in an array which grows dynamically
// as new students are registered. Interaction with the program should be done through a menu as follows:
//
//a. Register a student.
//b. List information about all the students (name, entrance time, exit time).
//c. Calculate the average length of stay in the department.
//d. Terminate the program.

// denis: When listing information about all students, option 2 of the menu, the padding is weird, might fix later.

#include <iostream>
#include <string>
#include <vector> // Using vector to store students dynamically
#include <iomanip>
using namespace std;

// Defining the Time structure
struct Time {
    int hour;
    int minute;
    int second;
};

// Function to print the time in the format HH:MM:SS
void printTime(Time time) {
    cout << time.hour << "h" << ":" << time.minute << "m" << ":" << time.second << "s";
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
    Time entered;
    Time left;
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
    cout << "Enter the time the student entered the building: " << endl;
    student.entered = askTime();
    cout << "Enter the time the student left the building: " << endl;
    student.left = askTime();

    return student;
}

int main() {
    vector<Student> students; // Vector to store the student information

    // Displaying the menu
    while (true) {
        cout << "Menu:" << endl;
        cout << "  1. Register a student" << endl;
        cout << "  2. List information about all the students" << endl;
        cout << "  3. Calculate the average length of stay in the department" << endl;
        cout << "  4. Terminate the program" << endl;
        cout << "Enter your choice: ";

        int choice;
        cin >> choice;

        if (choice == 1) {
            // Asking for the student information
            Student student = askStudent();

            // Calculating the duration the student was inside the building
            int duration = (student.left.hour - student.entered.hour) * 3600 + (student.left.minute - student.entered.minute) * 60 + (student.left.second - student.entered.second);

            // If the duration is negative, add 24 hours to it
            if (duration < 0) {
                duration += 24 * 3600;
            }

            // Adding the student to the vector
            students.push_back(student);
        } else if (choice == 2) {
            // Listing the information about all the students
            cout << left << setw(6) << "Number" << "  " << setw(10) << "Name" << "  " << setw(14) << "Entrance Time" << "  " << setw(11) << "Exit Time" << "  " << setw(12) << "Duration" << endl;
            for (const Student& student : students) {
                cout << left << setw(6) << student.studentNumber << "  " << setw(10) << student.studentName << "  ";
                printTime(student.entered);
                cout << "  ";
                printTime(student.left);
                cout << "  ";
                int duration = (student.left.hour - student.entered.hour) * 3600 + (student.left.minute - student.entered.minute) * 60 + (student.left.second - student.entered.second);
                // If the duration is negative, add 24 hours to it
                if (duration < 0) {
                    duration += 24 * 3600;
                }
                printTime(Time { duration / 3600, (duration % 3600) / 60, duration % 60 });
                cout << endl;
            }
        } else if (choice == 3) {
            // Calculating the average length of stay in the department
            int totalDuration = 0;
            for (const Student& student : students) {
                int duration = (student.left.hour - student.entered.hour) * 3600 + (student.left.minute - student.entered.minute) * 60 + (student.left.second - student.entered.second);
                // If the duration is negative, add 24 hours to it
                if (duration < 0) {
                    duration += 24 * 3600;
                }
                totalDuration += duration;
            }
            int averageDuration = totalDuration / students.size();
            cout << "Average length of stay in the department: ";
            printTime(Time { averageDuration / 3600, (averageDuration % 3600) / 60, averageDuration % 60 });
            cout << endl;
        } else if (choice == 4) {
            // Terminating the program
            break;
        } else {
            cout << "Invalid choice, please try again." << endl;
        }
    }

    return 0;
}