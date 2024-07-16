#include <Transport/Car.h>

//Realizatuion car type class:

Car::Car(const int& ID, const QString& brand,
         const QString& model, const int& year,
         const int& weight, const int& mileage,
         const int& ownersQuantity
         )
    : TransportBase(ID, brand, model, year, weight)
{
    type = "Car";
    this->mileage = mileage;
    this->ownersQuantity = std::stoi(std::to_string(ownersQuantity));
}

Car::Car(TransportBase* transportObject)
    : TransportBase(transportObject->getID().toUInt(), transportObject->getBrand().toString(),
                    transportObject->getModel().toString(), transportObject->getYear().toUInt(),
                    transportObject->getWeight().toUInt()
                    )
{
    type = "Car";
    mileage = transportObject->getSpecialFirst().toUInt();
    ownersQuantity = transportObject->getSpecialSecond().toUInt();
}

Car::~Car() {}

void Car::editSpecialFirst(const uint32_t& mileage)
{
    this->mileage = mileage;
}


void Car::editSpecialSecond(const QString& ownersQuantity)
{
    this->ownersQuantity = ownersQuantity.toInt();
}

// Getters:

QVariant Car::getType()
{
    return QString::fromStdString(type);
}

QVariant Car::getSpecialFirst()
{
    return QString::fromStdString(std::to_string(mileage));
}

QVariant Car::getSpecialSecond()
{
    return QString::fromStdString(std::to_string(ownersQuantity));
}
