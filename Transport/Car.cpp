#include <Transport/Car.h>
//Realizatuion car type class:

Car::Car(const int& ID, const QString& brand,
         const QString& model, const int& year,
         const int& weight, const int& mileage,
         const int& owners
         )
{
	uniqueID = ID;
	type = "Car";
    this->brand = brand.toStdString();
    this->model = model.toStdString();
    this->year = year;
    this->weight = weight;
    specialFirst = mileage;
    specialSecond = std::to_string(owners);
    outputQstring = "Q";
}

Car::~Car() {}

void Car::operator=(TransportBase& object)
{
    TransportBase::operator=(object);
    specialFirst = object.getSpecialFirst().toUInt();
    specialSecond = object.getSpecialSecond().toUInt();
}

std::unique_ptr<TransportBase> Car::clone() const
{
    return std::make_unique<Car>(*this);
}


void Car::editSpecialFirst(const uint32_t& mileage)
{
    this->specialFirst = mileage;
}


void Car::editSpecialSecond(const QString& ownersQuantity)
{
    specialSecond = ownersQuantity.toInt();
}

QVariant Car::getSpecialFirst()
{
    return QString::fromStdString(std::to_string(specialFirst));
}

QVariant Car::getSpecialSecond()
{
    return QString::fromStdString(specialSecond);
}
