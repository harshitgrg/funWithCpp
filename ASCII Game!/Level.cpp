#include "Level.h"
#include <fstream>
#include<cstdlib>

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
            switch (tile)
            {
            case '#':
                break;
            case '@':
                player.setPosition( j,i);
                break;
            case '.':
                break;
            }
        }
    }}
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
        }
}
