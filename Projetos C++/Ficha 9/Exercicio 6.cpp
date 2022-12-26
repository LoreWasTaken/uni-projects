// denis: Didn't understand what the exercise was asking, but I think it should look something like this.
// Didn't test because I don't have the file in the specified path

// denis: To use this program, simply run it. 
// It will read the file "/etc/dictionaries-common/words" and list and count the words that have equal consecutive letters.
//
//Note that this program assumes that the file "/etc/dictionaries-common/words" exists and is readable. 
// You may need to adjust the file path depending on your system.
#include <iostream>
#include <fstream>

using namespace std;

// Returns the number of letter pairs found in the given string.
int repeats(const string &s) {
    int count = 0;
    for (size_t i = 0; i < s.size() - 1; ++i) {
        if (s[i] == s[i + 1]) {
            ++count;
        }
    }
    return count;
}

int main() {
    // Open the file for reading.
    ifstream file("/etc/dictionaries-common/words");
    if (!file.is_open()) {
        cerr << "Error opening file." << endl;
        return 1;
    }

    // Read the words from the file and count those that have equal consecutive letters.
    string word;
    int count = 0;
    while (file >> word) {
        if (repeats(word) > 0) {
            cout << word << endl;
            ++count;
        }
    }

    cout << "Total: " << count << endl;
    return 0;
}
