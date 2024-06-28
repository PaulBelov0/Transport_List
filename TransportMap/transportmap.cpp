#include <TransportMap/transportmap.h>
#include <Transport/TransportBase/TransportBase.h>


TransportMap::TransportMap() {}
TransportMap::~TransportMap() {}

bool TransportMap::findDatabaseElement(const uint32_t& index)
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

void TransportMap::addNewElement(uint32_t index, TransportBase& data)
{
    if (transportDB->count(index) == false)
    {
        transportDB->insert(std::pair<uint32_t, TransportBase&>(index, data));
    }
    else
    {
        messageToUserWindow.show();
    }
}

void TransportMap::deleteElement(const uint32_t& index)
{
    if (transportDB->count(index) == true)
    {
        transportDB->erase(index);
    }
}

std::map<uint32_t, TransportBase&>& TransportMap::getMap()
{
    std::map<uint32_t, TransportBase&>& outputMap = *transportDB;
    return outputMap;
}

