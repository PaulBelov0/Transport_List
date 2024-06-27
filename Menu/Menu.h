#ifndef MENU_H
#define MENU_H

#include <TransportMap/transportmap.h>
#include <Transport/TransportBase/TransportBase.h>
#include <Database/Database.h>

class Menu
{
public:

	Menu();
	~Menu();

    void addNewElement(uint32_t& ID);
    void deleteDatabaseElement(const uint32_t& ID);
    QString* showDatabaseElement(const uint32_t& ID);
    void findElement();
    void saveDatabase();
    TransportMap& loadDatabase();
    QSqlDatabase* getDatabaseFromSource();

private:
    static uint32_t uniqueID;
    TransportMap& transportDatabase;
    Database database;
};

#endif //MENU_H
