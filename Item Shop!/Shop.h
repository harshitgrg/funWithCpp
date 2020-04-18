#ifndef SHOP_H
#define SHOP_H
#include <string>
#include "Items.h"
#include <list>
using namespace std;

class Shop
{
    public:
        Shop(string name,int money);

        void printShop();
        bool purchaseItem(string name, Items &newItem);
        void addItem(Items newItem);
        bool canAffordItem(string name,int money);
        int getMoney(){return _money;}
        string getName(){return _name;}
        void addMoney(int money){_money+=money;}
        //void getList(){return _items;}
    private:
        string _name;
        list<Items>_items;
        int _money;
};

#endif // SHOP_H
