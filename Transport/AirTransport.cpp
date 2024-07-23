#include "Transport/AirTransport.h"

//Realizaton air transport class:

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
