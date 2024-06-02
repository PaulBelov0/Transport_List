#include <Transport/TransportBase/TransportBase.h>
#include <exception>
#include <iostream>
//Realizaton air type transport class:

class AirTransport : public TransportBase
{
public:
	AirTransport(uint32_t ID);
	~AirTransport();

	inline void editWingspan();
	inline void editPayloadCapacity();

	void def(const uint32_t) override
	{
		wingspan = 0;
		payloadCapacity = 0;
	}
private:
	int wingspan;
	int payloadCapacity;
};

AirTransport::AirTransport(uint32_t ID)
{
	uniqueID = ID;
	type = "Air Transport Type";
	if (ID == 0)
	{
		def(0);
	}
	else
	{
		addNewData();
		editWingspan();
		editPayloadCapacity();
	}
}

AirTransport::~AirTransport()
{

}

void AirTransport::editWingspan()
{
	std::cout << "Enter the wingspan (meters) : ";
	try
	{
		std::cin >> wingspan;
	}
	catch (_exception)
	{
		std::cout << "Incorrect Data!";
	}
}

void AirTransport::editPayloadCapacity()
{
	std::cout << "Enter the Payload Capacity (kilograms): ";
	try
	{
		std::cin >> payloadCapacity;
	}
	catch (_exception)
	{
		std::cout << "Incorrect Data!";
	}
}