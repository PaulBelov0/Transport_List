#include <Source.h>

void addNewTransport(std::unordered_map<uint32_t, TransportBase> transportDB);

Car createCarElement(uint32_t identifier);
Shuttle createShuttleElement(uint32_t identifier);
AirTransport createAirTransportElement(uint32_t identifier);
Boat createBoatElement(uint32_t identifier);

int main()
{
	Car defCar(0);
	// Problem: unord_map doesn't work with polimorphic types.
	std::unordered_map<uint32_t, Car> transportDB;

	transportDB;

	//addNewTransport(transportDB);

	return 0;
}

void addNewTransport(std::unordered_map<uint32_t, TransportBase> transportDB)
{
	static uint32_t identifier = 1;
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
		createCarElement(identifier);
		break;
	case 2:
		createBoatElement(identifier);
		break;
	case 3:
		createShuttleElement(identifier);
		break;
	case 4:
		createAirTransportElement(identifier);
		break;
	default:
		std::cout << "\n\nINCORRECT DATA!" << std::endl;
		break;
	}
	identifier++;
}

Car createCarElement(uint32_t identifier)
{
	Car car = Car(identifier);
	return car;
}

Shuttle createShuttleElement(uint32_t identifier)
{
	Shuttle shuttle = Shuttle(identifier);
	return shuttle;
}

Boat createBoatElement(uint32_t identifier)
{
	Boat boat = Boat(identifier);
	return boat;
}

AirTransport createAirTransportElement(uint32_t identifier)
{
	AirTransport airTransport = AirTransport(identifier);
	return airTransport;
}