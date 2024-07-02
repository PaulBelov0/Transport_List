#include <Menu/Menu.h>

//QT_Version

Menu::Menu() { transportMap = new TransportMap; messageToUserWindow = new MessageToUserWindow; }

Menu::~Menu() { delete transportMap; delete messageToUserWindow; }

int Menu::addNewElement(const uint32_t& ID, const QString& type,
                        const QString& brand, const QString& model,
                        const uint32_t& year, const uint32_t& weight,
                        const uint32_t& specialFieldFirst, const QString& specialFieldSecond
                        )
{


    if (type == "Air")
    {
        std::string* specialFieldSecond_tmp = new std::string(specialFieldSecond.toStdString());
        try
        {
            int specialSecondIntVersion = std::stoi(*specialFieldSecond_tmp);
            delete specialFieldSecond_tmp;

            AirTransport airTransport(ID, brand, model, year, weight, specialFieldFirst, specialSecondIntVersion);

            transportMap->addNewElement(ID, airTransport);
        }
        catch (const std::invalid_argument& e)
        {
            messageToUserWindow->show();
            messageToUserWindow->setTextMessage("ERROR!\nWrong data in <Special 2> field!");
        }
        return 0;
    }
    else if (type == "Car")
    {
        std::string* spececialFieldSecond_tmp = new std::string(specialFieldSecond.toStdString());

        try
        {
            int spececialFieldSecondIntVersion = std::stoi(*spececialFieldSecond_tmp);
            delete spececialFieldSecond_tmp;

            Car car(ID, brand, model, year, weight, specialFieldFirst, spececialFieldSecondIntVersion);

            transportMap->addNewElement(ID, car);
        }
        catch (const std::invalid_argument& e)
        {
            messageToUserWindow->show();
            messageToUserWindow->setTextMessage("ERROR!\nWrong data in <Special 2> field!");
        }
        return 0;
    }
    else if (type == "Boat")
    {
        std::string* specialFieldSecond_tmp = new std::string(specialFieldSecond.toStdString());

        try
        {
            int specialFieldSecondIntVersion = std::stoi(*specialFieldSecond_tmp);
            delete specialFieldSecond_tmp;

            Boat boat(ID, brand, model, year, weight, specialFieldFirst, specialFieldSecondIntVersion);

            transportMap->addNewElement(ID, boat);
        }
        catch (const std::invalid_argument& e)
        {
            messageToUserWindow->show();
            messageToUserWindow->setTextMessage("ERROR!\nWrong data in <Special 2> field!");
        }
        return 0;
    }
    else if (type == "Shuttle")
    {
        Shuttle shuttle(ID, brand, model, year, weight, specialFieldFirst, specialFieldSecond);

        transportMap->addNewElement(ID, shuttle);

        return 0;
    }
    else
    {
        return 1;
    }
}

QString& Menu::deleteDatabaseElement(const uint32_t& ID)
{
    transportMap->findDatabaseElement(ID);
    std::map<uint32_t, TransportBase&> map = transportMap->getMap();

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

bool Menu::checkElementAvilable(uint32_t& ID)
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
    transportMap = &inputMap;
}

void Menu::setID(uint32_t& ID)
{
    uniqueID = ID;
}


uint32_t& Menu::getID()
{
    return uniqueID;
}
