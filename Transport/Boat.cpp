#include <transport.h>

//Realization boat class:

Boat::Boat(uint32_t ID)
{
	uniqueID = ID;
	type = "Water Transport";
}

Boat::~Boat()
{

}

void Boat::editDisplacement(int displacement)
{
	this->displacement = displacement;
}

void Boat::editScrewDepth(int screwDepth)
{
	this->screwDepth = screwDepth;
}