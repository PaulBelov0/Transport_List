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

    AirTransport(TransportBase* transportObject);

	~AirTransport();

    void editSpecialFirst(const uint32_t& wingspan);

    void editSpecialSecond(const QString& payloadCapacity);

    QVariant getSpecialFirst() override;

    QVariant getSpecialSecond() override;

    QVariant getType() override;

private:
    uint32_t wingspan;
    uint64_t payloadCapacity;
};

#endif //AIRTRANPORT_H
