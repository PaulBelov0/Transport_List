#include <Transport/AirTransport.h>

//Realizaton air transport class:

AirTransport::AirTransport(const int& ID, const QString& brand,
                           const QString& model, const int& year,
                           const int& weight, const int& wingspan,
                           const int& payloadCapacity
                           )
{
    uniqueID = ID;
    type = "Air";
    this->brand = brand.toStdString();
    this->model = model.toStdString();
    this->year = year;
    this->weight = weight;
    this->wingspan = wingspan;
    this->payloadCapacity = payloadCapacity;
}

AirTransport::~AirTransport() {}

void AirTransport::editSpecialFirst(const uint32_t& wingspan)
{
    this->wingspan = wingspan;
}


void AirTransport::editSpecialSecond (const QString& payloadCapacity)
{
    this->payloadCapacity = payloadCapacity.toInt();
}


QVariant& AirTransport::getSpecialFirst()
{
    outputQstring = wingspan;
    return outputQstring;
}

QVariant& AirTransport::getSpecialSecond()
{
    outputQstring = payloadCapacity;
    return outputQstring;
}
