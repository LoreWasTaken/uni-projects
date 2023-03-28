#include <iostream>
#include "point3.h"
#include "vector3.h"

int main() {
  Point3 p1(1, 2, 3);
  Point3 p2(4, 5, 6);
  Vector3 v1(1, 1, 1);
  Vector3 v2(2, 2, 2);

  std::cout << "p1: " << p1 << std::endl;
  std::cout << "p2: " << p2 << std::endl;
  std::cout << "v1: " << v1 << std::endl;
  std::cout << "v2: " << v2 << std::endl;

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
