#ifndef SERIALIZATOR_H
#define SERIALIZATOR_H

#include <memory>
#include <list>
#include <iostream>
#include <fstream>
#include <ios>

#include "Transport/TransportCreator/TransportObjectCreator.h"
#include "Transport/Transport.h"

// Класс отвечает за сериализацию и десериализацию структуры данных в файл "database.txt"

class Serializator
{
public:

    Serializator();

    void serialize(std::list<std::shared_ptr<TransportBase>>& inputList);

    std::list<std::shared_ptr<TransportBase>> deserialize();

private:

    inline std::string& objectFieldsToString(std::shared_ptr<TransportBase>& obj);

    std::shared_ptr<TransportBase> getTransportObject(std::string& fileRaw);

    //Fields:

    std::list<std::shared_ptr<TransportBase>> localList;
    std::string filename;
    std::string rawTmp;
};

#endif // SERIALIZATOR_H
