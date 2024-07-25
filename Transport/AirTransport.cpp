#include "Transport/AirTransport.h"

//Realizaton air transport class:


AirTransport::AirTransport(std::vector<std::string> args) : TransportBase(args)
{
    type = "Air";
    wingspan = std::stoi(args[6]);
    wingspan = std::stoi(args[7]);
}
AirTransport::AirTransport(std::shared_ptr<AirTransport> transportObject)
    : TransportBase(transportObject->uniqueID, transportObject->brand,
                    transportObject->model, transportObject->year,
                    transportObject->weight
                    )
{
    type = "Air";
    this->wingspan = transportObject->wingspan;
    this->payloadCapacity = transportObject->payloadCapacity;
}

