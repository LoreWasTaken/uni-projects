#include "vector3.h"

Vector3::Vector3() : Tuple(3) {}

Vector3::Vector3(double x, double y, double z) : Tuple(3) {
  elements[0] = x;
  elements[1] = y;
  elements[2] = z;
}

Vector3::Vector3(const Vector3& other) : Tuple(other) {}

Vector3::~Vector3() {}

Vector3& Vector3::operator=(const Vector3& other) {
  Tuple::operator=(other);
  return *this;
}

std::ostream& operator<<(std::ostream& os, const Vector3& vector) {
  os << "<" << vector.elements[0] << ", " << vector.elements[1] << ", " << vector.elements[2] << ">";
  return os;
}

bool Vector3::operator==(const Vector3& other) const {
  return elements[0] == other.elements[0] &&
         elements[1] == other.elements[1] &&
         elements[2] == other.elements[2];
}

bool Vector3::operator!=(const Vector3& other) const {
  return !(*this == other);
}

Vector3 operator+(const Vector3& vector1, const Vector3& vector2) {
  return Vector3(vector1.elements[0] + vector2.elements[0],
                 vector1.elements[1] + vector2.elements[1],
                 vector1.elements[2] + vector2.elements[2]);
}

Vector3 operator-(const Vector3& vector1, const Vector3& vector2) {
  return Vector3(vector1.elements[0] - vector2.elements[0],
                 vector1.elements[1] - vector2.elements[1],
                 vector1.elements[2] - vector2.elements[2]);
}

Vector3 Vector3::operator*(double scalar) const {
  return Vector3(elements[0] * scalar, elements[1] * scalar, elements[2] * scalar);
}

double operator*(const Vector3& vector1, const Vector3& vector2) {
  return vector1.elements[0] * vector2.elements[0] +
         vector1.elements[1] * vector2.elements[1] +
         vector1.elements[2] * vector2.elements[2];
}
