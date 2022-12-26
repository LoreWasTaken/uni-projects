// denis:  Added an option to store the information about all the students in a text file. 
// The file’s name should be requested to the user. 
// Also added, in order to test the program and verify if the file was correctly created, added
// another option which allows reading student information stored in a file. 
// This option should replace an eventual list of students previously existing in the program. 
// The file's name should be requested to the user.

#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

struct Time {
    int hour;
    int minute;
    int second;
};

void print_time(const Time& time) {
    cout << time.hour << ":" << time.minute << ":" << time.second << endl;
}

Time ask_for_time() {
    Time time;

    while (true) {
        cout << "Enter a time (HH:MM:SS): ";
        cin >> time.hour >> time.minute >> time.second;

        if (time.hour >= 0 && time.hour <= 23 && time.minute >= 0 && time.minute <= 59 && time.second >= 0 && time.second <= 59) {
            break;
        }

        cout << "Invalid time. Please try again." << endl;
    }

    return time;
}

struct Student {
    int number;
    string name;
    Time entrance;
    Time exit;
};

Student ask_for_student() {
    Student student;

    cout << "Enter student number: ";
    cin >> student.number;
    cin.ignore();
    cout << "Enter student name: ";
    getline(cin, student.name);

    cout << "Enter entrance time: ";
    student.entrance = ask_for_time();

    cout << "Enter exit time: ";
    student.exit = ask_for_time();

    return student;
}

void save_students_to_file(const vector<Student>& students, const string& filename) {
    ofstream out_file(filename);
    if (!out_file) {
        cerr << "Error opening file " << filename << " for writing." << endl;
        return;
    }

    for (const Student &student: students) {
        out_file << student.number << " " << student.name << " " << student.entrance.hour << " " << student.entrance.minute << " " << student.entrance.second << " " << student.exit.hour << " " << student.exit.minute << " " << student.exit.second << endl;
    }

    out_file.close();
    cout << "Students saved to file " << filename << "." << endl;
}

vector<Student> load_students_from_file(const string& filename) {
    vector<Student> students;

    ifstream in_file(filename);
    if (!in_file) {
        cerr << "Error opening file " << filename << " for reading." << endl;
        return students;
    }

    while (true) {
        Student student;
        in_file >> student.number >> student.name >> student.entrance.hour >> student.entrance.minute
                >> student.entrance.second >> student.exit.hour >> student.exit.minute >> student.exit.second;
        if (in_file.eof()) {
            break;
        }
        students.push_back(student);
    }

    in_file.close();
}

int main() {
    vector<Student> students;

    while (true) {
        cout << "1. Register a student" << endl;
        cout << "2. List information about all the students" << endl;
        cout << "3. Calculate the average length of stay in the department" << endl;
        cout << "4. Save students to a file" << endl;
        cout << "5. Load students from a file" << endl;
        cout << "6. Terminate the program" << endl;

        int option;
        cout << "Enter an option: ";
        cin >> option;

        if (option == 1) {
            // Code for registering a student
            Student student = ask_for_student();
            students.push_back(student);
        } else if (option == 2) {
            // Code for listing information about all the students
            for (Student &student: students) {
                cout << "Student number: " << student.number << endl;
                cout << "Student name: " << student.name << endl;
                cout << "Entrance time: ";
                print_time(student.entrance);
                cout << "Exit time: ";
                print_time(student.exit);
                cout << endl;
            }
        } else if (option == 3) {
            // Code for calculating the average length of stay
            int total_length = 0;
            int num_students = 0;
            for (const Student &student: students) {
                Time entrance = student.entrance;
                Time exit = student.exit;

                // Calculate the length of stay for this student.
                int length = (exit.hour - entrance.hour) * 3600 + (exit.minute - entrance.minute) * 60 +
                             (exit.second - entrance.second);

                // Add the length of stay to the total.
                total_length += length;
                ++num_students;
            }

            if (num_students > 0) {
                // Calculate and print the average length of stay.
                double avg_length = total_length / num_students;
                cout << "The average length of stay is " << avg_length << " seconds." << endl;
            } else {
                cout << "No students have been registered yet." << endl;
            }
        } else if (option == 4) {
            // Code for saving students to a file
            string filename;
            cout << "Enter the name of the file: ";
            cin >> filename;
            save_students_to_file(students, filename);
        } else if (option == 5) {
            // Code for loading students from a file
            string filename;
            cout << "Enter the name of the file: ";
            cin >> filename;
            students = load_students_from_file(filename);
        } else if (option == 6) {
            // Code for terminating the program
            return 0;
        } else {
            // Code for handling invalid options
            cout << "Invalid option. Please try again." << endl;
        }
    }
}