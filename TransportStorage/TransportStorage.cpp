#include "TransportStorage/TransportStorage.h"

TransportStorage::TransportStorage(std::map<uint32_t, TransportBase*> map)
{
    for (auto& element : map)
    {
        transportDatabase.insert({element.second->getID().toUInt(), element.second});
    }
}

TransportStorage::TransportStorage(TransportStorage& map)
{
    transportDatabase = map.tanspotDatabase;
}

bool TransportStorage::findDatabaseElement(const uint32_t& index)
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

void TransportStorage::addNewElement(const TransportBase* object)
{
    transportDatabase.insert({object->getID().toUInt(), object});
}

void TransportStorage::deleteElement(const uint32_t& index)
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

std::map<uint32_t, TransportBase*> TransportStorage::getMap()
{
    return transportDatabase;
}

void TransportStorage::insertPair(TransportBase* object)
{
    transportDatabase.insert({object->getID().toUInt(), object});
}
