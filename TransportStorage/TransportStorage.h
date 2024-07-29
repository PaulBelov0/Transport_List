#ifndef TRANSPORTSTORAGE_H
#define TRANSPORTSTORAGE_H

#include <list>
#include <cstdint>

#include <QString>
#include <QSignalMapper>

#include "Transport/TransportBase/TransportBase.h"
#include "Transport/TransportCreator/TransportObjectCreator.h"
#include "MessageToUserWindow.h"

class TransportStorage
{
public:

    TransportStorage(std::list<std::shared_ptr<TransportBase>> storage);

    TransportStorage(const TransportStorage& storage);

    TransportStorage();

    bool findDatabaseElement(const uint32_t& index);

    void addNewElement(std::shared_ptr<TransportBase>& object);

    void deleteElement(const uint32_t& index);

    std::list<std::shared_ptr<TransportBase>>& getList();

    bool checkListEmpty();

private:
    std::list<std::shared_ptr<TransportBase>> transportDatabase;
    MessageToUserWindow* messageToUserWindow;
};

#endif // TRANSPORTSTORAGE_H
