#ifndef LEVEL_H
#define LEVEL_H
#include <vector>
#include <string>
#include <cstdio>
#include "Enemy.h"
#include <iostream>
#include "Player.h"
using namespace std;
class Level
{
    public:
        Level();
        void load(string fileName,Player &player);
        void print();
        void movePlayer(char input,Player &player);
        char getTile(int x,int y);
        void setTile(int x,int y,char tile);
        void updateMonsters(Player &player);



    private:
        vector<string> _levelData;
        void processPlayerMove(Player &player,int targetX,int targetY);
        void processMonsterMove(Player &player,int enemyIndex,int targetX,int targetY);
        void battleMonster(Player &player,int targetX,int targetY);
        vector <Enemy> _enemies;

};

#endif // LEVEL_H
