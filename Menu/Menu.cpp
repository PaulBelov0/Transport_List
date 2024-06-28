#include <Menu/Menu.h>

//QT_Version

Menu::Menu() : transportMap(loadDatabase()) {}

Menu::~Menu() {}

int Menu::addNewElement(const uint32_t& ID, const QString& type, const QString& brand,
                         const QString& model, const uint32_t& year, const uint32_t& weight,
                         const uint32_t& specialFieldFirst, const QString& specialFieldSecond
                         )
{


    if (type == "Air")
    {
        std::string* specialFieldSecond_tmp = new std::string(specialFieldSecond.toStdString());
        int specialSecondIntVersion = std::stoi(*specialFieldSecond_tmp);
        delete specialFieldSecond_tmp;

        AirTransport airTransport(ID, brand, model, year, weight, specialFieldFirst, specialSecondIntVersion);

        transportMap.addNewElement(ID, airTransport);

        return 0;
    }
    else if (type == "Car")
    {
        std::string* spececialFieldSecond_tmp = new std::string(specialFieldSecond.toStdString());
        int spececialFieldSecondIntVersion = std::stoi(*spececialFieldSecond_tmp);
        delete spececialFieldSecond_tmp;

        Car car(ID, brand, model, year, weight, specialFieldFirst, spececialFieldSecondIntVersion);

        transportMap.addNewElement(ID, car);

        return 0;
    }
    else if (type == "Boat")
    {
        std::string* specialFieldSecond_tmp = new std::string(specialFieldSecond.toStdString());
        int specialFieldSecondIntVersion = std::stoi(*specialFieldSecond_tmp);
        delete specialFieldSecond_tmp;

        Boat boat(ID, brand, model, year, weight, specialFieldFirst, specialFieldSecondIntVersion);

        transportMap.addNewElement(ID, boat);

        return 0;
    }
    else if (type == "Shuttle")
    {
        Shuttle shuttle(ID, brand, model, year, weight, specialFieldFirst, specialFieldSecond);

        transportMap.addNewElement(ID, shuttle);

        return 0;
    }
    else
    {
        return 1;
    }
}

QString& Menu::deleteDatabaseElement(const uint32_t& ID)
{
    QString* result;

    transportMap.findDatabaseElement(ID);
    std::map<uint32_t, TransportBase&> map = transportMap.getMap();

    if (map.count(ID) != NULL)
    {
        transportMap.deleteElement(ID);
        *result = "Element deleted successful!";
    }
    else
    {
        *result = "Error! No one element have this ID!";
    }
    return *result;
}

bool Menu::checkElementAvilable(uint32_t& ID)
{
    bool result;

    result = transportMap.findDatabaseElement(ID);
    //TODO

    // std::map<uint32_t, TransportBase&> map = transportMap.getMap();

    // if (map.count(ID) != NULL)
    // {
    //     result = true;
    // }
    // else
    // {
    //     result = false;
    // }
    return result;
}

void Menu::findElement()
{

}

void Menu::saveDatabase()
{
    database.upload();
}


TransportMap& Menu::loadDatabase()
{
    Database database;
    return database.download();
}

QSqlDatabase* Menu::getDatabaseFromSource()
{
    return database.getDatabase();
}

void Menu::editElement(const uint32_t& ID, const QString& type, const QString& brand,
                       const QString& model, const uint32_t& year, const uint32_t& weight,
                       const uint32_t& specialFieldFirst,  const QString& specialFieldSecond
                       )
{

    transportMap.deleteElement(ID);
    addNewElement(ID, type, brand, model, year, weight, specialFieldFirst, specialFieldSecond);
}

