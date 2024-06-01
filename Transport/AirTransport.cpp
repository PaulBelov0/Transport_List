#include "Transport/TransportBase/TransportBase.h"
#include <exception>

class AirTransport : public TransportBase
{
public:
	AirTransport() : TransportBase() override;
	~AirTransport() : ~TransportBase() override;

	void editWingspan();
	void editPayloadCapacity();
private:
	int wingspan;
	int payloadCapacity;
};

AirTransport::AirTransport()
{

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