#ifndef ANIMAL_H
#define ANIMAL_H

#include<SDL/SDL.h>

#define ATTACK_RANGE_ANI 25
#define RANGEA 100





enum animalType { WOLF, BOAR, SHEEP, STAG}; /* type of ressources we are dealing with
 each tile may have a ressource type -> NONE = no ressources on a tile.1000000,*/
typedef enum movement{LEFT, RIGHT, ABOVE, BELLOW, LEFT_BELLOW, LEFT_ABOVE, RIGHT_BELLOW, RIGHT_ABOVE, NO_MOVE} movement;


class Animal
{
protected:
    int type;
    int life_point;
    int attack;     /*to know whether the animal is attacking or not*/
    int dommage;
    int speed;
    int range;
    int meat;
    int dist_to_cam;
    int direction;
    void *target;
    SDL_Rect r;
    SDL_Surface *s;


public:

    Animal();
    void set_coordA(int x, int y);
    void get_coordA(int *x, int *y)const;

    int moveA();

    int is_attacking ()const;

    ~Animal();
};






#endif
