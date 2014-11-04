#include <iostream>
#include"sales_item.h"
#include<fstream>
#include<string>
#include<iostream>

using namespace std;
void save(string type,float number,float sum);
int main()
{
    string a;
    sales_item *p = new sales_item[300];
    set(p);
    cout << "Now the data is all kept in the data.txt,if you want to change the data,printf YES or NO"<< endl;
    cin >> a;
    if(a=="YES")
        change(p);
    cout << "Now the data is update,and you want buy some thing,printf YES or NO"<<endl;
    cin >> a;
    if(a=="YES")
    {
        ofstream idata;
        idata.open("result.txt");
        idata << "Type  "<<" "<<"Number   "<<" "<<"Sum    "<<"\n";
        idata.close();
        buy(p);
        refresh(p);
    }
    return 0;
}


