#ifndef PLAYER_H
#define PLAYER_H
#include <random>
#include <ctime>
using namespace std;

class Player
{
    public:
        Player();

        void setPosition(int x,int y);
        void getPosition(int &x,int &y);
        void init(int level,int health,int attack,int defense,int experience);

        //getters
        int getHealth(){return _health;}
        int getLevel(){return _level;}
        int attack();
        int takeDamage(int attack);
        void addExperience(int experience);
        int getAttack(){return _attack;}

        int getDefense(){return _defense;}
        int getExperience(){return _experience;}
    private:
        int _level;
        int _health,_attack,_defense,_experience;
        int _x,_y;
};

#endif // PLAYER_H
