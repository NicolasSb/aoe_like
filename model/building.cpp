#include <iostream>
#include "building.h"

using namespace std;

Building::Building()
{
    this->action=SLEEP;
    this->building_r.h=120;
    this->building_r.w=120;
    this->building_r.x=0;
    this->building_r.y=100;
    this->dist_to_cam = 0;
    this->target = NULL;
}

Building::Building(type_building type)
{
    Building();
    this->type = type;
}
void Building::setActionFlag(action_building flag)
{
    this->action = flag;
}
void Building::setTargetB(void *target)
{
    this->target = target;
}

int Building::getActionFlag()const
{
    return this->action;
}

int Building::getDistToCam() const
{
    return this->dist_to_cam;
}

int Building::getHP()const
{
    return this->hp;
}

void Building::increaseHP(int a)
{
    this->hp += a;
}

void Building::decreaseHP(int a)
{
    this->hp -= a;
}

void Building::printBuilding()const
{
    cout << "I have "<<this->hp<<"hp" << endl;
}

Building::~Building()
{
    this->target = NULL;
}
