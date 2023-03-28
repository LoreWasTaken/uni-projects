#ifndef POO_FICHA_6_1_H_
#define POO_FICHA_6_1_H_

#include <iostream>

class Tuple {
 protected:
  unsigned int n;
  double* elements;

 public:
  Tuple();
  Tuple(unsigned int n);
  Tuple(const Tuple& other);
  virtual ~Tuple();

  Tuple& operator=(const Tuple& other);

  double& operator[](unsigned int index);
  unsigned int size() const;

  double getElement(unsigned int index) const;
};

#endif //POO_FICHA_6_1_H_
