#include <iostream>
#include "character.h"
#include "characterType.h"

using namespace std;

Archer::Archer(int team)
{
    Character(ARCHER);
    this->armor = ARCHER_ARMOR;
    this->attack_range = ARCHER_ATTACK_RANGE;
    this->damage=ARCHER_DAMAGE;
    this->range=ARCHER_RANGE;
    this->action =  DO_NOTHING;
    this->team = team;
}

void Archer::printCharacter()const
{
    cout << "I am an archer from the team " << this->team << endl;
    Character::printCharacter();
}


Swordman::Swordman(int team)
{
    Character(SWORDMAN);
    this->armor = SWORDMAN_ARMOR;
    this->attack_range = SWORDMAN_ATTACK_RANGE;
    this->damage=SWORDMAN_DAMAGE;
    this->range=SWORDMAN_RANGE;
    this->action = DO_NOTHING;
    this->team = team;
}

void Swordman::printCharacter()const
{
    cout << "I am a swordman from the team " << this->team<< endl;
    Character::printCharacter();
}

Villager::Villager(int team)
{
    Character(VILLAGER);
    this->armor = VILLAGER_ARMOR;
    this->attack_range = VILLAGER_ATTACK_RANGE;
    this->damage=VILLAGER_DAMAGE;
    this->range=VILLAGER_RANGE;
    this->action = DO_NOTHING;
    this->team = team;
}

void Villager::printCharacter() const
{
    cout << "I am a Villager from the team " << this->team <<endl;
    Character::printCharacter();
}
