//Realization of transport base type

#include "TransportBase.h"

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

 QString* TransportBase::print()
 {
     QString* output = new QString[7];
     outputString[0] = "ID : #";
     outputString[0] += uniqueID;
     outputString[1] = "Brand: " + brand;
     outputString[2] = "Model: " + model;
     outputString[3] = "Year: ";
     outputString[3] += year;
     outputString[4] = "Weight: ";
     outputString[4] += weight;

     for (int i = 0; i < 5; i++)
     {
         output[i] = QString::fromStdString(outputString[i]);
     }

     return output;
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
