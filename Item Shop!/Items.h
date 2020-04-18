#ifndef ITEMS_H
#define ITEMS_H
#include <string>
#include<list>
using namespace std;
class Items
{
    public:
        Items(string name,int value,int count);

        void addOne();
        void removeOne();

        //getters
        string getName(){return _name;}
        int getCount(){return _count;}
        int getValue(){return _value;}
    //setters
        void setCount(int count){_count=count;}
    private:
        string _name;
        int _value;
        int _count;

};

#endif // ITEMS_H
