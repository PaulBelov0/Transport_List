#pragma once

#ifndef BOAT_H
#define BOAT_H

#include <Transport/TransportBase/TransportBase.h>

class Boat : public TransportBase
{
public:
    Boat(const int& ID, const QString& brand,
         const QString& model, const int& year,
         const int& weight, const int& displacement,
         const int& screwDepth
         );

    Boat(TransportBase* transportObject);

	~Boat();

    void operator=(TransportBase& object) override;
    void editSpecialFirst(const uint32_t& displacement);
    void editSpecialSecond(const QString& screwDepth);
    std::unique_ptr<TransportBase> clone() const override;

    QVariant getSpecialFirst() override;
    QVariant getSpecialSecond() override;

private:
    uint32_t displacement;
    uint32_t screwDepth;
};

#endif //BOAT_H
