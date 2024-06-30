#ifndef TRANSPORTCREATOR_H
#define TRANSPORTCREATOR_H

#include <Transport/transport.h>
#include <QString>
#include <QVariant>

class TransportCreator
{
public:
    TransportCreator(const uint32_t& ID, const QString& type,
                     const QString& brand, const QString& model,
                     const uint32_t& year, const uint32_t& weight,
                     const uint32_t& specialFirst, const QString& specialSecond);

    TransportBase& createTransportObject();

private:
    uint32_t ID;
    QString type;
    QString brand;
    QString model;
    uint32_t year;
    uint32_t weight;
    uint32_t specialFirst;
    QString specialSecond;
};

#endif // TRANSPORTCREATOR_H
