#ifndef SEQLIST_H
#define SEQLIST_H


#include <iostream>
#include <stdlib.h>
using namespace std;

const int MaxListSize = 100;

template <class T>
class SeqList
{

    T listitem[MaxListSize];

    int size;
public:

    SeqList(void);

    int ListSize(void)const;
    int ListEmpty(void)const;
    int Find(T &item)const;
    T GetData(int pos)const;

    void Insert(const T &item);
    void Delete(const T &item);
    T DeleteFront(void);
    void ClearList(void);
};

  template <class T>
  SeqList<T>::SeqList(void):size(0)
    {}
  template <class T>
  int SeqList<T>::ListSize(void)const
  {
      return size;
  }
  template <class T>
  int SeqList<T>::ListEmpty(void)const
  {
      return size == 0;
  }

  template <class T>
  void SeqList<T>::ClearList(void)
  {
      size(0);
  }

  template <class T>
  int SeqList<T>::Find(T &item)const
  {
      int i = 0;
      if (ListEmpty())
          return 0;
      while (i<size && !(item==listitem[i]))
          i++;
      if (i<size)
          return 1;
      else
          return 0;
  }


  template <class T>
  void SeqList<T>::Insert(const T &item)
  {
      if (size + 1 > MaxListSize)
      {
          cerr<< "List full" <<endl;
          exit(1);
      }
      listitem[size] = item;
      size++;
  }


  template <class T>
  void SeqList<T>::Delete(const T &item)
  {
      int i =0;
      while (i<size && !(item==listitem[i]))
          i++;
      if (i<size)
      {
          while (i<size-1)
          {
            listitem[i] = listitem[i+1];
            i++;
          }
          size--;
      }
  }


  template <class T>
  T SeqList<T>::DeleteFront(void)
  {
      T frontItem;
      if (size==0)
      {
          cerr<<"List empty"<<endl;
          exit(1);
      }
      frontItem = listitem[0];
      Delete(frontItem);
      return frontItem;
  }


  template <class T>
  T SeqList<T>::GetData(int pos)const
  {
      if (pos<0 ||pos>=size)
      {
          cerr<<"Indekc not in massive" <<endl;
          exit(1);
      }
      return listitem[pos];
  }

#endif // SEQLIST_H
