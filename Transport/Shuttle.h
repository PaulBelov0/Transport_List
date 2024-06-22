#pragma once

#ifndef SHUTTLE_H
#define SHUTTLE_H

#include <Transport/TransportBase/TransportBase.h>

class Shuttle : public TransportBase
{
public:
	Shuttle(uint32_t ID);
	~Shuttle();

    void editFuelType(std::string fuelType);
    void editMaxFlyingDistance(int maxFlyingDistance);
    QString* print() override;
    std::string finderOnValueType(char typeOfValue) override;

private:
	std::string fuelType;
	int maxFlyingDistance;
};

#endif //SHUTTLE_H
