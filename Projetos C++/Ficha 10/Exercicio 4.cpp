/*
denis: This program first extracts the words from the file and stores them in a vector, as in the previous example. (W10E3)
Then, it asks the user for a word to search for and uses the std::find algorithm to search for the word in the vector.
If the word is found, it prints a message indicating that the word was found;
otherwise, it prints a message indicating that the word was not found.
 */

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// Function to extract words from a text file and store them in a vector
vector<string> extractWords(const string& filename)
{
    // Open the file
    ifstream file(filename);

    // Vector to store the words
    vector<string> words;

    // Read the file word by word
    string word;
    while (file >> word)
    {
        // Store the word in the vector
        words.push_back(word);
    }

    // Return the vector of words
    return words;
}

int main()
{
    // Extract the words from the file
    vector<string> words = extractWords("test.txt");

    // Sort the words alphabetically
    sort(words.begin(), words.end());

    // Ask the user for a word to search for
    cout << "Enter a word to search for: ";
    string word;
    cin >> word;

    // Search for the word in the vector
    auto it = find(words.begin(), words.end(), word);

    // Check if the word was found
    if (it != words.end())
    {
        cout << "The word '" << word << "' was found in the vector." << endl;
    }
    else
    {
        cout << "The word '" << word << "' was not found in the vector." << endl;
    }

    return 0;
}
