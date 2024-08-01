#include "Menu.h"

Menu::Menu()
{
    controller = new Controller();
    controller->loadDatabase();
    uniqueID = 0;
}

Menu::~Menu()
{
    controller->saveDatabase();
    delete controller;
}

void Menu::mainProcedure()
{
    std::string userInput;
    bool looper = true;
    bool mapEmptyFlag;

    std::vector<std::string> argumentsList;

    if (controller->getStorage().checkListEmpty() == true)
    {
        mapEmptyFlag = true;
    }
    else
    {
        mapEmptyFlag = false;
    }

    while(looper == true)
    {
        userInput.clear();

        std::cout << "\nSelect action (Enter number of action):" << std::endl;
        std::cout << "1) Add new element.\n" << "2) Delete element.\n" << "3) Show database.\n" << "4) Edit element.\n" <<"5) Exit.\n\n";

        std::cin >> userInput;

        try
        {
            switch(std::stoi(userInput))
            {
            case 1:
            {
                argumentsList = enterElementFields(true);
                controller->addNewElement(argumentsList);
                break;
            }
            case 2:
            {
                std::cout << "Enter the element ID:\t" << std::endl;
                std::cin >> userInput;

                try
                {
                    if (std::stoi(userInput) > 0)
                    {
                        system("cls");
                        std::cout << controller->deleteDatabaseElement(std::stoi(userInput)).toStdString() << std::endl;
                        std::this_thread::sleep_for(std::chrono::seconds(3));
                    }
                    else
                    {
                        throwError();
                    }
                }
                catch(std::invalid_argument& e)
                {
                    throwError();
                }

                break;
            }
            case 3:
            {
                system("cls");

                mapEmptyFlag = controller->getStorage().checkListEmpty();

                if (mapEmptyFlag == false)
                {
                    auto list = controller->getStorage().getList();
                    for (auto& element : list)
                    {
                        if (element->uniqueID != 0)
                            printElementFields(element);
                    }

                    std::cout << "\n\nEnter any symbol to continue to continue: " << std::endl;
                    std::cin >> userInput;
                }
                else
                {
                    std::cout << "Database is empty!" << std::endl;
                    std::cout << "\n\nEnter any symbol to continue to continue: " << std::endl;
                    std::cin >> userInput;
                }
                break;
            }
            case 4:
            {
                std::cout << "Enter the element ID:\t" << std::endl;
                std::cin >> userInput;

                try
                {
                    if (std::stoi(userInput) > 0)
                    {
                        if (controller->getStorage().findDatabaseElement(std::stoi(userInput)) == true)
                        {
                            auto storageTmp = controller->getStorage().getList();
                            for (auto& element : storageTmp)
                            {
                                if (element->uniqueID == std::stoul(userInput))
                                {
                                    printElementFields(element);

                                    uniqueTmp = uniqueID;
                                    uniqueID = element->uniqueID;

                                    controller->editElement(enterElementFields(false));

                                    uniqueID = uniqueTmp;
                                }
                            }

                            system("cls");
                        }
                    }
                    else
                    {
                        throwError();
                    }
                }
                catch(std::invalid_argument& e)
                {
                    throwError();
                }
                break;
            }
            case 5:
            {
                looper = false;
                system("cls");
                break;
            }
            default:
            {
                throwError();
                break;
            }
            }
        }
        catch (std::invalid_argument& e)
        {
            throwError();
        }

        system("cls");
    }
}

std::vector<std::string> Menu::enterElementFields(bool adding)
{
    if(adding == true)
    {
        ++uniqueID;
    }

    system("cls");

    bool looper = true;
    std::vector<std::string> argumentsList;
    std::string userInput;
    int typeIndex;

    while (looper == true)
    {

    reEnterFields:

        argumentsList.clear();
        argumentsList.push_back(std::to_string(uniqueID));

        std::cout << "Enter transport type (1 - Air, 2 - Car, 3 - Boat, 4 - Shuttle):\t";
        std::cin >> userInput;

        try
        {
            typeIndex = std::stoi(userInput);
            if (typeIndex < 6 && typeIndex > 0)
            {
                argumentsList.push_back(userInput);
                userInput.clear();
            }
            else
            {
                throwError();
                goto reEnterFields;
            }
        }
        catch(std::invalid_argument& e)
        {
            throwError();
            goto reEnterFields;
        }

        argumentsList.push_back(enterTransportField("brand"));

        argumentsList.push_back(enterTransportField("model"));
        try
        {
            argumentsList.push_back(enterTransportField("year"));

            if (checkDataConvertibleToUInt(argumentsList, 4) == false)
            {
                goto reEnterFields;
            }


            argumentsList.push_back(enterTransportField("weight"));

            if (checkDataConvertibleToUInt(argumentsList, 5) == false)
            {
                goto reEnterFields;
            }

            switch(typeIndex)
            {
            case 1:

                argumentsList.push_back(enterTransportField("wingspan"));

                if (checkDataConvertibleToUInt(argumentsList, 6) == false)
                {
                    goto reEnterFields;
                }

                argumentsList.push_back(enterTransportField("payload capacity"));

                if (checkDataConvertibleToUInt(argumentsList, 7) == false)
                {
                    goto reEnterFields;
                }

                looper = false;
                break;
            case 2:

                argumentsList.push_back(enterTransportField("mileage"));

                if (checkDataConvertibleToUInt(argumentsList, 6) == false)
                {
                    goto reEnterFields;
                }

                argumentsList.push_back(enterTransportField("owners quantity"));

                if (checkDataConvertibleToUInt(argumentsList, 7) == false)
                {
                    goto reEnterFields;
                }

                looper = false;
                break;
            case 3:

                argumentsList.push_back(enterTransportField("displacement"));

                if (checkDataConvertibleToUInt(argumentsList, 6) == false)
                {
                    goto reEnterFields;
                }

                argumentsList.push_back(enterTransportField("screw depth"));

                if (checkDataConvertibleToUInt(argumentsList, 7) == false)
                {
                    goto reEnterFields;
                }

                looper = false;
                break;
            case 4:
                argumentsList.push_back(enterTransportField("max fluing distance"));

                if (checkDataConvertibleToUInt(argumentsList, 6) == false)
                {
                    goto reEnterFields;
                }

                argumentsList.push_back(enterTransportField("fuel type"));

                looper = false;
                break;
            }
        }
        catch(std::invalid_argument& e)
        {
            throwError();
        }
    }
    return argumentsList;
}

std::string Menu::enterTransportField(std::string fieldName)
{
    std::string userInput;
    std::cout << "Enter transport " << fieldName << ":   ";
    std::cin >> userInput;
    return userInput;
}

bool Menu::checkDataConvertibleToUInt(std::vector<std::string>& value, int elementNumber)
{
    try
    {
        if(std::stoi(value[elementNumber]) <= 0)
        {
            throwError();
            return false;
        }
        else
        {
            return true;
        }
    }
    catch (std::invalid_argument& e)
    {
        throwError();

        return false;
    }
}

void Menu::printElementFields(std::shared_ptr<TransportBase>& element)
{
    std::cout << "Unique ID: " << element->uniqueID << std::endl;

    std::cout << "Type: " << element->type << std::endl;

    std::cout << "Brand: " << element->brand << std::endl;

    std::cout << "Model: " << element->model << std::endl;

    std::cout << "Year: " << element->year << std::endl;

    std::cout << "Weight: " << element->weight << std::endl;

    if (element->type == "Air")
    {
        auto air = std::dynamic_pointer_cast<AirTransport>(element);

        std::cout << "Wingspan: " << air.get()->wingspan << std::endl;
        std::cout << "Payload Capacity: " << air.get()->payloadCapacity << "\n" << std::endl;
    }
    else if (element->type == "Car")
    {
        auto car = std::dynamic_pointer_cast<Car>(element);

        std::cout << "Mileage: " << car.get()->mileage << std::endl;
        std::cout << "Owners Quantity: " << car.get()->ownersQuantity << "\n" << std::endl;
    }
    else if (element->type == "Boat")
    {
        auto boat = std::dynamic_pointer_cast<Boat>(element);

        std::cout << "Displacement: " << boat.get()->displacement << std::endl;
        std::cout << "Screw Depth: " << boat.get()->screwDepth << "\n" << std::endl;
    }
    else if (element->type == "Shuttle")
    {
        auto shuttle = std::dynamic_pointer_cast<Shuttle>(element);

        std::cout << "Max Flying Distance: " << shuttle.get()->maxFlyingDistance << std::endl;
        std::cout << "Fuel Type: " << shuttle.get()->fuelType << "\n" << std::endl;
    }
}

void Menu::throwError()
{

    system("cls");

    std::cerr << "Error! Unsupported input data!" << std::endl;

    std::this_thread::sleep_for(std::chrono::seconds(2));
    system("cls");
}
