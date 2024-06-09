#include <iostream>
#include <transport.h>
#include <unordered_map>
#include <cstdint>
#include <fstream>
#include <Menu.h>

int main()
{
	Car defCar(0);
	std::unordered_map<uint32_t, TransportBase&> transportDB;
	uint32_t index = 1;

	transportDB.insert({1, defCar});

	return 0;
}