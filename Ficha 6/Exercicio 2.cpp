// denis: String manipulation
#include <iostream>
#include <string>
using namespace std;

/* Worksheet 6 Exercise 1
void print_reverse_string(const string &str)
{
    for (string::const_reverse_iterator i = str.rbegin(); i != str.rend(); i++)
        cout << *i;
}
*/

int count_lower(const string &str) {
    unsigned count = 0;
    for (string::const_iterator i = str.begin(); i != str.end(); i++)
        if (*i >= 'a' and *i <= 'z') count++;
    return count;
}

int count_upper(const string &str) {
    unsigned count = 0;
    for (string::const_iterator i = str.begin(); i != str.end(); i++)
        if (*i >= 'A' and *i <= 'Z') count++;
    return count;
}

int count_alpha(const std::string &str) {
    return count_lower(str) + count_upper(str);
}
/* Two other ways to do the same thing
int count_alpha(const string &s){
    int n_alpha = 0;             |       int n_alpha = 0
    for (char c : s)             |       int size = s.length();
        if(isalpha(c) != 0)      |       for(int i = 0; i < size; i++)
            n_alpha++;           |           if((s.at(i) >= 'a') && (s.at(i) <= 'z')) || ((s.at(t) >= 'A' && (s.at(t) <= 'Z'))) // Counting bitwise
    return n_alpha;              |       n_alpha++;
}
*/

void equals_or_greater(const string &str1, const string &str2) {
    size_t min_size = min(str1.length(), str2.length());
    for (size_t i = 0; i < min_size; i++) {
        if (str1.at(i) == str2.at(i)) continue;
        else if (str1.at(i) >= str2.at(i))
            cout << "The string " << str1 << " is greater than the string " << str2 << endl;
        else
            cout << "The string " << str2 << " is greater than the string " << str1 << endl;
        return;
    }
    cout << "The string " << str1 << " is equal to the string " << str2 << endl;
}

string to_lower(const string &str) {
    string return_str = str;
    for (string::iterator i = return_str.begin(); i != return_str.end(); i++)
        if (*i >= 'A' and *i <= 'Z') *i += 0x20; // Two rows down on the ASCII table
    return return_str;
}
/* Using "tolower" function existing in C
string to_lower(const string &s){
    string minus;
    for (char c : s)                for(int i; i < s.size(); i++)
        minus += tolower(c);            if(s.at(i) >= 'A' && s.at(i) <= 'Z')
    return minus;                           minus += tolower(s.at(i));
}                                       else
                                            minus += s.at(i);
*/

/*
string capitalize(const string &str) {
    string return_str = str;
    for (string::iterator i = return_str.begin(); i != return_str.end(); i++)
    if (*i >= 'a' and *i <= 'z') *i -= 0x20; // Two rows down on the ASCII table
    return return_str;
}
*/
string capitalize(string &str) {
    for (int x = 0; x < str.length(); x++){
        if (x == 0){
            str[x] = toupper(str[x]);
        }
        else if (str[x - 1] == ' ')
        {
            str[x] = toupper(str[x]);
        }
    }
    return str;
}

string replace(const string &s) {
   string str = s;
   size_t x;
   x = str.find("  ");
    while (x < str.size()){
        str.erase(x, 1);
        x = str.find("  ");
    }
    return str;
}

string is_palindrome(const string &str){

    // Iterate over the range [0, N/2]
    for (int i = 0; i < str.length() / 2; i++) {

        // If S[i] is not equal to
        // the S[N-i-1]
        if (str[i] != str[str.length() - i - 1]) {
            // Return No
            return "No";
        }
    }
    // Return "Yes"
    return "Yes";
}

int main(){
    string phrase;
    string phrase2;
    cout << "Insert a word or phrase: ";
    getline(cin, phrase);
    cout << "Now, insert another word or phrase: ";
    getline(cin, phrase2);
    cout << "Your word/phrase: " << phrase << endl;
    cout << "Total number of alphabetical characters: " << count_alpha(phrase) << endl;
    cout << "Total number of upper case characters: " << count_upper(phrase) << endl;
    cout << "Total number of lower case characters: " << count_lower(phrase) << endl;
    equals_or_greater(phrase, phrase2);
    cout << "Your word/phrase in lower case: " << to_lower(phrase) << endl;
    cout << "If your phrase has multiple spaces, sets it just to one space: " << replace(phrase) << endl;
    cout << "Capitalize the first letter of each word in your phrase: " << capitalize(phrase) << endl;
    cout << "Your word/phrase is a palindrome? " << is_palindrome(phrase);
}