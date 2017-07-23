#include <iostream>
#include "resource.h"
#include "resourceType.h"

using namespace std;

Stone::Stone()
{
    Resource(STONE);
    this->amount = STONE_AMOUNT;
}

void Stone::printStone() const
{
    std::cout<<"Hello I am a stone" <<endl;
    Resource::printResource();
}
