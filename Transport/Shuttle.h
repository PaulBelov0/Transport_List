#pragma once

#ifndef _SHUTTLE_H_
#define _SHUTTLE_H_

#include "TransportBase/TransportBase.h"

class Shuttle : public TransportBase
{
public:
	Shuttle(uint32_t ID);
	~Shuttle();

	inline void editFuelType(std::string fuelType);
	inline void editMaxFlyingDistance(int maxFlyingDistance);
	inline void print() override;
	inline std::string finderOnValueType(char typeOfValue) override;

private:
	std::string fuelType;
	int maxFlyingDistance;
};

#endif