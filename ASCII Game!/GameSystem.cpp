#include "GameSystem.h"
#include <cstdlib>
#include <conio.h>
GameSystem::GameSystem(string levelName)
{


    _player.init(1,100,10,10,0);
    _level.load(levelName,_player);
    system("PAUSE");
}


void GameSystem::playGame()
{
    bool isDone=false;
    while(isDone==false)
    {
        _level.print();
        PlayerMove();
        _level.updateMonsters(_enemies);


    }
}

void GameSystem::PlayerMove()
{
    printf("Enter a move commmand w s a d \n");
     wchar_t input = _getch();
    _level.movePlayer(input,_player);

}
