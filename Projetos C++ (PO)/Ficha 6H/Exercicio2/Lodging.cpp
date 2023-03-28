#include "Lodging.h"

Lodging::Lodging(const std::string &id, const std::string &location, double daily_price)
    : id(id), location(location), daily_price(daily_price), available(true) {}

void Lodging::book() { available = false; }
void Lodging::check_in() { available = false; }
void Lodging::check_out() { available = true; }

std::string Lodging::get_id() const { return id; }
std::string Lodging::get_location() const { return location; }
double Lodging::get_daily_price() const { return daily_price; }
bool Lodging::is_available() const { return available; }