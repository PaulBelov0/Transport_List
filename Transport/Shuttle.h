
#ifndef SHUTTLE_H
#define SHUTTLE_H

#include "Transport/TransportBase/TransportBase.h"

class Shuttle : public TransportBase
{
public:

    Shuttle(std::vector<std::string> args);

    Shuttle(std::shared_ptr<Shuttle> transportObject);

    uint32_t maxFlyingDistance;
    std::string fuelType;
};

#endif //SHUTTLE_H
