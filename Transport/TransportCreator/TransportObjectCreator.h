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

     TransportObjectCreator(std::vector<std::string> args);

    std::shared_ptr<TransportBase>& getTransportObject();

private:
    void showDataErrorMessage();

    std::shared_ptr<TransportBase> base;
};

#endif // TRANSPORTOBJECTCREATOR_H
