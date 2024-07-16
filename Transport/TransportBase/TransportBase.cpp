//Realization of transport base type

#include "TransportBase.h"

TransportBase::TransportBase(const int& ID, const QString& brand,
                             const QString& model, const int& year,
                             const int& weight
                             )
{
    uniqueID = ID;
    this->brand = brand.toStdString();
    this->model = model.toStdString();
    this->year = year;
    this->weight = weight;
}
TransportBase::~TransportBase() {}

void TransportBase::operator=(TransportBase& object)
{
    uniqueID = object.getID().toUInt();
    type = object.getType().toString().toStdString();
    brand = object.getBrand().toString().toStdString();
    model = object.getModel().toString().toStdString();
    year = object.getYear().toUInt();
    weight = object.getWeight().toUInt();
}

// Setters / editors :

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

 // Getters :

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

 QVariant TransportBase::getSpecialFirst() { return " ";}

 QVariant TransportBase::getSpecialSecond() { return " "; }

