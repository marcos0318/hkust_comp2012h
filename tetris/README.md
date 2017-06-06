HKUST COMP2012H
FALL 2016
Project2: tetris

Made by 
1,BAI Jiaxin stdid: 20327648
2,LIU Qinhan stdid: 20328953


Two images, used as backgrounds for gameboard and preview

Two classes, one is Game, controlling the game loop, keyboard event and the drawings; the other is Block, the falling part, react correspondently to the game events.

In Game:

There is a 2-dimensional array, board[10][20], to store the position of the fallen blocks;1 means occupied,0 means empty;

checkBoard() check: 1, whether the falling board should join the fallen one; 2, whether there is a row should be reducted; 3, whether game is over;


In Block:
7 types of blocks
Different functions that controlling the movement and rotation of the block, also ensuring the validaty of the movement
 

