#ifndef POO_FICHA_6_1_H_
#define POO_FICHA_6_1_H_

#endif //POO_FICHA_6_A_H_

#include "tuple.h"
#include "vector3.h"

class Point3 : public Tuple {
 public:
  Point3();
  Point3(double x, double y, double z);
  Point3(const Point3& other);
  ~Point3();

  Point3& operator=(const Point3& other);

  friend std::ostream& operator<<(std::ostream& os, const Point3& point);
  bool operator==(const Point3& other) const;
  bool operator!=(const Point3& other) const;

  friend Point3 operator+(const Point3& point, const Vector3& vector);
  friend Vector3 operator-(const Point3& point1, const Point3& point2);
};

#endif //POO_FICHA_6_1_H_
