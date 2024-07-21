#include "TransportStorage/TransportStorage.h"

TransportStorage::TransportStorage(std::map<uint32_t, std::shared_ptr<TransportBase>> map)
{
    for (auto& element : map)
    {
        transportDatabase.insert({element.second->getID(), element.second});
    }
}

TransportStorage::TransportStorage(TransportStorage& map)
{
    transportDatabase = map.transportDatabase;
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

void TransportStorage::addNewElement(std::shared_ptr<TransportBase> object)
{
    transportDatabase.insert(std::make_pair(object->getID(), object));
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

std::map<uint32_t, std::shared_ptr<TransportBase>> TransportStorage::getMap()
{
    return transportDatabase;
}

void TransportStorage::insertPair(std::shared_ptr<TransportBase> object)
{
    transportDatabase.insert({object->getID(), object});
}
