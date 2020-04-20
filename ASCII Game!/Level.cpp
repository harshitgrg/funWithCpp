#include "Level.h"
#include <fstream>
#include<cstdlib>
#include <iostream>
Level::Level()
{

}
void Level::load(string fileName,Player &player)
{
    ifstream inputfile;
    inputfile.open(fileName.c_str()); // this is the doubt why an error popped up here
    if(inputfile.fail()){
        perror(fileName.c_str());
        system("PAUSE");
        exit(1);
    }
    string line;
    while(getline(inputfile,line)){
        _levelData.push_back(line);
    }
    inputfile.close();
//To know about player's data:
    char tile;
    for(int i=0;i<_levelData.size();i++){
        for(int j=0;j<_levelData[i].size();j++){
            tile=_levelData[i][j];
            switch (tile) //scanning the levelData
            {
            case '#':
                break;
            case '@':
                player.setPosition( j,i);
                break;
            case '.':
                break;
            case 'S':
                _enemies.push_back(Enemy("snake",'S',1,3,1,10,50));
                _enemies.back().setPosition(j,i);
                break;
            case 'g':
                _enemies.push_back(Enemy("goblin",'g',2,10,5,55,50));
                _enemies.back().setPosition(j,i);
                break;
            case 'O':
                _enemies.push_back(Enemy("ogre",'O',4,20,20,200,500));
                _enemies.back().setPosition(j,i);
                break;
            case 'B':
                _enemies.push_back(Enemy("bandit",'B',1,3,1,10,250));
                _enemies.back().setPosition(j,i);
                break;
            case 'D':
                _enemies.push_back(Enemy("Dragon!!",'B',34,5,234,4667,50000));
                _enemies.back().setPosition(j,i);
                break;
                }
        }
    }
    }
void Level::print()
{
    cout<<string(100,'\n');
    for(int i=0;i<_levelData.size();i++){
        printf("%s\n",_levelData[i].c_str());

    }
    printf("\n");
}

void Level::movePlayer(char input,Player &player)
{
    int PlayerX;
    int PlayerY;
    player.getPosition(PlayerX,PlayerY);
    char moveTile;

    switch(input){
    case 'w':
    case'W':
        processPlayerMove(player,PlayerX,PlayerY-1);
        break;
    case 'S':
    case's':
        processPlayerMove(player,PlayerX,PlayerY+1);

        break;
    case 'A':
    case'a':
        processPlayerMove(player,PlayerX-1,PlayerY);

        break;
    case 'D':
    case'd':
        processPlayerMove(player,PlayerX+1,PlayerY);

        break;
    default:
        printf("invalid input \n");
        system("PAUSE");
        }

}
char Level::getTile(int x,int y){return _levelData[y][x];}

void Level::setTile(int x,int y,char tile)
{
    _levelData[y][x]=tile;
}

void Level::processPlayerMove(Player &player,int targetX,int targetY)
{
    int playerx;
    int playery;
    player.getPosition(playerx,playery);
    char moveTile=getTile(targetX,targetY);
    switch(moveTile){

    case '.':
        player.setPosition(targetX,targetY);
        setTile(playerx,playery,'.');
        setTile(targetX,targetY,'@');
        break;
    case '#':
        break;
    default:
        battleMonster(player,targetX,targetY);
        }
}
void Level::battleMonster(Player &player,int targetX,int targetY)
{
    int enemyX;
    int enemyY;
    int attackRoll;
    int attackResult;
    int playerX;
    int playerY;
    player.getPosition(playerX,playerY);
    for(int i=0;i<_enemies.size();i++){
            _enemies[i].getPosition(enemyX,enemyY);

        if(targetX==enemyX&&targetY==enemyY){
            //battle
            attackRoll=player.attack();
            attackResult=_enemies[i].takeDamage(attackRoll);
            printf("%s attacked monster with a damage of %d","Player",attackRoll);
            string enemyName;
            enemyName=_enemies[i].getName();
            if(attackResult!=0){
                setTile(targetX,targetY,'.');
                print();
                cout<<"Monster Died! \n";
                _enemies[i]=_enemies.back();
                _enemies.pop_back();
                i--;   //process
                system("PAUSE");
                player.addExperience(attackResult);
                return;
            }
            //Monster's turn!
                cout<<"It's the monster's turn\n";
                //system("PAUSE");
                attackRoll=_enemies[i].attack(); // Problem is here.
                attackResult=player.takeDamage(attackRoll);
                printf("%s attacked player with a damage of %d",enemyName.c_str(),attackRoll);
            if(attackResult!=0){
                setTile(playerX,playerY,'X'); //doubt here
                print();
                cout<<"You died\n";
                system("PAUSE");
                exit(0);
             }
             system("PAUSE");
             return; //battle se bahar aa gye.
            }

            //battle

        }
    }

void Level::updateMonsters(Player &player)
{
char aiMove;
int playerX;
int playerY;
int enemyX;
int enemyY;


player.getPosition(playerX,playerY);

    for(int i=0;i<_enemies.size();i++){
        aiMove=_enemies[i].getMove()
        _enemies[i].getPosition(enemyX,enemyY);
        switch(aiMove){
    case 'w':

        processMonsterMove(player,PlayerX,PlayerY-1);
        break;

    case's':
        processMonsterMove(player,PlayerX,PlayerY+1);

        break;

    case'a':
        processMonsterMove(player,PlayerX-1,PlayerY);

        break;

    case'd':
        processMonsterMove(player,PlayerX+1,PlayerY);

        break;
        }
    }
}

void Level::processMonsterMove(Player &player,int enemyIndex,int targetX,int targetY)
{
    int playerY;
    int playerX;
    int enemyX;
    int enemyY;
    _enemies[enemyIndex].getPosition(enemyX,enemyY);
    player.getPosition(playerX,playerY);
    char moveTile=getTile(targetX,targetY);
    switch(moveTile){

    case '.':
        _enemies[enemyIndex].setPosition(targetX,targetY);

        setTile(enemyX,enemyY,'.');
        setTile(targetX,targetY,_enemies[enemyIndex].getTile());
        break;
    case '#':
        break;
    case '@':
        battleMonster(player,enemyX,enemyY);
        break;
    default:
        break;
        }

}
