#include "TransportObjectCreator.h"

TransportObjectCreator::TransportObjectCreator() {}

TransportObjectCreator::TransportObjectCreator(std::vector<std::string>& args)
{
    try
    {
        if (args[1] == "1" || "Air")
        {
            AirTransport air(args);
            base = std::make_unique<AirTransport>(air);

        }
        else if(args[1] == "2" || "Car")
        {
            Car car(args);
            base = std::make_unique<Car>(car);

        }
        else if(args[1] == "3" || "Boat")
        {
            Boat boat(args);
            base = std::make_unique<Boat>(boat);

        }
        else
        {
            Shuttle shuttle(args);
            base = std::make_unique<Shuttle>(shuttle);
        }
    }
    catch (const std::invalid_argument &e)
    {
        showDataErrorMessage();
    }
}


void TransportObjectCreator::showDataErrorMessage()
{
    std::cout << "Error!" << std::endl;
}

std::shared_ptr<TransportBase>& TransportObjectCreator::getTransportObject()
{
    return base;
}
