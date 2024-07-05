#include <TransportMap/transportmap.h>
#include <Transport/TransportBase/TransportBase.h>


TransportMap::TransportMap()
{
    Car* car = new Car(0, "Test", "Test", 1860, 1000, 100, 12);
    transportDB[0] = car->clone();
    delete car;
}

TransportMap::TransportMap(TransportMap& map)
{
    setMap(map.getMap());
}
TransportMap::~TransportMap() {}

bool TransportMap::findDatabaseElement(const uint32_t& index)
{
    if (!transportDB.empty())
    {
        bool output;
        if (transportDB.count(index))
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

void TransportMap::addNewElement(std::unique_ptr<TransportBase> element)
{
    std::unique_ptr<TransportBase> value = element->clone();
    uint32_t key = value->getID().toInt();

    std::initializer_list<std::pair<const uint32_t, std::unique_ptr<TransportBase>>> list =
        {std::pair<const uint32_t, std::unique_ptr<TransportBase>>(key, value->clone())};

    transportDB.insert(list);
}

void TransportMap::deleteElement(const uint32_t& index)
{
    const auto& iterator = transportDB.find(index);
    if (iterator != transportDB.end())
    {
        transportDB.erase(iterator);
    }
}

std::map<uint32_t, std::unique_ptr<TransportBase>>& TransportMap::getMap()
{
    return transportDB;
}

void TransportMap::setMap(std::map<uint32_t, std::unique_ptr<TransportBase>>& inputMap)
{
    transportDB.clear();

    transportDB = inputMap;
}

