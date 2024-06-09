#include <transport.h>
//Realizaton air transport class:

AirTransport::AirTransport(uint32_t ID)
{
	uniqueID = ID;
	type = "Air Transport";
}

AirTransport::~AirTransport()
{

}

void AirTransport::editWingspan(int wingspan)
{
	this->wingspan = wingspan;
}

void AirTransport::editPayloadCapacity(int payloadCapacity)
{
	this->payloadCapacity = payloadCapacity;
}