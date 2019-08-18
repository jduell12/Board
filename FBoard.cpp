/*****************************************************************************************
 ** Date: July 15, 2019
 ** Description: Class called FBoard that creates a 8x8 char array for a game. Has a data
 ** member called gameState that holds the value of the game state. It has a data member
 ** to keep track of the x piece. It has a default constructor. It has a getGameState method
 ** which returns the game state. It has a method moveX and a method moveO which allows the
 ** x and o pieces to move around the board.
 ******************************************************************************************/
#include "FBoard.hpp"
#include <string>
using std::string;

/*****************************************************************************************
 **                                FBoard::FBoard()
 ** Default constructor that initializes the array to empty using the char E. It puts four
 ** O pieces at (5,7), (6,6), (7,5), (7,7). It puts the X piece at (0,0). It sets the
 ** gameState to unfinished.
 *****************************************************************************************/
FBoard::FBoard() {
    currentx_x = 0;
    currentx_y = 0;
    gameState = UNFINISHED;
    for (int row = 0; row < 8; row++) {
        for (int col = 0; col < 8; col++) {
            board[row][col] = 'E';
        }
    }

    //places the O pices on the board
    board[5][7] = 'O';
    board[6][6] = 'O';
    board[7][5] = 'O';
    board[7][7] = 'O';

    //places the X pice on the board
    board[currentx_x][currentx_y] = 'X';

}
/*****************************************************************************************
 **                               FBoard::getGameState()
 ** Returns the value of gameState
 *****************************************************************************************/
State FBoard::getGameState() {
    return gameState;
}
/*****************************************************************************************
 **                      FBoard::moveX(int row, int col)
 ** Moves the x piece to the square indicated by the int parameters where the first int is
 ** the row and the second int is the column. Returns true if move is made and false if
 ** it can't be made or the game is won.
 *****************************************************************************************/
bool FBoard::moveX(int row, int col) {
    bool move = false;

    int x_x = row;
    int x_y = col;
    //check to see if game has been won
    if (gameState == UNFINISHED) {
        //check to make sure the move doesn't go outside the bounds of the board
        if (x_x > 7 || x_x < 0 || x_y > 7 || x_y < 0) {
            move = false;
        }
        //checks to see if space is occupied
        else if (board[x_x][x_y] != 'E') {
            move = false;
        }
        //checks to see if the move is a valid move for x (diagonal 1 space move in any direction)
        else if ((x_x == currentx_x - 1 || x_x == currentx_x + 1)
                  && (x_y == currentx_y - 1 || x_y == currentx_y + 1)) {
            //puts x piece in the spot
            board[x_x][x_y] = 'X';
            //changes the last space to empty since the x piece has moved
            board[currentx_x][currentx_y] = 'E';
            //changes current x position variables to current x position
            currentx_x = x_x;
            currentx_y = x_y;
            move = true;
        }
    } else {
        move = false;
    }

    //if x moves the piece to (7,7) x wins the game
    if (board[7][7] == 'X') {
        gameState = X_WON;
    }

    return move;
}

/*****************************************************************************************
 **               FBoard::moveO(int row, int col, int row2, int col2)
 ** Moves O piece from one space (first two parameters) to a new space (last two
 ** parameters). Checks to see that the desired move is allowed and the game is not won.
 ** Returns true if the move is made and false if it's not allowed or the game is won.
 *****************************************************************************************/
bool FBoard::moveO(int r1, int c1, int r2, int c2){
    bool move = false;
    //checks to make sure game is unfinished
    if (gameState == UNFINISHED){
        //checks to make sure the space to be moved to is within bounds
        if (r2 < 0 || r2 > 7 || c2 < 0 || c2 > 7 ){
            move = false;
        }
        //checks to see if the space to move to is occupied
        else if(board[r2][c2] != 'E'){
            move = false;
        } else {
            /** checks to see that the move is a valid move for O (1 space
            ** diagonally without increasing both the row and column **/
            if (r2 == (r1 - 1) || r2 == (r1 + 1) || c2 == (c1 - 1)){
                //moves O piece
                board[r2][c2] = 'O';
                //changes space O piece was from back to empty
                board[r1][c1] = 'E';
                move = true;
             } else if (r2 == (r1 - 1) || c2 == (c1 -1) || c2 == (c1 + 1)){
                //moves O piece
                board[r2][c2] = 'O';
                //changes space O piece was from back to empty
                board[r1][c1] = 'E';
                move = true;
            } else {
                move = false;
            }
        }
    } else {
        move = false;
    }

    return move;
}
