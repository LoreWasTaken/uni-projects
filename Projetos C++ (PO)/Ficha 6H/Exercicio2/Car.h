#ifndef POO_FICHA_6_2_CAR_H_
#define POO_FICHA_6_2_CAR_H_

#include <string>

enum class CarClass { LUXURY, ECONOMY, FAMILY };
enum class FuelType { PETROL, DIESEL, ELECTRIC, HYBRID };

class Car {
 public:
  Car(const std::string &license_plate, CarClass car_class, FuelType fuel_type, double daily_price);

  void book();
  void pick_up();
  void return_car();

  std::string get_license_plate() const;
  CarClass get_car_class() const;
  FuelType get_fuel_type() const;
  double get_daily_price() const;
  bool is_available() const;

 private:
  std::string license_plate;
  CarClass car_class;
  FuelType fuel_type;
  double daily_price;
  bool available;
};

#endif  // POO_FICHA_6_2_CAR_H_