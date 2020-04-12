#ifndef TICTACTOE_H
#define TICTACTOE_H


class TicTacToe
{
    public:
        TicTacToe();
        void playGame();
    private:
        bool checkMarker(int x, int y, char currentPlayer);
        int getXCoord();
        int getYCoord();
        void clearBoard();
        void printBoard();
        char board[3][3];

};

#endif // TICTACTOE_H
