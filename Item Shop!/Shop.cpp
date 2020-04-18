#include "Shop.h"
#include <iostream>
#include <list>

using namespace std;
Shop::Shop(string name,int money)
{
    _name=name;
    _money=money;//ctor
}
void Shop::printShop(){
    cout<<"Welcome to "<<_name<<endl;
    cout<<"Money: "<<_money<<" GP \n\n";
    list<Items>::iterator lit;

    int i=0;

    for(lit=_items.begin();lit!=_items.end();lit++){
        cout<<(*lit).getName()<<" x "<<(*lit).getCount()<<"Price "<<(*lit).getValue()<<" GP\n";
        i++;


    }
    cout<<"\n";
}
bool Shop::canAffordItem(string name,int money){
    list <Items>::iterator lit;
    for(lit=_items.begin();lit!=_items.end();lit++){
        if((*lit).getValue()<=money){
            return true;
        }else{return false;}
    }
return false;
}

bool Shop::purchaseItem(string name,Items &newItem){

    list<Items>::iterator lit;
    for(lit=_items.begin();lit!=_items.end();lit++){
        if((*lit).getName()==name){ //checking availability
            newItem=(*lit);
            newItem.setCount(1); //doubt here
            (*lit).removeOne();
            if((*lit).getCount()==0){
                _items.erase(lit);
            }
            return true;
        }

}
return false;}

void Shop::addItem(Items newItem){
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



