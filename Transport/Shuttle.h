#ifndef SHUTTLE_H
#define SHUTTLE_H

#include "Transport/TransportBase/TransportBase.h"

// Транспортный класс реализующий космический тип транспорта

class Shuttle : public TransportBase
{
public:

    Shuttle(std::vector<std::string> args);

    Shuttle(std::shared_ptr<Shuttle> transportObject);

    uint32_t maxFlyingDistance;
    std::string fuelType;
};

#endif //SHUTTLE_H
