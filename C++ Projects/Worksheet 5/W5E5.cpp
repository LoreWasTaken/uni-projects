// denis: Create a function that prints the greatest of its parameters ( with 3 parameters now )
#include "iostream"
using namespace std;

double max3(double x, double y, double z){
    return (x > y) ? x : (y > z) ? y : z;
}

int main(){
    double x, y, z;
    cout << "Insert three values: ";
    cin >> x >> y >> z;
    cout << "Greatest value of " << "(" << x << ", " << y << ", " << z << ")" << " is " << max3(x,y,z) << endl;

    return 0;
}

// Other possible way of doing
/*

int max2(int a, int b){
    if a > b
        return a;
    else
        return b;
}

int max3(int a, int b, int c){
    int max = max2(a, b);
    return max2(max, c) // return max2(a, max2(b,c))
}

*/