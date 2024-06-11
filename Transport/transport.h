#ifndef _TRANSPORT_H_
#define _TRANSPORT_H_

#include <Transport/TransportBase/TransportBase.h>

class AirTransport : public TransportBase
{
public:
	AirTransport(uint32_t ID);
	~AirTransport();

	inline void editWingspan(int wingspan);
	inline void editPayloadCapacity(int payloadCapacity);
	inline void print() override;

private:
	int wingspan;
	int payloadCapacity;
};


class Boat : public TransportBase
{
public:
	Boat(uint32_t ID);
	~Boat();

	inline void editDisplacement(int displacement);
	inline void editScrewDepth(int screwDepth);
	inline void print() override;

private:
	int displacement;
	int screwDepth;
};


class Car : public TransportBase
{
public:
	Car(uint32_t ID);
	~Car();

	inline void editOwnersQuantity(int ownersQuantity);
	inline void editMileage(int mileage);
	inline void print() override;

private:

	int ownersQuantity;
	int mileage;
};


class Shuttle : public TransportBase
{
public:
	Shuttle(uint32_t ID);
	~Shuttle();

	inline void editFuelType(std::string fuelType);
	inline void editMaxFlyingDistance(int maxFlyingDistance);
	inline void print() override;

private:
	std::string fuelType;
	int maxFlyingDistance;
};

#endif