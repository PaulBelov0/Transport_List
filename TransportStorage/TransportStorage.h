#ifndef TRANSPORTSTORAGE_H
#define TRANSPORTSTORAGE_H

#include <list>
#include <cstdint>

#include <QString>
#include <QSignalMapper>

#include "Transport/TransportBase/TransportBase.h"

// Класс хранит в себе структуру данных и имеет методы для взаимодействия с ней

class TransportStorage
{
public:

    TransportStorage(std::list<std::shared_ptr<TransportBase>> storage);

    TransportStorage(TransportStorage& storage);

    TransportStorage();

    bool findDatabaseElement(const uint32_t& index);

    void addNewElement(std::shared_ptr<TransportBase>& object);

    void deleteElement(const uint32_t& index);

    std::list<std::shared_ptr<TransportBase>>& getList();

    void insertPair(std::shared_ptr<TransportBase> object);

    bool checkListEmpty();

private:
    std::list<std::shared_ptr<TransportBase>> transportDatabase;
};

#endif // TRANSPORTSTORAGE_H
