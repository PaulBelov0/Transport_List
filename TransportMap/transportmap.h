#ifndef TRANSPORTMAP_H
#define TRANSPORTMAP_H

#include <QString>
#include <map>
#include <cstdint>
#include <memory>
#include <Transport/transport.h>
#include <Transport/TransportBase/TransportBase.h>
#include <MessageToUserWindow.h>

class TransportMap
{
public:
    TransportMap();
    ~TransportMap();

    bool findDatabaseElement(const uint32_t& index);
    void addNewElement(uint32_t index, TransportBase& data);
    void deleteElement(const uint32_t& index);

    std::map<uint32_t, TransportBase&>& getMap();
    void setMap(std::map<uint32_t, TransportBase&> inputMap);

private:
    std::map<uint32_t, TransportBase&>* transportDB;

    MessageToUserWindow messageToUserWindow;
};

#endif // TRANSPORTMAP_H
