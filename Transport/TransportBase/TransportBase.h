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
    TransportBase(std::vector<std::string> args);

    virtual ~TransportBase();

    uint32_t uniqueID;
    std::string type;
    std::string brand;
    std::string model;
    uint32_t year;
    uint32_t weight;
};

#endif //TRANSPORTBASE_H
