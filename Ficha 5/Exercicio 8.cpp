// denis: Create a function which determines the binary representation of a positive integer number
// Positive integer introduced by the user
#include "iostream"
using namespace std;

// One way to make Binary representation of a number
/*
// Function that gives the length of the binary form of a decimal number
int binary(int n){
    int count = 0;
    while(n){
        count++;
        n = n >> 1;
    }
    return count;
}

// Prints the bits of the binary form of a decimal number
void BinaryRepresentation(int n){
    int i = binary(n) - 1;
    do {
        cout << (((n & (1 << i)) != 0) ? 1 : 0);
    } while (i--);
}
*/

// One more way to do it
/*
void parabase2(int n){
    int restos[32];
    int indx = 0;
    do{
        resto[indx++] = n%2;
        n = n/2;
    } while (n != 0);
    for (int i = indx-1; i >=0; i--)
        cout << restos[i];
}
 */


void binaryrep(int n){
    if (n > 1) // If the number is greater than 1, then divide the number by 2 and will call the function again till false
        binaryrep(n / 2);
    cout << n % 2; // Prints the least significant bit of the number in this call
}

int main(){
    int number;
    do {
        cout << "Binary Representation" << endl;
        cout << "Insert a positive number: ";
        cin >> number;
    } while (number <= 0);
    //cout << "Binary representation of: " << number << " is "; BinaryRepresentation(number);
    cout << "Binary representation of: " << number << " is ";
    binaryrep(number);
    cout << endl;

    return 0;
}