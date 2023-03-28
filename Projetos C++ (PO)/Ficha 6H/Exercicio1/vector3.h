#ifndef POO_FICHA_6_1_H_
#define POO_FICHA_6_1_H_

#include "tuple.h"
#include "point3.h"

class Vector3 : public Tuple {
 public:
  Vector3();
  Vector3(double x, double y, double z);
  Vector3(const Vector3& other);
  ~Vector3();

  Vector3& operator=(const Vector3& other);

  friend std::ostream& operator<<(std::ostream& os, const Vector3& vector);
  bool operator==(const Vector3& other) const;
  bool operator!=(const Vector3& other) const;

  friend Vector3 operator+(const Vector3& vector1, const Vector3& vector2);
  friend Vector3 operator-(const Vector3& vector1, const Vector3& vector2);

  Vector3 operator*(double scalar) const;
  friend double operator*(const Vector3& vector1, const Vector3& vector2);
};

#endif //POO_FICHA_6_1_H_
