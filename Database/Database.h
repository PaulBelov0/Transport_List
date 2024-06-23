#ifndef DATABASE_H
#define DATABASE_H

#include <TransportMap/transportmap.h>

class Database
{
public:
    Database();
    ~Database();

    TransportMap& download();
    void upload(TransportMap& database);
};

#endif // DATABASE_H
