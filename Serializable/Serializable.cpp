#include "Serializable.h"

Serializator::Serializator() : filename("database.txt")
{

}

Serializator::Serializator(const std::list<std::shared_ptr<TransportBase>>& inputList) : filename("database.txt")
{

    if (inputList.empty() != true)
    {
        for (auto& value : inputList)
        {
            localList.push_back(value);
        }
    }
}

void Serializator::serialize(std::list<std::shared_ptr<TransportBase>>& inputList)
{
    std::ofstream file(filename, std::ios::binary);
    if(!file.is_open())
    {
        std::cerr << "Error: Failed open file for writing" << std::endl;
        return;
    }
    std::string elementFields;
    for (auto& element : inputList)
    {
        elementFields = objectFieldsToString(elementFields, element);
        file.write(elementFields.c_str(), elementFields.size());
    }
    file.close();
    std::cout << "Data structure serialized succesfully!" << std::endl;
}

std::list<std::shared_ptr<TransportBase>> Serializator::deserialize()
{
    std::list<std::shared_ptr<TransportBase>> outputList;

    std::ifstream file(filename, std::ios::binary);

    if(!file.is_open())
    {
        std::cerr << "Error: Failed open file for writing" << std::endl;
    }
    else
    {
        std::string fileRawTmp;
        while(std::getline(file, fileRawTmp))
        {
            outputList.push_back(getTransportObject(fileRawTmp));
        }
    }

    return outputList;
}

inline std::string& Serializator::objectFieldsToString(std::string& raw, std::shared_ptr<TransportBase>& obj)
{
    if (obj->type == "Air")
    {
        std::shared_ptr<AirTransport> airTmp(std::dynamic_pointer_cast<AirTransport>(obj));

        raw+= airTmp->type + "|";
        raw = std::to_string(airTmp->uniqueID) + "|";
        raw+= airTmp->brand + "|";
        raw+= airTmp->model + "|";
        raw+= std::to_string(airTmp->year) + "|";
        raw+= std::to_string(airTmp->weight) + "|";
        raw+= std::to_string(airTmp->wingspan) + "|";
        raw+= std::to_string(airTmp->payloadCapacity) + "|";

        return raw;
    }
    else if (obj->type == "Car")
    {
        std::shared_ptr<Car> boatTmp(std::dynamic_pointer_cast<Car>(obj));

        raw+= boatTmp->type + "|";
        raw = std::to_string(boatTmp->uniqueID) + "|";
        raw+= boatTmp->brand + "|";
        raw+= boatTmp->model + "|";
        raw+= std::to_string(boatTmp->year) + "|";
        raw+= std::to_string(boatTmp->weight) + "|";
        raw+= std::to_string(boatTmp->mileage) + "|";
        raw+= std::to_string(boatTmp->ownersQuantity) + "|";

        return raw;
    }
    else if (obj->type == "Boat")
    {
        std::shared_ptr<Boat> boatTmp(std::dynamic_pointer_cast<Boat>(obj));

        raw+= boatTmp->type + "|";
        raw = std::to_string(boatTmp->uniqueID) + "|";
        raw+= boatTmp->brand + "|";
        raw+= boatTmp->model + "|";
        raw+= std::to_string(boatTmp->year) + "|";
        raw+= std::to_string(boatTmp->weight) + "|";
        raw+= std::to_string(boatTmp->displacement) + "|";
        raw+= std::to_string(boatTmp->displacement) + "|";

        return raw;
    }
    else
    {
        std::shared_ptr<Shuttle> shuttleTmp(std::dynamic_pointer_cast<Shuttle>(obj));

        raw = std::to_string(shuttleTmp->uniqueID) + "|";
        raw+= shuttleTmp->type + "|";
        raw+= shuttleTmp->brand + "|";
        raw+= shuttleTmp->model + "|";
        raw+= std::to_string(shuttleTmp->year) + "|";
        raw+= std::to_string(shuttleTmp->weight) + "|";
        raw+= std::to_string(shuttleTmp->maxFlyingDistance) + "|";
        raw+= shuttleTmp->fuelType + "|";

        return raw;
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
