#include <TransportMap/transportmap.h>
#include <Transport/TransportBase/TransportBase.h>


TransportMap::TransportMap() {}
TransportMap::~TransportMap() {}

QString* TransportMap::showDatabaseElement(const uint32_t& index)
{
    QString* outputString = transportDB->find(index)->second.print();
    return outputString;
}

void TransportMap::addNewElement(uint32_t& index, TransportBase& data)
{
    transportDB->insert(std::pair<uint32_t, TransportBase&>(index, data));
}

void deleteElement(const uint32_t& index)
{

}
