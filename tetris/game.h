#include<QtGui>
#include<stdlib.h>
#include<qtimer.h>
#include<QKeyEvent>
#include"block.h"
#ifndef GAME_H
#define GAME_H
class Game:public QWidget
{
	Q_OBJECT
private:
	QImage backgroundimg;
	QImage previewimg;
	QLabel background;
	QLabel preview;
	QLabel score;
	QLabel level;
	QTimer* timer;	

	QVBoxLayout previewAndScore;
	QHBoxLayout mainLayout;
	int speed;
	char buffer[32];
	int Score;
	int Level;	


	Block* current;
	Block* next;
	
	int start;
	int board[10][20];
	void Gamestart();	
	void Gameover();	

public:
	Game();
	void checkBoard();
protected:
	void keyPressEvent(QKeyEvent *event);




public slots:
	void updateBlock();



};
#endif
