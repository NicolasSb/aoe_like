#include <iostream>
#include "buildingType.h"


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
