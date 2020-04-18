#ifndef PLAYER_H
#define PLAYER_H
#include <string>
#include <list>

#include "Items.h"

using namespace std;

class Player
{
    public:
        Player();
    bool removeItem(string name,Items &newItem);

    void init(string name,int money);
    void addItem(Items newItem);
    bool canAffordItem(string name,int money);
    int getMoney(){return _money;}
    void subtractMoney(int amount){_money-=amount;}
    void printInventory();
    private:
        string _name;
        list<Items> _items;
        int _money;

};

#endif // PLAYER_H
