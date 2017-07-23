#include <iostream>
#include "resource.h"
#include "resourceType.h"

using namespace std;

Stone::Stone()
{
    Resource(STONE);
    this->amount = STONE_AMOUNT;
}

void Stone::printStone() const
{
    std::cout<<"Hello I am a stone" <<endl;
    Resource::printResource();
}

Wood::Wood()
{
    Resource(WOOD);
    this->amount = WOOD_AMOUNT;
}

void Wood::printWood() const
{
    std::cout<<"Hello I am wood" <<endl;
    Resource::printResource();
}

Gold::Gold()
{
    Resource(GOLD);
    this->amount = GOLD_AMOUNT;
}

void Gold::printGold() const
{
    std::cout<<"Hello I am a goldmine 8D" <<endl;
    Resource::printResource();
}

Food::Food()
{
    Resource(FOOD);
    this->amount = FOOD_AMOUNT;
}

void Food::printFood() const
{
    std::cout<<"Hello I am a piece of meat" <<endl;
    Resource::printResource();
}
