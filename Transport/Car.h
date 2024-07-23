
#ifndef CAR_H
#define CAR_H

#include "Transport/TransportBase/TransportBase.h"

class Car : public TransportBase
{
public:

    Car(std::vector<std::string> args);

    Car(TransportBase* transportObject);

    void editSpecialFirst(const uint32_t& mileage);
    void editSpecialSecond(const QString& ownersQuantity);

    uint32_t getSpecialFirst();

    std::string getSpecialSecond();

    std::string getType();

private:
    uint32_t mileage;
    uint32_t ownersQuantity;
};

#endif //CAR_H
