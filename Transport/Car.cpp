#include "Transport/Car.h"

//Realizatuion car type class:


//CONSTRUCTORS:


Car::Car(std::vector<std::string> args) : TransportBase(args)
{
    type = "Car";
    mileage = std::stoi(args[5]);
    ownersQuantity = std::stoi(args[6]);
}

Car::Car(std::shared_ptr<Car> transportObject)
    : TransportBase(transportObject->uniqueID, transportObject->brand,
                    transportObject->model, transportObject->year,
                    transportObject->weight
                    )
{
    type = "Car";
    this->mileage = transportObject->mileage;
    this->ownersQuantity = transportObject->ownersQuantity;
}
