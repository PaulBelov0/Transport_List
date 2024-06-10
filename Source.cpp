#include <iostream>
#include <transport.h>
#include <map>
#include <cstdint>
#include <Menu.h>

int main()
{
	std::map<uint32_t, TransportBase&>* transportDB = new std::map<uint32_t, TransportBase&>;

	Menu menu(transportDB);
	menu.mainMenu();

	return 0;
}