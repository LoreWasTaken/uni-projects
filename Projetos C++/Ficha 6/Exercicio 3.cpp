// denis: Program that reads a sentence from the keyboard (string), inserted by the user, and calculate some information:
// Count and print the number of lowercase characters, uppercase characters, numeric characters, number of vowels, and
// the number of consonants.
#include "iostream"
using namespace std;

// Function to count lowercase characters
int Count_Lowercase(const string &str) {
    unsigned count = 0;
    for (string::const_iterator i = str.begin(); i != str.end(); i++)
        if (*i >= 'a' and *i <= 'z') count++;
    return count;
}

// Function to count uppercase characters
int Count_Uppercase(const string &str) {
    unsigned count = 0;
    for (string::const_iterator i = str.begin(); i != str.end(); i++)
        if (*i >= 'A' and *i <= 'Z') count++;
    return count;
}

// Function to count numeric characters
int Count_Numeric(const string &str) {
    unsigned count = 0;
    for (string::const_iterator i = str.begin(); i != str.end(); i++)
        if (*i >= '0' and *i <= '9') count ++;
    return count;
}

// Function to count vowels
int Count_Vowels(const string &str) {
    unsigned count = 0;
    for (string::const_iterator i = str.begin(); i != str.end(); i++)
        if (*i == 'a' || *i == 'A' || *i == 'e' || *i == 'E' || *i == 'i' || *i == 'I' || *i == 'o' || *i == 'O' || *i == 'u' || *i == 'U') count ++;
    return count;
}

// Function to count the number of consonants
int Count_Consonants(const string &str) {
    unsigned count = 0;
    for (string::const_iterator i = str.begin(); i != str.end(); i++)
        if ((*i >='a'&& *i<='z') || ( *i >='A'&& *i<='Z')) count++;
    return count;
}
int main(){
    string phrase;

    cout << "Phrase analysis: " << endl;
    cout << "phrase -> ";
    getline(cin, phrase);
    cout << "number of lowercase characters -> " << Count_Lowercase(phrase) << endl;
    cout << "number of uppercase characters -> " << Count_Uppercase(phrase) << endl;
    cout << "number of numeric characters -> " << Count_Numeric(phrase) << endl;
    cout << "number of vowels -> " << Count_Vowels(phrase) << endl;
    cout << "number of consonants -> " << Count_Consonants(phrase) << endl;
}
