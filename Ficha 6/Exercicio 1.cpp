// denis: Create a function that given a string prints the string backwards
// string inserted by the user

#include <iostream>
using namespace std;

void reverse_String(const string &s){
    for (unsigned i = s.length()-1; i>0; i--)
        cout << s[i]; //s.at(i);
}

int main() {
    string a;
    cout << "Insert a word: ";
    cin >> a;
    cout<<"String before reversal: "<< a <<endl;
    cout<<"String after reversal: " << endl;
    reverse_String(a);

    return 0;
}