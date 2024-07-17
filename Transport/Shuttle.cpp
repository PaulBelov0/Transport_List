#include "Transport/Shuttle.h"

//Realization Space shuttle class:

Shuttle::Shuttle(const int& ID, const QString& brand,
                 const QString& model, const int& year,
                 const int& weight,
                 const int& maxFlyingDistance,
                 const QString& fuelType
                 )
    : TransportBase(ID, brand, model, year, weight)
{
    type = "Shuttle";
    this->maxFlyingDistance = maxFlyingDistance;
    this->fuelType = fuelType.toStdString();
}

Shuttle::Shuttle(TransportBase* transportObject)
    : TransportBase(transportObject->getID().toUInt(), transportObject->getBrand().toString(),
                    transportObject->getModel().toString(), transportObject->getYear().toUInt(),
                    transportObject->getWeight().toUInt()
                    )
{
    type = "Shuttle";
    maxFlyingDistance = transportObject->getSpecialFirst().toUInt();
    fuelType = transportObject->getSpecialSecond().toString().toStdString();
}


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
