// denis: Program to compute the Euclidean distance between two points
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

struct Point2D {
    double x;
    double y;
};

Point2D get_point() {
    Point2D point;
    cout << "Enter x coordinate: ";
    cin >> point.x;
    cout << "Enter y coordinate: ";
    cin >> point.y;
    return point;
}

void print_point(Point2D point) {
    cout << "(" << showpos << fixed << setprecision(3) << point.x << ", " << point.y << ")";
}

double distance(Point2D p1, Point2D p2) {
    double dx = p1.x - p2.x;
    double dy = p1.y - p2.y;
    return sqrt(dx * dx + dy * dy);
}

int main() {
    Point2D origin = {0, 0};
    Point2D furthest;
    double furthest_distance = 0;
    int count = 0;
    double sum_distances = 0;

    while (true) {
        Point2D point = get_point();

        // Stop asking for points if the user enters (0, 0)
        if (point.x == 0 && point.y == 0) {
            break;
        }

        double d = distance(origin, point);
        sum_distances += d;
        count++;

        // Update the furthest point if the current point is further away from the origin
        if (d > furthest_distance) {
            furthest_distance = d;
            furthest = point;
        }
    }

    cout << "The sum of the distances of the " << count << " points to the origin is " << fixed << setprecision(3) << sum_distances << endl;
    cout << "The point further away from the origin is: ";
    print_point(furthest);
    cout << endl;

    return 0;
}