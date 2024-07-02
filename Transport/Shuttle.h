#pragma once

#ifndef SHUTTLE_H
#define SHUTTLE_H

#include <Transport/TransportBase/TransportBase.h>

class Shuttle : public TransportBase
{
public:
    Shuttle(const int& ID, const QString& brand,
            const QString& model, const int& year,
            const int& weight,
            const int& maxFlyingDistance,
            const QString& fuelType
            );
	~Shuttle();

    void editSpecialFirst(const uint32_t& maxFlyingDistance) override;
    void editSpecialSecond(const QString& fuelType) override;

    QVariant& getSpecialFirst() override;
    QVariant& getSpecialSecond() override;

private:
    uint32_t maxFlyingDistance;
    std::string fuelType;
};

#endif //SHUTTLE_H
