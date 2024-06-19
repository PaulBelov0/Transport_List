#pragma once

#ifndef _CAR_H_
#define _CAR_H_

#include "TransportBase/TransportBase.h"

class Car : public TransportBase
{
public:
	Car(uint32_t ID);
	~Car();

	inline void editOwnersQuantity(int ownersQuantity);
	inline void editMileage(int mileage);
	inline void print() override;
	inline std::string finderOnValueType(char typeOfValue) override;

private:

	int ownersQuantity;
	int mileage;
};

#endif