#include <TransportMap/transportmap.h>
#include <Transport/TransportBase/TransportBase.h>


TransportMap::TransportMap() {}

TransportMap::TransportMap(TransportMap& map)
{
    setMap(map.getMap());
}
TransportMap::~TransportMap() {}

bool TransportMap::findDatabaseElement(const uint32_t& index)
{
    if (transportDB->empty() != true)
    {
        bool output;
        if (transportDB->count(index) == true)
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
    else
    {
        return false;
    }
}

void TransportMap::addNewElement(uint32_t key, TransportBase& element)
{
    const auto& iterator = transportDB->find(key);
    if (iterator != transportDB->end())
    {
        const auto& iter = transportDB->end();
        transportDB->insert(iter, std::pair<uint32_t, TransportBase&>(key, element));
    }
    else
    {
        messageToUserWindow.show();
        messageToUserWindow.setTextMessage("Error! No one element have this ID!");
    }
}

void TransportMap::deleteElement(const uint32_t& index)
{
    const auto& iterator = transportDB->find(index);
    if (iterator != transportDB->end())
    {
        transportDB->erase(iterator);
    }
}

std::map<uint32_t, TransportBase&>& TransportMap::getMap()
{
    return *transportDB;
}

void TransportMap::setMap(std::map<uint32_t, TransportBase&>& inputMap)
{
    transportDB->clear();

    *transportDB = inputMap;
}

