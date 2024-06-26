#include <Transport/Shuttle.h>

//Realization Space shuttle class:

Shuttle::Shuttle(uint32_t ID)
{
	uniqueID = ID;
	type = "Space Shuttle";
}

Shuttle::~Shuttle() {}

void Shuttle::editFuelType(std::string fuelType)
{
	this->fuelType = fuelType;
}

void Shuttle::editMaxFlyingDistance(int maxFlyingDistance)
{
	this->maxFlyingDistance = maxFlyingDistance;
}

QString* Shuttle::print()
{
    QString* output = new QString [7];

    TransportBase::print();

    outputString[5] = "Fuel type: ";
    outputString[5] += fuelType;
    outputString[6] = "Max flying distance: ";
    outputString[6] += maxFlyingDistance;

    for (int i = 5; i < 7; i++)
    {
        output[7] = QString::fromStdString(outputString[i]);
    }

    return output;
}

