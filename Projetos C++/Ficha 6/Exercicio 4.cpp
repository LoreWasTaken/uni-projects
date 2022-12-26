// denis: Function that indicates if a given string matches the given pattern (a non-zero return value means yes, a zero means no).
// Valid patterns: AA-00-00, 00-AA-00 ,00-00-AA
// Calling this function, the program checks if a string entered by the user is a valid Portuguese license plate.
#include <iostream>
#include <cstring>
using namespace std;

// returns 1 if the given string matches the given pattern, 0 otherwise
int matchPattern(const char* str, const char* pattern, const char* patternName) {
    // check if the length of the string and the pattern are the same
    if (strlen(str) != strlen(pattern)) return 0;

    // iterate over the string and the pattern and check if each character
    // in the string matches the corresponding character in the pattern
    for (int i = 0; i < strlen(str); i++) {
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
    // define the three possible patterns
    const char *pattern1 = "AA-00-00";
    const char *pattern2 = "00-00-AA";
    const char *pattern3 = "00-AA-00";

    while (true) {
        cout << "Enter a Portuguese license plate: ";
        char str[256];
        cin.getline(str, 256);

        // check if the entered string matches any of the three patterns
        int res1 = matchPattern(str, pattern1, "AA-00-00");
        int res2 = matchPattern(str, pattern2, "00-00-AA");
        int res3 = matchPattern(str, pattern3, "00-AA-00");

        cout << "The entered string " << (res1 || res2 || res3 ? "matches" : "does not match") << " one of the patterns." << endl;
    }
    return 0;
}
