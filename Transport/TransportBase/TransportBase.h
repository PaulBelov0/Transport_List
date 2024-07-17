#ifndef TRANSPORTBASE_H
#define TRANSPORTBASE_H

#include <QString>
#include <string>
#include <cstdint>
#include <QVariant>

class TransportBase
{
public:

    TransportBase(const int& ID, const QString& brand,
                  const QString& model, const int& year,
                  const int& weight
                  );
    virtual ~TransportBase();

    void editBrand(const std::string& brand);
    void editModel(const std::string& model);
    void editYear(const int& year);
    void editWeight(const int& weight);

    QVariant getID();
    virtual QVariant getType() = 0;
    QVariant getBrand();
    QVariant getModel();
    QVariant getYear();
    QVariant getWeight();
    virtual QVariant getSpecialFirst();
    virtual QVariant getSpecialSecond();


protected:

    uint32_t uniqueID;
    std::string type;
    std::string brand;
    std::string model;
    uint32_t year;
    uint32_t weight;
};

#endif //TRANSPORTBASE_H
