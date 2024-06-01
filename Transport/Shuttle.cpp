#include "Transport/TrasnportBase/TransportBase.h"
#include <string>
#include <exception>

class Shuttle : public TransportBase
{
public:
	Shuttle() : TransportBase() override;
	~Shuttle() : ~TransportBase() override;

	void editFuelType();
	void editMaxFlyingDistance();
private:
	std::string fuelType;
	int maxFlyingDistance;
};

Shuttle::Shuttle()
{

}

Shuttle::~Shuttle()
{

}

Shuttle::editFuelType()
{
	std::cout << "Enter the fuel type: ";
	std::getline(std::cin, fuelType);
}

Shuttle::editMaxFlyingDistance()
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