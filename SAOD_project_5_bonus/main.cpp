#include <QCoreApplication>
#include <stdio.h>
#include <iostream>
#include <string.h>
#include <cmath>
#include "point.h"
#include "circle.h"
#include "fileio.h"

using namespace std;
using namespace fileInOut;


int main(){
    unsigned m,n;
    cout<<"Ammount of points for the circles: ";
    cin>>m;
    cout<<endl<<"Ammount of points to be inside circles: ";
    cin>>n;
    Point points1[m];
    Point points2[n];
    pointsInput(points1,m,"the circles (points 1)");
    pointsInput(points2,n,"inside circles (points 2)");

    Point A(-1,1);
    Point B(2,-1);
    Point C(4,0);
    Circle C1;
    C1.circleMidCalc(A,B,C);

    Circle tempCrc;
    Circle CirclesArr[m-2];
    for(unsigned i=0;i<m-2;i++){
        CirclesArr[i].circleMidCalc(points1[i],points1[i+1],points1[i+2]);
        CirclesArr[i].calcR(points1[i]);
        CirclesArr[i].calcArea();
        for(unsigned j=0;j<n;j++){
            float lenP2 = calc_xyLen(CirclesArr[i].r(),points2[j]);
            if(lenP2 > CirclesArr[i].r()){ // длина вектора от центра к точке в P2 > радиус - точка вне круга
                break;
            }
            CirclesArr[i].hasAllPointsIn_setTrue(); // круг в котором все точки!
        }
    }

    int resIndex = -1;
    float minArea = std::numeric_limits<float>::max(); // максимальное значение для float из библ. numeric_limits
    for(unsigned i=0;i<m-2;i++){
        if(CirclesArr[i].s() < minArea && CirclesArr[i].allPointsIn()){ // ищем минимальную площадь круга И обхват всего p2 мас
            minArea = CirclesArr[i].s();
            resIndex = i;
        }
    }

    if(resIndex > -1){ // нашелся круг который включил в себя все точки points2
        cout<<"Circle with minimal area that contains all points:"<<endl;
        cout<<"Radius: "<<CirclesArr[resIndex].r()<<" Area: "<<CirclesArr[resIndex].s()<<" Middle: ("<<
              CirclesArr[resIndex].mid().X()<<","<<CirclesArr[resIndex].mid().Y()<<")."<<endl;
    }
    else{
        cout<<"Circles not found!"<<endl;
    }
    writeTxt(points1,points2,m,n,CirclesArr,m-2,resIndex,minArea,"Session 3");
}
