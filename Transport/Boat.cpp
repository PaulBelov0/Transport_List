#include "Transport/Boat.h"

//Realization boat class:



Boat::Boat(std::vector<std::string> args) : TransportBase(args)
{
    type = "Boat";
    displacement = std::stoi(args[6]);
    screwDepth = std::stoi(args[7]);
}

Boat::Boat(std::shared_ptr<Boat> transportObject)
    : TransportBase(transportObject->uniqueID, transportObject->brand,
                    transportObject->model, transportObject->year,
                    transportObject->weight
                    )
{
    type = "Boat";
    this->displacement = transportObject->displacement;
    this->screwDepth = transportObject->screwDepth;
}
