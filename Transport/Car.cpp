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
    this->mileage = mileage;
    ownersQuantity = owners;
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

QVariant& Car::getSpecialFirst()
{
    outputQstring = mileage;
    return outputQstring;
}

QVariant& Car::getSpecialSecond()
{
    outputQstring = ownersQuantity;
    return outputQstring;
}
