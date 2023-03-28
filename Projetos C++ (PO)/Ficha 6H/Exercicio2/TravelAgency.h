#ifndef POO_FICHA_6_2_TRAVELAGENCY_H_
#define POO_FICHA_6_2_TRAVELAGENCY_H_

#include <vector>
#include "Car.h"
#include "Apartment.h"
#include "HotelRoom.h"

class TravelAgency {
 public:
  TravelAgency(const std::string &name, const std::string &address);

  void add_car(Car car);
  void add_apartment(Apartment apartment);
  void add_hotel_room(HotelRoom hotel_room);

  std::vector<Lodging *> get_all_lodgings();
  void book_car(const std::string &license_plate);
  void pick_up_car(const std::string &license_plate);
  void return_car(const std::string &license_plate);
  void book_lodging(const std::string &id);
  void check_in_lodging(const std::string &id);
  void check_out_lodging(const std::string &id);
  void print_status();

 private:
  std::string name;
  std::string address;
  std::vector<Car> cars;
  std::vector<Apartment> apartments;
  std::vector<HotelRoom> hotel_rooms;
};

#endif  // POO_FICHA_6_2_TRAVELAGENCY_H_