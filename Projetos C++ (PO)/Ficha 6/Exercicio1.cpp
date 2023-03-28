#include <iostream>

// Forward declaration of Point3 and Vector3 classes
class Point3;
class Vector3;

// Base class for Point3 and Vector3
class Tuple {
 protected:
  unsigned int n;      // Number of elements in the tuple
  double* elements;    // Pointer to the elements array

 public:
  // Default constructor
  Tuple() : n(0), elements(nullptr) {}

  // Constructor with size
  Tuple(unsigned int n) : n(n), elements(new double[n]) {}

  // Copy constructor
  Tuple(const Tuple& other) : n(other.n), elements(new double[other.n]) {
    for (unsigned int i = 0; i < n; i++) {
      elements[i] = other.elements[i];
    }
  }

  // Destructor
  virtual ~Tuple() { delete[] elements; }

  // Assignment operator
  Tuple& operator=(const Tuple& other) {
    if (this != &other) {
      delete[] elements;
      n = other.n;
      elements = new double[n];
      for (unsigned int i = 0; i < n; i++) {
        elements[i] = other.elements[i];
      }
    }
    return *this;
  }

  // Subscript operator
  double& operator[](unsigned int index) {
    if (index >= n) throw std::out_of_range("Index out of range");
    return elements[index];
  }

  // Returns the size of the tuple
  unsigned int size() const { return n; }

  // Getter for elements
  double getElement(unsigned int index) const {
    if (index >= n) throw std::out_of_range("Index out of range");
    return elements[index];
  }
};

// Point3 class representing 3D points
class Point3 : public Tuple {
 public:
  // Default constructor
  Point3() : Tuple(3) {}

  // Constructor with coordinates
  Point3(double x, double y, double z) : Tuple(3) {
    elements[0] = x;
    elements[1] = y;
    elements[2] = z;
  }

  // Copy constructor
  Point3(const Point3& other) : Tuple(other) {}

  // Destructor
  ~Point3() {}

  // Assignment operator
  Point3& operator=(const Point3& other) {
    Tuple::operator=(other);
    return *this;
  }

  // Stream insertion operator
  friend std::ostream& operator<<(std::ostream& os, const Point3& point) {
    os << "(" << point.elements[0] << ", " << point.elements[1] << ", " << point.elements[2] << ")";
    return os;
  }

  // Equality operator
  bool operator==(const Point3& other) const {
    return elements[0] == other.elements[0] &&
        elements[1] == other.elements[1] &&
        elements[2] == other.elements[2];
  }

  // Inequality operator
  bool operator!=(const Point3& other) const {
    return !(*this == other);
  }

  // Friend functions for arithmetic operations
  friend Point3 operator+(const Point3& point, const Vector3& vector);
  friend Vector3 operator-(const Point3& point1, const Point3& point2);
};

// Vector3 class representing 3D vectors
class Vector3 : public Tuple {
 public:
  // Default constructor
  Vector3() : Tuple(3) {}

  // Constructor with components
  Vector3(double x, double y, double z) : Tuple(3) {
    elements[0] = x;
    elements[1] = y;
    elements[2] = z;
  }

  // Copy constructor
  Vector3(const Vector3& other) : Tuple(other) {}

  // Destructor
  ~Vector3() {}

  // Assignment operator
  Vector3& operator=(const Vector3& other) {
    Tuple::operator=(other);
    return *this;
  }

  // Stream insertion operator
  friend std::ostream& operator<<(std::ostream& os, const Vector3& vector) {
    os << "<" << vector.elements[0] << ", " << vector.elements[1] << ", " << vector.elements[2] << ">";
    return os;
  }

  // Equality operator
  bool operator==(const Vector3& other) const {
    return elements[0] == other.elements[0] &&
        elements[1] == other.elements[1] &&
        elements[2] == other.elements[2];
  }

  // Inequality operator
  bool operator!=(const Vector3& other) const {
    return !(*this == other);
  }

  // Friend functions for arithmetic operations
  friend Vector3 operator+(const Vector3& vector1, const Vector3& vector2);
  friend Vector3 operator-(const Vector3& vector1, const Vector3& vector2);

  // Scalar multiplication
  Vector3 operator*(double scalar) const {
    return Vector3(elements[0] * scalar, elements[1] * scalar, elements[2] * scalar);
  }

  // Dot product
  friend double operator*(const Vector3& vector1, const Vector3& vector2);
};

// Point3 addition with Vector3
Point3 operator+(const Point3& point, const Vector3& vector) {
  return Point3(point.getElement(0) + vector.getElement(0),
                point.getElement(1) + vector.getElement(1),
                point.getElement(2) + vector.getElement(2));
}

// Vector3 subtraction between two Point3 instances
Vector3 operator-(const Point3& point1, const Point3& point2) {
  return Vector3(point1.getElement(0) - point2.getElement(0),
                 point1.getElement(1) - point2.getElement(1),
                 point1.getElement(2) - point2.getElement(2));
}

// Main function
int main() {
  Point3 p1(1, 2, 3);
  Point3 p2(4, 5, 6);
  Vector3 v1(1, 1, 1);
  Vector3 v2(2, 2, 2);

  // Display points and vectors
  std::cout << "p1: " << p1 << std::endl;
  std::cout << "p2: " << p2 << std::endl;
  std::cout << "v1: " << v1 << std::endl;
  std::cout << "v2: " << v2 << std::endl;

  // Perform arithmetic operations and display results
  Vector3 v3 = p1 - p2;
  std::cout << "p1 - p2: " << v3 << std::endl;

  Point3 p3 = p1 + v1;
  std::cout << "p1 + v1: " << p3 << std::endl;

  Vector3 v4 = v1 + v2;
  std::cout << "v1 + v2: " << v4 << std::endl;

  Vector3 v5 = v1 - v2;
  std::cout << "v1 - v2: " << v5 << std::endl;

  Vector3 v6 = v1 * 2;
  std::cout << "v1 * 2: " << v6 << std::endl;

  double dot_product = v1 * v2;
  std::cout << "v1 * v2: " << dot_product << std::endl;

  return 0;
}