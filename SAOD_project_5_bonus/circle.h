#ifndef CIRCLE_H
#define CIRCLE_H
#include <cmath>
#include "point.h"


using namespace std;


class Circle :public Point{
private:
    float R;
    float S;
    bool hasAllPointsIn = false;
    Point Mid;
public:
    void setR(const float r);
    void calcR(const Point p);
    float r() const;
    void setArea(const float s);
    void calcArea();
    float s() const;
    void setMid(const Point p);
    void hasAllPointsIn_setTrue();
    bool allPointsIn() const;
    Point mid() const;
    void circleMidCalc(const Point A, const Point B, const Point C);
};

#endif // CIRCLE_H
