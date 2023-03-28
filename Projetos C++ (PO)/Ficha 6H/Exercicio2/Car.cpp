#include "Car.h"

Car::Car(const std::string &license_plate, CarClass car_class, FuelType fuel_type, double daily_price)
    : license_plate(license_plate), car_class(car_class), fuel_type(fuel_type), daily_price(daily_price), available(true) {}

void Car::book() { available = false; }
void Car::pick_up() { available = false; }
void Car::return_car() { available = true; }

std::string Car::get_license_plate() const { return license_plate; }
CarClass Car::get_car_class() const { return car_class; }
FuelType Car::get_fuel_type() const { return fuel_type; }
double Car::get_daily_price() const { return daily_price; }
bool Car::is_available() const { return available; }