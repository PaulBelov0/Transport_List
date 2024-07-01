#include "TransportCreator.h"

TransportCreator::TransportCreator(const uint32_t& ID, const QString& type,
                                   const QString& brand, const QString& model,
                                   const uint32_t& year, const uint32_t& weight,
                                   const uint32_t& specialFirst, const QString& specialSecond)
{
    this->ID = ID;
    this->brand = brand;
    this->model = model;
    this->year = year;
    this->weight = weight;
    this->specialFirst = specialFirst;
    this->specialSecond = specialSecond;
}


TransportBase& TransportCreator::createTransportObject()
{
    if (type == "Air")
    {
        std::string* specialFieldSecond_tmp = new std::string(specialSecond.toStdString());
        int specialSecondIntVersion = std::stoi(*specialFieldSecond_tmp);
        delete specialFieldSecond_tmp;

        AirTransport airTransportLocal(ID, brand, model, year, weight, specialFirst, specialSecondIntVersion);

        return airTransportLocal;
    }
    else if (type == "Boat")
    {
        std::string* specialFieldSecond_tmp = new std::string(specialSecond.toStdString());
        int specialSecondIntVersion = std::stoi(*specialFieldSecond_tmp);
        delete specialFieldSecond_tmp;

        Car carLocal(ID, brand, model, year, weight, specialFirst, specialSecondIntVersion);

        return carLocal;
    }
    else if (type == "Car")
    {
        std::string* specialFieldSecond_tmp = new std::string(specialSecond.toStdString());
        int specialSecondIntVersion = std::stoi(*specialFieldSecond_tmp);
        delete specialFieldSecond_tmp;

        Boat boatLocal(ID, brand, model, year, weight, specialFirst, specialSecondIntVersion);

        return boatLocal;
    }
    else if (type == "Shuttle")
    {
        Shuttle shuttleLocal(ID, brand, model, year, weight, specialFirst, specialSecond);

        return shuttleLocal;
    }
}
