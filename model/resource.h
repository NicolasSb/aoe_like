#ifndef Resource_H
#define Resource_H

#include <iostream>
#include <SDL/SDL.h>


#define COLLECT_AREA 70



enum ResType { FOOD = 0, WOOD = 1, STONE = 2, GOLD = 3};
/* type of Resources we are dealing with
each tile may have a Resource type -> NONE = no Resources on a tile.*/


class Resource
{
protected:
    ResType type;   /*to know what type of Resource we are collecting linked with the enum below*/
    int amount;
    int collect_time;
    int dist_to_cam;
    SDL_Rect r;

public:
    Resource();
    Resource(ResType t);
    void set_position (int x, int y);
    void get_coordo (int *x, int *y) const;
    int getDistToCam() const;
    void improve_collect_time ();
    int decreaseResource(int collect);
    void printResource()const;
};



#endif /* Resource_H*/
