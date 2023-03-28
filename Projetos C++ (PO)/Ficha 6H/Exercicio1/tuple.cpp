#include "tuple.h"

Tuple::Tuple() : n(0), elements(nullptr) {}

Tuple::Tuple(unsigned int n) : n(n), elements(new double[n]) {}

Tuple::Tuple(const Tuple& other) : n(other.n), elements(new double[other.n]) {
  for (unsigned int i = 0; i < n; i++) {
    elements[i] = other.elements[i];
  }
}

Tuple::~Tuple() { delete[] elements; }

Tuple& Tuple::operator=(const Tuple& other) {
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

double& Tuple::operator[](unsigned int index) {
  if (index >= n) throw std::out_of_range("Index out of range");
  return elements[index];
}

unsigned int Tuple::size() const { return n; }

double Tuple::getElement(unsigned int index) const {
  if (index >= n) throw std::out_of_range("Index out of range");
  return elements[index];
}
