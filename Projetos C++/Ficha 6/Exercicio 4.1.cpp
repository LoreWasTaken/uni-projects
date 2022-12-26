// denis: Uma segunda maneira de resolver o exercício 4

// denis: Function that indicates if a given string matches the given pattern (a non-zero return value means yes, a zero means no).
// Valid patterns: AA-00-00, 00-AA-00 ,00-00-AA
// Calling this function, the program checks if a string entered by the user is a valid Portuguese license plate.
#include <iostream>
using namespace std;

// returns 1 if the given string matches the given pattern, 0 otherwise
int matchPattern(const string& str, const string& pattern) {
    // check if the length of the string and the pattern are the same
    if (str.length() != pattern.length()) return 0;

    // iterate over the string and the pattern and check if each character
    // in the string matches the corresponding character in the pattern
    for (int i = 0; i < str.length(); i++) {
        char ch = str[i];
        char pch = pattern[i];

        if (pch == 'A') {
            // if the pattern character is 'A', the string character must be
            // an uppercase letter
            if (!isupper(ch)) return 0;
        } else if (pch == '0') {
            // if the pattern character is '0', the string character must be
            // a digit
            if (!isdigit(ch)) return 0;
        } else if (ch != pch) {
            // if the pattern character is not 'A' or '0', the string character
            // must be the same as the pattern character
            return 0;
        }
    }

    return 1;
}

int main() {
    string patterns[3] = {"AA-00-00", "00-00-AA", "00-AA-00"};

    while (true) {
        cout << "Enter a Portuguese license plate: ";
        string str;
        getline(cin, str);

        // check if the entered string matches any of the given patterns
        int res = 0;
        for (int i = 0; i < 3; i++) {
            res = matchPattern(str, patterns[i]);
            if (res) break;
        }
        if (res) cout << "Valid license plate" << endl;
        if (!res) cout << "Invalid license plate" << endl;
    }
    return 0;
}