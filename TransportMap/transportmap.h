#ifndef TRANSPORTMAP_H
#define TRANSPORTMAP_H

#include <QString>
#include <QPair>
#include <map>
#include <cstdint>
#include <Transport/transport.h>
#include <Transport/TransportBase/TransportBase.h>
#include <MessageToUserWindow.h>

class TransportMap
{
public:
    TransportMap(std::map<uint32_t, std::unique_ptr<TransportBase>> map);
    TransportMap(TransportMap& map);
    ~TransportMap();

    bool findDatabaseElement(const uint32_t& index);
    void addNewElement(const std::unique_ptr<TransportBase> object);
    void deleteElement(const uint32_t& index);

    std::map<uint32_t, std::unique_ptr<TransportBase>> getMap();

    void insertPair(TransportBase* object);

private:
    std::map<uint32_t, TransportBase*> transportDatabase;

    MessageToUserWindow messageToUserWindow;

    std::map<uint32_t, TransportBase*>::iterator iter;
};

#endif // TRANSPORTMAP_H
