#include <Menu/Menu.h>

//QT_Version

Menu::Menu() : transportDatabase(loadDatabase()) {}

Menu::~Menu() {}

void Menu::addNewElement(uint32_t& ID)
{

}

void Menu::deleteDatabaseElement(const uint32_t& ID)
{
    transportDatabase.deleteElement(ID);
}

QString* Menu::showDatabaseElement(const uint32_t& ID)
{
    QString* result;
    result = transportDatabase.showDatabaseElement(ID);
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

