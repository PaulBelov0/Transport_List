#include "Transport/Boat.h"

//Realization boat class:



Boat::Boat(std::vector<std::string> args) : TransportBase(args)
{
    type = "Boat";
    displacement = std::stoi(args[6]);
    screwDepth = std::stoi(args[7]);
}

Boat::Boat(TransportBase* transportObject)
    : TransportBase(transportObject->getID(), transportObject->getBrand(),
                    transportObject->getModel(), transportObject->getYear(),
                    transportObject->getWeight()
                    )
{
    type = "Boat";
    this->displacement = transportObject->getSpecialFirst();
    this->screwDepth = std::stoi(transportObject->getSpecialSecond());
}

void Boat::editSpecialFirst(const uint32_t& displacement)
{
    this->displacement = displacement;
}


void Boat::editSpecialSecond(const QString& screwDepth)
{
    this->screwDepth = screwDepth.toInt();
}

// Getters:

std::string Boat::getType()
{
    return type;
}

uint32_t Boat::getSpecialFirst()
{
    return displacement;
}

std::string Boat::getSpecialSecond()
{
    return std::to_string(screwDepth);
}
