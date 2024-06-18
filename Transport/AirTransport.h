#pragma once

#ifndef _AIRTRANSPORT_H_
#define _AIRTRANSPORT_H_


#include <Transport/TransportBase/TransportBase.h>

class AirTransport : public TransportBase
{
public:
	AirTransport(uint32_t ID);
	~AirTransport();

	inline void editWingspan(int wingspan);
	inline void editPayloadCapacity(int payloadCapacity);
	inline void print() override;
	inline std::string finderOnValueType(char typeOfValue) override;

private:
	int wingspan;
	int payloadCapacity;
};

#endif