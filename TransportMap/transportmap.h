#ifndef TRANSPORT_MAP_H
#define TRANSPORT_MAP_H
#include <Transport/transport.h>

class TransportMap
{
public:
    TransportMap();
    ~TransportMap();
private:
    std::map<uint32_t, TransportBase&> transportDB;
};

#endif // TRANSPORT_MAP_H
