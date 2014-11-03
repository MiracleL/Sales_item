#include "sales_item.h"
#include<iostream>
#include<string>
#include<fstream>
using namespace std;

int n = 0;
sales_item::sales_item()
{
}

void set(sales_item *p)
{
    string a;
    ifstream idata;
    idata.open("data.txt");
    for(int i=0;;i++)
    {
        idata >> p[i].type >> p[i].price >> p[i].number;
        idata >> p[i].inventory;
        if(idata.eof())
        {
            n=i;
            break;
        }
    }
    idata.close();
}

void change(sales_item *p)
{
    string type;
    float price,number,inventory,k;
    cout <<"Input the number of data you want to change:"<<endl;
    cin >> k;
    cout << "Input the new data, Type,Price,Number,Inventory:"<< endl;
    for(int j=0;j<k;j++)
    {
        cin >> type >> price >> number >> inventory;
        for(int i =0;i<n;i++)
        {
            if(p[i].type==type)
            {
                p[i].number=number;
                p[i].price=price;
                p[i].inventory=inventory;
            }
        }
    }
    ofstream idata;
    idata.open("data.txt");
    for(int i =0;i<n;i++)
    {
        idata << p[i].type <<" "<<p[i].price<<" ";
        idata << p[i].number << " "<<p[i].inventory<<"\0";
    }
    idata.close();

}

void cut(sales_item *p,int i,float j)   //修改类的销量与库存，需要传入第几个类，变化的销量，与变换的库存
{
    p[i].number +=j;
    p[i].inventory-=j;
}

void buy(sales_item *p)
{
    void save(string type,float number,float sum);
    string type;
    float number,price,sum =0;
    int k;
    cout << "Printf the number of the different kinds of goods you want to buy:"<<endl;
    cin >> k;
    cout << "Printf the type and the number:"<<endl;
    for(int i=0;i<k;i++)
    {
        cin >>type >> number;
        for(int j=0;j<n;j++)
        {
            if(p[j].type==type)
            {
                if(p[j].inventory<number)
                {
                    cout<<"Sorry,the inventory is insufficient,you can buy "
                          <<p[j].inventory<<"at most"<<endl;
                    cout <<"Please change the number"<<endl;
                    cin >> number;
                    cut(p,j,number);
                }
                else
                    cut(p,i,number);
                price =p[i].price;
            }
        }
        sum+=price*number;
        save(type,number,sum);
    }

}
void save(string type,float number,float sum)
{
    ofstream idata;
    idata.open("result.txt",ofstream::app);
    idata <<type<<"    "<<number<<"     "<<sum<<"\n";
    idata.close();
}
void refresh(sales_item *p)
{
    ofstream idata;
    idata.open("data.txt");
    for(int i =0;i<n;i++)
    {
        idata << p[i].type <<" "<<p[i].price<<" ";
        idata << p[i].number << " "<<p[i].inventory<<"\n";
    }
    idata.close();
}
