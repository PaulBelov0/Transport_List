#pragma once

#ifndef CAR_H
#define CAR_H

#include <Transport/TransportBase/TransportBase.h>

class Car : public TransportBase
{
public:
	Car(uint32_t ID);
	~Car();

    void editOwnersQuantity(int ownersQuantity);
    void editMileage(int mileage);
    QString* print() override;

private:

	int ownersQuantity;
	int mileage;
};

#endif //CAR_H
