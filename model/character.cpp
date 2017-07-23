#include <iostream>
#include <SDL/SDL.h>
#include "character.h"
#include "math_utils.h"

using namespace std;

Character::Character()
{
    this->hp=0;
    this->r.x=65;
    this->r.y=200;
    this->r.h=40;
    this->r.w=20;
    this->t.t= NULL;
    this->t.type=TARGET_INVALID;
    this->dist_cam = 0;
};

Character::Character(int type)
{
    Character();
    this->type = type;
}

void Character::setCoord(int x, int y)
{
    this->r.x = (Sint16) x;
    this->r.y = (Sint16) y;
}

int Character::attack()
{
    int attack_distance, enemy_team_number, player_team_number, tmp_distPlX, tmp_distPlY, tmpDist_enX, tmpDist_enY;
    if (this!= NULL && this->t.t !=NULL){
        Character *enemy = static_cast<Character*> (this->t.t);
        enemy_team_number = enemy->getTeam();
        player_team_number = this->getTeam();
        this->getCoordinates(&tmp_distPlX, &tmp_distPlY);
        enemy->getCoordinates(&tmpDist_enX, &tmpDist_enY);
        tmp_distPlX +=this->r.w/2;
        tmp_distPlY +=this->r.h/2;
        tmpDist_enX +=enemy->r.w/2;
        tmpDist_enX +=enemy->r.h/2;
        attack_distance = computeDistance(tmp_distPlX,tmp_distPlY,tmpDist_enX,tmpDist_enY);
        if(this->attack_range > attack_distance && enemy_team_number != player_team_number){
           if (enemy->hp <=0){
                    this->setActionFlagC(WAIT);
                    return 1;
           }
           else if(enemy->hp >0){
                enemy->decreaseHp(abs((this->damage)-enemy->armor));
                enemy->setAttacked(this);
           }
        }
        else {
            this->followC(enemy);
        }

    return 0;
    }
    return -1;
}

int Character::setAttacked(Character *enemy)
{
    if( this !=NULL && enemy != NULL){
        this->setTarget((void*) enemy, TARGET_CHARACTER);
        if (this->action == WAIT || this->action == MOVE)
            this->setActionFlagC(ATTACK);
        return 0;
    }
    return -1;
}

int Character::followC(Character *enemy)
{
    return 0;
}

int Character::moveC(int x, int y)
{
    return 0;
}

int Character::chooseMoveCode(int x, int y) const
{
    return 0;
}

void Character::getCoordinates(int *x, int*y) const
{
    *x = this->r.x;
    *y = this->r.y;
}

int Character::getTeam()const
{
    return this->team;
}

void Character::setTarget(void *target, int target_Type)
{
    this->t.type = target_Type;
    this->t.t = target;
}

void Character::setActionFlagC(int a)
{
    this->action = a;
}

int Character::getActionFlagC()const
{
    return this->action;
}

void Character::setTeam(int team_number)
{
    this->team = team_number;
}

void Character::setRect(SDL_Rect r)
{
    this->r.x=r.x;
    this->r.y=r.y;
    this->r.h=r.h;
    this->r.w=r.w;
}
void Character::increaseHp(int a)
{
    this->hp +=a;
}

void Character::decreaseHp(int a)
{
    this->hp -= a;
}


void Character::printCharacter() const
{
    std::cout << "I have " << this->hp << "Hp" << std::endl;
}

Character::~Character()
{
    this->t.t = NULL;
}
