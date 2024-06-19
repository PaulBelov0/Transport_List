#pragma once

#ifndef _BOAT_H_
#define _BOAT_H_

#include "TransportBase/TransportBase.h"

class Boat : public TransportBase
{
public:
	Boat(uint32_t ID);
	~Boat();

	inline void editDisplacement(int displacement);
	inline void editScrewDepth(int screwDepth);
	inline void print() override;
	inline std::string finderOnValueType(char typeOfValue) override;

private:
	int displacement;
	int screwDepth;
};

#endif