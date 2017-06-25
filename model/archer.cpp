#include <iostream>
#include "character.h"
#include "archer.h"

using namespace std;

Archer::Archer(int team)
{
    Character(ARCHER);
    this->armor = ARCHER_ARMOR;
    this->attack_range = ARCHER_ATTACK_RANGE;
    this->damage=ARCHER_DAMAGE;
    this->range=ARCHER_RANGE;
    this->action =  WAIT ;
    this->team = team;
}

void Archer::printCharacter()const
{
    cout << "I am an archer from the team " << this->team << endl;
    Character::printCharacter();
}


