#ifndef _Utilities_H_
#define _Utilities_H_

#include <ctime>
#include <cmath>
#include <iostream>
#include <fstream>

//Field limits
static const unsigned FIELD_XMAX = 61;
static const unsigned FIELD_YMAX = 30;
//Attritbutes vector indexes
static const unsigned v_x = 0;
static const unsigned v_y = 1;
static const unsigned v_velocity_x = 2;
static const unsigned v_velocity_y = 3;
//Attributes and Coordinates vector size
static const unsigned _Attributes = 4;
static const unsigned _Coordinates = 2;

using namespace std;

//Return distance between two coordinates
static inline const double EuclideanDistance(const double& x1,const double& y1,const double& x2,const double& y2)
{
    double x = x1 - x2;
    double y = y1 - y2;
    double dist;

    dist = pow(x,2)+pow(y,2);           //calculating distance by euclidean formula
    dist = sqrt(dist);                  //sqrt is function in math.h

    return dist;
}

#endif


