#ifndef BUILDING_T_H
#define BUILDING_T_H

#include "building.h"

#define BARRACKS_HP 400

class Barrack : public Building
{
public :
    Barrack(int team);
    void printBuilding()const;
};

#define CHALL 600

class CityHall : public Building
{
public :
    CityHall(int team);
    void printBuilding()const;
};

#define HOUSE_HP 250

class House : public Building
{
public :
    House(int team);
    void printBuilding()const;
};

#define TOWER_HP 400

class Tower : public Building
{
public :
    Tower(int team);
    void printBuilding()const;
};


#endif
