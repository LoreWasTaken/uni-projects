/*

denis: Adding the extra stuff asked in the exercise 5 of this worksheet.
This code uses the ifstream class to read the text file, the stringstream class to split the lines into words,
and the sort function from the algorithm header to sort the vector of words.
It also uses the rbegin and rend iterators to sort the vector in descending order.

Note that this code assumes that the text file is in the same directory as the executable and that it is called test.txt.
You can change the name of the file by passing a different string to the extractWords function.

*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>

using namespace std;

// Function that extracts all words from a text file and stores them in a vector
vector<string> extractWords(const string& fileName) {
    vector<string> words;

    // Open the text file
    ifstream file(fileName);

    // Read the text file line by line
    string line;
    while (getline(file, line)) {
        // Split the line into words
        string word;
        stringstream ss(line);
        while (ss >> word) {
            words.push_back(word);
        }
    }

    return words;
}

// Testing program
int main() {
    // Extract the words from the text file
    vector<string> words = extractWords("test.txt");

    // Print the words in alphabetical order
    sort(words.begin(), words.end());
    cout << "Words in alphabetical order: " << endl;
    for (const string& word : words) {
        cout << word << " ";
    }

    cout << endl;

    // Print the words in descending order
    sort(words.rbegin(), words.rend());
    cout << "Words in descending order: " << endl;
    for (const string& word : words) {
        cout << word << " ";
    }

    return 0;
}