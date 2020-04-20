#ifndef GAMESYSTEM_H
#define GAMESYSTEM_H
#include "Level.h"
#include "Player.h"
#include <iostream>
#include "Enemy.h"
#include <iostream>
using namespace std;
class GameSystem
{
    public:
        GameSystem(string levelName);

        //_player.init(1,100,10,10,0);
        void playGame();
        void PlayerMove();

    private:
        Player _player;// yeh saare player ke attribute diye player ko mene
        Level _level;


};

#endif // GAMESYSTEM_H
