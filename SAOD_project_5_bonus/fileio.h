#ifndef FILEIO_H
#define FILEIO_H
#include <string>
#include "point.h"
#include "circle.h"

using namespace std;


namespace fileInOut{
void writeTxt(Point * p1, Point * p2, unsigned const p1size, unsigned const p2size, Circle * c0,
              unsigned const c0size, int const resIndex, float const minArea, string txt="");
}

#endif // FILEIO_H
