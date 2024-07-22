#include "Transport/Boat.h"

//Realization boat class:

Boat::Boat(const uint32_t& ID, const std::string& brand,
           const std::string& model, const uint32_t& year,
           const uint32_t& weight, const uint32_t& displacement,
           const uint32_t& screwDepth
           )
    : TransportBase(ID, brand, model, year, weight)
{
    type = "Boat";
    this->displacement = displacement;
    this->screwDepth = std::stoi(std::to_string(screwDepth));
}

Boat::Boat(std::vector<std::string> args) : TransportBase(args)
{
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
