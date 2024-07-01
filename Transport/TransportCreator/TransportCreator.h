#ifndef TRANSPORTCREATOR_H
#define TRANSPORTCREATOR_H

#include <Transport/transport.h>
#include <QString>
#include <QVariant>
#include <MessageToUserWindow.h>

class TransportCreator
{
public:
    TransportCreator(const uint32_t& ID, const QString& type,
                     const QString& brand, const QString& model,
                     const uint32_t& year, const uint32_t& weight,
                     const uint32_t& specialFirst, const QString& specialSecond);
    ~TransportCreator();

    TransportBase& createTransportObject();

private:

    TransportBase* base;
};

#endif // TRANSPORTCREATOR_H
