#include <Transport/AirTransport.h>

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

AirTransport::~AirTransport() {}

void AirTransport::operator=(TransportBase& object)
{
    TransportBase::operator=(object);
    wingspan = object.getSpecialFirst().toUInt();
    payloadCapacity = object.getSpecialSecond().toUInt();
}

std::unique_ptr<TransportBase> AirTransport::clone() const
{
    return std::make_unique<AirTransport>(*this);
}

void AirTransport::editSpecialFirst(const uint32_t& wingspan)
{
    this->wingspan = wingspan;
}


void AirTransport::editSpecialSecond (const QString& payloadCapacity)
{
    this->payloadCapacity = payloadCapacity.toInt();
}


QVariant AirTransport::getSpecialFirst()
{
    return QString::fromStdString(std::to_string(wingspan));
}

QVariant AirTransport::getSpecialSecond()
{
    return QString::fromStdString(std::to_string(payloadCapacity));
}
