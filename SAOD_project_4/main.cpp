#include <QCoreApplication>
#include <string.h>
#include <iostream>
#include <fstream>
#include "student.h"
#include "fileio.h"

using namespace std;
using namespace fileInOut;


int main(){
    string fileName = "Student_Grades.csv";
    studentReadCsv(fileName); // чтение с csv файла
    const unsigned ammOfStuds = 10;
    Student *Studs = new Student[ammOfStuds];
    for(unsigned i=0;i<ammOfStuds;i++){
        Studs[i].lastName = strInput(i,"Last Name");
        Studs[i].firstName = strInput(i,"First Name");
        Studs[i].fathersName = strInput(i,"Father's Name");
        Studs[i].groupNumber = intInput(i,"Group Number");
        cout<<endl<<Studs[i].lastName<<" "<<Studs[i].firstName<<" "
           <<Studs[i].fathersName<<":"<<endl;
        for(unsigned j=0;j<Studs[i].ammOfGrades;j++){
            Studs[i].grades[j] = intInput(i,"Grade "+to_string(j));
        }

        cout<<endl<<"_______________________________________________________"<<endl;
        cout<<endl<<"Student:"<<endl<<Studs[i].lastName<<" "<<Studs[i].firstName<<" "
           <<Studs[i].fathersName<<endl<<"Group: "<<Studs[i].groupNumber
          <<endl<<"Grades: "<<endl;
        for(unsigned j=0;j<Studs[i].ammOfGrades; j++){
            cout<<Studs[i].grades[j]<<" ";
        }
        cout<<endl<<"_______________________________________________________"<<endl;
    }

    for(unsigned i=0;i<ammOfStuds;i++){
        unsigned pos = i;
        Student tempStud = Studs[i];
        char tempChr = Studs[i].lastName[0];
        for(unsigned j=i+1;j<ammOfStuds;j++){
            if(Studs[j].lastName[0] < tempChr){
                pos = j;
                tempStud = Studs[j];
            }
        }
        Studs[pos] = Studs[i];
        Studs[i] = tempStud;
    }

    writeTxt(Studs,ammOfStuds,"Session 2"); // запись в текстовый файл
    studentWriteCsv(Studs,ammOfStuds, fileName); // запись в csv файл
    AltWriteTxt(Studs,ammOfStuds,"Session 1");
    unsigned Cnt = 0;
    ofstream out("SAOD_proj4.txt",std::ios::app);
    ofstream outALT("SAOD_proj4_ALT.txt",std::ios::app);
    for(unsigned i=0;i<ammOfStuds;i++){
        for(unsigned j=0;j<Studs[i].ammOfGrades;j++){
            if(Studs[i].grades[j] <= 2){
                Cnt++;
                cout<<"Student "<<Studs[i].lastName<<" From Group "<<Studs[i].groupNumber<<" Has bad grades!"<<endl;
                out<<"Student "<<Studs[i].lastName<<" From Group "<<Studs[i].groupNumber<<" Has bad grades!"<<endl;
                outALT<<"Student "<<Studs[i].lastName<<" From Group "<<Studs[i].groupNumber<<" Has bad grades!"<<endl;
                break;
            }
        }
    }
    if(Cnt == 0){
        cout<<endl<<"No students with bad grades!"<<endl;
        out<<endl<<"No students with bad grades!"<<endl;
        outALT<<endl<<"No students with bad grades!"<<endl;
    }
    out.close();

}
