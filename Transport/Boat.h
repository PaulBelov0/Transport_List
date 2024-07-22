
#ifndef BOAT_H
#define BOAT_H

#include "Transport/TransportBase/TransportBase.h"

class Boat : public TransportBase
{
public:

    Boat(std::vector<std::string> args);

    Boat(TransportBase* transportObject);

    void editSpecialFirst(const uint32_t& displacement);

    void editSpecialSecond(const QString& screwDepth);

    uint32_t getSpecialFirst() override;

    std::string getSpecialSecond() override;

    std::string getType() override;

private:
    uint32_t displacement;
    uint32_t screwDepth;
};

#endif //BOAT_H
