#include <iostream>
#include "character.h"
#include "villager.h"

using namespace std;

Villager::Villager(int team)
{
    Character(VILLAGER);
    this->armor = VILLAGER_ARMOR;
    this->attack_range = VILLAGER_ATTACK_RANGE;
    this->damage=VILLAGER_DAMAGE;
    this->range=VILLAGER_RANGE;
    this->action =  WAIT;
    this->team = team;
}

void Villager::printCharacter() const
{
    cout << "I am a Villager from the team " << this->team <<endl;
    Character::printCharacter();
}
