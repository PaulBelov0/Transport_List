#include <Transport/transport.h>

//Realizatuion car type class:

Car::Car(uint32_t ID)
{
	uniqueID = ID;
	type = "Car";
}

Car::~Car() {}

void Car::editMileage(int mileage)
{
	this->mileage = mileage;
}

void Car::editOwnersQuantity(int ownersQuantity)
{
	this->ownersQuantity = ownersQuantity;
}

void Car::print()
{
	TransportBase::print();
	std::cout << "Mileage: " << mileage << std::endl;
	std::cout << "Owners quantity: " << ownersQuantity << std::endl;
}

std::string Car::finderOnValueType(char typeOfValue)
{
	std::string returningValue = TransportBase::finderOnValueType(typeOfValue);

	if (returningValue == std::to_string(NULL))
	{
		if (typeOfValue == '6')
		{
			returningValue = std::to_string(mileage);
			return returningValue;
		}
		else if (typeOfValue == '7')
		{
			returningValue = std::to_string(ownersQuantity);
		}
	}
	else
	{
		return returningValue;
	}
}