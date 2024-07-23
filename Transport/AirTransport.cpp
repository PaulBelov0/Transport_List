#include "Transport/AirTransport.h"

//Realizaton air transport class:

AirTransport::AirTransport(const uint32_t& ID, const std::string& brand,
                           const std::string& model, const uint32_t& year,
                           const uint32_t& weight, const uint32_t& wingspan,
                           const uint32_t& payloadCapacity
                           )
    : TransportBase(ID, brand, model, year, weight)
{
    type = "Air";
    this->wingspan = wingspan;
    this->payloadCapacity = std::stoul(std::to_string(payloadCapacity));
}

AirTransport::AirTransport(std::vector<std::string> args) : TransportBase(args)
{
    type = "Air";
    wingspan = std::stoi(args[6]);
    wingspan = std::stoi(args[7]);
}

AirTransport::AirTransport(TransportBase* transportObject)
    : TransportBase(transportObject->getID(), transportObject->getBrand(),
                    transportObject->getModel(), transportObject->getYear(),
                    transportObject->getWeight()
                    )
{
    type = "Air";
    wingspan = transportObject->getSpecialFirst();
    payloadCapacity = std::stoi(transportObject->getSpecialSecond());
}

//GETTERS & SETTERS:

void AirTransport::editSpecialFirst(const uint32_t& wingspan)
{
    this->wingspan = wingspan;
}


void AirTransport::editSpecialSecond (const QString& payloadCapacity)
{
    this->payloadCapacity = payloadCapacity.toInt();
}

// Getters:

std::string AirTransport::getType()
{
    return type;
}

uint32_t AirTransport::getSpecialFirst()
{
    return wingspan;
}

std::string AirTransport::getSpecialSecond()
{
    return std::to_string(payloadCapacity);
}
