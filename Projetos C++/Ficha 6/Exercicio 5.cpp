//denis: O programa não parece estar a funcionar como pedido no enunciado. Se calhar arranjo, um dia.

#include <iostream>

int main() {
    // Read the keyword from the user
    std::string keyword;
    std::cout << "Enter the keyword: ";
    std::cin >> keyword;

    // Initialize the word and keyword counters
    int word_count = 0;
    int keyword_count = 0;

    // Read paragraphs from the user until they enter "End"
    std::string paragraph;
    std::cin.ignore();
    std::cout << "Enter a paragraph (enter 'End' to finish): ";
    std::getline(std::cin, paragraph);
    while (paragraph != "End") {
        // Split the paragraph into words using the most common separators
        int start = 0;
        for (int i = 0; i < paragraph.size(); i++) {
            if (paragraph[i] == ' ' || paragraph[i] == '\n' || paragraph[i] == ',' || paragraph[i] == '.' || paragraph[i] == '!' || paragraph[i] == '?') {
                std::string word = paragraph.substr(start, i - start);
                // Update the word count
                word_count++;

                // Count the number of occurrences of the keyword in the paragraph
                if (word == keyword) {
                    keyword_count++;
                }
                start = i + 1;
            }
        }
        // Read the next paragraph
        std::cout << "Enter a paragraph (enter 'End' to finish): ";
        std::getline(std::cin, paragraph);
    }

    // Print the final counts
    std::cout << "Number of words: " << word_count << std::endl;
    std::cout << "Number of occurrences of the keyword '" << keyword << "': " << keyword_count << std::endl;

    return 0;
}