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
    TransportMap();
    TransportMap(TransportMap& map);
    ~TransportMap();

    bool findDatabaseElement(const uint32_t& index);
    void addNewElement(std::unique_ptr<TransportBase> element);
    void deleteElement(const uint32_t& index);

    std::map<uint32_t, std::unique_ptr<TransportBase>>& getMap();
    void setMap(std::map<uint32_t, std::unique_ptr<TransportBase>>& inputMap);

private:
    std::map<uint32_t, std::unique_ptr<TransportBase>> transportDB;

    MessageToUserWindow messageToUserWindow;
};

#endif // TRANSPORTMAP_H
