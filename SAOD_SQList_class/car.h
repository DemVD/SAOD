#ifndef CAR_H
#define CAR_H
#include <string.h>
struct CarData
{
    char CarName[32];
    char customerName[32];
};
int operator == (const CarData &A, const CarData &B)
{
    return strcmp(A.CarName,B.CarName);
}
#endif // CAR_H
