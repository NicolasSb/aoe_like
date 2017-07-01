#include <iostream>
#include "animal.h"


Animal::Animal()
{
    this->range = RANGEA;
    this->target=NULL;
    this->r.h=30;
    this->r.w=30;
    this->r.x=0;
    this->r.y=0;
    this->dist_to_cam = 0;
    this->direction = 0;
}


/**
*   \brief get an animal coordinates
*/

void Animal::get_coordA(int *x, int *y)const
{
    if (this)
    {
        *x=this->r.x;
        *y=this->r.y;
    }
}

/**
*   \brief set the position of the animal
*/

void Animal::set_coordA (int x, int y)
{
    if (this)
    {
        this->r.x=x;
        this->r.y=y;
    }
}

/**
*   \brief animal moves diagonally (one step left and one step above)
*
*   \return 1 whether everything is OK
*/


int Animal::moveA ()
{
    if (this)
    {
        int s = this->speed;
        switch(this->direction)
        {
        case LEFT_ABOVE:
            this->r.x -= s;
            this->r.y -= s;
            return 1;
        case RIGHT_ABOVE:
            this->r.x += s;
            this->r.y -= s;
            return 1;
        case LEFT_BELLOW:
            this->r.x -= s;
            this->r.y += s;
            return 1;
        case RIGHT_BELLOW:
            this->r.x += s;
            this->r.y += s;
            return 1;
        case LEFT:
            this->r.x -= s;
            return 1;
        case RIGHT:
            this->r.x += s;
            return 1;
        case ABOVE:
            this->r.y -= s;
            return 1;
        case BELLOW:
            this->r.y += s;
            return 1;
        default:
            return 0;
        }
    }
    return 0;
}

/**
*   \brief determine whether or not the animal is attacking
*
*   \return 1 whether everything is OK
*/

int Animal::is_attacking ()const
{
    if(this->attack == 1)
        return 1;
    return 0;
}


/**
*   \brief free animal
*/

Animal::~Animal()
{
    if (this)
    {
        this->target = NULL;
    }
}
