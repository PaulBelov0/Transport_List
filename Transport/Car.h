
#ifndef CAR_H
#define CAR_H

#include "Transport/TransportBase/TransportBase.h"

class Car : public TransportBase
{
public:
    Car(const uint32_t& ID, const std::string& brand,
             const std::string& model, const uint32_t& year,
             const uint32_t& weight, const uint32_t& mileage,
             const uint32_t& ownersQuantity
             );

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
