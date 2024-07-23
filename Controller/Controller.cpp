#include "Controller/Controller.h"

Controller::Controller() : transportStorage(new TransportStorage()) // MUST BE RESET!
{

}

void Controller::addNewElement(std::vector<std::string> args)
{
    std::string type = args.at(2);

    std::shared_ptr<TransportObjectCreator>transportObjectCreator(new TransportObjectCreator(args));

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

void Controller::editElement(std::vector<std::string> args)
{
    transportStorage->deleteElement(std::stoi(args[0]));
    addNewElement(args);
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
