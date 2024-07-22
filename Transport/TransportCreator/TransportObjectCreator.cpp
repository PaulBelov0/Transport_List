#include "TransportObjectCreator.h"

TransportObjectCreator::TransportObjectCreator() {}

TransportObjectCreator::TransportObjectCreator(std::vector<std::string> args)
{
    try
    {
        if (args[1] == "1")
        {
            AirTransport air(args);
            base = std::make_unique<AirTransport>(air);

        }
        else if(args[1] == "2")
        {
            Car car(args);
            base = std::make_unique<Car>(car);

        }
        else if(args[1] == "3")
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

TransportObjectCreator::TransportObjectCreator(const uint32_t& ID, const std::string& type,
                                               const std::string& brand, const std::string& model,
                                               const uint32_t& year, const uint32_t& weight,
                                               const uint32_t& specialFieldFirst, const std::string& specialFieldSecond
                                               )
{
    try
    {
        if (type == "Air")
        {
            AirTransport air(ID, brand, model, year, weight, specialFieldFirst, std::stoi(specialFieldSecond));
            base = std::make_unique<AirTransport>(air);

        }
        else if(type == "Car")
        {
            Car car(ID, brand, model, year, weight, specialFieldFirst, std::stoi(specialFieldSecond));
            base = std::make_unique<Car>(car);

        }
        else if(type == "Boat")
        {
            Boat boat(ID, brand, model, year, weight, specialFieldFirst, std::stoi(specialFieldSecond));
            base = std::make_unique<Boat>(boat);

        }
        else
        {
            Shuttle shuttle(ID, brand, model, year, weight, specialFieldFirst, specialFieldSecond);
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

std::shared_ptr<TransportBase> TransportObjectCreator::getTransportObject()
{
    return base;
}
