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
    std::unique_ptr<TransportBase> clone() const override;

    QVariant& getSpecialFirst() override;
    QVariant& getSpecialSecond() override;
};

#endif //AIRTRANPORT_H
