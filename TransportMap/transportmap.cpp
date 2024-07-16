#include <TransportMap/transportmap.h>
#include <Transport/TransportBase/TransportBase.h>

TransportMap::TransportMap(std::map<uint32_t, std::unique_ptr<TransportBase>> map)
{
    for (auto& element : map)
    {
        transportDatabase.insert({element.second->clone()->getID().toUInt(), element.second->clone()});
    }
}

TransportMap::TransportMap(TransportMap& map)
{
    for (auto& mapElement : map.getMap())
    {
        transportDatabase.insert({mapElement.second.get()->clone()->getID().toUInt(), mapElement.second.get()->clone()});
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
    transportDatabase.insert({object->clone()->getID().toUInt(), object->clone()});
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

std::map<uint32_t, std::unique_ptr<TransportBase>> TransportMap::getMap()
{
    std::map<uint32_t, std::unique_ptr<TransportBase>> outputMap;
    return outputMap;
}

void TransportMap::insertPair(const TransportBase* object)
{
    transportDatabase.insert({object->clone()->getID().toUInt(), object->clone()});
}
