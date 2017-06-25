#ifndef ARCHER_H
#define ARCHER_H
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

#endif
