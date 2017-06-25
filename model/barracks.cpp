#include <iostream>
#include "building.h"
#include "barracks.h"

using namespace std;

Barrack::Barrack(int team)
{
    Building(BARRACKS);
    this->hp=0;
    this->range=60;
    this->team = team;
}


void Barrack::printBuilding()const
{
    cout << "I am a barrack from team " << this->team <<endl;
}
