#include <Menu/Menu.h>

//QT_Version

Menu::Menu()
{
    loadDataBase();
}

Menu::~Menu()
{

}

void Menu::addNewElement(uint32_t ID)
{

}

void Menu::deleteElement(const uint32_t ID)
{

}

void Menu::showDatabase()
{

}

void Menu::findElement()
{

}

void Menu::saveDatabase(TransportMap& transportMap)
{
    database.upload(transportMap);
}

TransportMap& Menu::loadDataBase()
{
    TransportMap& transportMap = database.download();
    return transportMap;
}

void Menu::createElement(uint32_t ID, char* type)
{

}
