#include "TravelAgency.h"
#include <iostream>

TravelAgency::TravelAgency(const std::string &name, const std::string &address) : name(name), address(address) {}

void TravelAgency::add_car(Car car) { cars.push_back(car); }
void TravelAgency::add_apartment(Apartment apartment) { apartments.push_back(apartment); }
void TravelAgency::add_hotel_room(HotelRoom hotel_room) { hotel_rooms.push_back(hotel_room); }

std::vector<Lodging *> TravelAgency::get_all_lodgings() {
  std::vector<Lodging *> lodgings;
  for (auto &apartment : apartments) {
    lodgings.push_back(&apartment);
  }
  for (auto &hotel_room : hotel_rooms) {
    lodgings.push_back(&hotel_room);
  }
  return lodgings;
}

void TravelAgency::book_car(const std::string &license_plate) {
  for (auto &car : cars) {
    if (car.get_license_plate() == license_plate) {
      car.book();
      return;
    }
  }
}

void pick_up_car(const std::string &license_plate) {
    for (Car &car : cars) {
      if (car.get_license_plate() == license_plate && car.is_available()) {
        car.pick_up();
        std::cout << "Car picked up successfully.\n";
        return;
      }
    }
    std::cout << "Car not found or unavailable.\n";
  }

  void return_car(const std::string &license_plate) {
    for (Car &car : cars) {
      if (car.get_license_plate() == license_plate && !car.is_available()) {
        car.return_car();
        std::cout << "Car returned successfully.\n";
        return;
      }
    }
    std::cout << "Car not found or already available.\n";
  }

  void book_lodging(const std::string &id) {
    for (Lodging *lodging : get_all_lodgings()) {
      if (lodging->get_id() == id && lodging->is_available()) {
        lodging->book();
        std::cout << "Lodging booked successfully.\n";
        return;
      }
    }
    std::cout << "Lodging not found or unavailable.\n";
  }

  void check_in_lodging(const std::string &id) {
    for (Lodging *lodging : get_all_lodgings()) {
      if (lodging->get_id() == id && lodging->is_available()) {
        lodging->check_in();
        std::cout << "Checked in to lodging successfully.\n";
        return;
      }
    }
    std::cout << "Lodging not found or unavailable.\n";
  }

  void check_out_lodging(const std::string &id) {
    for (Lodging *lodging : get_all_lodgings()) {
      if (lodging->get_id() == id && !lodging->is_available()) {
        lodging->check_out();
        std::cout << "Checked out of lodging successfully.\n";
        return;
      }
    }
    std::cout << "Lodging not found or already available.\n";
  }

  void print_status () {
    std::cout << "Travel Agency: " << name << "\nAddress: " << address << "\n\n";
    std::cout << "Cars:\n";
    for (const Car &car : cars) {
      std::cout << "License Plate: " << car.get_license_plate()
                << "\nClass: " << static_cast<int>(car.get_car_class())
                << "\nFuel Type: " << static_cast<int>(car.get_fuel_type())
                << "\nDaily Price: " << car.get_daily_price()
                << "\nAvailable: " << (car.is_available() ? "Yes" : "No") << "\n\n";
    }

    std::cout << "Apartments:\n";
    for (const Apartment &apartment : apartments) {
      std::cout << "ID: " << apartment.get_id()
                << "\nLocation: " << apartment.get_location()
                << "\nDaily Price: " << apartment.get_daily_price()
                << "\nRooms: " << apartment.get_num_rooms()
                << "\nAvailable: " << (apartment.is_available() ? "Yes" : "No") << "\n\n";
    }

    std::cout << "Hotel Rooms:\n";
    for (const HotelRoom &hotel_room : hotel_rooms) {
      std::cout << "ID: " << hotel_room.get_id()
                << "\nLocation: " << hotel_room.get_location()
                << "\nDaily Price: " << hotel_room.get_daily_price()
                << "\nRoom Type: " << static_cast<int>(hotel_room.get_room_type())
                << "\nAvailable: " << (hotel_room.is_available() ? "Yes" : "No") << "\n\n";
    }
  }
