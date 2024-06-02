#include "Transport/TrasnportBase/TransportBase.h"
#include <exception>

//Realizatuion car type class:

class Car : public TransportBase
{
public:
	Car() : TransportBase() override;
	~Car() : ~TransportBase() override;

	inline void editOwnersQuantity();
	inline void editMileage();

private:

	int ownersQuantity;
	int mileage;
};

Car::Car(uint32_t ID)
{
	type = "Car Type";
	uniqueID = ID;

	addNewData();
	editOwnersQuantity();
	editMileage();
}

Car::~Car()
{

}

Car::editMileage()
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

Car::editOwnersQuantity()
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