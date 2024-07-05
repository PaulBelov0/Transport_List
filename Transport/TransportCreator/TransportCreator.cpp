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
            AirTransport air(ID, brand, model, year, weight, specialFirst, specialSecond.toUInt());
            base = air.clone();
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
            Car car(ID, brand, model, year, weight, specialFirst, specialSecond.toUInt());
            base = car.clone();
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
            Boat boat(ID, brand, model, year, weight, specialFirst, specialSecond.toUInt());
            base = boat.clone();
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
        Shuttle shuttle(ID, brand, model, year, weight, specialFirst, specialSecond);
        base = shuttle.clone();
    }
}

TransportCreator::~TransportCreator() {}

std::unique_ptr<TransportBase> TransportCreator::createTransportObject()
{
    return base->clone();
}
