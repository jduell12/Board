# Board
1. Class for playing a game where player x is trying to get their piece to the corner square at (7,7) and player o is trying to make it so player x doesn't have any legal moves. 
2. Has a board of 8x8 (using an array of char)
3. Data member named gameState that holds the state of the game as an enum
4. Default constructor that initializes the board to empty (using the char E to signify an empty spot). Places 4 o piees at (5,7), (6,6), (7,5), (7,7). It places the x piece at (0,0).
5. Method called moveX that takes the row and column of the square to move to as parameters. A legal move is 1 square in any direction diagonally without moving off the board or to an already occupied space. x wins when they get their piece to the square (7,7).
6. Method called moveO that takes as parameters the row and column to move from and the row and column to move to. Player o can move their piece 1 square diagonally in any direction as long as the row and column don't both increase. Player o can't move their piece off the board or to an occupied space.  o wins when player x has no more legal moves. 
7. Either move method can be called multiple times. Doesn't keep track of whose turn it is. 
