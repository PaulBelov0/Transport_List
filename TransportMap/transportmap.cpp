#include <TransportMap/transportmap.h>
#include <Transport/TransportBase/TransportBase.h>


TransportMap::TransportMap() {}
TransportMap::~TransportMap() {}

QString* TransportMap::showDatabaseElement(const uint32_t& index)
{
    QString* outputString;
    if (transportDB->count(index) == true)
    {
        outputString = transportDB->find(index)->second.print();
    }
    else
    {
        ElementIDErrorWindow error;
        error.show();
    }
    return outputString;
}

void TransportMap::addNewElement(uint32_t index, TransportBase& data)
{
    if (transportDB->count(index) == false)
    {
        transportDB->insert(std::pair<uint32_t, TransportBase&>(index, data));
    }
    else
    {
        ElementIDErrorWindow error;
        error.show();
    }
}

void TransportMap::deleteElement(const uint32_t& index)
{
    if (transportDB->count(index) == true)
    {
        transportDB->erase(index);
    }
}
