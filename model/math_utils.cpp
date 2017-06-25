#include <iostream>
#include "math_utils.h"
#include <math.h>


double computeDistance(int x1, int y1, int x2, int y2)
{
    int x = x2-x1;
    int y = y2-y1;
    return sqrt(pow(x,2)+pow(y,2));
}
