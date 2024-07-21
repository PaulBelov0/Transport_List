//Realization of transport base type

#include "TransportBase.h"

TransportBase::TransportBase(const uint32_t& ID, const std::string& brand,
                             const std::string& model, const uint32_t& year,
                             const uint32_t& weight
                             )
{
    uniqueID = ID;
    this->brand = brand;
    this->model = model;
    this->year = year;
    this->weight = weight;
}
TransportBase::~TransportBase() {}


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

 uint32_t TransportBase::getID()
 {
     return uniqueID;
 }

 std::string TransportBase::getBrand()
 {
     return brand;
 }

 std::string TransportBase::getModel()
 {
     return model;
 }

 uint32_t TransportBase::getYear()
 {
     return year;
 }

 uint32_t TransportBase::getWeight()
 {
     return weight;
 }

