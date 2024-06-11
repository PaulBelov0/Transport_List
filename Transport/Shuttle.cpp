#include <Transport/transport.h>

//Realization Space shuttle class:

Shuttle::Shuttle(uint32_t ID)
{
	uniqueID = ID;
	type = "Space Shuttle";
}

Shuttle::~Shuttle() {}

void Shuttle::editFuelType(std::string fuelType)
{
	this->fuelType = fuelType;
}

void Shuttle::editMaxFlyingDistance(int maxFlyingDistance)
{
	this->maxFlyingDistance = maxFlyingDistance;
}

void Shuttle::print()
{
	TransportBase::print();
	std::cout << "Fuel type: " << fuelType << std::endl;
	std::cout << "Max flying distance: " << maxFlyingDistance << std::endl;
}