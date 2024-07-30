#ifndef SERIALIZABLE_H
#define SERIALIZABLE_H

#include <memory>
#include <list>
#include <iostream>
#include <fstream>
#include <filesystem>

#include "Transport/TransportCreator/TransportObjectCreator.h"
#include "Transport/Transport.h"

class Serializator
{
public:
    Serializator();

    Serializator(const std::list<std::shared_ptr<TransportBase>>& inputList);

    void serialize(std::list<std::shared_ptr<TransportBase>>& inputList);

    std::list<std::shared_ptr<TransportBase>> deserialize();

private:
    inline std::string& objectFieldsToString(std::string& raw, std::shared_ptr<TransportBase>& obj);

    std::shared_ptr<TransportBase> getTransportObject(std::string& fileRaw);

    std::list<std::shared_ptr<TransportBase>> localList;
    std::string filename;
};

#endif // SERIALIZABLE_H
