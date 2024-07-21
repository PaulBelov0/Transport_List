#include "Menu.h"

Menu::Menu()
{
    controller = new Controller();
}

Menu::~Menu()
{
    delete controller;
}

void Menu::mainProcedure()
{
    std::string userInput;
    bool mapEmptyFlag;
    bool looper = true;

    if (controller->getStorage().checkMapEmpty() == true)
    {
        mapEmptyFlag = true;
    }
    else
    {
        mapEmptyFlag = false;
    }

    while(looper == true)
    {
        system("cls");

        std::cout << "Select action (Enter number of action):" << std::endl;
        std::cout << "1) Add new element.\n" << "2) Delete element.\n" << "3) Show database.\n" << "4) Edit element\n" <<"5) Exit.\n\n";

        std::getline(std::cin, userInput);

        system("cls");


        try
        {
            switch(std::stoi(userInput))
            {
            case 1:
                enterElementFields();
                break;

            case 2:
                break;

            case 3:
                system("cls");
                if (mapEmptyFlag == false)
                {
                    auto map = controller->getStorage().getMap();
                    for (auto& element : map)
                    {
                        std::cout << element.second->getID();

                        std::cout << element.second->getType();

                        std::cout << element.second->getBrand();

                        std::cout << element.second->getModel();

                        std::cout << element.second->getYear();

                        std::cout << element.second->getWeight();

                        std::cout << element.second->getSpecialFirst();

                        std::cout << element.second->getSpecialSecond();
                    }
                }
                break;

            case 4:
                break;

            case 5:
                looper = false;
                system("cls");
                break;

            default:
                throwError();
                break;
            }
        }
        catch (std::invalid_argument& e)
        {
            throwError();
        }
    }
}

void Menu::enterElementFields()
{
    bool looper = true;
    system("cls");
    std::vector<std::string> argumentsList;
    std::string userInput;

    while (looper == true)
    {

        argumentsList.push_back(enterTransportField("ID"));


        argumentsList.push_back(enterTransportField("type (Car, Air, Boat, Shuttle)"));

        if (argumentsList.back().substr() != "car" || "air" || "boat" || "shuttle")
        {
            throwError();
        }
        else
        {
            int typeIndex;

            if (userInput == "air")
            {
                typeIndex = 1;
            }
            else if (userInput == "car")
            {
                typeIndex = 2;
            }
            else if (userInput == "boat")
            {
                typeIndex = 3;
            }
            else
            {
                typeIndex = 4;
            }

            argumentsList.push_back(enterTransportField("brand"));

            argumentsList.push_back(enterTransportField("model"));
            try
            {
                argumentsList.push_back(enterTransportField("year"));

                checkDataConvertibleToUInt(argumentsList);


                argumentsList.push_back(enterTransportField("weight"));

                checkDataConvertibleToUInt(argumentsList);

            repeat:
                switch(typeIndex)
                {
                case 1:

                    argumentsList.push_back(enterTransportField("wingspan"));

                    if (checkDataConvertibleToUInt(argumentsList) == false)
                    {
                        goto repeat;
                    }

                    argumentsList.push_back(enterTransportField("payload capacity"));

                    if (checkDataConvertibleToUInt(argumentsList) == false)
                    {
                        goto repeat;
                    }

                    looper = false;
                    break;
                case 2:

                    argumentsList.push_back(enterTransportField("mileage"));

                    if (checkDataConvertibleToUInt(argumentsList) == false)
                    {
                        goto repeat;
                    }

                    argumentsList.push_back(enterTransportField("owners quantity"));

                    if (checkDataConvertibleToUInt(argumentsList) == false)
                    {
                        goto repeat;
                    }

                    looper = false;
                    break;
                case 3:

                    argumentsList.push_back(enterTransportField("displacement"));

                    if (checkDataConvertibleToUInt(argumentsList) == false)
                    {
                        goto repeat;
                    }

                    argumentsList.push_back(enterTransportField("screw depth"));

                    if (checkDataConvertibleToUInt(argumentsList) == false)
                    {
                        goto repeat;
                    }

                    looper = false;
                    break;
                case 4:
                    argumentsList.push_back(enterTransportField("max fluing distance"));

                    if (checkDataConvertibleToUInt(argumentsList) == false)
                    {
                        goto repeat;
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
    }
    controller->addNewElement(argumentsList);
}

void Menu::throwError()
{
    system("cls");

    std::cout << "Error! Unsupported input data!" << std::endl;

    std::this_thread::sleep_for(std::chrono::seconds(3));
    system("cls");
}

std::string Menu::enterTransportField(std::string fieldName)
{
    std::string userInput;
    std::cout << "Enter transport " << fieldName << ":\t";
    std::getline(std::cin, userInput);

    return userInput;
}

bool Menu::checkDataConvertibleToUInt(std::vector<std::string>& value)
{
    if(std::stoi(value.back()) <= 0)
    {
        throwError();
        return false;
    }
    else
    {
        return true;
    }
}
