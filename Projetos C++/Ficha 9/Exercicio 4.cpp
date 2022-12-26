// denis: program which determines the amount of times all letters appear in a text file.
// The file'’'s name should be passed as an argument through the command line 
// As an example, download some text file examples from Project Gutenberg (https://www.gutenberg.org/)
// and do the counting. 
// Also, adjusted the program to only consider letters and not distinguish lower case from upper case letters.

#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, char *argv[]) {
    if (argc != 2) {
        cerr << "Usage: " << argv[0] << " filename" << endl;
        return 1;
    }

    // Open the file for reading.
    ifstream in_file(argv[1]);
    if (!in_file.is_open()) {
        cerr << "Error opening file " << argv[1] << endl;
        return 1;
    }

    // Initialize the letter count to 0.
    int letter_count[26] = {};

    // Read the file one character at a time.
    char c;
    while (in_file.get(c)) {
        // Increment the count for the corresponding letter, if c is a letter.
        if (isalpha(c)) {
            letter_count[tolower(c) - 'a']++;
        }
    }

    // Print the letter counts.
    for (int i = 0; i < 26; i++) {
        cout << (char)('a' + i) << ": " << letter_count[i] << endl;
    }

    return 0;
}
