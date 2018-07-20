#ifndef BEHAVIOR
#define BEHAVIOR

#include <iostream>
#include <cassert>
#include <vector>
#include <algorithm>
#include <cmath>


using namespace std;

double leadGapTarget( double object_speed)
{
    return 1.1*abs(object_speed);
}


bool leadCarTooClose( double host_speed, double object_speed, double object_s)
{
    double gap_target = host_speed;
    if (object_speed *3 < object_s)
    {
        return true;
    }
    else
    {
        return false;
    }


}


#endif