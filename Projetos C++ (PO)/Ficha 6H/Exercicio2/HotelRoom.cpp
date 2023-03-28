#include "HotelRoom.h"

HotelRoom::HotelRoom(const std::string &id, const std::string &location, double daily_price, RoomType room_type)
    : Lodging(id, location, daily_price), room_type(room_type) {}

RoomType HotelRoom::get_room_type() const { return room_type; }