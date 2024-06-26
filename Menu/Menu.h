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
    TransportMap& loadDatabase();
    void saveDatabase(TransportMap& transportMap);

protected:

    void createElement(uint32_t ID, char* type);

private:
    static uint32_t uniqueID;
    TransportMap& transportDatabase;
};

#endif //MENU_H
