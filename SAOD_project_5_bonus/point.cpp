#include <math.h>
#include "point.h"

using namespace std;


void pointsInput(Point * arr,const  unsigned arrSize,const string txt){
    float bufFloat=0;
    cout<<endl<<"Enter points for "<<txt<<endl;
    for(unsigned i=0;i<arrSize;i++){
        cout<<endl<<"Enter point X"<<i<<":";
        cin>>bufFloat;
        arr[i].setX(bufFloat);
        cout<<"Enter point Y"<<i<<":";
        cin>>bufFloat;
        arr[i].setY(bufFloat);
    }
}

Point::Point(float X,float Y){
    x = X;
    y = Y;
}

void Point::setX(float const X){
    x = X;
}

void Point::setY(float const Y){
    y = Y;
}

void Point::setXY(float const X, float const Y){
    x = X;
    y = Y;
}

float Point::X() const{
    return x;
}

float Point::Y() const{
    return y;
}

float calc_xyLen(const Point A, const Point B){
    return sqrt( pow((A.X() - B.X()),2) + pow((A.Y() - B.Y()),2) );
}
