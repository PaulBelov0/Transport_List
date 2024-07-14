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
    specialFirst = maxFlyingDistance;
    specialSecond = fuelType.toStdString();
    outputQstring = "Q";
}

Shuttle::~Shuttle() {}

void Shuttle::operator=(TransportBase& object)
{
    TransportBase::operator=(object);
    specialFirst = object.getSpecialFirst().toUInt();
    specialSecond = object.getSpecialSecond().toString().toStdString();
}

std::unique_ptr<TransportBase> Shuttle::clone() const
{
    return std::make_unique<Shuttle>(*this);
}

void Shuttle::editSpecialFirst(const uint32_t& maxFlyingDisatnce)
{
    this->specialFirst = maxFlyingDisatnce;
}


void Shuttle::editSpecialSecond(const QString& fuelType)
{
    this->specialSecond = fuelType.toStdString();
}


QVariant Shuttle::getSpecialFirst()
{
    return QString::fromStdString(std::to_string(specialFirst));
}

QVariant Shuttle::getSpecialSecond()
{
    return QString::fromStdString(specialSecond);
}
