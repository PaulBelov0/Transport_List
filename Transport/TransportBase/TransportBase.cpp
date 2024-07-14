//Realization of transport base type

#include "TransportBase.h"

TransportBase::TransportBase() {}
TransportBase::~TransportBase() {}

void TransportBase::operator=(TransportBase& object)
{
    uniqueID = object.getID().toUInt();
    type = object.getType().toString().toStdString();
    brand = object.getBrand().toString().toStdString();
    model = object.getModel().toString().toStdString();
    year = object.getYear().toUInt();
    weight = object.getWeight().toUInt();
    specialFirst = object.getSpecialFirst().toInt();
    specialSecond = object.getSpecialSecond().toString().toStdString();
}

 void TransportBase::editBrand(const std::string& brand)
{
	 this->brand = brand;
}


 void TransportBase::editModel(const std::string& model)
 {
	 this->model = model;
 }


 void TransportBase::editYear(const int& year)
 {
	 this->year = year;
 }

 void TransportBase::editWeight(const int& weight)
 {
	 this->weight = weight;
 }

 QVariant TransportBase::getID()
 {
     return QString::fromStdString(std::to_string(uniqueID));
 }

 QVariant TransportBase::getType()
 {
     return QString::fromStdString(type);
 }

 QVariant TransportBase::getBrand()
 {
     return QString::fromStdString(brand);
 }

 QVariant TransportBase::getModel()
 {
     return QString::fromStdString(model);
 }

 QVariant TransportBase::getYear()
 {
     return QString::fromStdString(std::to_string(year));
 }

 QVariant TransportBase::getWeight()
 {
     return QString::fromStdString(std::to_string(weight));
 }


 void TransportBase::editSpecialFirst(const uint32_t& value)
 {
     specialFirst = value;
 }

 void TransportBase::editSpecialSecond(const QString& value)
 {
     specialSecond = value.toStdString();
 }

 QVariant TransportBase::getSpecialFirst()
 {
     return QString::fromStdString(std::to_string(specialFirst));
 }

 QVariant TransportBase::getSpecialSecond()
 {
     return QString::fromStdString(specialSecond);
 }
