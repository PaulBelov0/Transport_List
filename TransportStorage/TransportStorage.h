#ifndef TRANSPORTSTORAGE_H
#define TRANSPORTSTORAGE_H

#include <map>
#include <cstdint>

#include <QString>
#include <QSignalMapper>

#include "Transport/TransportBase/TransportBase.h"
#include "MessageToUserWindow.h"

class TransportStorage
{
public:
    TransportStorage(std::map<uint32_t, TransportBase*> map);
    TransportStorage(TransportStorage& map);

    bool findDatabaseElement(const uint32_t& index);
    void addNewElement(TransportBase* object);
    void deleteElement(const uint32_t& index);

    std::map<uint32_t, TransportBase*> getMap();

    void insertPair(TransportBase* object);
// signals:
//     QSignalMapper error();
private:
    std::map<uint32_t, TransportBase*> transportDatabase;

    MessageToUserWindow messageToUserWindow;
};

#endif // TRANSPORTSTORAGE_H
