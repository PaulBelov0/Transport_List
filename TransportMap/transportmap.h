#ifndef TRANSPORT_MAP_H
#define TRANSPORT_MAP_H

#include <map>
#include <cstdint>
#include <memory>
#include <Transport/transport.h>
#include <Transport/TransportBase/TransportBase.h>

class TransportMap
{
public:
    TransportMap(uint32_t index);
    ~TransportMap();
private:
    std::unique_ptr<std::map<uint32_t, TransportBase&>> transportDB;
};

#endif // TRANSPORT_MAP_H
