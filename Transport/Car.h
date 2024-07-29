
#ifndef CAR_H
#define CAR_H

#include "Transport/TransportBase/TransportBase.h"

class Car : public TransportBase
{
public:

    Car(std::vector<std::string> args);

    Car(std::shared_ptr<Car> transportObject);

    uint32_t mileage;
    uint32_t ownersQuantity;
};

#endif //CAR_H
