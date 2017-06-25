#ifndef SWORDMAN_H
#define SWORDMAN_H
#include "character.h"

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

#endif
