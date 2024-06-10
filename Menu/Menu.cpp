#include <Menu.h>

Menu::Menu(std::map<uint32_t, TransportBase&>* DB)
{
	transportDB = DB;
}

Menu::~Menu()
{
	delete transportDB;
}

int Menu::mainMenu()
{
	std::cout << "Hello!\n" << "\nThis is Transport Database application." << std::endl;

	std::cout << "We're loading database . . . " << std::endl;

	transportDB = loadDataBase();

	try
	{
		auto& element = transportDB->at(1);
		std::cout << "Database loaded succesful!" << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout << "Database is empty." << std::endl;
	}

	while (true)
	{
		std::cout << "What's your next action? (Enter the variant number):\n" << std::endl;
		std::cout << "1. Add new element.\n2. Delete element.\n3. Show all database. \n4. Find element.\n5. Save database.\n6. Quit.\n" << std::endl;
		
		while (userInput != nullptr)
		{
			try
			{
				std::cin >> *userInput;
			}
			catch (const std::exception& e)
			{
				std::cout << "Incorrect input!" << std::endl;
			}

			switch (*userInput)
			{
			case'1':
				uniqueID = 1;
				addNewElement(uniqueID);
				uniqueID++;
				break;
			case'2':
				deleteElement(uniqueID);
				break;
			case'3':
				showDatabase();
				break;
			case'4':
				findElement();
				break;
			case'5':
				saveDatabase();
				break;
			case'6':
				return 0;
				break;
			default:
				std::cout << "Incorrect input!" << std::endl;
				break;
			}
		}
	}
}

void Menu::addNewElement(uint32_t ID)
{
	char* transportType = nullptr;

	while(transportType == nullptr)
	{
		std::cout << "Enter the number of transport type\n" << std::endl;
		std::cout << "1. Air transport\n2. Water transport\n3. Car\n4. Space shuttle" << std::endl;
		try
		{
			std::cin >> *transportType;
		}
		catch (const std::exception& e)
		{
			std::cout << "Incorrect input!" << std::endl;
		}

		switch (*transportType)
		{
		case'1':
			transportDB->insert({ID, createElement(ID, transportType)});
			break;
		case'2':
			transportDB->insert({ ID, createElement(ID, transportType) });
			break;
		case'3':
			transportDB->insert({ ID, createElement(ID, transportType) });
			break;
		case'4':
			transportDB->insert({ ID, createElement(ID, transportType) });
			break;
		default:
			transportType = nullptr;
			break;
		}
	}
}

std::string Menu::deleteElement(const uint32_t ID)
{
	try
	{
		transportDB->erase(ID);
	}
	catch (const std::exception& e)
	{
		return "Key is not allowed.";
	}
	return "Element deleted";
}

void Menu::showDatabase()
{
	for (auto& element : *transportDB)
	{
		element.second.print();
	}
}

void Menu::findElement()
{
}

int Menu::saveDatabase()
{

}

std::map<uint32_t, TransportBase&>* Menu::loadDataBase()
{

}

TransportBase& Menu::createElement(uint32_t ID, char* type)
{
	if (*type == '1')
	{
		AirTransport airTransport(ID);
		return airTransport;
	}
	if (*type == '2')
	{
		Boat boat(ID);
		return boat;
	}
	if (*type == '3')
	{
		Car car(ID);
		return car;
	}
	if (*type == '4')
	{
		Shuttle shuttle(ID);
		return shuttle;
	}
}