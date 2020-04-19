#ifndef LEVEL_H
#define LEVEL_H
#include <vector>
#include <string>
#include <cstdio>
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


    private:
        vector<string> _levelData;
        void processPlayerMove(Player &player,int targetX,int targetY);

};

#endif // LEVEL_H
