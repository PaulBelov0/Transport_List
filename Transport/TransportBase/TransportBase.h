#ifndef TRANSPORTBASE_H
#define TRANSPORTBASE_H

#include <QString>
#include <string>
#include <cstdint>
#include <QVariant>

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

    QVariant& getID();
    QVariant& getType();
    QVariant& getBrand();
    QVariant& getModel();
    QVariant& getYear();
    QVariant& getWeight();
    virtual QVariant& getSpecialFirst();
    virtual QVariant& getSpecialSecond();


protected:

	uint32_t uniqueID;
    std::string type;
    std::string brand;
    std::string model;
    uint32_t year;
    uint32_t weight;

    QVariant outputQstring;
};

#endif //TRANSPORTBASE_H
