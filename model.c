/* Alperen İnci 18120205016
 * model.c
 * provides the grid (model) 
 * and functions to handle the grid for the game of life
 */

#include "gameoflife.h"
int grid[M][N] = {0};/*M and N are constants defined in gameOfLife.h*/
int neighbordizisi[M][N]={0}; 	
int initGridWithBlinker(){
for(int i =5;i<M;i=i+10){
   
	   grid[i][i]=1;
	   grid[i-1][i]=1;
	   grid[i-2][i]=1;
   }
  }
int initGridWithGlider(){
for(int i=5;i<M;i=i+10){
	grid[i][i]=1;
	grid[i-1][i]=1;
	grid[i-2][i]=1;
	grid[i-2][i-1]=1;
	grid[i-1][i-2]=1;  
    }
   } 
/**
 * initializes the grid with the chosen initial state
 */
int initGrid(int initialState){
if(initialState==1){
   initGridWithBlinker();} /* blinker fonksiyonunu cagirir.*/
if(initialState==2){
	initGridWithGlider();} /*glider fonksiyonunu cagirir.*/
      	  
	return 0;
}


/**
 * returns the number of live neighbors of the cell
 * at position (x, y) on the grid
 */
int getNumberOfLiveNeighbors(int x, int y){
int neighbors=0;
for (int i = x-1; i <= x+1; i++){
        for(int j = y-1; j <= y+1; j++){
            if (!(i == x && j == y)){
				if(i < M && j < N && i >= 0 && j >= 0){
					if (grid[i][j] == 1){
						neighbors++;   
     }
    }
   }	
  }
}
	return neighbors;
}

/**
 * updates each cell by following the update rules of the game of life
 */
int updateGrid(){	

for(int x=0;x<M;x++){
	for(int y=0;y<N;y++){
		neighbordizisi[x][y]=getNumberOfLiveNeighbors(x,y);
	}
   }		
   for(int x=0;x<M;x++){
      for(int y=0;y<N;y++){
	   if(neighbordizisi[x][y]<=1){
		   grid[x][y]=0;  
	   }
	   else if(grid[x][y]==1 && (neighbordizisi[x][y]==2 || neighbordizisi[x][y]==3)){
		   grid[x][y]=1;
	   }
		else if(grid[x][y]==1 && (neighbordizisi[x][y]==0 || neighbordizisi[x][y]==1)){
		   grid[x][y]=0;
	   }
		 else if(grid[x][y]==0 && neighbordizisi[x][y]==3){
		   grid[x][y]=1;
	   }
	  }
     }  
	return 0;
}

