#include <Transport/transport.h>

//Realization boat class:

Boat::Boat(uint32_t ID)
{
	uniqueID = ID;
	type = "Water Transport";
}

Boat::~Boat() {}

void Boat::editDisplacement(int displacement)
{
	this->displacement = displacement;
}

void Boat::editScrewDepth(int screwDepth)
{
	this->screwDepth = screwDepth;
}

void Boat::print()
{
	TransportBase::print();
	std::cout << "Displacement: " << displacement << std::endl;
	std::cout << "Screw depth: " << screwDepth << std::endl;
}