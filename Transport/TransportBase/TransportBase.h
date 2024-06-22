#ifndef TRANSPORTBASE_H
#define TRANSPORTBASE_H

#include <QString>
#include <string>
#include <cstdint>

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
    virtual QString* print();

protected:

	uint32_t uniqueID;
	std::string type;
	std::string brand;
	std::string model;
	int year;
	int weight;

    std::string outputString[7];
};

#endif //TRANSPORTBASE_H
