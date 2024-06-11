#ifndef _MENU_H_
#define _MENU_H_

#include <transport.h>
#include <map>

class Menu
{
public:

	Menu(std::map<uint32_t, TransportBase&>* DB);
	~Menu();

	int mainMenu();
	void addNewElement(uint32_t ID);
	std::string deleteElement(const uint32_t ID);
	void showDatabase();
	void findElement();
	int saveDatabase();
	std::map<uint32_t, TransportBase&>* loadDataBase();

protected:

	TransportBase& createElement(uint32_t ID, char* type);

private:
	static uint32_t uniqueID;
	char* userInput;
	std::map<uint32_t, TransportBase&>* transportDB;
};

#endif