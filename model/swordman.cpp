#include <iostream>
#include "character.h"
#include "swordman.h"

using namespace std;

Swordman::Swordman(int team)
{
    Character(SWORDMAN);
    this->armor = SWORDMAN_ARMOR;
    this->attack_range = SWORDMAN_ATTACK_RANGE;
    this->damage=SWORDMAN_DAMAGE;
    this->range=SWORDMAN_RANGE;
    this->action =  WAIT;
    this->team = team;
}

void Swordman::printCharacter()const
{
    cout << "I am a swordman from the team " << this->team<< endl;
    Character::printCharacter();
}
