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

 QVariant& TransportBase::getID()
 {
     outputQstring = uniqueID;
     return outputQstring;
 }

 QVariant& TransportBase::getType()
 {
     outputQstring = QString::fromStdString(type);
     return outputQstring;
 }

 QVariant& TransportBase::getBrand()
 {
     outputQstring = QString::fromStdString(brand);
     return outputQstring;
 }

 QVariant& TransportBase::getModel()
 {
     outputQstring = QString::fromStdString(model);
     return outputQstring;
 }

 QVariant& TransportBase::getYear()
 {
     outputQstring = year;
     return outputQstring;
 }

 QVariant& TransportBase::getWeight()
 {
     outputQstring = weight;
     return outputQstring;
 }


 void TransportBase::editSpecialFirst(const uint32_t& value) {}
 void TransportBase::editSpecialSecond(const QString& value) {}

 QVariant& TransportBase::getSpecialFirst() {}
 QVariant& TransportBase::getSpecialSecond() {}
