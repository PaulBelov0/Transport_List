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
        transportMap->addNewElement(transportObject.getTransportObject());
    }
    else if(type == "Car")
    {
        transportMap->addNewElement(transportObject.getTransportObject());
    }
    else if(type == "Boat")
    {
        transportMap->addNewElement(transportObject.getTransportObject());
    }
    else if (type == "Shuttle")
    {
        transportMap->addNewElement(transportObject.getTransportObject());
    }

    return 0;
}

QString& Menu::deleteDatabaseElement(const uint32_t& ID)
{
    transportMap->findDatabaseElement(ID);

    if (transportMap->getMap().count(ID) != 0)
    {
        transportMap->deleteElement(ID);
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

    result = transportMap->findDatabaseElement(ID);

    return result;
}

void Menu::editElement(const uint32_t& ID, const QString& type, const QString& brand,
                       const QString& model, const uint32_t& year, const uint32_t& weight,
                       const uint32_t& specialFieldFirst,  const QString& specialFieldSecond
                       )
{

    transportMap->deleteElement(ID);
    addNewElement(ID, type, brand, model, year, weight, specialFieldFirst, specialFieldSecond);
}


TransportMap& Menu::getMap()
{
    return *transportMap;
}

void Menu::setMap(TransportMap& inputMap)
{
        TransportMap transportDB(inputMap);
        transportMap = std::make_unique<TransportMap>(transportDB);
}

void Menu::setID(const uint32_t& ID)
{
    uniqueID = ID;
}


uint32_t& Menu::getID()
{
    return uniqueID;
}
