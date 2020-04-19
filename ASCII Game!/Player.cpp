#include "Player.h"

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
