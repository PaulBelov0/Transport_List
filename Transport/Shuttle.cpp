#include "Transport/Shuttle.h"

//Realization Space shuttle class:

Shuttle::Shuttle(const uint32_t& ID, const std::string& brand,
                 const std::string& model, const uint32_t& year,
                 const uint32_t& weight,
                 const uint32_t& maxFlyingDistance,
                 const std::string& fuelType
                 )
    : TransportBase(ID, brand, model, year, weight)
{
    type = "Shuttle";
    this->maxFlyingDistance = maxFlyingDistance;
    this->fuelType = fuelType;
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
