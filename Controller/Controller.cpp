#include "Controller/Controller.h"

Controller::Controller() : transportStorage(new TransportStorage()) // MUST BE RESET!
{

}

void Controller::addNewElement(const uint32_t& ID, const std::string& type,
                        const std::string& brand, const std::string& model,
                        const uint32_t& year, const uint32_t& weight,
                        const uint32_t& specialFieldFirst, const std::string& specialFieldSecond
                        )
{


    transportObjectCreator.reset(new TransportObjectCreator(ID, type, brand, model,
                                                            year, weight, specialFieldFirst,
                                                            specialFieldSecond
                                                            ));

    if (type == "Air")
    {
        transportStorage->addNewElement(transportObjectCreator->getTransportObject());
    }
    else if(type == "Car")
    {
        transportStorage->addNewElement(transportObjectCreator->getTransportObject());
    }
    else if(type == "Boat")
    {
        transportStorage->addNewElement(transportObjectCreator->getTransportObject());
    }
    else if (type == "Shuttle")
    {
        transportStorage->addNewElement(transportObjectCreator->getTransportObject());
    }
    transportStorage.get();
}

void Controller::addNewElement(std::vector<std::string> args)
{
    std::string type = args.at(2);
    transportObjectCreator.reset(new TransportObjectCreator(args));
    if (type == "air")
    {
        transportStorage->addNewElement(transportObjectCreator->getTransportObject());
    }
    else if(type == "car")
    {
        transportStorage->addNewElement(transportObjectCreator->getTransportObject());
    }
    else if(type == "boat")
    {
        transportStorage->addNewElement(transportObjectCreator->getTransportObject());
    }
    else if (type == "shuttle")
    {
        transportStorage->addNewElement(transportObjectCreator->getTransportObject());
    }
    transportStorage.get();
}

QString& Controller::deleteDatabaseElement(const uint32_t& ID)
{
    transportStorage->findDatabaseElement(ID);

    if (transportStorage->getMap().count(ID) != 0)
    {
        transportStorage->deleteElement(ID);
        deletingResult = "Element deleted successful!";
    }
    else
    {
        deletingResult = "Error! No one element have this ID!";
    }
    return deletingResult;
}

bool Controller::checkElementAvilable(const uint32_t& ID)
{
    bool result;

    result = transportStorage->findDatabaseElement(ID);

    return result;
}

void Controller::editElement(const uint32_t& ID, const std::string& type, const std::string& brand,
                       const std::string& model, const uint32_t& year, const uint32_t& weight,
                       const uint32_t& specialFieldFirst,  const std::string& specialFieldSecond
                       )
{

    transportStorage->deleteElement(ID);
    addNewElement(ID, type, brand, model, year, weight, specialFieldFirst, specialFieldSecond);
}


TransportStorage& Controller::getStorage()
{
    return *transportStorage;
}

void Controller::setMap(TransportStorage& inputStorage)
{
    TransportStorage transportDatabase(inputStorage);
    transportStorage = std::make_unique<TransportStorage>(transportDatabase);
}

void Controller::setID(const uint32_t& ID)
{
    uniqueID = ID;
}


uint32_t& Controller::getID()
{
    return uniqueID;
}
