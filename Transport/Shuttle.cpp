#include <Transport/Shuttle.h>

//Realization Space shuttle class:

Shuttle::Shuttle(const int& ID, const QString& brand,
                 const QString& model, const int& year,
                 const int& weight,
                 const int& maxFlyingDistance,
                 const QString& fuelType
                 )
    : TransportBase(ID, brand, model, year, weight)
{
    type = "Shuttle";
    this->maxFlyingDistance = maxFlyingDistance;
    this->fuelType = fuelType.toStdString();
}

Shuttle::Shuttle(TransportBase* transportObject)
    : TransportBase(transportObject->getID().toUInt(), transportObject->getBrand().toString(),
                    transportObject->getModel().toString(), transportObject->getYear().toUInt(),
                    transportObject->getWeight().toUInt()
                    )
{
    type = "Shuttle";
    maxFlyingDistance = transportObject->getSpecialFirst().toUInt();
    fuelType = transportObject->getSpecialSecond().toString().toStdString();
}

Shuttle::~Shuttle() {}

void Shuttle::operator=(TransportBase& object)
{
    TransportBase::operator=(object);
    maxFlyingDistance = object.getSpecialFirst().toUInt();
    fuelType = object.getSpecialSecond().toString().toStdString();
}

std::unique_ptr<TransportBase> Shuttle::clone() const
{
    return std::make_unique<Shuttle>(*this);
}

void Shuttle::editSpecialFirst(const uint32_t& maxFlyingDisatnce)
{
    this->maxFlyingDistance = maxFlyingDisatnce;
}


void Shuttle::editSpecialSecond(const QString& fuelType)
{
    this->fuelType = fuelType.toStdString();
}


QVariant Shuttle::getSpecialFirst()
{
    return QString::fromStdString(std::to_string(maxFlyingDistance));
}

QVariant Shuttle::getSpecialSecond()
{
    return QString::fromStdString(fuelType);
}
