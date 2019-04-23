#ifndef FILEIO_H
#define FILEIO_H
#include <vector>
#include "student.h"

using namespace std;


namespace fileInOut{
void vectorToFile(vector<float> &V, string fileName);
void matrixToFile(vector<vector<float>> M, string fileName);
vector<float> getVectorFromFile(string fileName);
vector<vector<float>> getMatrixFromFile(string fileName);
void writeTxt(Student *sts, unsigned ammOfStudents, string txt);
void AltWriteTxt(Student *sts, unsigned ammOfPoints, string txt);
void studentWriteCsv(Student *sts, unsigned ammOfStudents, string fileName="untitled.csv"
        ,string title="Last_Name,First_Name,Fathers_Name,Group_Number,Grades");
void studentReadCsv(string fileName
                    ,string title="Last_Name,First_Name,Fathers_Name,Group_Number,Grades");
void LFP_error_msg(); // сообщение об ошибке ввода
int intInput(unsigned index, string txt="");
string strInput(unsigned index, string txt="");
}

#endif // FILEIO_H
