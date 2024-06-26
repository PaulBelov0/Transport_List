#pragma once

#ifndef BOAT_H
#define BOAT_H

#include <Transport/TransportBase/TransportBase.h>

class Boat : public TransportBase
{
public:
	Boat(uint32_t ID);
	~Boat();

    void editDisplacement(int displacement);
    void editScrewDepth(int screwDepth);
    QString* print() override;

private:
	int displacement;
	int screwDepth;
};

#endif //BOAT_H
