#include "TicTacToe.h"
#include <iostream>
using namespace std;


TicTacToe::TicTacToe()
{
    //
        //ctor
}

void TicTacToe::playGame(){
    char Player1='X';
    char Player2='Y';
    clearBoard();
    char currentPlayer='X';
    bool isDone=false;
    int x,y;

    while(isDone==false){
        printBoard();
        x=getXCoord();
        y=getYCoord();
        checkMarker(x,y,currentPlayer);

    }

    }

bool TicTacToe::checkMarker(int x,int y,char currentPlayer){
    if(board[y][x]!=' '){
        return false;
    }

        board[y][x]=currentPlayer;

    }





int TicTacToe::getXCoord(){
int x;
cout<<"Enter the X coordinate: \n";
cin>>x;
return x;
}
int TicTacToe::getYCoord(){
int y;
cout<<"Enter the Y coordinate: \n";
cin>>y;
return y;
}



void TicTacToe::clearBoard(){
    for(int i=0; i<3 ; i++){
        for(int j=0;j<3;j++){
            board[i][j]=' ';
        }
    }

}
void TicTacToe::printBoard()
{
    //ugly formatting yay
    cout << endl;
    cout << " |1 2 3|\n";
    for (int i = 0;i < 3;i++){
        cout << " -------\n";
        cout << i+1 << "|" << board[i][0] << "|" << board[i][1] << "|" << board[i][2] << "|\n";
    }
    cout << " -------\n";
}
