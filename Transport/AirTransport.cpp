#include "Transport/TransportBase/TransportBase.h"
#include <exception>

//Realizaton air type transport class:

class AirTransport : public TransportBase
{
public:
	AirTransport() : TransportBase() override;
	~AirTransport() : ~TransportBase() override;

	inline void editWingspan();
	inline void editPayloadCapacity();
private:
	int wingspan;
	int payloadCapacity;
};

AirTransport::AirTransport(uint32_t ID)
{
	uniqueID = ID;
	type = "Air Transport Type";

	addNewData();
	editWingspan();
	editPayloadCapacity();
}

AirTransport::~AirTransport()
{

}

AirTransport::editWingspan()
{
	std::cout << "Enter the wingspan (meters) : ";
	try
	{
		std::cin >> weigth;
	}
	catch (_exception)
	{
		std::cout << "Incorrect Data!";
	}
}

AirTransport::editPayloadCapacity()
{
	std::cout << "Enter the Payload Capacity (kilograms): ";
	try
	{
		std::cin >> weigth;
	}
	catch (_exception)
	{
		std::cout << "Incorrect Data!";
	}
}