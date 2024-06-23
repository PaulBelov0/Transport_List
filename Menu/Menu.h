#ifndef MENU_H
#define MENU_H

#include <TransportMap/transportmap.h>
#include <map>
#include <Transport/TransportBase/TransportBase.h>
#include <Database/Database.h>

class Menu
{
public:

	Menu();
	~Menu();

	int mainMenu();
	void addNewElement(uint32_t ID);
    void deleteElement(const uint32_t ID);
	void showDatabase();
	void findElement();
    void saveDatabase(TransportMap& transportMap);
    TransportMap& loadDataBase();

protected:

    void createElement(uint32_t ID, char* type);

private:
    static uint32_t uniqueID;
    TransportMap& transportDatabase;
    Database database;
};

#endif //MENU_H
