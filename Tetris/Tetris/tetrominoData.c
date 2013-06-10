/**********
* Include *
**********/
#include "pch.h"
#include "tetrominoData.h"

/**********************
* Function definition *
**********************/
TETROMINODATA *TetrominoData_create(void){

	TETROMINODATA initialize = {0,0,0,0,
								 0,0,
								 3,0};
	TETROMINODATA *tetrominoData;
	tetrominoData = (TETROMINODATA *)(malloc(sizeof(*tetrominoData)));
	tetrominoData->tetromino = Tetromino_create();
	return tetrominoData;
}

void TetrominoData_destroy(TETROMINODATA *tetrominoData){
	Tetromino_destroy(tetrominoData->tetromino);
	free(tetrominoData);
}

void TetrominoData_set(TETROMINODATA *tetrominoData){

	TETROMINODATA initialize = {0,0,0,0,
								 0,0,
								 3,0};

	Tetromino_getRandamTetris(tetrominoData->tetromino);

	initialize.z = tetrominoData->tetromino->randTetris[0][0]-1;
	initialize.tetromino = tetrominoData->tetromino;
	
	*tetrominoData = initialize;
	
	Tetromino_resetRandamTetris(tetrominoData->tetromino);
	
	TetrominoData_update(tetrominoData);
}

void TetrominoData_update(TETROMINODATA *tetrominoData){
	
	int y,x;
	int *mapData;

	TETROMINODATA initialize = {tetrominoData->x,tetrominoData->y,tetrominoData->roll,tetrominoData->z,
								4,0,
								tetrominoData->blockX,tetrominoData->blockY};

	typedef struct DATA{
		unsigned int flag,flagX,flagY;
	}DATA;

	DATA set = {1,0,1,};

	initialize.tetromino = tetrominoData->tetromino;
	*tetrominoData = initialize;

	mapData =&tetrominoData->tetromino->data[tetrominoData->z].data[tetrominoData->roll].data[tetrominoData->y][tetrominoData->x];// &(*(*(*(tetromino->data+tetoriminoData->z)->data).data));//&tetromino->data[tetoriminoData->z].data[tetoriminoData->roll].data[tetoriminoData->y][tetoriminoData->x];

	for(y=0;y<enumhTETLIS_BLOCK;y++){
		set.flagX = 0;
		for(x=0;x<enumhTETLIS_BLOCK;x++){
			if(mapData[y*enumhTETLIS_BLOCK+x] == 1 ||mapData[y*enumhTETLIS_BLOCK+x] == 2){
				if(set.flagY){
					tetrominoData->gapBlockY = y;
					tetrominoData->gapBlockX = MIN(x,tetrominoData->gapBlockX);
					set.flagY = 0;set.flagX++;
				}else{
					tetrominoData->gapBlockX = MIN(x,tetrominoData->gapBlockX);
					set.flagX++;
					if(set.flagX>=2)
						set.flag = 0;
				}
			}
			if(mapData[y*enumhTETLIS_BLOCK+x] == 2 && tetrominoData->gapBlockX == x){
				tetrominoData->gapBlockX--;
			}
		}
	}
	if(set.flag)tetrominoData->gapBlockX--;
}

void TetrominoData_draw(TETROMINODATA *tetrominoData){
	int y,x;
	for(y=0;y<enumhTETLIS_BLOCK;y++){
		for(x=0;x<enumhTETLIS_BLOCK;x++){
			switch( tetrominoData->tetromino->data[tetrominoData->z].data[tetrominoData->roll].data[y][x]){//model->data[i][j]
				case 0:
					printf("　");
					break;
				case 1:case 2:
					printf("■");
					break;
			}
		}	
		printf("\n");
	}
}

void TetrominoData_draw_sprintf(TETROMINODATA *tetrominoData){
	int y,x,i;
	char *pstr = tetrominoData->tetromino->str;
	
	i=0,pstr+=26;//右端 

	for(y=0;y<enumhTETLIS_BLOCK;y++){
		for(x=0;x<enumhTETLIS_BLOCK;x++){
			switch( tetrominoData->tetromino->data[tetrominoData->z].data[tetrominoData->roll].data[y][x]){//model->data[i][j]
				case 0:
					sprintf(pstr,"　");
					pstr+=2;
					break;
				case 1:case 2:
					sprintf(pstr,"■");
					pstr+=2;
					break;
			}
		}	
		sprintf(pstr,"\n");
		i++;
		pstr+=26*i;//次の描画位置に移動
	}
}
