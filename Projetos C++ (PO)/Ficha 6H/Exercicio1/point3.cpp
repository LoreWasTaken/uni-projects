#include "point3.h"

Point3::Point3() : Tuple(3) {}

Point3::Point3(double x, double y, double z) : Tuple(3) {
  elements[0] = x;
  elements[1] = y;
  elements[2] = z;
}

Point3::Point3(const Point3& other) : Tuple(other) {}

Point3::~Point3() {}

Point3& Point3::operator=(const Point3& other) {
  Tuple::operator=(other);
  return *this;
}

std::ostream& operator<<(std::ostream& os, const Point3& point) {
  os << "(" << point.elements[0] << ", " << point.elements[1] << ", " << point.elements[2] << ")";
  return os;
}

bool Point3::operator==(const Point3& other) const {
  return elements[0] == other.elements[0] &&
         elements[1] == other.elements[1] &&
         elements[2] == other.elements[2];
}

bool Point3::operator!=(const Point3& other) const {
  return !(*this == other);
}
