//Realization of transport base type

#include "TransportBase.h"

void TransportBase::defaultElement(const uint32_t)
{
	uniqueID = 0;
	type = "None";
	brand = "None";
	model = "None";
	year = 0;
	weight = 0;
}

TransportBase::TransportBase() {}

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

 void TransportBase::print()
 {
	 std::cout << "ID : #" << uniqueID << std::endl;
	 std::cout << "Brand : " << brand << std::endl;
	 std::cout << "Model : " << model << std::endl;
	 std::cout << "Year : " << year << std::endl;
	 std::cout << "Weight : " << weight << std::endl;
 }

 void TransportBase::uploadBase()
 {
	 
 }

 std::string TransportBase::finderOnValueType(char typeOfValue)
 {
	 std::string returningValue;

	 if (typeOfValue == '1')
	 {
		 returningValue = std::to_string(uniqueID);
		 return returningValue;
	 }
	 else if (typeOfValue == '2')
	 {
		 returningValue = brand;
		 return returningValue;
	 }
	 else if (typeOfValue == '3')
	 {
		 returningValue = model;
		 return returningValue;
	 }
	 else if (typeOfValue == '4')
	 {
		 returningValue == std::to_string(year);
		 return returningValue;
	 }
	 else if (typeOfValue == '5')
	 {
		 returningValue == std::to_string(weight);
		 return returningValue;
	 }
	 else
	 {
		 return std::to_string(NULL);
	 }
 }