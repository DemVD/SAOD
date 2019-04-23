#include <QCoreApplication>
#include <vector>
#include <iostream>
#include <time.h>
#include <string.h>

using namespace std;


// сгенерировать одномерный массив, элементы которого расположены в промежутке lim1;lim2
vector<int> generateVectorOfInts(const int n, const int lim1, const int lim2); // генерирует одномерный массив
void showVectorOfInts(vector<int> &vec, const string msg="Vector of Ints:"); // отображение одномерного массива
int func1ElemMul(vector<int> &vec); // перемножение всех элементов на четном индексе
int func2ElemSum(vector<int> &vec); // суммa элементов массива, расположенных между первым и последним нулевыми элементами.
void vectorBubbleSort(vector<int> &vec); // пузырьковая сортировка одномерного массива

int main(){ // ядро программы
    int n, lim1=-10, lim2=10; // параметры: промежутки и кол-во элементов одномерного массива
    cout<<"Enter the number of elements (int) n: "; // запрос в консоли на ввод кол-ва элементов
    cin>>n; // ввод в переменную n

    srand(time(nullptr)); // более "рандомная" генерация псевдослучайных чисел
    vector<int> v1 = generateVectorOfInts(n,lim1,lim2); // вызов функции генерации одномерного массива
    showVectorOfInts(v1, "Generated Vector of Ints:"); // вызов функции показа одномерного массива
    int res1 = func1ElemMul(v1); // вызов функции перемножения эл-тов на четных индексах массива
    cout<<"Multiplication of all numbers in i%2 indexes: "<<res1<<endl; // вывод результата
    v1[1]=0;

    v1[5]=0; // для точной проверки второго пункта
    showVectorOfInts(v1, "updated vector with Zeroes:"); // обновленный массив
    int res2 = func2ElemSum(v1); // вызов функции суммы эл-тов между двумя нулями (строго первого и последнего)
    cout<<"Summ of elems between first 0 and last 0: "<<res2<<endl;
    vectorBubbleSort(v1); // вызов функции, которая сортирует массив
    showVectorOfInts(v1, "Sorted vector: ");

    int arr[] = { 1, 3, 4 }; // статический массив
    int* arr2 = new int[3]; // динамический массив
    cin>>n;
}

void vectorBubbleSort(vector<int> &vec){ // сортировка пузырьком
    unsigned vecSize = vec.size();
    int bufInt=0;
    for(unsigned i=0;i<vecSize;i++){ // i - номер прохода
        for(unsigned j=vecSize-1;j>i;j--){ // внутренний цикл прохода
          if(vec[j-1] < vec[j] ){
          bufInt=vec[j-1];
          vec[j-1]=vec[j];
          vec[j]=bufInt;
        }
      }
        if(i>vec.size()/2){
            break;
        }
    }
}


int func2ElemSum(vector<int> &vec){ // сумма эл-тов на четных индексах массива
    unsigned lim1=0, lim2=0;
    int resSum=0;
    for(unsigned i=0;i<vec.size();i++){ // находим первый ноль
        if(vec[i] == 0){
            lim1=i;
            break;
        }
    }
    if(lim1 == 0){ return 0;} // если нулей нет вообще, нет смысла выполнять код ниже
    for(unsigned i=vec.size()-1;i>0;i--){ // первый элемент, если и ноль, то точно не выполнит условия.
        if(vec[i] == 0){ // находим второй ноль, перебирая элементы от конца к началу.
            lim2=i;
            break;
        }
    }
    if(lim1 != lim2){ // если это не один и тот же ноль (на одном и том же индексе)
        for(unsigned i=lim1;i<lim2;i++){ // все элементы в этом промежутке - складываем.
            resSum += vec[i];
        }
        return resSum;
    }
    else{ // если же индекс один - ответ сразу ноль.
        return 0;
    }
}


int func1ElemMul(vector<int> &vec){ // перемножение элементов на четных индексах массива
    int mulRes = vec[0];
    unsigned vecSize = vec.size();
    for(unsigned i=2;i<vecSize;i+=2){ // установлен шаг 2. если i больше кол-ва эл-тов - выход.
        if(i < vecSize){
            mulRes*=vec[i];
        }
    }

    return mulRes;
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


vector<int> generateVectorOfInts(const int n, const int lim1, const int lim2){ // генерация массива
    vector<int> vec;
    for(int i=0;i<n;i++){ // заполнение псевдослучайными числами в переданном промежутке.
        vec.push_back(lim1 + (rand() % static_cast<int>(lim2 - lim1 + 1)));
    }
    return vec;
}
