#include "Transport/AirTransport.h"

//Realizaton air transport class:

AirTransport::AirTransport(const int& ID, const QString& brand,
                           const QString& model, const int& year,
                           const int& weight, const int& wingspan,
                           const int& payloadCapacity
                           )
    : TransportBase(ID, brand, model, year, weight)
{
    type = "Air";
    this->wingspan = wingspan;
    this->payloadCapacity = std::stoul(std::to_string(payloadCapacity));
}

AirTransport::AirTransport(TransportBase* transportObject)
    : TransportBase(transportObject->getID().toUInt(), transportObject->getBrand().toString(),
                    transportObject->getModel().toString(), transportObject->getYear().toUInt(),
                    transportObject->getWeight().toUInt()
                    )
{
    type = "Air";
    wingspan = transportObject->getSpecialFirst().toUInt();
    payloadCapacity = transportObject->getSpecialSecond().toUInt();
}


void AirTransport::editSpecialFirst(const uint32_t& wingspan)
{
    this->wingspan = wingspan;
}


void AirTransport::editSpecialSecond (const QString& payloadCapacity)
{
    this->payloadCapacity = payloadCapacity.toInt();
}

// Getters:

QVariant AirTransport::getType()
{
    return QString::fromStdString(type);
}

uint32_t AirTransport::getSpecialFirst()
{
    return wingspan;
}

uint32_t AirTransport::getSpecialSecond()
{
    return payloadCapacity;
}
