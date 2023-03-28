#ifndef POO_FICHA_6_2_LODGING_H_
#define POO_FICHA_6_2_LODGING_H_

#include <string>

class Lodging {
 public:
  Lodging(const std::string &id, const std::string &location, double daily_price);

  void book();
  void check_in();
  void check_out();

  std::string get_id() const;
  std::string get_location() const;
  double get_daily_price() const;
  bool is_available() const;

 private:
  std::string id;
  std::string location;
  double daily_price;
  bool available;
};

#endif  // POO_FICHA_6_2_LODGING_H_