#include "Menu/Menu.h"

Menu::Menu()
{
    messageToUserWindow = new MessageToUserWindow();
}

Menu::~Menu()
{
    delete messageToUserWindow;
}

int Menu::addNewElement(const uint32_t& ID, const QString& type,
                        const QString& brand, const QString& model,
                        const uint32_t& year, const uint32_t& weight,
                        const uint32_t& specialFieldFirst, const QString& specialFieldSecond
                        )
{


    TransportObjectCreator* transportObject(ID, type, brand, model, 
                                            year, weight, specialFieldFirst, 
                                            specialFieldSecond
                                            );

    if (type == "Air")
    {
        transportStorage->addNewElement(transportObject->getTransportObject());
    }
    else if(type == "Car")
    {
        transportStorage->addNewElement(transportObject->getTransportObject());
    }
    else if(type == "Boat")
    {
        transportStorage->addNewElement(transportObject->getTransportObject());
    }
    else if (type == "Shuttle")
    {
        transportStorage->addNewElement(transportObject->getTransportObject());
    }

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

void Menu::editElement(const uint32_t& ID, const QString& type, const QString& brand,
                       const QString& model, const uint32_t& year, const uint32_t& weight,
                       const uint32_t& specialFieldFirst,  const QString& specialFieldSecond
                       )
{

    transportStorage->deleteElement(ID);
    addNewElement(ID, type, brand, model, year, weight, specialFieldFirst, specialFieldSecond);
}


TransportStorage& Menu::getMap()
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
