#ifndef TRANSPORTMAP_H
#define TRANSPORTMAP_H

#include <QString>
#include <QPair>
#include <map>
#include <cstdint>
#include <Transport/transport.h>
#include <Transport/TransportBase/TransportBase.h>
#include <MessageToUserWindow.h>
#include <initializer_list>

class TransportMap
{
public:
    TransportMap();
    TransportMap(TransportMap& map);
    ~TransportMap();

    bool findDatabaseElement(const uint32_t& index);
    void addNewElement(uint32_t key, TransportBase& element);
    void deleteElement(const uint32_t& index);

    std::map<uint32_t, TransportBase&>& getMap();
    void setMap(std::map<uint32_t, TransportBase&>& inputMap);

private:
    std::map<uint32_t, TransportBase&> transportDB;

    MessageToUserWindow messageToUserWindow;
};

#endif // TRANSPORTMAP_H
