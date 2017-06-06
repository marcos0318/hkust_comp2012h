#include<QtGui>
#include<qtimer.h>
#include<QKeyEvent>
#include<stdlib.h>
#include "game.h"
#include "block.h"

Game::Game(){
start = 0;
	//set layout  
        previewAndScore.addWidget(&preview);
        previewAndScore.addWidget(&score);
        previewAndScore.addWidget(&level);
        mainLayout.addWidget(&background);
        mainLayout.addLayout(&previewAndScore);
        setLayout(&mainLayout);


	backgroundimg.load("background.bmp");
	background.setPixmap(QPixmap::fromImage(backgroundimg));


	previewimg.load("previewimg.png");	

	preview.setPixmap(QPixmap::fromImage(previewimg));

	background.show();
	preview.show();
}





void Game::Gamestart(){
start =1;


//set game board
	memset(board,0,sizeof(board));
	Score = 0;
	Level = 1;

//set objects

	current = new Block(rand()%7);	
	next = new Block(rand()%7);

//set timer 
	timer = new QTimer(this);
	timer->start(1000 - (Level -1)*100);
	QObject::connect(timer,SIGNAL(timeout()),this,SLOT( updateBlock() )  );


if (start){

//draw background and block as well as board	
	backgroundimg.load("background.bmp");
	QPainter painter1(&backgroundimg);
	painter1.setBrush(Qt::SolidPattern);
    	painter1.setBrush(Qt::red);
        painter1.setPen(Qt::darkRed);
	for(int i =0; i<4 ; i++){
		painter1.drawRect((current->x+current->relativeX[i])*20,(current->y+current->relativeY[i])*20,20,20);
	}

	//draw the board	
	for(int i=0;i<10;i++){
		for(int j=0;j<20;j++){
			if(board[i][j])painter1.drawRect(i*20,j*20,20,20);
		}
	}
	background.setPixmap(QPixmap::fromImage(backgroundimg));

//draw preview board and block

	previewimg.load("previewimg.png");	
	QPainter painter2(&previewimg);
	painter2.setBrush(Qt::SolidPattern);
    	painter2.setBrush(Qt::red);
        painter2.setPen(Qt::darkRed);
	for(int i =0; i<4 ; i++){
		painter2.drawRect((2+next->relativeX[i])*20,(4+next->relativeY[i])*20,20,20);
	}
	

	preview.setPixmap(QPixmap::fromImage(previewimg));

	
	bzero(buffer,32);
	sprintf(buffer,"Score: %d", Score);
	score.setText(buffer);
	bzero(buffer,32);
	sprintf(buffer, "Level: %d", Level);	
	level.setText(buffer);



	background.show();
	preview.show();
	score.show();
	level.show();
}
}


void Game::keyPressEvent(QKeyEvent *event){

	if (event->key() == Qt::Key_Up){
		if(start == 0)Gamestart();
	}


	else if (event->key() == Qt::Key_Left){
		int p,q;
		int move = 1;
		for(int n = 0;n<4;n++){
			p = current->x +current->relativeX[n]-1;
			q = current->y +current->relativeY[n];
			if (board[p][q]==1)move=0;
		}	
		if(move)current->moveLeft();
	}

	else if (event->key() == Qt::Key_Right){
		int p,q;
		int move = 1;
		for(int n = 0;n<4;n++){
			p = current->x +current->relativeX[n]+1;
			q = current->y +current->relativeY[n];
			if (board[p][q]==1)move=0;
		}	
		if(move)current->moveRight();
	}
	else if (event->key() == Qt::Key_Down){
		int p,q;
		int move = 1;
		for(int n = 0;n<4;n++){
			p = current->x +current->relativeX[n];
			q = current->y +current->relativeY[n]+1;
			if (board[p][q]==1)move=0;
		}	
		if(move)current->moveDown();
	}	
	else if (event->key() == Qt::Key_Z){
		int p,q;
		int move = 1;
		for(int n = 0;n<4;n++){
			p = current->x +current->relativeY[n];
			q = current->y -current->relativeX[n];
			if (board[p][q]==1)move=0;
		}	
		
		
		if(move)current->rotateClockwise();
	}
	else if (event->key() == Qt::Key_X){
		int p,q;
		int move = 1;
		for(int n = 0;n<4;n++){
			p = current->x -current->relativeY[n];
			q = current->y +current->relativeX[n];
			if (board[p][q]==1)move=0;
		}	
		if(move)current->rotateAnticlockwise();
	}

if(start){
	backgroundimg.load("background.bmp");
	QPainter painter1(&backgroundimg);
	painter1.setBrush(Qt::SolidPattern);
    	painter1.setBrush(Qt::red);
        painter1.setPen(Qt::darkRed);
	for(int i =0; i<4 ; i++){
		painter1.drawRect((current->x+current->relativeX[i])*20,(current->y+current->relativeY[i])*20,20,20);
	}
	
	//draw the board	
	for(int i=0;i<10;i++){
		for(int j=0;j<20;j++){
			if(board[i][j])painter1.drawRect(i*20,j*20,20,20);
		}
	}
	background.setPixmap(QPixmap::fromImage(backgroundimg));
	background.show();
}
}


void Game::updateBlock(){
if (start){
	int p,q;
	int isDown = 0;	
	for (int n =0;n<4;n++ ){
		p = current->x +current->relativeX[n];
		q = current->y +current->relativeY[n]+1;
		if(board[p][q]==1)isDown = 1;
		if(q>19)isDown =1;	

	}
	if(isDown){
		for (int n = 0; n<4 ;n++){
			p = current->x +current->relativeX[n];
			q = current->y +current->relativeY[n];
			board[p][q]=1;
		}
		current = next;
		next = new Block(rand()%7);		

		previewimg.load("previewimg.png");	
		QPainter painter2(&previewimg);
		painter2.setBrush(Qt::SolidPattern);
    		painter2.setBrush(Qt::red);
  	      	painter2.setPen(Qt::darkRed);
		for(int i =0; i<4 ; i++){
			painter2.drawRect((2+next->relativeX[i])*20,(4+next->relativeY[i])*20,20,20);
		}
	
		preview.setPixmap(QPixmap::fromImage(previewimg));
	}
 	else current->moveDown();	
	checkBoard();		
	
	if(start){
	backgroundimg.load("background.bmp");
	QPainter painter1(&backgroundimg);
	painter1.setBrush(Qt::SolidPattern);
    	painter1.setBrush(Qt::red);
        painter1.setPen(Qt::darkRed);
	for(int i =0; i<4 ; i++){
		painter1.drawRect((current->x+current->relativeX[i])*20,(current->y+current->relativeY[i])*20,20,20);
	}

	
	//draw the board	
	for(int i=0;i<10;i++){
		for(int j=0;j<20;j++){
			if(board[i][j])painter1.drawRect(i*20,j*20,20,20);
		}
	}
	background.setPixmap(QPixmap::fromImage(backgroundimg));
	background.show();
}
}
}
void Game::checkBoard(){
	int combo = 0;
	int n = 19;
	int product ;
	while (n!=2){
		product = 1;
		for (int i =0;i<10;i++)product*=board[i][n];
		if (product){
			for(int j = n;j>0;j--){
				for(int i = 0;i<10;i++){
					board[i][j]=board[i][j-1];
				}
				
			}
			combo++;

		}
		else {n = n-1;}
	
	}
	
	int sum = 0;
	for(int i = 0;i<10;i++){
		sum += board[i][0];
		sum += board[i][1];
	}
	if (sum)Gameover();	
	Score+=10*combo*combo;
	bzero(buffer,32);
	sprintf(buffer,"Score: %d", Score);
	score.setText(buffer);
	Level = Score/100 +1;
	if(Level >10)Level = 10;
	bzero(buffer,32);
	sprintf(buffer, "Level: %d", Level);	
	level.setText(buffer);
	timer->start(1000 - (Level -1)*100);
}



void Game::Gameover(){

	memset(board,0,sizeof(board));
	start = 0;
	





        backgroundimg.load("background.bmp");
        background.setPixmap(QPixmap::fromImage(backgroundimg));


        previewimg.load("previewimg.png");

        preview.setPixmap(QPixmap::fromImage(previewimg));

        background.show();
        preview.show();





}





