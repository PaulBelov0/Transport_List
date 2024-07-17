
#ifndef SHUTTLE_H
#define SHUTTLE_H

#include "Transport/TransportBase/TransportBase.h"

class Shuttle : public TransportBase
{
public:
    Shuttle(const int& ID, const QString& brand,
            const QString& model, const int& year,
            const int& weight,
            const int& maxFlyingDistance,
            const QString& fuelType
            );

    Shuttle(TransportBase* transportObject);

    void editSpecialFirst(const uint32_t& maxFlyingDistance);

    void editSpecialSecond(const QString& fuelType);

    uint32_t getSpecialFirst() override;

    std::string getSpecialSecond() override;

    std::string getType() override;

private:
    uint32_t maxFlyingDistance;
    std::string fuelType;
};

#endif //SHUTTLE_H
