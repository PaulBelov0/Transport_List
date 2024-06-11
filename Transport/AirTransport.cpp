#include <Transport/transport.h>
//Realizaton air transport class:

AirTransport::AirTransport(uint32_t ID)
{
	uniqueID = ID;
	type = "Air Transport";
}

AirTransport::~AirTransport() {}

void AirTransport::editWingspan(int wingspan)
{
	this->wingspan = wingspan;
}

void AirTransport::editPayloadCapacity(int payloadCapacity)
{
	this->payloadCapacity = payloadCapacity;
}

void AirTransport::print()
{
	TransportBase::print();
	std::cout << "Wingspan: " << wingspan << std::endl;
	std::cout << "Payload capacity: " << payloadCapacity << std::endl;
}

std::string AirTransport::finderOnValueType(char typeOfValue)
{
	std::string returningValue = TransportBase::finderOnValueType(typeOfValue);

	if (returningValue == std::to_string(NULL))
	{
		if (typeOfValue == '6')
		{
			returningValue = std::to_string(wingspan);
			return returningValue;
		}
		else if (typeOfValue == '7')
		{
			returningValue = std::to_string(payloadCapacity);
		}
	}
	else
	{
		return returningValue;
	}
}