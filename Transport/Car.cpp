#include "Car.h"

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

QString* Car::print()
{
    QString* output = new QString [7];

    TransportBase::print();

    outputString[5] = "Mileage: ";
    outputString[5] += mileage;
    outputString[6] = "Owners quantity: ";
    outputString[6] += ownersQuantity;

    for (int i = 5; i < 7; i++)
    {
        output[7] = QString::fromStdString(outputString[i]);
    }

    return output;
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
