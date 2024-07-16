#include "TransportObjectCreator.h"

TransportObjectCreator::TransportObjectCreator(const uint32_t ID, const QString type,
                                               const QString brand, const QString model,
                                               const uint32_t year, const uint32_t weight,
                                               const uint32_t specialFirst, const QString specialSecond
                                               )
{
    if (type == "Air")
    {
        try
        {
            AirTransport air(ID, brand, model, year, weight, specialFirst, specialSecond.toUInt());
            base = std::make_unique<AirTransport>(air);
        }
        catch (const std::invalid_argument& e)
        {
            showDataErrorMessage();
        }
    }
    else if(type == "Car")
    {
        try
        {
            Car car(ID, brand, model, year, weight, specialFirst, specialSecond.toUInt());
            base = std::make_unique<Car>(car);
        }
        catch (const std::invalid_argument& e)
        {
            showDataErrorMessage();
        }
    }
    else if(type == "Boat")
    {
        try
        {
            Boat boat(ID, brand, model, year, weight, specialFirst, specialSecond.toUInt());
            base = std::make_unique<Boat>(boat);
        }
        catch (const std::invalid_argument& e)
        {
            showDataErrorMessage();
        }
    }
    else
    {
        Shuttle shuttle(ID, brand, model, year, weight, specialFirst, specialSecond);
        base = std::make_unique<Shuttle>(shuttle);
    }
}

TransportObjectCreator::~TransportObjectCreator() {}

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
