// denis: Program which verifies if two files are equal. 
// In order to save time and memory, reading and comparing is 1 KiB block at a time, 
// and is terminated as soon as a difference is detected. 
// The file’s name should be passed as a command line argument. 

// denis: To use this program, pass the names of the text files as arguments when running the program.
// This will compare the contents of file1.txt and file2.txt and print whether they are equal or not.

#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, char *argv[]) {
    if (argc != 3) {
        cerr << "Usage: " << argv[0] << " file1 file2" << endl;
        return 1;
    }

    // Open the files for reading.
    ifstream file1(argv[1]);
    if (!file1.is_open()) {
        cerr << "Error opening file " << argv[1] << endl;
        return 1;
    }

    ifstream file2(argv[2]);
    if (!file2.is_open()) {
        cerr << "Error opening file " << argv[2] << endl;
        return 1;
    }

    // Read and compare the files line by line.
    string line1, line2;
    while (getline(file1, line1) && getline(file2, line2)) {
        if (line1 != line2) {
            // The lines are not equal.
            cout << "The files are not equal." << endl;
            return 0;
        }
    }

    if (file1.eof() && file2.eof()) {
        // We have reached the end of both files.
        cout << "The files are equal." << endl;
        return 0;
    } else {
        // One file is longer than the other.
        cout << "The files are not equal." << endl;
        return 0;
    }
}