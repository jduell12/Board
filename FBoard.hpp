/*****************************************************************************************
** Date: July 15, 2019
** Description: FBoard class specification file
******************************************************************************************/
#ifndef FBoard_hpp
#define FBoard_hpp
#include<string>
using std::string;

//defines the enum data member called State
enum State {X_WON, O_WON, UNFINISHED};

//gives outline of Fboard class
class FBoard{
private:
    char board[8][8];
    State gameState;
    int currentx_x, currentx_y;
public:
    FBoard();
    State getGameState();
    bool moveX(int row, int col);
    bool moveO(int row, int col, int row2, int col2);

};


#endif
