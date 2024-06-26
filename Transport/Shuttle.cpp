#include <Transport/Shuttle.h>

//Realization Space shuttle class:

Shuttle::Shuttle(const int& ID, const QString& brand,
                 const QString& model, const int& year,
                 const int& weight,
                 const int& maxFlyingDistance,
                 const QString& fuelType
                 )
{
    uniqueID = ID;
    type = "Shuttle";
    this->brand = brand.toStdString();
    this->model = model.toStdString();
    this->year = year;
    this->weight = weight;
    this->maxFlyingDistance = maxFlyingDistance;
    this->fuelType = fuelType.toStdString();
}

Shuttle::~Shuttle() {}


void Shuttle::editSpecialFirst(const uint32_t& maxFlyingDisatnce)
{
    this->maxFlyingDistance = maxFlyingDisatnce;
}


void Shuttle::editSpecialSecond(const QString& fuelType)
{
    this->fuelType = fuelType.toStdString();
}


QVariant& Shuttle::getSpecialFirst()
{
    outputQstring = maxFlyingDistance;
    return outputQstring;
}

QVariant& Shuttle::getSpecialSecond()
{
    outputQstring = QString::fromStdString(fuelType);
    return outputQstring;
}
