#pragma once

#ifndef CAR_H
#define CAR_H

#include <Transport/TransportBase/TransportBase.h>

class Car : public TransportBase
{
public:
    Car(const int& ID, const QString& brand,
        const QString& model, const int& year,
        const int& weight, const int& mileage,
        const int& owners
        );

    Car(TransportBase* transportObject);

	~Car();

    void operator=(TransportBase& object) override;
    void editSpecialFirst(const uint32_t& mileage);
    void editSpecialSecond(const QString& ownersQuantity);
    std::unique_ptr<TransportBase> clone() const override;

    QVariant getSpecialFirst() override;
    QVariant getSpecialSecond() override;

private:
    uint32_t mileage;
    uint32_t ownersQuantity;
};

#endif //CAR_H
