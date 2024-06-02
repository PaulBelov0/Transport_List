#include "Source.h"
#include <unordered_map>
#include <cstdint>

void addNewTransport(std::unordered_map<TransportBase, uint32_t> transportDB);

int main()
{
	std::unordered_map<TransportBase, uint32_t> transportDB;

	addNewTransport(transportDB);

	return 0;
}

void addNewTransport(std::unordered_map<TransportBase, uint32_t> transportDB)
{
	static uint32_t identifier = 0;
	std::string userInput;

	std::cout << "If you want add a new transport to data base, enter the type of transport (Example - '1'):\n1. Car type.\n2. Water transport type.\n3. Space Shuttle type.\n 4. Air transport type." << std::endl;
	std::cin >> userInput;

	switch (userInput)
	{
	case "1":
		Car* car = new Car(identifier);
		transportDB.insert(*car, identifier);
		delete car;
		break;
	case "2":
		Boat* boat = new Boat(identifier);
		transportDB.insert(*boat, identifier);
		delete boat;
		break;
	case "3":
		Shuttle* shuttle = new Shuttle(identifier);
		transportDB.insert(*shuttle, identifier);
		delete shuttle;
		break;
	case "4":
		AirTransport* airTrsnprt = new AirTransport(identifier);
		transportDB.insert(*airTrsnprt, identifier);
		delete airTrsnprt;
		break;
	default:
		std::cout << "\n\nINCORRECT DATA!" << std::endl;
		break;
	}
	identifier++;
}