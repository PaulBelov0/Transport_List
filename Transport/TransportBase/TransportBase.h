#ifndef TRANSPORTBASE_H
#define TRANSPORTBASE_H

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

	inline void editBrand(std::string brand);
	inline void editModel(std::string model);
	inline void editYear(int year);
	inline void editWeight(int weight);
	void virtual defaultElement(const uint32_t ID);
	void virtual print();
	void virtual write();

protected:

	uint32_t uniqueID;
	std::string type;
	std::string brand;
	std::string model;
	int year;
	int weight;

};

#endif