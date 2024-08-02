#ifndef AIRTRANSPORT_H
#define AIRTRANSPORT_H

#include <memory>

#include "Transport/TransportBase/TransportBase.h"

// Транспортный класс реализующий воздушный тип транспорта

class AirTransport : public TransportBase
{
public:

    AirTransport(std::vector<std::string> args);

    AirTransport(std::shared_ptr<AirTransport> transportObject);

    AirTransport(AirTransport* transportObject);

    uint32_t wingspan;
    uint32_t payloadCapacity;
};

#endif //AIRTRANPORT_H
