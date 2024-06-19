#ifndef _TRANSPORTBASE_H_
#define _TRANSPORTBASE_H_

#include <string>
#include <iostream>
#include <exception>
#include <cstdint>
#include <fstream>

class TransportBase
{
public:
	TransportBase();
	virtual ~TransportBase() = 0;

	void editBrand(std::string brand);
	void editModel(std::string model);
	void editYear(int year);
	void editWeight(int weight);

	std::string virtual finderOnValueType(char typeOfValue);
	void virtual defaultElement(const uint32_t ID);
	void virtual print();
	void virtual uploadBase();

protected:

	uint32_t uniqueID;
	std::string type;
	std::string brand;
	std::string model;
	int year;
	int weight;

};

#endif