#ifndef TRANSPORTOBJECTCREATOR_H
#define TRANSPORTOBJECTCREATOR_H

#include <Transport/transport.h>
#include <QString>
#include <QVariant>
#include <MessageToUserWindow.h>
#include <memory>

class TransportObjectCreator
{
public:
    TransportObjectCreator(const uint32_t& ID, const QString& type,
                     const QString& brand, const QString& model,
                     const uint32_t& year, const uint32_t& weight,
                     const uint32_t& specialFirst, const QString& specialSecond);
    ~TransportObjectCreator();

    TransportBase* getTransportObject();

private:
    void showDataErrorMessage();

    std::unique_ptr<TransportBase> base;
};

#endif // TRANSPORTOBJECTCREATOR_H
