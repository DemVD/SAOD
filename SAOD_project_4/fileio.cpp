#include <fstream>
#include <iostream>
#include <vector>
#include "fileio.h"

using namespace std;


namespace fileInOut{
void vectorToFile(vector<float> &V, string fileName)
{
    ofstream file(fileName);
    for(auto numb:V)
    {
        file << numb;
        if(not(numb == V[V.size()-1]) ){file << ","; }
    }
    file.close();
}


void matrixToFile(vector<vector<float>> M, string fileName)//& err
{
    ofstream file(fileName);
    for(auto V:M)
    {
        for(auto numb:V)
        {
            file << numb << ",";
            //if(not(numb == V[V.size()-1]) ){file << ","; }
        }
        file << endl;
    }
    file.close();
}


vector<float> getVectorFromFile(string fileName)
{
    vector<float> nV;
    string sNum;
    float fNum;

    ifstream file(fileName);
    cout << endl;
    while(getline(file, sNum, ','))
    {
        //fNum = strtof((sNum).c_str(),nullptr);
        fNum = stof(sNum);
        nV.push_back(fNum);
    }
    file.close();

    return nV;
}


vector<vector<float>> getMatrixFromFile(string fileName)
{
    vector<vector<float>> nM;
    vector<float> nV;
    string sNum;
    float fNum;

    ifstream file(fileName);
    cout << endl;

    for(;;)
    {
        while(getline(file, sNum, ','))
        {
            fNum = stof(sNum);
            nV.push_back(fNum);
        }
        getline(file, sNum);
        nM.push_back(nV);
    }

    file.close();

    return nM;
}

void writeTxt(Student *sts, unsigned ammOfPoints, string txt){
    string strBuf;
    std::ofstream out("SAOD_proj4.txt",std::ios::app);
    if (out.is_open())
    {
        out<<endl<<txt<<":"<<endl;
        out.width(6);
        for(unsigned i=0;i<ammOfPoints;i++){
            strBuf="";
            for(unsigned j=0;j<sts[i].ammOfGrades; j++){ strBuf += to_string(sts[i].grades[j]) +" "; }
            out<<sts[i].lastName<<" "<<sts[i].firstName<<" "<<sts[i].fathersName<<"      |"<<"Group: "<<sts[i].groupNumber
              <<"      |"<<"Grades: "<<strBuf<<endl;
        }
    }
    out.close();
}

void AltWriteTxt(Student *sts, unsigned ammOfPoints, string txt){
    string strBuf;
    unsigned maxFullNameLen = 0;
    unsigned bufUns1=0;
    for(unsigned i=0;i<ammOfPoints;i++){ // находим максимальную длину строки для идеального вывода в тхт файл
        unsigned FN = sts[i].lastName.length()+sts[i].firstName.length()+sts[i].fathersName.length()+5;
        if(FN > maxFullNameLen){
            maxFullNameLen = FN;
        }
    }

    std::ofstream out("SAOD_proj4_ALT.txt",std::ios::app);
    if (out.is_open())
    {
        out<<endl<<txt<<":"<<endl;
        //out.width(6); //не работает (неэффективно при разной длине трех слов)
        for(unsigned i=0;i<ammOfPoints;i++){
            strBuf="";
            bufUns1 = maxFullNameLen - sts[i].lastName.length()+1; // что добавить к концу фамилии для ровных разделений
            strBuf += sts[i].lastName+" "+sts[i].firstName+" "+sts[i].fathersName;
            for(unsigned j=0;j<bufUns1;j++){
                strBuf+=" ";
            }
            strBuf += "|   Group: "+to_string(sts[i].groupNumber)+"   |   Grades: ";
            for(unsigned j=0;j<sts[i].ammOfGrades;j++){
                strBuf += to_string(sts[i].grades[j])+" ";
            }
            out<<strBuf<<endl;
    }
    out.close();
    }
}

void studentWriteCsv(Student *sts, unsigned ammOfStudents, string fileName, string title){
    ofstream file(fileName,ios::app);
    if (file.is_open()){
        file<<title<<endl;
        for(unsigned i=0;i<ammOfStudents;i++){
            file<<sts[i].lastName<<","<<sts[i].firstName<<","<<sts[i].fathersName<<","<<sts[i].groupNumber<<",";
            for(unsigned j=0;j<sts[i].ammOfGrades; j++){
                file<<sts[i].grades[j];
                if(j != sts[i].ammOfGrades-1){file<<",";}
            }
            file<<endl;
        }
    }
    file.close();
}

void studentReadCsv(string fileName, string title){
    string bufStr;
    ifstream file(fileName);

    while(getline(file, bufStr)){
        if(bufStr == title){
            cout<<bufStr<<endl;
            continue;
        }
        cout<<bufStr<<endl;
    }
}

void LFP_error_msg(){ // сообщение об ошибке ввода
    cout<<endl<<"incorrect input! try again!"<<endl;
}

int intInput(unsigned index, string txt){
    int bufInt=0;
    while(true){
        cout<<endl<<"Enter student "<<index<<"'s "<<txt<<": ";
        cin>>bufInt;
        if(bufInt > 0){
            break;
        }
        else{
            LFP_error_msg();
        }
    }
    return bufInt;
}

string strInput(unsigned index, string txt){
    string bufStr="";
    while(true){
        cout<<endl<<"Enter student "<<index<<"'s "<<txt<<": ";
        cin>>bufStr;
        if(bufStr.length() > 1){
            return bufStr;
        }
        else{
            LFP_error_msg();
        }
    }
}

}
