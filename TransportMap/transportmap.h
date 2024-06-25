#ifndef TRANSPORTMAP_H
#define TRANSPORTMAP_H

#include <QString>
#include <map>
#include <cstdint>
#include <memory>
#include <Transport/transport.h>
#include <Transport/TransportBase/TransportBase.h>

class TransportMap
{
public:
    TransportMap();
    ~TransportMap();

    QString* showDatabaseElement(const uint32_t& index);
    void addNewElement(uint32_t& index, TransportBase& data);
    void deleteElement(const uint32_t& index);

private:
    std::unique_ptr<std::map<uint32_t, TransportBase&>> transportDB;
};

#endif // TRANSPORTMAP_H
