#include<QtGui>
#include<qtimer.h>
#include"block.h"

Block::Block(int t):
	type(t),x(4),y(2)

{
	setBlock();

}
void Block::moveLeft(){
	int move = 1;
	for(int i = 0; i<4 ;i++){
		if (x+relativeX[i]-1<0)move = 0;
	}
	if (move)x--;
}
void Block::moveRight(){
	int move = 1;
	for(int i = 0; i<4 ;i++){
		if (x+relativeX[i]+1>9)move = 0;
	}
	if(move)x++;
}

void Block::moveDown(){
	int move = 1;
	for(int i = 0; i<4; i++){
		if (y+relativeY[i]+1>19)move = 0;
	}
	
	if (move)y++;
}



void Block::rotateClockwise(){
	int move = 1;
	for(int i = 0; i<4; i++){
		if(x+relativeY[i]<0||x+relativeY[i]>9||y-relativeX[i]>19)move = 0;	
	}
	
	if(move){
		for (int i =0; i<4 ; i++){
	                tmp[i] = relativeX[i];
	        }

		for (int i =0; i<4 ; i++){
			relativeX[i] = relativeY[i];
		}
		for (int i =0; i<4 ; i++){
	                relativeY[i] = -tmp[i];
	        }
	}



}

void Block::rotateAnticlockwise(){
	int move = 1;
	for(int i = 0; i<4; i++){
		if(x-relativeY[i]<0||x-relativeY[i]>9||y+relativeX[i]>19)move = 0;	
	}

	if(move){
	
		for (int i = 0 ;i<4; i++){
			tmp[i] = relativeY[i];
		}
		for (int i = 0; i< 4 ; i++){
			relativeY[i] = relativeX[i];
		}
		for (int i = 0; i<4 ;i++){
			relativeX[i] = -tmp[i];
		}
	}

}

void Block::setBlock(){
	if (type == 0){
		for(int i= 0;i<4;i++)relativeX[i]=0;
		relativeY[0] =  0; 
		relativeY[1] = -2; 
		relativeY[2] = -1; 
		relativeY[3] =  1;
	}	
	else if(type == 1){
		relativeX[0] = 0 ;
		relativeX[1] = -1 ;
		relativeX[2] =  -1;
		relativeX[3] =  0;
		relativeY[0] =  0; 
		relativeY[1] =  0; 
		relativeY[2] =  -1; 
		relativeY[3] =  -1; 

	}
	else if(type == 2){
		relativeX[0] = 0 ;
		relativeX[1] = 0 ;
		relativeX[2] = 1 ;
		relativeX[3] = 1 ;
		relativeY[0] =  0; 
		relativeY[1] =  -1; 
		relativeY[2] =  0; 
		relativeY[3] =  1; 
		
	}
	else if(type == 3){
		relativeX[0] = 0 ;
		relativeX[1] = 0 ;
		relativeX[2] = 1 ;
		relativeX[3] = 1 ;
		relativeY[0] = 0 ; 
		relativeY[1] = 1 ; 
		relativeY[2] = 0 ; 
		relativeY[3] = -1 ; 
	}
	else if(type == 4){
		relativeX[0] = 0 ;
		relativeX[1] = 0 ;
		relativeX[2] = 0 ;
		relativeX[3] = 1 ;
		relativeY[0] = 0 ; 
		relativeY[1] = -1 ; 
		relativeY[2] = 1 ; 
		relativeY[3] = 1 ; 
	}
	else if(type == 5){
		relativeX[0] = 0 ;
		relativeX[1] = 0 ;
		relativeX[2] = 0 ;
		relativeX[3] = -1 ;
		relativeY[0] = 0 ; 
		relativeY[1] = -1 ; 
		relativeY[2] = 1 ; 
		relativeY[3] = 1 ; 
	}
	else if(type == 6){
		relativeX[0] = 0 ;
		relativeX[1] = 0 ;
		relativeX[2] = 1 ;
		relativeX[3] = -1 ;
		relativeY[0] = 0 ; 
		relativeY[1] = -1 ; 
		relativeY[2] = 0 ; 
		relativeY[3] = 0 ; 
	}


}


































	



