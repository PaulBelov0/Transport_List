#pragma once

#ifndef AIRTRANSPORT_H
#define AIRTRANSPORT_H

#include <Transport/TransportBase/TransportBase.h>

class AirTransport : public TransportBase
{
public:
	AirTransport(uint32_t ID);
	~AirTransport();

    void editWingspan(int wingspan);
    void editPayloadCapacity(int payloadCapacity);
    QString* print() override;
    std::string finderOnValueType(char typeOfValue) override;

private:
	int wingspan;
	int payloadCapacity;
};

#endif //AIRTRANPORT_H
