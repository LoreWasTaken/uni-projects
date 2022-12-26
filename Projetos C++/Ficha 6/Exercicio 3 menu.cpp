// denis: Isto não era pedido mas é a minha tentativa de fazer o mesmo exercicio so que com um menu

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

int main() {
    string phrase;

    while (true) {
        cout << "Enter your choice:" << endl;
        cout << "1. Enter a phrase" << endl;
        cout << "2. Count lowercase characters" << endl;
        cout << "3. Count uppercase characters" << endl;
        cout << "4. Count numeric characters" << endl;
        cout << "5. Count vowels" << endl;
        cout << "6. Count consonants" << endl;
        cout << "7. Exit" << endl;

        int choice;
        cin >> choice;

        // ignore any remaining newline characters in the input stream
        cin.ignore();

        switch (choice) {
            case 1:
                // prompt the user to enter a phrase
                cout << "Enter a phrase: ";
                getline(cin, phrase);
                break;
            case 2:
                // count and print the number of lowercase characters
                cout << "Number of lowercase characters: " << Count_Lowercase(phrase) << endl;
                break;
            case 3:
                // count and print the number of uppercase characters
                cout << "Number of uppercase characters: " << Count_Uppercase(phrase) << endl;
                break;
            case 4:
                // count and print the number of numeric characters
                cout << "Number of numeric characters: " << Count_Numeric(phrase) << endl;
                break;
            case 5:
                // count and print the number of vowels
                cout << "Number of vowels: " << Count_Vowels(phrase) << endl;
                break;
            case 6:
                // count and print the number of consonants
                cout << "Number of consonants: " << Count_Consonants(phrase) << endl;
                break;
            case 7:
                // exit the program
                return 0;
            default:
                cout << "Invalid choice." << endl;
                break;
        }
    }
}