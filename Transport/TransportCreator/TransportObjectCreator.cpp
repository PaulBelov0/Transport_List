#include "TransportObjectCreator.h"

TransportObjectCreator::TransportObjectCreator(const uint32_t& ID, const QString& type,
                                               const QString& brand, const QString& model,
                                               const uint32_t& year, const uint32_t& weight,
                                               const uint32_t& specialFirst, const QString& specialSecond
                                               )
{
    if (type == "Air")
    {
        try
        {
            AirTransport air(ID, brand, model, year, weight, specialFirst, specialSecond.toUInt());
            *base = air;
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
            *base = car;
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
            *base = boat;
        }
        catch (const std::invalid_argument& e)
        {
            showDataErrorMessage();
        }
    }
    else
    {
        Shuttle shuttle(ID, brand, model, year, weight, specialFirst, specialSecond);
        *base = shuttle;
    }
}

TransportObjectCreator::~TransportObjectCreator() {}

void TransportObjectCreator::showDataErrorMessage()
{
    MessageToUserWindow message;
    message.show();
    message.setTextMessage("ERROR!\nWorng input data in <Special 2> field!");
}

std::unique_ptr<TransportBase> TransportObjectCreator::getTransportObject()
{
    return base->clone();
}
