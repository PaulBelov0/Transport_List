#include <TransportMap/transportmap.h>

TransportMap::TransportMap(std::map<uint32_t, TransportBase*> map)
{
    for (auto& element : map)
    {
        transportDatabase.insert({element.second->getID().toUInt(), element.second});
    }
}

TransportMap::TransportMap(TransportMap& map)
{
    if (map.getMap().end() != map.getMap().begin())
        for (auto& element : map.getMap())
        {
            transportDatabase.insert({element.second->getID().toUInt(), element.second});
        }
}

TransportMap::~TransportMap() {}

bool TransportMap::findDatabaseElement(const uint32_t& index)
{
    bool output;
    if (transportDatabase.count(index))
    {
        output = true;
    }
    else
    {
        output = false;
        messageToUserWindow.show();
        messageToUserWindow.setTextMessage("Error! No one element have this ID!");
    }
    return output;
}

void TransportMap::addNewElement(const std::unique_ptr<TransportBase> object)
{
    transportDatabase.insert({object->getID().toUInt(), object.get()});
}

void TransportMap::deleteElement(const uint32_t& index)
{
    if (transportDatabase.count(index) > 0 && !transportDatabase.empty())
    {
        const auto& iterator = transportDatabase.find(index);

        if (iterator != transportDatabase.end() && iterator != transportDatabase.begin())
        {
            transportDatabase.erase(iterator);
        }
    }
}

std::map<uint32_t, TransportBase*> TransportMap::getMap()
{
    return transportDatabase;
}

void TransportMap::insertPair(TransportBase* object)
{
    transportDatabase.insert({object->getID().toUInt(), object});
}