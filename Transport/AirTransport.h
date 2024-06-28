#pragma once

#ifndef AIRTRANSPORT_H
#define AIRTRANSPORT_H

#include <Transport/TransportBase/TransportBase.h>

class AirTransport : public TransportBase
{
public:
    AirTransport(const int& ID, const QString& brand,
                 const QString& model, const int& year,
                 const int& weight, const int& wingspan,
                 const int& payloadCapacity
                 );
	~AirTransport();

    void editSpecialFirst(const uint32_t& wingspan) override;
    void editSpecialSecond(const QString& payloadCapacity) override;

    uint32_t& getSpecialFirst() override;
    QString& getSpecialSecond() override;

private:
    uint32_t wingspan;
    uint32_t payloadCapacity;
};

#endif //AIRTRANPORT_H
