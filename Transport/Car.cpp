#include <transport.h>

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