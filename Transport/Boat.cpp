#include <Transport/TransportBase/TransportBase.h>
#include <exception>
#include <iostream>

//Realization boat class:

class Boat : public TransportBase
{
public:
	Boat(uint32_t ID);
	~Boat();

	inline void editDisplacement();
	inline void editScrewDepth();

	void def(const uint32_t) override
	{
		TransportBase::def(0);
		displacement = 0;
		screwDepth = 0;
	}

	void printElements() override
	{
		TransportBase::printElements();
		std::cout << "Water displacement : " << displacement << std::endl;
		std::cout << "Screw depth : " << screwDepth << "\n\n" << std::endl;
	}

private:
	int displacement;
	int screwDepth;
};

Boat::Boat(uint32_t ID)
{
	uniqueID = ID;
	type = "Water Transport Type";

	if (ID == 0)
	{
		def(0);
	}
	else
	{
		addNewData();
		editDisplacement();
		editScrewDepth();
	}
}

Boat::~Boat()
{

}

void Boat::editDisplacement()
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

void Boat::editScrewDepth()
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