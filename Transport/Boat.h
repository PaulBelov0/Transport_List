#ifndef BOAT_H
#define BOAT_H

#include <memory>

#include "Transport/TransportBase/TransportBase.h"

// Транспортный класс реализующий водный тип транспорта

class Boat : public TransportBase
{
public:

    Boat(std::vector<std::string> args);

    Boat(std::shared_ptr<Boat> transportObject);

    uint32_t displacement;
    uint32_t screwDepth;
};

#endif //BOAT_H
