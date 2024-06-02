#include "Transport/TrasnportBase/TransportBase.cpp"
#include <exception>

//Realization boat class:

class Boat : public TransportBase
{
public:
	Boat() : TransportBase() override;
	~Boat() : ~TransportBase() override;

	inline void editDisplacement();
	inline void editScrewDepth();
private:
	int displacement;
	int screwDepth;
};

Boat::Boat(uint32_t ID)
{
	uniqueID = ID;
	type = "Water Transport Type";

	addNewData();
	editDisplacement();
	editScrewDepth();
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