#include <iostream>
#include <string>
#include <vector>

enum class CarClass { LUXURY, ECONOMY, FAMILY };
enum class FuelType { PETROL, DIESEL, ELECTRIC, HYBRID };
enum class RoomType { SINGLE, DOUBLE, TRIPLE };

class Car {
 public:
  Car(const std::string &license_plate, CarClass car_class, FuelType fuel_type, double daily_price)
      : license_plate(license_plate), car_class(car_class), fuel_type(fuel_type), daily_price(daily_price), available(true) {}

  void book() { available = false; }
  void pick_up() { available = false; }
  void return_car() { available = true; }

  std::string get_license_plate() const { return license_plate; }
  CarClass get_car_class() const { return car_class; }
  FuelType get_fuel_type() const { return fuel_type; }
  double get_daily_price() const { return daily_price; }
  bool is_available() const { return available; }

 private:
  std::string license_plate;
  CarClass car_class;
  FuelType fuel_type;
  double daily_price;
  bool available;
};

class Lodging {
 public:
  Lodging(const std::string &id, const std::string &location, double daily_price)
      : id(id), location(location), daily_price(daily_price), available(true) {}

  void book() { available = false; }
  void check_in() { available = false; }
  void check_out() { available = true; }

  std::string get_id() const { return id; }
  std::string get_location() const { return location; }
  double get_daily_price() const { return daily_price; }
  bool is_available() const { return available; }

 private:
  std::string id;
  std::string location;
  double daily_price;
  bool available;
};

class Apartment : public Lodging {
 public:
  Apartment(const std::string &id, const std::string &location, double daily_price, int num_rooms)
      : Lodging(id, location, daily_price), num_rooms(num_rooms) {}

  int get_num_rooms() const { return num_rooms; }

 private:
  int num_rooms;
};

class HotelRoom : public Lodging {
 public:
  HotelRoom(const std::string &id, const std::string &location, double daily_price, RoomType room_type)
      : Lodging(id, location, daily_price), room_type(room_type) {}

  RoomType get_room_type() const { return room_type; }

 private:
  RoomType room_type;
};

class TravelAgency {
 public:
  TravelAgency(const std::string &name, const std::string &address) : name(name), address(address) {}

  void add_car(Car car) { cars.push_back(car); }
  void add_apartment(Apartment apartment) { apartments.push_back(apartment); }
  void add_hotel_room(HotelRoom hotel_room) { hotel_rooms.push_back(hotel_room); }

  std::vector<Lodging *> get_all_lodgings() {
    std::vector<Lodging *> all_lodgings;
    for (Apartment &apartment : apartments) {
      all_lodgings.push_back(&apartment);
    }
    for (HotelRoom &hotel_room : hotel_rooms) {
      all_lodgings.push_back(&hotel_room);
    }
    return all_lodgings;
  }

  void book_car(const std::string &license_plate) {
    for (Car &car : cars) {
      if (car.get_license_plate() == license_plate && car.is_available()) {
        car.book();
        std::cout << "Car booked successfully.\n";
        return;
      }
    }
    std::cout << "Car not found or unavailable.\n";
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
 private:
  std::string name;
  std::string address;
  std::vector<Car> cars;
  std::vector<Apartment> apartments;
  std::vector<HotelRoom> hotel_rooms;
};

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

  return 0;
}