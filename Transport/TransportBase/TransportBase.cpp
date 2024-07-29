//Realization of transport base type

#include "TransportBase.h"

TransportBase::TransportBase(const uint32_t& ID, const std::string& brand,
                             const std::string& model, const uint32_t& year,
                             const uint32_t& weight
                             )
{
    uniqueID = ID;
    this->brand = brand;
    this->model = model;
    this->year = year;
    this->weight = weight;
}

TransportBase::TransportBase(std::vector<std::string> args)
{
    uniqueID = std::stoi(args[0]);
    this->brand = args[2];
    this->model = args[3];
    this->year = std::stoi(args[4]);
    this->weight = std::stoi(args[5]);
}

TransportBase::~TransportBase() {}
