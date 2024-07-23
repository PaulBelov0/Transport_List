#pragma once

#ifndef AIRTRANSPORT_H
#define AIRTRANSPORT_H

#include "Transport/TransportBase/TransportBase.h"

class AirTransport : public TransportBase
{
public:
    AirTransport(const uint32_t& ID, const std::string& brand,
                 const std::string& model, const uint32_t& year,
                 const uint32_t& weight, const uint32_t& wingspan,
                 const uint32_t& payloadCapacity
                 );

    AirTransport(std::vector<std::string> args);

    AirTransport(TransportBase* transportObject);

    void editSpecialFirst(const uint32_t& wingspan);

    void editSpecialSecond(const QString& payloadCapacity);

    uint32_t getSpecialFirst() override;

    std::string getSpecialSecond() override;

    std::string getType() override;

private:
    uint32_t wingspan;
    uint32_t payloadCapacity;
};

#endif //AIRTRANPORT_H
