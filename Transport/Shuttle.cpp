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

std::string Shuttle::finderOnValueType(char typeOfValue)
{
	std::string returningValue = TransportBase::finderOnValueType(typeOfValue);

	if (returningValue == std::to_string(NULL))
	{
		if (typeOfValue == '6')
		{
			returningValue = fuelType;
			return returningValue;
		}
		else if (typeOfValue == '7')
		{
			returningValue = std::to_string(maxFlyingDistance);
			return returningValue;
		}
	}
	else
	{
		return returningValue;
	}
}