#include <QCoreApplication>
#include <iostream>
#include <fstream>

using namespace std;


vector<vector<int>> generateMatrixOfInts(const unsigned n, const int lim1=0, const int lim2=99); // генерирует матрицу
void showMatrixOfInts(vector<vector<int>> &mat, const string msg="Matrix of Ints:"); // выводит матрицу
void showVectorOfInts(vector<int> &vec, const string msg); // выводит массив
vector<int> getMatrixSaddle(const vector<vector<int>> &mat); // находит все седловые точки матрицы
void writeTxt(const vector<vector<int>> mat, const vector<int> sads); // сохранение в .txt файл


int main(){
    srand(time(nullptr));
    for(unsigned q=0;q<50;q++){
        vector<vector<int>> mat = generateMatrixOfInts(5);
        showMatrixOfInts(mat);
        vector<int> Saddles = getMatrixSaddle(mat);
        showVectorOfInts(Saddles, "Saddles: ");

        writeTxt(mat, Saddles);
    }
}


vector<vector<int>> generateMatrixOfInts(const unsigned n, const int lim1, const int lim2){ // генерация матрицы
    vector<vector<int>> mat;
    vector<int> vec;
    for(unsigned i=0;i<n;i++){
        for(unsigned j=0;j<n;j++){
            vec.push_back(lim1 + (rand() % static_cast<int>(lim2 - lim1 + 1)));
        }
        mat.push_back(vec);
        vec.clear();
    }
    return mat;
}


void showMatrixOfInts(vector<vector<int>> &mat, const string msg){ // отображение матрицы
    cout<<endl;
    cout<<msg<<endl;
    for(unsigned i=0;i<mat.size();i++){
        for(unsigned j=0;j<mat[i].size();j++){
            //cout.fill('.');
            cout.width(6);
            cout<<"|   "<<mat[i][j];
        }
        cout<<"   |"<<endl;
    }
}


void showVectorOfInts(vector<int> &vec, const string msg){ // отображение массива
    cout<<endl;
    cout<<msg<<endl;
    for(unsigned i=0;i<vec.size();i++){
        //cout.fill('.');
        cout.width(6);
        cout<<"|   "<<vec[i];
    }
    cout<<"   |"<<endl;
}


vector<int> getMatrixSaddle(const vector<vector<int>> &mat){
    unsigned n = mat.size();
    int minRow=0, maxCol=0;
    vector<int> resVect;
    for(unsigned i=0;i<n;i++){

        minRow = mat[i][0]; // поиск минимального элемента (если их несколько - надо все проверить потом)
        for(unsigned m=0;m<n;m++){
            if(mat[i][m] < minRow){ minRow = mat[i][m]; } // общий минимальный элемент для всей строки
        }

        for(unsigned j=0;j<n;j++){ // проверяем каждую минимальную точку строки
            if(mat[i][j] == minRow){ // нашли общий минимальный элемент
                maxCol = mat[0][j]; // берем первый элемент столбца за максимум
                for(unsigned k=0;k<n;k++){ // ищем максимальный элемент столбца
                    if(mat[k][j] > maxCol){ maxCol = mat[k][j]; }
                }
            }
            if(maxCol == minRow){ // если минимальный элемент столбца и максимальный строки равны
                resVect.push_back(maxCol);
                maxCol = -1;
            }
        }
    }
    return resVect;
}


void writeTxt(const vector<vector<int> > mat, const vector<int> sads){
    std::ofstream out("SAOD_proj3.txt",std::ios::app);
    if (out.is_open())
    {
        out<<endl<<"Generated matrix:"<<endl;
        for(unsigned i=0;i<mat.size();i++){
            for(unsigned j=0;j<mat[i].size();j++){
                //cout.fill('.');
                out.width(6);
                out<<"|   "<<mat[i][j];
            }
            out<<"   |"<<endl;
        }
        out<<"Matrix Saddles: ";
        for(unsigned j=0;j<sads.size();j++){
            out<<sads[j]<<" ";
        }
        out<<endl<<endl;
    }
    out.close();
}
