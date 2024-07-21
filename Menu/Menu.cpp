#include "Menu/Menu.h"

Menu::Menu()
{
    messageToUserWindow = new MessageToUserWindow();
}

Menu::~Menu()
{
    delete messageToUserWindow;
}

int Menu::addNewElement(const uint32_t& ID, const std::string& type,
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
    transportObjectCreator.get();
    return 0;
}

QString& Menu::deleteDatabaseElement(const uint32_t& ID)
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

bool Menu::checkElementAvilable(const uint32_t& ID)
{
    bool result;

    result = transportStorage->findDatabaseElement(ID);

    return result;
}

void Menu::editElement(const uint32_t& ID, const std::string& type, const std::string& brand,
                       const std::string& model, const uint32_t& year, const uint32_t& weight,
                       const uint32_t& specialFieldFirst,  const std::string& specialFieldSecond
                       )
{

    transportStorage->deleteElement(ID);
    addNewElement(ID, type, brand, model, year, weight, specialFieldFirst, specialFieldSecond);
}


TransportStorage& Menu::getStorage()
{
    return *transportStorage;
}

void Menu::setMap(TransportStorage& inputStorage)
{
        TransportStorage transportDatabase(inputStorage);
        transportStorage = std::make_unique<TransportStorage>(transportDatabase);
}

void Menu::setID(const uint32_t& ID)
{
    uniqueID = ID;
}


uint32_t& Menu::getID()
{
    return uniqueID;
}
