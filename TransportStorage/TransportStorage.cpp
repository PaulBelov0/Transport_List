#include "TransportStorage/TransportStorage.h"

TransportStorage::TransportStorage(std::list<std::shared_ptr<TransportBase>> list)
{
    for (auto& element : list)
    {
        transportDatabase.push_back(element);
    }
}

TransportStorage::TransportStorage(TransportStorage& list)
{
    transportDatabase = list.transportDatabase;
}

TransportStorage::TransportStorage()
{
    std::shared_ptr<TransportBase> testObj(new TransportBase(std::vector<std::string>{"0", "1", "0", "0", "0", "0"}));
    transportDatabase.push_back(testObj);
}

bool TransportStorage::findDatabaseElement(const uint32_t& index)
{
    bool output = false;
    for(auto& element : transportDatabase)
    {
        if (element->uniqueID == index)
        {
            output = true;
        }
    }
    return output;
}

void TransportStorage::addNewElement(std::shared_ptr<TransportBase> object)
{
    transportDatabase.push_back(object);
}

void TransportStorage::deleteElement(const uint32_t& index)
{
    for (std::list<std::shared_ptr<TransportBase>>::const_iterator iter = transportDatabase.begin(); iter != transportDatabase.end(); ++iter)
    {
        if(iter->get()->uniqueID == index)
        {
            transportDatabase.erase(iter);
            return;
        }
    }
}

std::list<std::shared_ptr<TransportBase>>& TransportStorage::getList()
{
    return transportDatabase;
}

bool TransportStorage::checkListEmpty()
{
    if (transportDatabase.size() == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}
