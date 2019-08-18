#include "FBoard.hpp"
#include <iostream>

using std::cout;
using std::endl;
using std::string;

int main(){
    FBoard board;
    cout << "Beginning board: " << endl;
    board.printBoard();

    board.moveX(1,1);
    cout << "Board after x move: " << endl;
    board.printBoard();

    board.moveX(2,0);
    cout << "Board after x move2: " << endl;
    board.printBoard();

    board.moveO(6, 6, 5, 5);
    cout << "Board after o move: " << endl;
    board.printBoard();

    string game = board.getGameState();
    cout << game << endl;


    return 0;
}

