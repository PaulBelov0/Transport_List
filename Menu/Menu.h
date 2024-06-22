#ifndef MENU_H
#define MENU_H

#include <TransportMap/transportmap.h>
#include <map>
#include <Transport/TransportBase/TransportBase.h>

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
    void saveDatabase();
    TransportMap loadDataBase();

protected:

    void createElement(uint32_t ID, char* type);

private:
    static uint32_t uniqueID;
    TransportMap database;
};

#endif //MENU_H
