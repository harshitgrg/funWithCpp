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
    int turn=0;

    while(isDone==false){
        printBoard();
        x=getXCoord();
        y=getYCoord();
        //checkMarker(x,y,currentPlayer);
        if (checkMarker(x,y,currentPlayer)==false){cout<<"Hey!, That place is occupied! \n";}
        else{
        turn++;
        if(turn!=9){
        //Switching players
        if(checkVictory(currentPlayer)==true){
            cout<<"Congratulations "<<currentPlayer<<" You won"<<endl;
            break;
        }
        if(currentPlayer=='X'){currentPlayer='Y';}
        else{currentPlayer='X';}
        cout<<"\n No of turns: "<<turn<<endl;
        }
        else{cout<<"It's a tie! \n";break;}}

    }

    }

bool TicTacToe::checkMarker(int x,int y,char currentPlayer){
    if(board[y][x]!=' '){
        return false;
    }

        board[y][x]=currentPlayer;
        return true;

    }





int TicTacToe::getXCoord(){
    int x;
    bool isInputBad=true;

    while(isInputBad==true){
    cout<<"Enter the X coordinate: \n";
    cin>>x;
    if(x<1||x>3){
        cout<<"Please enter the right input: \n";

    }
    else{isInputBad=false;}
    return x-1;


    }}
int TicTacToe::getYCoord(){
    int y;
    bool isInputBad=true;

    while(isInputBad==true){
    cout<<"Enter the Y coordinate: \n";
    cin>>y;
    if(y<1||y>3){
        cout<<"Please enter the right input: \n";

    }
    else{isInputBad=false;}
    return y-1;


    }
}

bool TicTacToe::checkVictory(char currentPlayer)
{
    //Check the rows
    for (int i = 0; i < 3; i++) {
        if ((board[i][0] == currentPlayer) && (board[i][0] == board[i][1]) && (board[i][1] == board[i][2])) {
            return true; //We won!
        }
    }

    //Check the columns
    for (int i = 0; i < 3; i++) {
        if ((board[0][i] == currentPlayer) && (board[0][i] == board[1][i]) && (board[1][i] == board[2][i])) {
            return true; //We won!
        }
    }

    //Check top left diagonal
    if ((board[0][0] == currentPlayer) && (board[0][0] == board[1][1]) && (board[1][1] == board[2][2])) {
        return true; //We won!
    }

    //Check top right diagonal
    if ((board[2][0] == currentPlayer) && (board[2][0] == board[1][1]) && (board[1][1] == board[0][2])) {
        return true; //We won!
    }

    return false;
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
