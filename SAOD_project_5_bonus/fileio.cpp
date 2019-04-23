#include <fstream>
#include <iostream>
#include <vector>
#include "fileio.h"

using namespace std;


namespace fileInOut{
void writeTxt(Point * p1, Point * p2, unsigned const p1size, unsigned const p2size, Circle * c0,
              unsigned const c0size, int const resIndex, float const minArea, string txt){
    ofstream out("SAOD_proj5.txt",std::ios::app);
    if (out.is_open()){
        out<<txt<<endl;
        string tempStr="Points for circles: ";
        for(unsigned i=0;i<p1size;i++){
            tempStr += "("+to_string(p1[i].X())+";"+to_string(p1[i].Y())+"),";
        }
        out<<tempStr<<endl;
        tempStr="Points to be inside cirlces: ";
        for(unsigned i=0;i<p2size;i++){
            tempStr += "("+to_string(p2[i].X())+";"+to_string(p2[i].Y())+"),";
        }
        out<<tempStr<<endl;
        tempStr="Circle middles list: ";
        for(unsigned i=0;i<c0size;i++){
            tempStr += "("+to_string(c0[i].mid().X())+";"+to_string(c0[i].mid().Y())+"),";
        }
        out<<tempStr<<endl;
        tempStr = "Circle with minimal area that contains all points: ";
        if(resIndex > -1){
            tempStr += "Radius: "+to_string(c0[resIndex].r())+" Area: "+to_string(c0[resIndex].s())+
                    " Middle: ("+to_string(c0[resIndex].mid().X())+","+to_string(c0[resIndex].mid().Y())+").";
        }
        else{
            tempStr += "None";
        }
        out<<tempStr<<endl;
    }
}

}
