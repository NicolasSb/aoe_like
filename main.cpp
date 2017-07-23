#include <iostream>
#include "model/characterType.h"
#include "model/resourceType.h"
#include "model/animalType.h"
#include "model/buildingType.h"
using namespace std;

int main()
{

    Swordman a(1);
    Swordman b(2);
    Stone st;
    a.increaseHp(100);
    b.increaseHp(100);
    a.setTarget((void*) &b, TARGET_CHARACTER);
    a.attack();
    b.printCharacter();
    a.printCharacter();
    st.printResource();
    return 0;
}
