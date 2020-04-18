#include "Player.h"
#include <iostream>
using namespace std;

Player::Player()
{
}

void Player::init(string name, int money){
    _name=name;
    _money=money;
}

bool Player::removeItem(string name,Items &newItem){
list<Items>::iterator lit;
    for(lit=_items.begin();lit!=_items.end();lit++){
        if((*lit).getName()==name){
            newItem=(*lit);
            (*lit).removeOne();
            if(newItem.getCount()==0){
            _items.erase(lit);}
            return true;
}
return false;
}}
void Player::addItem(Items newItem)
{
    list<Items>::iterator lit;
    for(lit=_items.begin();lit!=_items.end();lit++){
        if((*lit).getName()==newItem.getName()){
            (*lit).addOne();
            return;

        }
    }
    _items.push_back(newItem);
    _items.back().setCount(1);

}

void Player::printInventory()
{

    cout << "*** " << _name << "'s inventory ***\n\n";
    cout << "Money: " << _money << " GP\n\n";
    list<Items>::iterator lit;

    int i = 0;

    for (lit = _items.begin(); lit != _items.end(); lit++) {
        cout << i << ". " << (*lit).getName() << " x " << (*lit).getCount() << " Price: " << (*lit).getValue() << " GP" << endl;
        i++;
    }
}

bool Player::canAffordItem(string name,int money){
    list <Items>::iterator lit;
    for(lit=_items.begin();lit!=_items.end();lit++){
        if((*lit).getValue()<=money){
            return true;
        }else{return false;}
    }
return false;
}
