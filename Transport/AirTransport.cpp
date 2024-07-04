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
    specialFirst = wingspan;
    specialSecond = std::to_string(payloadCapacity);
    outputQstring = "Q";
}

AirTransport::~AirTransport() {}

void AirTransport::editSpecialFirst(const uint32_t& wingspan)
{
    this->specialFirst = wingspan;
}


void AirTransport::editSpecialSecond (const QString& payloadCapacity)
{
    this->specialSecond = payloadCapacity.toInt();
}


QVariant& AirTransport::getSpecialFirst()
{
    outputQstring = specialFirst;
    return outputQstring;
}

QVariant& AirTransport::getSpecialSecond()
{
    outputQstring = QString::fromStdString(specialSecond);
    return outputQstring;
}
