#ifndef STUDENT_H
#define STUDENT_H
#include <iostream>
#include <string.h>

using namespace std;


struct Student{
public:
    string firstName=""; // фамилия и инициалы
    string lastName="";
    string fathersName="";
    int groupNumber=0; // номер группы
    unsigned ammOfGrades=5; // колво оценок (для массива)
    int *grades = new int[ammOfGrades]; // пять оценок
};

#endif // STUDENT_H
