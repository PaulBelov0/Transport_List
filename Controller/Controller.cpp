#include "Controller/Controller.h"

Controller::Controller(const TransportStorage& storage) : transportStorage(new TransportStorage(storage)) {}

void Controller::addNewElement(std::vector<std::string>& args)
{
    std::shared_ptr<TransportObjectCreator>transportObjectCreator(new TransportObjectCreator(args));

    transportStorage->addNewElement(transportObjectCreator->getTransportObject());
}

QString& Controller::deleteDatabaseElement(const uint32_t& ID)
{
    if (transportStorage->findDatabaseElement(ID) != true)
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
    return transportStorage->findDatabaseElement(ID);
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

void Controller::setList(const TransportStorage& inputStorage)
{
    //TODO:
    transportStorage.reset(new TransportStorage(inputStorage));
}

void Controller::setID(const uint32_t& ID)
{
    uniqueID = ID;
}


uint32_t& Controller::getID()
{
    return uniqueID;
}
