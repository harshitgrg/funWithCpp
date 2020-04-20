#include "Player.h"
#include <iostream>
Player::Player()
{
    //ctor
}

void Player::setPosition(int x,int y)
{
    _x=x;
    _y=y;

}

void Player::getPosition(int &x,int &y)
{
    x=_x;
    y=_y;
}
void Player::init(int level,int health,int attack,int defense,int experience)
{
    _level=level;
    _health=health;
    _attack=attack;
    _defense=defense;
    _experience=experience;
}
int Player::attack()
{
    static default_random_engine randomEngine(time(NULL));
    uniform_int_distribution<int> attackRoll(0,_attack);
    return attackRoll(randomEngine);
}

void Player::addExperience(int experience){
_experience+=experience;
while(_experience>50){
    _experience-=50;
    _attack+=10;
    _health+=20;
    _level++;
    _defense+=10;
    printf("Congratulations, you have levelled up \n");

}
}
int Player::takeDamage(int attack)
{
    attack-=_defense;
    cout<<"Player has been attacked\n";
    if(attack>0){
        _health-=attack;
        if(_health<=0){
            return 1;
        }

    }else{return 0;}//that means the player is alive}
}
