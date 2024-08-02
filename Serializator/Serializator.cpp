#include "Serializator.h"

#include <thread>

Serializator::Serializator() : filename("database.txt") {}

void Serializator::serialize(std::list<std::shared_ptr<TransportBase>>& inputList)
{
    std::ofstream dbFile;

    dbFile.open(filename);

    if(dbFile.is_open() == false)
    {
        std::cout << "Error: Failed open file for writing" << std::endl;
        return;
    }

    std::string elementFields;

    for (auto& element : inputList)
    {
        elementFields = objectFieldsToString(element);
        dbFile.write(elementFields.c_str(), elementFields.size());
    }

    dbFile.close();

    system("cls");

    std::cout << "Data structure serialized succesfully!" << std::endl;

    std::this_thread::sleep_for(std::chrono::seconds(2));
}

std::list<std::shared_ptr<TransportBase>> Serializator::deserialize()
{
    std::list<std::shared_ptr<TransportBase>> outputList;

    std::ifstream dbFile(filename);

    dbFile.open(filename);

    if(dbFile.is_open() == false)
    {
        std::cout << "Error: Failed open file for writing" << std::endl;
    }
    else
    {
        std::string fileRawTmp;
        while(std::getline(dbFile, fileRawTmp))
        {
            outputList.push_back(getTransportObject(fileRawTmp));
        }
    }

    dbFile.close();

    return outputList;
}

inline std::string& Serializator::objectFieldsToString(std::shared_ptr<TransportBase>& obj)
{
    rawTmp.clear();

    if (obj->type == "Air")
    {
        std::shared_ptr<AirTransport> airTmp(std::dynamic_pointer_cast<AirTransport>(obj));

        rawTmp+= airTmp->type + "|";
        rawTmp = std::to_string(airTmp->uniqueID) + "|";
        rawTmp+= airTmp->brand + "|";
        rawTmp+= airTmp->model + "|";
        rawTmp+= std::to_string(airTmp->year) + "|";
        rawTmp+= std::to_string(airTmp->weight) + "|";
        rawTmp+= std::to_string(airTmp->wingspan) + "|";
        rawTmp+= std::to_string(airTmp->payloadCapacity) + "|";

        return rawTmp;
    }
    else if (obj->type == "Car")
    {
        std::shared_ptr<Car> boatTmp(std::dynamic_pointer_cast<Car>(obj));

        rawTmp+= boatTmp->type + "|";
        rawTmp = std::to_string(boatTmp->uniqueID) + "|";
        rawTmp+= boatTmp->brand + "|";
        rawTmp+= boatTmp->model + "|";
        rawTmp+= std::to_string(boatTmp->year) + "|";
        rawTmp+= std::to_string(boatTmp->weight) + "|";
        rawTmp+= std::to_string(boatTmp->mileage) + "|";
        rawTmp+= std::to_string(boatTmp->ownersQuantity) + "|";

        return rawTmp;
    }
    else if (obj->type == "Boat")
    {
        std::shared_ptr<Boat> boatTmp(std::dynamic_pointer_cast<Boat>(obj));

        rawTmp+= boatTmp->type + "|";
        rawTmp = std::to_string(boatTmp->uniqueID) + "|";
        rawTmp+= boatTmp->brand + "|";
        rawTmp+= boatTmp->model + "|";
        rawTmp+= std::to_string(boatTmp->year) + "|";
        rawTmp+= std::to_string(boatTmp->weight) + "|";
        rawTmp+= std::to_string(boatTmp->displacement) + "|";
        rawTmp+= std::to_string(boatTmp->displacement) + "|";

        return rawTmp;
    }
    else
    {
        std::shared_ptr<Shuttle> shuttleTmp(std::dynamic_pointer_cast<Shuttle>(obj));

        rawTmp = std::to_string(shuttleTmp->uniqueID) + "|";
        rawTmp+= shuttleTmp->type + "|";
        rawTmp+= shuttleTmp->brand + "|";
        rawTmp+= shuttleTmp->model + "|";
        rawTmp+= std::to_string(shuttleTmp->year) + "|";
        rawTmp+= std::to_string(shuttleTmp->weight) + "|";
        rawTmp+= std::to_string(shuttleTmp->maxFlyingDistance) + "|";
        rawTmp+= shuttleTmp->fuelType + "|";

        return rawTmp;
    }
}

std::shared_ptr<TransportBase> Serializator::getTransportObject(std::string& fileRaw)
{
    std::vector<std::string> args;

    std::string elementRaw;

    for (auto& symbol : fileRaw)
    {
        while(symbol != '|')
        {
            elementRaw += symbol;
        }

        args.push_back(elementRaw);
        elementRaw.clear();
    }

    TransportObjectCreator creator(args);

    return creator.getTransportObject();
}
