#include <iostream>
#include "building.h"
#include "house.h"

using namespace std;

House::House(int team)
{
    Building(HOUSE);
    this->hp=0;
    this->range=50;
    this->team = team;
}


void House::printBuilding()const
{
    cout << "I am a house from team " << this->team <<endl;
}
