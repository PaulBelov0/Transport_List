#ifndef _MENU_H_
#define _MENU_H_

#include "TransportMap/transportmap.h"
#include <map>
#include <memory>
#include "Transport/TransportBase/TransportBase.h"

class Menu
{
public:

	Menu();
	~Menu();

	int mainMenu();
	void addNewElement(uint32_t ID);
	std::string deleteElement(const uint32_t ID);
	void showDatabase();
	void findElement();
	int saveDatabase();
	std::map<uint32_t, TransportBase&> loadDataBase();

protected:

	TransportBase& createElement(uint32_t ID, char* type);

private:
	static uint32_t uniqueID;
	char* userInput;
	std::unique_ptr<std::map<uint32_t, TransportBase&>> transportDB;
};

#endif
