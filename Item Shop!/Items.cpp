#include "Items.h"
using namespace std;
Items::Items(string name, int value,int count)
{
    _name=name;
    _value=value;
    count=1;
}

void Items::addOne(){
    _count++;
}
void Items::removeOne(){

    if(_count>0){
        _count--;
    }}
