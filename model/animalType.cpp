#include <iostream>
#include "animal.h"
#include "animalType.h"


Boar::Boar()
{
    Animal();
    this->type = BOAR;
    this->life_point = BOAR_HP;
    this->attack = 0;                       /*Two states : 0 isn't attacking, 1 is attacking*/
    this->meat = BOAR_MEAT;
    this->dommage = BOAR_DAMMAGE;
    this->speed = BOAR_SPEED;
}

Stag::Stag()
{
    Animal();
    this->type = STAG;
    this->life_point = STAG_HP;
    this->attack = 0;
    this->meat = STAG_MEAT;
    this->dommage = STAG_DAMMAGE;
    this->speed = STAG_SPEED;
}

Sheep::Sheep()
{
    Animal();
    this->type = SHEEP;
    this->life_point = SHEEP_HP;
    this->attack = 0;
    this->meat = SHEEP_MEAT;
    this->dommage = SHEEP_DAMMAGE;
    this->speed = SHEEP_SPEED;
}

Wolf::Wolf()
{
    Animal();
    this->type = WOLF;
    this->life_point = WOLF_HP;
    this->attack = 0;
    this->meat = WOLF_MEAT;
    this->dommage = WOLF_DAMMAGE;
    this->speed = WOLF_SPEED;
}

