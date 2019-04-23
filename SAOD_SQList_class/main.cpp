#include <QCoreApplication>

#include "smaslist.h"

int main()
{
    SeqList <CarData> inventoryList, customerList;
    int ch;
    SetupInventoryList(inventoryList);
    do
    {
     CarArend(inventoryList,customerList);
     cout << "For next Y "<< endl;
     ch=getchar();
    }
    while (char(ch)=='Y');
    cout << endl;
    cout<<"List customers mashins: " << endl;
    PrintCustomerList(customerList);
    cout << " " << endl;
    cout <<"List inventory mashins: " << endl;
    PrintInventoryList(inventoryList);
    return 0;
}

