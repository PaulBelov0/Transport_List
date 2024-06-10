#include "Transport/TransportBase/TransportBase.h"
#include <exception>
#include <iostream>

//Realizatuion car type class:

#include <transport.h>

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