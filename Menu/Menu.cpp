#include <Menu/Menu.h>

//QT_Version

Menu::Menu() { messageToUserWindow = new MessageToUserWindow(); }

Menu::~Menu() { delete messageToUserWindow; }

int Menu::addNewElement(const uint32_t& ID, const QString& type,
                        const QString& brand, const QString& model,
                        const uint32_t& year, const uint32_t& weight,
                        const uint32_t& specialFieldFirst, const QString& specialFieldSecond
                        )
{
    int specialSecondFieldIntVersion;

    if (type == "Air")
    {
        try
        {
            specialSecondFieldIntVersion = specialFieldSecond.toUInt();

            AirTransport air(ID, brand, model, year, weight, specialFieldFirst, specialSecondFieldIntVersion);

            transportMap->addNewElement(air.clone());
        }
        catch (const std::invalid_argument& e)
        {
            messageToUserWindow->show();
            messageToUserWindow->setTextMessage("ERROR!\nWrong data in <Special 2> field!");
            while (messageToUserWindow->isEnabled()) {}
        }
    }
    else if (type == "Car")
    {
        try
        {
            specialSecondFieldIntVersion = specialFieldSecond.toUInt();

            Car car(ID, brand, model,year, weight, specialFieldFirst, specialSecondFieldIntVersion);

            transportMap->addNewElement(car.clone());

        }
        catch (const std::invalid_argument& e)
        {
            messageToUserWindow->show();
            messageToUserWindow->setTextMessage("ERROR!\nWrong data in <Special 2> field!");
            while (messageToUserWindow->isEnabled()) {}
        }


    }
    else if (type == "Boat")
    {
        try
        {
            specialSecondFieldIntVersion = specialFieldSecond.toUInt();
            Boat boat(ID, brand, model, year, weight, specialFieldFirst, specialSecondFieldIntVersion);
            transportMap->addNewElement(boat.clone());
        }
        catch (const std::invalid_argument& e)
        {
            messageToUserWindow->show();
            messageToUserWindow->setTextMessage("ERROR!\nWrong data in <Special 2> field!");
            while (messageToUserWindow->isEnabled()) {}
        }
    }
    else
    {
        Shuttle shuttle(ID, brand, model, year, weight, specialFieldFirst, specialFieldSecond);
        transportMap->addNewElement(shuttle.clone());
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
