#ifndef VILLAGER_H
#define VILLAGER_H
#include "character.h"

#define VILLAGER_ARMOR 5
#define VILLAGER_ATTACK_RANGE 30
#define VILLAGER_DAMAGE 10
#define VILLAGER_HP 50
#define VILLAGER_RANGE 50

class Villager : public Character
{
public :
    Villager(int team);
    void printCharacter()const;
};

#endif // VILLAGER_H
