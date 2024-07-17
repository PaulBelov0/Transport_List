#ifndef TRANSPORTSTORAGE_H
#define TRANSPORTSTORAGE_H

#include <QString>
#include <map>
#include <cstdint>

#include "Transport/TransportBase/TransportBase.h"
#include "MessageToUserWindow.h"
#include "Transport/Transport.h"

class TransportMap
{
public:
    TransportMap(std::map<uint32_t, TransportBase*> map);
    TransportMap(TransportMap& map);
    ~TransportMap();

    bool findDatabaseElement(const uint32_t& index);
    void addNewElement(const TransportBase* object);
    void deleteElement(const uint32_t& index);

    std::map<uint32_t, TransportBase*> getMap();

    void insertPair(TransportBase* object);

private:
    std::map<uint32_t, TransportBase*> transportDatabase;

    MessageToUserWindow messageToUserWindow;

    std::map<uint32_t, TransportBase*>::iterator iter;
};

#endif // TRANSPORTSTORAGE_H
