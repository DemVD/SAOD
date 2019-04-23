#include <QCoreApplication>
#include <iostream>

using namespace std;


float funcF(float a, float b, float c, float x); // прототипизация функции (определена после ядра программы)


int main(){ // ядро программы
    float xFirst, xLast, dX, a, b, c; // все используемые параметры: Хнач, Хкон, приращение Dx, а,b,c.

    cout<<"Enter xFirst (float) : "; // вывод в консоль "введите Хнач"
    cin>>xFirst; // присваивание введенного параметра с консоли в параметр.
    cout<<"Enter xLast (float) : "; // аналогичные действия для других параметров.
    cin>>xLast;
    cout<<"Enter dX (float) : ";
    cin>>dX;
    cout<<"Enter a (float) : ";
    cin>>a;
    cout<<"Enter b (float) : ";
    cin>>b;
    cout<<"Enter c (float) : ";
    cin>>c;

    cout<<endl;
    for(float x=xFirst;x<xLast;x+=dX){ // цикл перебора всех иксов в заданном промежутке с заданным шагом.
        //cout.fill('.');
        cout.width(6);
        cout<<"|    "<<x;
        cout<<"|    "<<funcF(a,b,c,x)<<"    |"<<endl; // funcF(float a, float b, float c, flat x)
    }
}


float funcF(float a, float b, float c, float x){ // функция F
    float res; // возвращаемое значение.

    if(a<0 && x!=0){ // если первое условие
        res = a*pow(x,2) + pow(b,2)*x; // то присвоить в результат первый ответ
    }
    else if(a>0 && x==0){ // аналогично
        res = x - a/(x-c);
    }
    else{
        res = 1 + x/c;
    }
    // перевод а,b,c в целочисленные и отдельные переменные.
    if( not(round(a) || round(b)) && (round(b) || round(c)) ){ // принимает собственное значение при выполнении условия 2
        return res;
    }
    else{ // или же округляется.
        return round(res);
    }
}
