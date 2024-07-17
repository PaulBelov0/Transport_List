
#ifndef CAR_H
#define CAR_H

#include "Transport/TransportBase/TransportBase.h"

class Car : public TransportBase
{
public:
    Car(const int& ID, const QString& brand,
        const QString& model, const int& year,
        const int& weight, const int& mileage,
        const int& owners
        );

    Car(TransportBase* transportObject);

    void editSpecialFirst(const uint32_t& mileage);
    void editSpecialSecond(const QString& ownersQuantity);
    //std::unique_ptr<TransportBase> clone() const override;

    uint32_t getSpecialFirst() override;
    uint32_t getSpecialSecond() override;
    std::string getType() override;

private:
    uint32_t mileage;
    uint32_t ownersQuantity;
};

#endif //CAR_H
