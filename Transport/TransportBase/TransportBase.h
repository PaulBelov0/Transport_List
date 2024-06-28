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

    void editBrand(const std::string& brand);
    void editModel(const std::string& model);
    void editYear(const int& year);
    void editWeight(const int& weight);
    virtual void editSpecialFirst(const uint32_t& inputValue);
    virtual void editSpecialSecond(const QString& inputValue);

    uint32_t& getID();
    QString& getType();
    QString& getBrand();
    QString& getModel();
    uint32_t& getYear();
    uint32_t& getWeight();
    virtual uint32_t& getSpecialFirst();
    virtual QString& getSpecialSecond();


protected:

	uint32_t uniqueID;
	std::string type;
	std::string brand;
	std::string model;
    uint32_t year;
    uint32_t weight;

    QString outputQstring;
};

#endif //TRANSPORTBASE_H
