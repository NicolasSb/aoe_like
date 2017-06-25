#include <iostream>
#include "model/character.h"
#include "model/villager.h"
#include "model/archer.h"
#include "model/swordman.h"

using namespace std;

int main()
{

    Swordman a(1);
    Swordman b(2);
    a.increaseHp(100);
    b.increaseHp(100);
    a.setTarget((void*) &b, TARGET_CHARACTER);
    a.attack();
    b.printCharacter();
    a.printCharacter();
    return 0;
}
