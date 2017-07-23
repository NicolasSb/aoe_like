#ifndef RESOURCE_T_H
#define RESOURCE_T_H

#include "resource.h"

#define WOOD_COLLECT_TIME 0.5   /* collect_time correspond to the number of Resources raised per seconds*/
#define FOOD_COLLECT_TIME 0.5
#define STONE_COLLECT_TIME 0.5
#define GOLD_COLLECT_TIME 0.5
#define WOOD_AMOUNT 1000
#define STONE_AMOUNT 2000
#define FOOD_AMOUNT 800
#define GOLD_AMOUNT 2000

class Stone : public Resource
{
public:
    Stone();
    void printStone()const;
};

class Food : public Resource
{
public:
    Food();
    void printFood()const;
};

class Gold : public Resource
{
public:
    Gold();
    void printGold()const;
};

class Wood : public Resource
{
public:
    Wood();
    void printWood()const;
};



#endif // RESOURCE_T_H

