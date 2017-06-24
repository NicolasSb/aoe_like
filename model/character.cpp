#include <iostream>
#include <SDL/SDL.h>
#include "character.h"


class character
{
private :
    int hp;
private :
    int damage;
private :
    int armor;
private :
    int attack_range;
private :
    int range;
private :
    Target_s t;
private :
    SDL_Rect r;
private :
    int dest_x;
private :
    int dest_y;
private :
    int type;
private :
    int team;
private :
    int dist_cam;

public : character()
{
    this->t.type = TARGET_INVALID;
    this->t.t = NULL;
}
};
