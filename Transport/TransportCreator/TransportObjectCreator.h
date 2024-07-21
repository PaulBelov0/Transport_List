#ifndef TRANSPORTOBJECTCREATOR_H
#define TRANSPORTOBJECTCREATOR_H

#include "Transport/Transport.h"
#include "MessageToUserWindow.h"

#include <QString>
#include <QVariant>
#include <QSignalMapper>
#include <memory>


class TransportObjectCreator
{
public:
    TransportObjectCreator();
    TransportObjectCreator(const uint32_t& ID, const std::string& type,
                           const std::string& brand, const std::string& model,
                           const uint32_t& year, const uint32_t& weight,
                           const uint32_t& specialFieldFirst, const std::string& specialFieldSecond
                           );

    std::shared_ptr<TransportBase> getTransportObject();

private:
    void showDataErrorMessage();

    std::shared_ptr<TransportBase> base;
};

#endif // TRANSPORTOBJECTCREATOR_H
