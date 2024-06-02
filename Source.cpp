#include <Source.h>

void addNewTransport(std::unordered_map<uint32_t, TransportBase> transportDB);

int main()
{
	Car defCar(0);
	// Problem: unord_map doesn't work with polimorphic types.
	std::unordered_map<uint32_t, TransportBase> transportDB;

	addNewTransport(transportDB);

	return 0;
}

void addNewTransport(std::unordered_map<uint32_t, TransportBase> transportDB)
{
	static uint32_t identifier = 0;
	int userInput = 0;

	std::cout << "If you want add a new transport to data base, enter the type of transport (Example - '1'):\n1. Car type.\n2. Water transport type.\n3. Space Shuttle type.\n 4. Air transport type." << std::endl;
	try
	{
		std::cin >> userInput;
	}
	catch (_exception)
	{
		std::cout << "\n\nINCORRECT DATA!" << std::endl;
	}


	switch (userInput)
	{
	case 1:
		Car car = Car(identifier);
		break;
	case 2:
		Boat boat = Boat(identifier);
		break;
	case 3:
		Shuttle shuttle = Shuttle(identifier);
		break;
	case 4:
		AirTransport airTrsnprt = AirTransport(identifier);
		break;
	default:
		std::cout << "\n\nINCORRECT DATA!" << std::endl;
		break;
	}
	identifier++;
}