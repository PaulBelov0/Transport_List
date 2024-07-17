#ifndef TRANSPORTSTORAGE_H
#define TRANSPORTSTORAGE_H

#include <QString>
#include <map>
#include <cstdint>

#include <QSignalMapper>

#include "Transport/TransportBase/TransportBase.h"
#include "MessageToUserWindow.h"
#include "Transport/Transport.h"

class TransportStorage
{
    Q_OBJECT
public:
    TransportStorage(std::map<uint32_t, TransportBase*> map);
    TransportStorage(TransportStorage& map);

    bool findDatabaseElement(const uint32_t& index);
    void addNewElement(const TransportBase* object);
    void deleteElement(const uint32_t& index);

    std::map<uint32_t, TransportBase*> getMap();

    void insertPair(TransportBase* object);
signals:
    QSignalMapper error();
private:
    std::map<uint32_t, TransportBase*> transportDatabase;

    MessageToUserWindow messageToUserWindow;

    std::map<uint32_t, TransportBase*>::iterator iter;
};

#endif // TRANSPORTSTORAGE_H
