#include <TransportMap/transportmap.h>
#include <Transport/TransportBase/TransportBase.h>

TransportMap::TransportMap(uint32_t index)
{

}
TransportMap::~TransportMap(){}

QString* TransportMap::print(uint32_t& index)
{
    QString* outputString = transportDB->at(index).print();
}
