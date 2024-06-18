#include <Transport/Boat.h>

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

std::string Boat::finderOnValueType(char typeOfValue)
{
	std::string returningValue = TransportBase::finderOnValueType(typeOfValue);

	if (returningValue == std::to_string(NULL))
	{
		if (typeOfValue == '6')
		{
			returningValue = std::to_string(displacement);
			return returningValue;
		}
		else if (typeOfValue == '7')
		{
			returningValue = std::to_string(screwDepth);
			return returningValue;
		}
	}
	else
	{
		return returningValue;
	}
}