#include <iostream>
#include "building.h"
#include "tower.h"

using namespace std;

Tower::Tower(int team)
{
    Building(TOWER);
    this->hp=0;
    this->range=80;
    this->team = team;
}


void Tower::printBuilding()const
{
    cout << "I am a tower from team " << this->team <<endl;
}
