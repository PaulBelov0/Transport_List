#include "TransportObjectCreator.h"

TransportObjectCreator::TransportObjectCreator() {}

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
    MessageToUserWindow message;
    message.show();
    message.setTextMessage("ERROR!\nWorng input data in <Special 2> field!");
}

TransportBase* TransportObjectCreator::getTransportObject()
{
    return base.get();
}
