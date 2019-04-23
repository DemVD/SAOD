#include <math.h>
#include "circle.h"

using namespace std;


void Circle::setR(const float r){ R = r; }

void Circle::calcR(const Point p){ R = calc_xyLen(Mid,p); }

float Circle::r() const{ return R; }

void Circle::setArea(const float s){ S = s; }

void Circle::calcArea(){ S = M_PI * pow(R,2); }

float Circle::s() const{ return S; }

void Circle::setMid(const Point p){ Mid = p; }

void Circle::hasAllPointsIn_setTrue(){ hasAllPointsIn = true; }

bool Circle::allPointsIn() const{ return hasAllPointsIn; }

Point Circle::mid() const{ return Mid; }

void Circle::circleMidCalc(const Point A, const Point B, const Point C){
    float t1 = B.X() - A.X();
    float t2 = B.Y() - A.Y();
    float t3 = C.X() - A.X();
    float t4 = C.Y() - A.Y();
    float e1 = t1 * (A.X() + B.X()) + t2 * (A.Y() + B.Y());
    float e2 = t3 * (A.X() + C.X()) + t4 * (A.Y() + C.Y());
    float e3 = 2 * (t1 * (C.Y() - B.Y()) - t2 * (C.X() - B.X()));
    float Cx = (t4*e1 - t2*e2)/e3;
    float Cy = (t1*e2 - t3*e1)/e3;
    Point M(Cx,Cy);
    setMid(M);
}

