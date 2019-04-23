#ifndef POINT_H
#define POINT_H
#include <stdio.h>
#include <iostream>
#include <string.h>

using namespace std;


class Point{
private:
    float x=0;
    float y=0;
public:
    Point(float X=0,float Y=0);
    void setX(float const X);
    void setY(float const Y);
    void setXY(float const X, float const Y);
    float X() const;
    float Y() const;
};

float calc_xyLen(Point const A, Point const B);
void pointsInput(Point * arr,const  unsigned arrSize,const string txt="");

#endif // POINT_H
