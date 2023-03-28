#include "Apartment.h"

Apartment::Apartment(const std::string &id, const std::string &location, double daily_price, int num_bedrooms)
    : Lodging(id, location, daily_price), num_bedrooms(num_bedrooms) {}

int Apartment::get_num_bedrooms() const { return num_bedrooms; }