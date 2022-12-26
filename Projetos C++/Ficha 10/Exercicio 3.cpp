/*
denis: Program that that extracts all the words existing in a
text file, into a vector (you can create a fake test file with several words).
Then, orders all the words in that vector alphabetically, and prints them on the screen.
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

    // Print the words
    for (const auto& word : words)
    {
        cout << word << " ";
    }

    return 0;
}
