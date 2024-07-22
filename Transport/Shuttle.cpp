#include "Transport/Shuttle.h"

//Realization Space shuttle class:


//CONSTRUCTORS:


Shuttle::Shuttle(std::vector<std::string> args) : TransportBase(args)
{
    type = "Shuttle";
    maxFlyingDistance = std::stoi(args[6]);
    fuelType = args[7];
}

Shuttle::Shuttle(TransportBase* transportObject)
    : TransportBase(transportObject->getID(), transportObject->getBrand(),
                    transportObject->getModel(), transportObject->getYear(),
                    transportObject->getWeight()
                    )
{
    type = "Shuttle";
    maxFlyingDistance = transportObject->getSpecialFirst();
    fuelType = transportObject->getSpecialSecond();
}

//GETTERS & SETTERS:

void Shuttle::editSpecialFirst(const uint32_t& maxFlyingDisatnce)
{
    this->maxFlyingDistance = maxFlyingDisatnce;
}


void Shuttle::editSpecialSecond(const QString& fuelType)
{
    this->fuelType = fuelType.toStdString();
}

// Getters:

std::string Shuttle::getType()
{
    return type;
}

uint32_t Shuttle::getSpecialFirst()
{
    return maxFlyingDistance;
}

std::string Shuttle::getSpecialSecond()
{
    return fuelType;
}
