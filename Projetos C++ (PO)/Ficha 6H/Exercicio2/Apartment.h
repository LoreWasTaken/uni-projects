#ifndef POO_FICHA_6_2_APARTMENT_H_
#define POO_FICHA_6_2_APARTMENT_H_

#include "Lodging.h"

class Apartment : public Lodging {
 public:
  Apartment(const std::string &id, const std::string &location, double daily_price, int num_bedrooms);

  int get_num_bedrooms() const;

 private:
  int num_bedrooms;
};

#endif  // POO_FICHA_6_2_APARTMENT_H_