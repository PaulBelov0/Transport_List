
#ifndef BOAT_H
#define BOAT_H

#include "Transport/TransportBase/TransportBase.h"

class Boat : public TransportBase
{
public:
    Boat(const int& ID, const QString& brand,
         const QString& model, const int& year,
         const int& weight, const int& displacement,
         const int& screwDepth
         );

    Boat(TransportBase* transportObject);

    void editSpecialFirst(const uint32_t& displacement);

    void editSpecialSecond(const QString& screwDepth);

    uint32_t getSpecialFirst() override;

    uint32_t getSpecialSecond() override;

    std::string getType() override;

private:
    uint32_t displacement;
    uint32_t screwDepth;
};

#endif //BOAT_H
