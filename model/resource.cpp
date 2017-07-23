#include <iostream>
#include "resource.h"
#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>
#include <cmocka.h>
/**
*
*   \file resource.c
*
*   \brief Resource model functions
*
*   \author Sourbier Nicolas
*
*   \date 23/07/2017
*/

using namespace std;

Resource::Resource()
{
    this->r.x = 5;
    this->r.y = 5;
    this->r.h = 100;
    this->r.w = 100;
    this->dist_to_cam = 0;
}

/**
*   \brief construct a resource specifying a type
*/
Resource::Resource(ResType t)
{
    Resource();
    this->type = t;
}
/**
*   \brief update the position of a resource
*/
void Resource::set_position (int x, int y)
{
    if(this)
    {
        this->r.x = x;
        this->r.y = y;
    }
}
/**
*   \brief get the position of a resource
*/
void Resource::get_coordo (int *x, int *y) const
{
    if (this)
    {
    *x = this->r.x;
    *y = this->r.y;
    }
}

int Resource::getDistToCam() const
{
    return this->dist_to_cam;
}

/**
*   \brief improve the collect time
*/
void Resource::improve_collect_time ()
{
    if(this)
    {
        this->collect_time *= 1.5;
    }
}
/**
*   \brief decrease the resource of int collect
*/
int Resource::decreaseResource(int collect)
{
    if (this)
    {
        if (this->amount > collect)
        {
            this->amount -= collect;
            return collect;
        }
        else if (this->amount >0 && this->amount < collect)
        {
            int tmp = this->amount;
            this->amount = 0;
            return tmp;
        }
    }
    return -1;
}

void Resource::printResource()const
{
    std::cout << "I have " << this->amount << "resources left" << std::endl;
}

