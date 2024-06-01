#include "Transport/TrasnportBase/TransportBase.h"
#include <exception>

class Car : public TransportBase
{
public:
	Car() : TransportBase() override;
	~Car() : ~TransportBase() override;

	void editOwnersQuantity();
	void editMileage();
private:
	int ownersQuantity;
	int mileage;
};

Car::Car()
{

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