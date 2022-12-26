/*
denis: In summary, in C++ we can sort arrays and vectors using the sort() function,
which takes iterators as arguments indicating the interval of elements to be sorted.
We can create these iterators by using vector<int>::iterator and initializing them with .begin() and .end() to point to the beginning and end of the vector,
respectively.
We can also use the binary_search() function to search for an item
in a vector by indicating the interval to be searched using iterators.
*/
#include <iostream>
#include <vector>
#include <algorithm> // for the sort() function
using namespace std;

int main() {
    int arr[4] = {9, 23, 44, 1};
    vector<int> v = {9, 23, 44, 1};

    // sort the array using the sort() function
    sort(arr, arr + 4);

    // print the sorted array
    cout << "array: ";
    for (int i = 0; i < 4; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
// This code will output the sorted array 1 9 23 44.
// Note that the second argument to the sort() function is arr + 4,
// which is a pointer to the element at index 3 in the array
// (since arr is a pointer to the element at index 0).
// This indicates that the sort() function should sort the whole array, from index 0 to index 3.

    // create iterators to the beginning and end of the vector
    vector<int>::iterator i = v.begin();
    vector<int>::iterator j = v.end();

    // sort the vector using the sort() function
    sort(i, j);

    // print the sorted vector
    cout << "vector: ";
    for (auto x : v) {
        cout << x << " ";
    }

    cout << endl;
// This code will output the sorted vector 1 9 23 44.

    // search for the number 7 in the vector using binary_search()
    if (binary_search(v.begin(), v.end(), 7)) {
        cout << "7 was found in the vector" << std::endl;
    } else {
        cout << "7 was not found in the vector" << std::endl;
    }

// This code will output 7 was not found in the vector, since the number 7 is not present in the vector.
    return 0;
}
