#include <iostream>
#include "math_utils.h"
#include <math.h>


double computeDistance(int x1, int y1, int x2, int y2)
{
    return sqrt(pow(x2-x1,2)+pow( y2-y1,2));
}
