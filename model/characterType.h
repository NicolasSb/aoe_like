#ifndef CHARACTER_T_H
#define CHARACTER_T_H
#include "character.h"

#define ARCHER_ARMOR 10
#define ARCHER_ATTACK_RANGE 120
#define ARCHER_DAMAGE 20
#define ARCHER_HP 50
#define ARCHER_RANGE 50

class Archer : public Character
{
public :
    Archer(int team);
    void printCharacter()const;
};

#define SWORDMAN_ARMOR 10
#define SWORDMAN_ATTACK_RANGE 30
#define SWORDMAN_DAMAGE 30
#define SWORDMAN_HP 60
#define SWORDMAN_RANGE 50

class Swordman : public Character
{
public :
    Swordman(int team);
    void printCharacter()const;
};


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


#endif
