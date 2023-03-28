#ifndef POO_FICHA_6_2_HOTELROOM_H_
#define POO_FICHA_6_2_HOTELROOM_H_

#include "Lodging.h"

class HotelRoom : public Lodging {
 public:
  HotelRoom(const std::string &id, const std::string &location, double daily_price, RoomType room_type);

  RoomType get_room_type() const;

 private:
  RoomType room_type;
};

#endif  // POO_FICHA_6_2_HOTELROOM_H_