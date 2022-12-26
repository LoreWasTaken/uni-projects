// denis: Program to compute the Euclidean distance between to points
// denis: Didn't finish the program, made a working one called Exercicio 1.1
#include "iostream"
#include "iomanip"
#include "cmath"
using namespace std;

// a) Defining a data structure, named Point2D, representing a 2-dimensional point with real coordinates x and y
typedef struct Point2D{
    double x;
    double y;
} Point2D_t;

// b) Function to ask the user for the two coordinates of the point
Point2D_t read_point() {    // Other way of defining => void read_point(Point2D_t *p){}
    Point2D_t tmp;
    cout << "Choose x and y coordinate for the first point: ";
    cin >> tmp.x;
    cout << "Choose x and y coordinate for the second point: ";
    cin >> tmp.y;

    return tmp;
}

// c) Function that prints the contents of a point in the format (+#.###,+#.###)  (+ represents the sign (+ or -) and # represents a digit between 0 and 9)
void print_point(Point2D_t p){
    cout << showpos << setprecision(3) << fixed << "(" << p.x << "," << p.y << ")" << "\n";
}

// d) Function that computes the Euclidean distance between two points
double EuclideanD(Point2D_t p1, Point2D_t p2){
    return sqrt(pow(p2.x-p1.x, 2) + pow(p2.y-p1.y, 2));
}

int main(){
    struct Point2D point;
    Point2D_t point2;
    point = read_point();
    point2 = read_point();
    print_point(point);
    cout << "The Euclidean distance between the two points is: " << EuclideanD(point, point2);
}