#ifndef TRANSPORTBASE_H
#define TRANSPORTBASE_H

#include <QString>
#include <string>
#include <cstdint>
#include <QVariant>

class TransportBase
{
public:

    TransportBase(const uint32_t& ID, const std::string& brand,
                  const std::string& model, const uint32_t& year,
                  const uint32_t& weight
                  );
    virtual ~TransportBase();

    void editBrand(const std::string& brand);
    void editModel(const std::string& model);
    void editYear(const int& year);
    void editWeight(const int& weight);

    uint32_t getID();
    virtual std::string getType() = 0;
    std::string getBrand();
    std::string getModel();
    uint32_t getYear();
    uint32_t getWeight();
    virtual uint32_t getSpecialFirst() = 0;
    virtual std::string getSpecialSecond() = 0;


protected:

    uint32_t uniqueID;
    std::string type;
    std::string brand;
    std::string model;
    uint32_t year;
    uint32_t weight;
};

#endif //TRANSPORTBASE_H
