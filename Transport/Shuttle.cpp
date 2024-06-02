#include <Transport/TransportBase/TransportBase.h>
#include <string>
#include <exception>
#include <iostream>

//Realization Space shuttle class:

class Shuttle : public TransportBase
{
public:
	Shuttle(uint32_t ID);
	~Shuttle();

	inline void editFuelType();
	inline void editMaxFlyingDistance();

	void def(const uint32_t) override
	{
		maxFlyingDistance = 0;
		fuelType = "None";
	}
private:
	std::string fuelType;
	int maxFlyingDistance;
};

Shuttle::Shuttle(uint32_t ID)
{
	uniqueID = ID;
	type = "Space Shuttle Type";
	if (ID == 0)
	{
		def(0);
	}
	else
	{
		addNewData();
		editFuelType();
		editMaxFlyingDistance();
	}
}

Shuttle::~Shuttle()
{

}

void Shuttle::editFuelType()
{
	std::cout << "Enter the fuel type: ";
	std::getline(std::cin, fuelType);
}

void Shuttle::editMaxFlyingDistance()
{
	std::cout << "Enter the max flying distance: ";
	try
	{
		std::cin >> maxFlyingDistance;
	}
	catch (_exception)
	{
		std::cout << "Incorrect Data!";
	}
}