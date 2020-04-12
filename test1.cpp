#include <iostream>
#include "TicTacToe.h"
using namespace std;
int main(){
    bool isDone=false;
    char response;
    TicTacToe game;
    while(isDone==false){
    game.playGame();
    cout<<"Would you like to play another game?? (Y\N)\n";
    cin>>response;
    if(response==('N'||'n')){isDone=true;}
    }

//system('PAUSE');
return 0;
}


