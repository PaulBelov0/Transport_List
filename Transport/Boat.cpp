#include "Transport/TrasnportBase/TransportBase.h"
#include <exception>

class Boat : public TransportBase
{
public:
	Boat() : TransportBase() override;
	~Boat() : ~TransportBase() override;

	void editDislacement();
	void editScrewDepth();
private:
	int displacement;
	int screwDepth;
};

Boat::Boat()
{

}

Boat::~Boat()
{

}

Boat::editDisplacement()
{
	std::cout << "Enter the displacement of a boat (liters): ";
	try
	{
		std::cin >> displacement;
	}
	catch (_exception)
	{
		std::cout << "Incorrect Data!";
	}
}

Boat::editScrewDepth()
{
	std::cout << "Enter the screw depth (meters): ";
	try
	{
		std::cin >> screwDepth;
	}
	catch (_exception)
	{
		std::cout << "Incorrect Data!";
	}
}