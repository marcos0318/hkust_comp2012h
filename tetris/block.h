#include<QtGui>
#include<qtimer.h>
#ifndef BLOCK_H
#define BLOCK_H
class Block
{
public:
	Block(int t);
	
	void moveLeft();
	void moveRight();
	void moveDown();
	void rotateClockwise();
	void rotateAnticlockwise();	
	int type;
	int x;
	int y;
	int relativeX[4];
	int relativeY[4];

private:
	void setBlock();
	int tmp[4];

	
};

#endif
