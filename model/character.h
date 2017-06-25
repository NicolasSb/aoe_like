#ifndef CHAR_H
#define CHAR_H
#include <SDL/SDL.h>


typedef struct Target_s Target_s;
struct Target_s
{
    int type;
    void *t;
};

enum type_characters{
    VILLAGER, SWORDMAN, ARCHER
};

enum action_flag
{
    WAIT, MOVE, ATTACK, COLLECT, BUILD, CONSTRUCT, DO_NOTHING
};

enum target_t
{
    TARGET_INVALID=0,
    TARGET_RESSOURCE,
    TARGET_CHARACTER,
    TARGET_BUILDING,
    TARGET_ANIMALS
};


class Character
{
protected :
    int hp;
    int damage;
    int armor;
    int attack_range;
    int range;
    Target_s t;
    SDL_Rect r;
    int dest_x;
    int dest_y;
    int type;
    int team;
    int dist_cam;
    int action;

public :
    Character();// constructeur
    Character(int type);
    void setCoord(int x, int y);
    int attack();
    int setAttacked(Character *enemy);
    int followC(Character *enemy);
    int moveC(int x, int y);
    int chooseMoveCode(int x, int y)const;
    void getCoordinates(int *, int*)const;
    int getTeam()const;
    void setTarget(void *target, int target_Type);
    void setActionFlagC(int action_flag);
    int getActionFlagC()const;
    void setTeam(int team_number);
    void setRect(SDL_Rect r);
    void increaseHp(int);
    void decreaseHp(int);
    void printCharacter()const;
    ~Character();
};
#endif // CHAR_H
