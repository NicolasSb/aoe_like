#include <iostream>
#include "building.h"
#include "cityHall.h"

using namespace std;

CityHall::CityHall(int team)
{
    Building(CITY_HALL);
    this->hp=0;
    this->range=80;
    this->team = team;
}


void CityHall::printBuilding()const
{
    cout << "I am a city hall from team " << this->team <<endl;
}
