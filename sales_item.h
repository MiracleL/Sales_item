#ifndef SALES_ITEM_H
#define SALES_ITEM_H
#include<iostream>
#include<string>
using namespace std;
class sales_item
{
private:
    float price,number,inventory;
    string type;
public:
    sales_item();
    friend void set(sales_item *p);
    friend void change(sales_item *p);
    friend void cut(sales_item *p,int i,float j);
    friend void buy(sales_item *p);
    friend void refresh(sales_item *p);
};

#endif // SALES_ITEM_H
