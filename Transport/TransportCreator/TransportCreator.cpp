#include "TransportCreator.h"

TransportCreator::TransportCreator(const uint32_t& ID, const QString& type,
                                   const QString& brand, const QString& model,
                                   const uint32_t& year, const uint32_t& weight,
                                   const uint32_t& specialFirst, const QString& specialSecond)
{
    if (type == "Air")
    {
        try
        {
            base = new AirTransport(ID, brand, model, year, weight, specialFirst, specialSecond.toUInt());
        }
        catch (const std::invalid_argument& e)
        {
            MessageToUserWindow message;
            message.show();
            message.setTextMessage("ERROR!\nWorng input data in <Special 2> field!");
        }
    }
    else if(type == "Car")
    {
        try
        {
            base = new Car(ID, brand, model, year, weight, specialFirst, specialSecond.toUInt());
        }
        catch (const std::invalid_argument& e)
        {
            MessageToUserWindow message;
            message.show();
            message.setTextMessage("ERROR!\nWorng input data in <Special 2> field!");
        }
    }
    else if(type == "Boat")
    {
        try
        {
            base = new Boat(ID, brand, model, year, weight, specialFirst, specialSecond.toUInt());
        }
        catch (const std::invalid_argument& e)
        {
            MessageToUserWindow message;
            message.show();
            message.setTextMessage("ERROR!\nWorng input data in <Special 2> field!");
        }
    }
    else
    {
        base = new Shuttle(ID, brand, model, year, weight, specialFirst, specialSecond);
    }
}

TransportCreator::~TransportCreator() { delete base; }

TransportBase& TransportCreator::createTransportObject()
{
    return *base;
}
