//Realization of transport base type

#include "TransportBase.h"

TransportBase::TransportBase() {}
TransportBase::~TransportBase() {}

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

 uint32_t& TransportBase::getID()
 {
     return uniqueID;
 }

 QString& TransportBase::getType()
 {
     outputQstring = QString::fromStdString(type);
     return outputQstring;
 }

 QString& TransportBase::getBrand()
 {
     outputQstring = QString::fromStdString(brand);
     return outputQstring;
 }

 QString& TransportBase::getModel()
 {
     outputQstring = QString::fromStdString(model);
     return outputQstring;
 }

 uint32_t& TransportBase::getYear()
 {
     return year;
 }

 uint32_t& TransportBase::getWeight()
 {
     return weight;
 }


 void TransportBase::editSpecialFirst(const uint32_t& value) {}
 void TransportBase::editSpecialSecond(const QString& value) {}

 uint32_t& TransportBase::getSpecialFirst() {}
 QString& TransportBase::getSpecialSecond() {}
