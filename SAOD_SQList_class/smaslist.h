#ifndef SMASLIST_H
#define SMASLIST_H

#include <iostream>
#include <conio.h>
#include <fstream>
#include <stdlib.h>
#include "car.h"
#include "seqlist.h"

using namespace std;

    void SetupInventoryList(SeqList <CarData> &inventoryList)
    {
        ifstream carFile;
        CarData fd;
        carFile.open("Cars.txt",ios::in);
        if (!carFile)
        {
          cerr<< "No file Cars" <<endl;
          exit(1);
        }
        while(carFile.getline(fd.CarName,32,'\n'))
            inventoryList.Insert(fd);
        carFile.close();
    }

    void PrintInventoryList(const SeqList <CarData> &inventoryList)
    {
        int i,n;
        CarData fd;
        n=inventoryList.ListSize();
        for (i=0;i<n;i++)
        {
            fd=inventoryList.GetData(i);
            cout<<fd.CarName<<endl;
        }
    }

    void PrintCustomerList(const SeqList <CarData> &customerList)
    {
        int i,n;
        CarData fd;
        n=customerList.ListSize();
        for (i=0;i<n;i++)
        {
            fd=customerList.GetData(i);
            cout<<fd.customerName<<"("<< fd.CarName <<")" <<endl;
        }
    }

    void CarArend(SeqList <CarData> &inventoryList,
           SeqList <CarData> &customerList)
    {
        char customer[20];
        CarData fdata;
        cout<<"Name client: ";
        cin.getline(customer,32,'\n');
        cin.getline(customer,32,'\n');
        //cout<< endl;
        cout<<"What mashin do you want?";
        cin.getline(fdata.CarName,32,'\n');

        cout<<fdata.CarName <<endl;
        system("pause");

        if (inventoryList.Find(fdata))
        {
            strcpy(fdata.customerName,customer);

            cout<<fdata.customerName <<endl;
            system("pause");

            cout<<"List customers mashins: " << endl;
            PrintCustomerList(customerList);
            system("pause");

            customerList.Insert(fdata);
            PrintCustomerList(customerList);
            system("pause");

            inventoryList.Delete(fdata);
            cout <<"List inventory mashins: " << endl;
            PrintInventoryList(inventoryList);
            system("pause");
        }
        else
            cout<<"This machin is not  "<<endl;
    }


#endif // SMASLIST_H
