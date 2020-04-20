#include "Player.h"
#ifndef ENEMY_H
#define ENEMY_H
#include <string>
#include <random>
#include <ctime>
using namespace std;

class Enemy
{
    public:
        Enemy(string name,char tile,int level,int attack,int defense,int health,int experienceValue);
        void setPosition(int x,int y);
        void getPosition(int &x,int &y);
        int attack();
        int takeDamage(int attack);
        string getName(){return _name;}
        char getTile(){return _tile;}


        //Gets the moving ability:
        char getMove(int playerX,int playerY);


    private:
        string _name;
        char _tile;
        int _attack;
        int _defense;
        int _health;
        int _experienceValue;
        int _level;
        int _x;
        int _y;


};

#endif // ENEMY_H
