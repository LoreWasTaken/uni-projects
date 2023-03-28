#include "Car.h"
#include "Apartment.h"
#include "HotelRoom.h"
#include "TravelAgency.h"
#include <iostream>

int main() {
  TravelAgency agency("Dreamy Travels", "1234 Main St, Anytown");

  // Add cars, apartments, and hotel rooms
  agency.add_car(Car("ABC123", CarClass::LUXURY, FuelType::PETROL, 100.0));
  agency.add_car(Car("DEF456", CarClass::ECONOMY, FuelType::DIESEL, 50.0));
  agency.add_car(Car("GHI789", CarClass::FAMILY, FuelType::HYBRID, 75.0));

  agency.add_apartment(Apartment("APT001", "New York", 120.0, 2));
  agency.add_apartment(Apartment("APT002", "Los Angeles", 100.0, 1));

  agency.add_hotel_room(HotelRoom("HR001", "Paris", 80.0, RoomType::SINGLE));
  agency.add_hotel_room(HotelRoom("HR002", "Tokyo", 120.0, RoomType::DOUBLE));
  agency.add_hotel_room(HotelRoom("HR003", "London", 150.0, RoomType::TRIPLE));

  // Print the status of the agency's cars and lodgings
  agency.print_status();

  int choice;
  bool exit_program = false;

  while (!exit_program) {
    std::cout << "Menu:\n";
    std::cout << "1. Book a car\n";
    std::cout << "2. Pick up a car\n";
    std::cout << "3. Return a car\n";
    std::cout << "4. Book a lodging\n";
    std::cout << "5. Check in to a lodging\n";
    std::cout << "6. Check out of a lodging\n";
    std::cout << "7. Print the status of the agency's cars and lodgings\n";
    std::cout << "8. Exit\n";
    std::cout << "Enter your choice: ";
    std::cin >> choice;

    std::string license_plate;
    std::string id;

    switch (choice) {
      case 1:
        // Book a car
        std::cout << "Enter the license plate of the car you want to book: ";
        std::cin >> license_plate;
        agency.book_car(license_plate);
        break;
      case 2:
        // Pick up a car
        std::cout << "Enter the license plate of the car you want to pick up: ";
        std::cin >> license_plate;
        agency.pick_up_car(license_plate);
        break;
      case 3:
        // Return a car
        std::cout << "Enter the license plate of the car you want to return: ";
        std::cin >> license_plate;
        agency.return_car(license_plate);
        break;
      case 4:
        // Book a lodging
        std::cout << "Enter the ID of the lodging you want to book: ";
        std::cin >> id;
        agency.book_lodging(id);
        break;
      case 5:
        // Check in to a lodging
        std::cout << "Enter the ID of the lodging you want to check in to: ";
        std::cin >> id;
        agency.check_in_lodging(id);
        break;
      case 6:
        // Check out of a lodging
        std::cout << "Enter the ID of the lodging you want to check out of: ";
        std::cin >> id;
        agency.check_out_lodging(id);
        break;
      case 7:
        // Print the status of the agency's cars and lodgings
        agency.print_status();
        break;
      case 8:
        // Exit the program
        exit_program = true;
        break;
      default:
        std::cout << "Invalid choice. Please try again.\n";
        break;
    }
  }
}