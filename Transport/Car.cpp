#include "Transport/TransportBase/TransportBase.h"
#include <exception>
#include <iostream>

//Realizatuion car type class:

class Car : public TransportBase
{
public:
	Car(uint32_t ID);
	~Car();

	inline void editOwnersQuantity();
	inline void editMileage();

	void def(const uint32_t) override
	{
		mileage = 0;
		ownersQuantity = 0;
	}
private:

	int ownersQuantity;
	int mileage;
};

Car::Car(uint32_t ID)
{
	type = "Car Type";
	uniqueID = ID;
	if (ID == 0)
	{
		def(0);
	}
	else
	{
		addNewData();
		editOwnersQuantity();
		editMileage();
	}
}

Car::~Car()
{

}

void Car::editMileage()
{
	std::cout << "Enter the mileage (kilometers): ";
	try
	{
		std::cin >> weigth;
	}
	catch (_exception)
	{
		std::cout << "Incorrect Data!";
	}
}

void Car::editOwnersQuantity()
{
	std::cout << "Enter the number of owner: ";
	try
	{
		std::cin >> weigth;
	}
	catch (_exception)
	{
		std::cout << "Incorrect Data!";
	}
}