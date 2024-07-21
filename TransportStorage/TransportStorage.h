#ifndef TRANSPORTSTORAGE_H
#define TRANSPORTSTORAGE_H

#include <map>
#include <cstdint>

#include <QString>
#include <QSignalMapper>

#include "Transport/TransportBase/TransportBase.h"

class TransportStorage
{
public:
    TransportStorage(std::map<uint32_t, std::shared_ptr<TransportBase>> map);
    TransportStorage(TransportStorage& map);
    TransportStorage();

    bool findDatabaseElement(const uint32_t& index);
    void addNewElement(std::shared_ptr<TransportBase> object);
    void deleteElement(const uint32_t& index);

    std::map<uint32_t, std::shared_ptr<TransportBase>> getMap();

    void insertPair(std::shared_ptr<TransportBase> object);

    bool checkMapEmpty();
// signals:
//     QSignalMapper error();
private:
    std::map<uint32_t, std::shared_ptr<TransportBase>> transportDatabase;
};

#endif // TRANSPORTSTORAGE_H
