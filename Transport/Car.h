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
	~Car();

    void operator=(TransportBase& object) override;
    void editSpecialFirst(const uint32_t& mileage) override;
    void editSpecialSecond(const QString& ownersQuantity) override;
    std::unique_ptr<TransportBase> clone() const override;

    QVariant getSpecialFirst() override;
    QVariant getSpecialSecond() override;
};

#endif //CAR_H
