#include "Transport/Shuttle.h"

//Realization Space shuttle class:


//CONSTRUCTORS:


Shuttle::Shuttle(std::vector<std::string> args) : TransportBase(args)
{
    type = "Shuttle";
    maxFlyingDistance = std::stoi(args[5]);
    fuelType = args[6];
}

Shuttle::Shuttle(std::shared_ptr<Shuttle> transportObject)
    : TransportBase(transportObject->uniqueID, transportObject->brand,
                    transportObject->model, transportObject->year,
                    transportObject->weight
                    )
{
    type = "Shuttle";
    this->maxFlyingDistance = transportObject->maxFlyingDistance;
    this->fuelType = transportObject->fuelType;
}
