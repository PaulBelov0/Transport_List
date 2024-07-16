#include <Menu/Menu.h>

//QT_Version

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


    TransportObjectCreator transportObject(ID, type, brand, model, year, weight, specialFieldFirst, specialFieldSecond);

    if (transportObject.getTransportObject()->getType().toString().toStdString() == "Air")
    {
        transportMap->addNewElement(std::make_unique<AirTransport>(transportObject.getTransportObject()));
    }
    else if(transportObject.getTransportObject()->getType().toString().toStdString() == "Car")
    {
        transportMap->addNewElement(std::make_unique<Car>(transportObject.getTransportObject()));
    }
    else if(transportObject.getTransportObject()->getType().toString().toStdString() == "Boat")
    {
        transportMap->addNewElement(std::make_unique<Boat>(transportObject.getTransportObject()));
    }
    else if (transportObject.getTransportObject()->getType().toString().toStdString() == "Shuttle")
    {
        transportMap->addNewElement(std::make_unique<Shuttle>(transportObject.getTransportObject()));
    }

    return 0;
}

QString& Menu::deleteDatabaseElement(const uint32_t& ID)
{
    transportMap->findDatabaseElement(ID);
    std::map<uint32_t, std::unique_ptr<TransportBase>> map;
    map = transportMap->getMap();

    if (map.count(ID) != 0)
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
    std::unique_ptr<TransportMap> transportDB(new TransportMap(inputMap));
    transportMap = std::make_unique<TransportMap>(*transportDB);
}

void Menu::setID(const uint32_t& ID)
{
    uniqueID = ID;
}


uint32_t& Menu::getID()
{
    return uniqueID;
}
