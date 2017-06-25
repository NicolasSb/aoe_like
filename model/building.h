#ifndef BUILDING_H
#define BULDING_H

#include <SDL/SDL.h>

enum type_building
{HOUSE, BARRACKS, CITY_HALL, TOWER
};
enum action_building {SLEEP, BUILD_PERSO, CONSTRUCT_P};


class Building
{
protected :
    int range;
    int hp;
    int type;
    int action;
    SDL_Rect building_r;
    int team;
    int dist_to_cam;
    void *target;

public :
    Building();
    Building(int type);
    void setActionFlag(int flag);
    void setTargetB(void *);
    int getActionFlag()const;
    int getHP()const;
    void increaseHP(int a);
    void decreaseHP(int);
    void printBuilding()const;
};





#endif // BUILDING_H
