#include "TransportObjectCreator.h"

TransportObjectCreator::TransportObjectCreator() {}

TransportObjectCreator::TransportObjectCreator(std::vector<std::string>& args)
{
    int typeIndex = std::stoi(args[1]);
    switch(typeIndex)
    {
    case 1:
    {
        AirTransport air(args);
        base = std::make_unique<AirTransport>(air);
        break;
    }
    case 2:
    {
        Car car(args);
        base = std::make_unique<Car>(car);
        break;
    }
    case 3:
    {
        Boat boat(args);
        base = std::make_unique<Boat>(boat);
        break;
    }
    case 4:
    {
        Shuttle shuttle(args);
        base = std::make_unique<Shuttle>(shuttle);
        break;
    }
    }
}


void TransportObjectCreator::showDataErrorMessage()
{
    std::cout << "Error!" << std::endl;
}

std::shared_ptr<TransportBase> TransportObjectCreator::getTransportObject()
{
    return base;
}
