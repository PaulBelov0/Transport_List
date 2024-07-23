#include "Transport/Car.h"

//Realizatuion car type class:

Car::Car(const uint32_t& ID, const std::string& brand,
         const std::string& model, const uint32_t& year,
         const uint32_t& weight, const uint32_t& mileage,
         const uint32_t& ownersQuantity
         )
    : TransportBase(ID, brand, model, year, weight)
{
    type = "Car";
    this->mileage = mileage;
    this->ownersQuantity = std::stoi(std::to_string(ownersQuantity));
}

Car::Car(std::vector<std::string> args) : TransportBase(args)
{
    type = "Car";
    mileage = std::stoi(args[6]);
    ownersQuantity = std::stoi(args[7]);
}

Car::Car(TransportBase* transportObject)
    : TransportBase(transportObject->getID(), transportObject->getBrand(),
                    transportObject->getModel(), transportObject->getYear(),
                    transportObject->getWeight()
                    )
{
    type = "Car";
    mileage = transportObject->getSpecialFirst();
    ownersQuantity = std::stoi(transportObject->getSpecialSecond());
}

//GETTERS & SETTERS:

void Car::editSpecialFirst(const uint32_t& mileage)
{
    this->mileage = mileage;
}


void Car::editSpecialSecond(const QString& ownersQuantity)
{
    this->ownersQuantity = ownersQuantity.toInt();
}

// Getters:

std::string Car::getType()
{
    return type;
}

uint32_t Car::getSpecialFirst()
{
    return mileage;
}

std::string Car::getSpecialSecond()
{
    return std::to_string(ownersQuantity);
}
