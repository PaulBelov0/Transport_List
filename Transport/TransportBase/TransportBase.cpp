//Realization of transport base type

#include "TransportBase.h"

TransportBase::TransportBase() {}
TransportBase::~TransportBase() {}

 void TransportBase::editBrand(std::string brand)
{
	 this->brand = brand;
}


 void TransportBase::editModel(std::string model)
 {
	 this->model = model;
 }


 void TransportBase::editYear(int year) 
 {
	 this->year = year;
 }

 void TransportBase::editWeight(int weight)
 {
	 this->weight = weight;
 }

 QString* TransportBase::print()
 {
     QString* output = new QString[7];
     outputString[0] = uniqueID;
     outputString[1] = brand;
     outputString[2] = model;
     outputString[3] = year;
     outputString[4] = weight;

     for (int i = 0; i < 5; i++)
     {
         output[i] = QString::fromStdString(outputString[i]);
     }

     return output;
 }

