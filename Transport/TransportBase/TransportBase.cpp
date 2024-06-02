//Realization of transport base type

//#ifndef STRING_H
//#define STRING_H

#include <string>
#include <iostream>
#include <exception>
#include <cstdint>

class TransportBase
{
public:
	TransportBase();
	virtual ~TransportBase() = 0;

	inline void editBrand();
	inline void editModel();
	inline void editYear() noexcept;
	inline void editWeigth() noexcept;
	void virtual def(const uint32_t);

	uint32_t uniqueID;
	std::string type;

protected:
	void addNewData();
	std::string brand;
	std::string model;
	int year;
	int weight;

};

void TransportBase::def(const uint32_t)
{
	uniqueID = 0;
	type = "None";
	brand = "None";
	model = "None";
	year = 0;
	weight = 0;
}

TransportBase::TransportBase()
{
	
}

 void TransportBase::editBrand()
{
	 std::cout << "Enter the Label: ";
	 std::getline(std::cin, brand);
}


 void TransportBase::editModel()
 {
	 std::cout << "Enter the Model: ";
	 std::getline(std::cin, brand);
 }


 void TransportBase::editYear()
 {
	 std::cout << "Enter the year of manufacturing: ";
	 try
	 {
		 std::cin >> weight;
	 }
	 catch (_exception)
	 {
		 std::cout << "Incorrect Data!";
	 }
 }

 void TransportBase::editWeigth()
 {
	 std::cout << "Enter the Weigth (killograms) : ";
	 try
	 {
		 std::cin >> weight;
	 }
	 catch (_exception)
	 {
		 std::cout << "Incorrect Data!";
	 }
 }

 void TransportBase::addNewData()
 {
	 editBrand();
	 editModel();
	 editYear();
	 editWeigth();
 }
//
//#endif