/**********
* Include *
**********/
#include "pch.h"
#include "tetorimino.h"

/**********************
* Function definition *
**********************/
void Tetrimino_main(){
	TETRIMINO tetorimino;
	Tetrimino_init(&tetorimino);
}
void Tetrimino_init(TETRIMINO *tetorimino){
	TETRIMINO initialize = {
		{
			{//z
				0,0,0,0,0,//□ □ □ □ □
				0,0,0,0,0,//□ □ □ □ □
				0,1,2,1,1,//□ ■ ■ ■ ■
				0,0,0,0,0,//□ □ □ □ □
				0,0,0,0,0,//□ □ □ □ □

				0,0,0,0,0,//□ □ □ □ □
				0,0,1,0,0,//□ □ ■ □ □
				0,0,2,0,0,//□ □ ■ □ □
				0,0,1,0,0,//□ □ ■ □ □
				0,0,1,0,0,//□ □ ■ □ □

				0,0,0,0,0,//□ □ □ □ □
				0,0,0,0,0,//□ □ □ □ □
				1,1,2,1,0,//□ ■ ■ ■ ■
				0,0,0,0,0,//□ □ □ □ □
				0,0,0,0,0,//□ □ □ □ □

				0,0,0,0,0,//□ □ □ □ □
				0,0,1,0,0,//□ □ ■ □ □
				0,0,2,0,0,//□ □ ■ □ □
				0,0,1,0,0,//□ □ ■ □ □
				0,0,1,0,0,//□ □ ■ □ □
			},
			{
				0,0,0,0,0,//□ □ □ □ □
                0,0,0,0,0,//□ □ □ □ □
                0,1,2,1,0,//□ ■ ■ ■ □
                0,0,1,0,0,//□ □ ■ □ □
                0,0,0,0,0,//□ □ □ □ □
          
                0,0,0,0,0,//□ □ □ □ □
                0,0,1,0,0,//□ □ ■ □ □
                0,1,2,0,0,//□ ■ ■ □ □
                0,0,1,0,0,//□ □ ■ □ □
                0,0,0,0,0,//□ □ □ □ □
          
                0,0,0,0,0,//□ □ □ □ □
                0,0,0,0,0,//□ □ □ □ □
                0,0,2,0,0,//□ □ ■ □ □
                0,1,1,1,0,//□ ■ ■ ■ □
                0,0,0,0,0,//□ □ □ □ □
          
                0,0,0,0,0,//□ □ □ □ □
                0,0,1,0,0,//□ □ ■ □ □
                0,0,2,1,0,//□ □ ■ ■ □
                0,0,1,0,0,//□ □ ■ □ □
                0,0,0,0,0,//□ □ □ □ □
			},
			{
				0,0,0,0,0,//□ □ □ □ □
                0,0,0,0,0,//□ □ □ □ □
                0,1,2,0,0,//□ ■ ■ □ □
                0,0,1,1,0,//□ □ ■ ■ □
                0,0,0,0,0,//□ □ □ □ □
          
                0,0,0,0,0,//□ □ □ □ □
                0,0,0,1,0,//□ □ □ ■ □
                0,0,2,1,0,//□ □ ■ ■ □
                0,0,1,0,0,//□ □ ■ □ □
                0,0,0,0,0,//□ □ □ □ □
           
                0,0,0,0,0,//□ □ □ □ □
                0,0,0,0,0,//□ □ □ □ □
                0,1,2,0,0,//□ ■ ■ □ □
                0,0,1,1,0,//□ □ ■ ■ □
                0,0,0,0,0,//□ □ □ □ □
           
                0,0,0,0,0,//□ □ □ □ □
                0,0,0,1,0,//□ □ □ ■ □
                0,0,2,1,0,//□ □ ■ ■ □
                0,0,1,0,0,//□ □ ■ □ □
                0,0,0,0,0,//□ □ □ □ □
			},
			{
				0,0,0,0,0,//□ □ □ □ □
                0,0,0,0,0,//□ □ □ □ □
                0,0,2,1,0,//□ □ ■ ■ □
                0,1,1,0,0,//□ ■ ■ □ □
                0,0,0,0,0,//□ □ □ □ □
           
                0,0,0,0,0,//□ □ □ □ □
                0,0,1,0,0,//□ ■ □ □ □
                0,0,2,1,0,//□ ■ ■ □ □
                0,0,0,1,0,//□ □ ■ □ □
                0,0,0,0,0,//□ □ □ □ □
           
                0,0,0,0,0,//□ □ □ □ □
                0,0,0,0,0,//□ □ □ □ □
                0,0,2,1,0,//□ □ ■ ■ □
                0,1,1,0,0,//□ ■ ■ □ □
                0,0,0,0,0,//□ □ □ □ □
           
                0,0,0,0,0,//□ □ □ □ □
                0,0,1,0,0,//□ □ ■ □ □
                0,0,2,1,0,//□ □ ■ ■ □
                0,0,0,1,0,//□ □ □ ■ □
                0,0,0,0,0,//□ □ □ □ □
			},
			{
				0,0,0,0,0,//□ □ □ □ □
                0,0,0,0,0,//□ □ □ □ □
                0,1,2,1,0,//□ ■ ■ ■ □
                0,0,0,1,0,//□ □ □ ■ □
                0,0,0,0,0,//□ □ □ □ □
           
                0,0,0,0,0,//□ □ □ □ □
                0,0,1,0,0,//□ □ ■ □ □
                0,0,2,0,0,//□ □ ■ □ □
                0,1,1,0,0,//□ ■ ■ □ □
                0,0,0,0,0,//□ □ □ □ □
         
                0,0,0,0,0,//□ □ □ □ □
                0,0,0,0,0,//□ □ □ □ □
                0,1,0,0,0,//□ ■ □ □ □
                0,1,1,1,0,//□ ■ ■ ■ □
                0,0,0,0,0,//□ □ □ □ □
          
                0,0,0,0,0,//□ □ □ □ □
                0,0,1,1,0,//□ □ ■ ■ □
                0,0,2,0,0,//□ □ ■ □ □
                0,0,1,0,0,//□ □ ■ □ □
                0,0,0,0,0,//□ □ □ □ □
			},
			{
				0,0,0,0,0,//□ □ □ □ □
                0,0,0,0,0,//□ □ □ □ □
                0,1,2,1,0,//□ ■ ■ ■ □
                0,1,0,0,0,//□ ■ □ □ □
                0,0,0,0,0,//□ □ □ □ □
           
                0,0,0,0,0,//□ □ □ □ □
                0,1,1,0,0,//□ ■ ■ □ □
                0,0,2,0,0,//□ □ ■ □ □
                0,0,1,0,0,//□ □ ■ □ □
                0,0,0,0,0,//□ □ □ □ □
            
                0,0,0,0,0,//□ □ □ □ □
                0,0,0,0,0,//□ □ □ □ □
                0,0,0,1,0,//□ □ □ ■ □
                0,1,2,1,0,//□ ■ ■ ■ □
                0,0,0,0,0,//□ □ □ □ □
           
                0,0,0,0,0,//□ □ □ □ □
                0,0,1,0,0,//□ □ ■ □ □
                0,0,2,0,0,//□ □ ■ □ □
                0,0,1,1,0,//□ □ ■ ■ □
                0,0,0,0,0,//□ □ □ □ □
			},
			{
				0,0,0,0,0,//□ □ □ □ □
                0,0,0,0,0,//□ □ □ □ □
                0,0,2,1,0,//□ □ ■ ■ □
                0,0,1,1,0,//□ □ ■ ■ □
                0,0,0,0,0,//□ □ □ □ □
           
                0,0,0,0,0,//□ □ □ □ □
                0,0,0,0,0,//□ □ □ □ □
                0,0,2,1,0,//□ □ ■ ■ □
                0,0,1,1,0,//□ □ ■ ■ □
                0,0,0,0,0,//□ □ □ □ □
           
                0,0,0,0,0,//□ □ □ □ □
                0,0,0,0,0,//□ □ □ □ □
                0,0,2,1,0,//□ □ ■ ■ □
                0,0,1,1,0,//□ □ ■ ■ □
                0,0,0,0,0,//□ □ □ □ □
          
                0,0,0,0,0,//□ □ □ □ □
                0,0,0,0,0,//□ □ □ □ □
                0,0,2,1,0,//□ □ ■ ■ □
                0,0,1,1,0,//□ □ ■ ■ □
                0,0,0,0,0,//□ □ □ □ □
			},
		},
	};
	*tetorimino =initialize;
}
void Tetrimino_draw(TETORIMINODATA *setTetoriminoData,const TETRIMINO *tetorimino){
	int y,x;
	for(y=0;y<enumhTETLIS_BLOCK;y++){
		for(x=0;x<enumhTETLIS_BLOCK;x++){
			switch( tetorimino->data[setTetoriminoData->z].data[setTetoriminoData->roll].data[y][x]){//model->data[i][j]
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

void Tetrimino_draw_sprintf(TETORIMINODATA *setTetoriminoData, TETRIMINO *tetorimino){
	int y,x,i;
	char *pstr = tetorimino->str;
	
	i=0,pstr+=26;//右端 

	for(y=0;y<enumhTETLIS_BLOCK;y++){
		for(x=0;x<enumhTETLIS_BLOCK;x++){
			switch( tetorimino->data[setTetoriminoData->z].data[setTetoriminoData->roll].data[y][x]){//model->data[i][j]
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
void Tetrimino_getRandamTetris(TETRIMINO *tetorimino){
	int i,j,k;
	int randData[enumhTETORIMINO_NUM+1];
	i=0,j=0,k=0;

	if(tetorimino->randTetris[0][i] == 0 && tetorimino->randTetris[1][i] != 0){
		for(i=0;i<enumhTETORIMINO_NUM;i++){
			tetorimino->randTetris[k][i] = randData[i+1];		
		}
		tetorimino->randTetris[k][0]=0;
	}
	while(k<2){

		if(tetorimino->randTetris[k][0] == 0){

			while(j<enumhTETORIMINO_NUM+1){

				randData[j] = 1 + (int)(0 + rand() * ( (enumhTETORIMINO_NUM-1) - 0 + 1.0) / (1.0 + RAND_MAX) );

				for(i=1;i<j;i++){
					if(randData[i] == randData[j]){
						j--;
						break;
					}
				}
				j++;
			
			}
			for(i=0;i<enumhTETORIMINO_NUM;i++){
				tetorimino->randTetris[k][i] = randData[i+1];		
			}
		}
		k++;
	}
	
}
void Tetrimino_resetRandamTetris(TETRIMINO *tetorimino){
	int i;
	for(i=1;i<enumhTETORIMINO_NUM;i++){
		tetorimino->randTetris[0][i-1] = tetorimino->randTetris[0][i];
		tetorimino->randTetris[0][i]	= 0;
		
	}
}
void Tetrimino_setgetRandamTetris(TETRIMINO *tetorimino){
	int i;
	if(tetorimino->randTetris[0][1] == 0){
		for(i=0;i<enumhTETORIMINO_NUM;i++){
			tetorimino->randTetris[0][i+1] = tetorimino->randTetris[1][i];
		}
	}
}
void Tetrimino_setTetoriminoData(TETORIMINODATA *tetoriminoData,TETRIMINO *tetorimino){

	TETORIMINODATA initialize = {0,0,0,0,
								 0,0,
								 3,0};

	Tetrimino_getRandamTetris(tetorimino);

	initialize.z = tetorimino->randTetris[0][0]-1;
	
	*tetoriminoData = initialize;
	
	Tetrimino_resetRandamTetris(tetorimino);
	
	Tetrimino_updateTetoriminoData(tetoriminoData,tetorimino);
}

void Tetrimino_updateTetoriminoData(TETORIMINODATA *setTetoriminoData,TETRIMINO *tetorimino){
	
	int y,x;
	int *mapData;

	TETORIMINODATA initialize = {setTetoriminoData->x,setTetoriminoData->y,setTetoriminoData->roll,setTetoriminoData->z,
								4,0,
								setTetoriminoData->blockX,setTetoriminoData->blockY};

	typedef struct DATA{
		unsigned int flag,flagX,flagY;
	}DATA;

	DATA set = {1,0,1,};

	*setTetoriminoData = initialize;

	mapData =&tetorimino->data[setTetoriminoData->z].data[setTetoriminoData->roll].data[setTetoriminoData->y][setTetoriminoData->x];// &(*(*(*(tetorimino->data+tetoriminoData->z)->data).data));//&tetorimino->data[tetoriminoData->z].data[tetoriminoData->roll].data[tetoriminoData->y][tetoriminoData->x];

	for(y=0;y<enumhTETLIS_BLOCK;y++){
		set.flagX = 0;
		for(x=0;x<enumhTETLIS_BLOCK;x++){
			if(mapData[y*enumhTETLIS_BLOCK+x] == 1 ||mapData[y*enumhTETLIS_BLOCK+x] == 2){
				if(set.flagY){
					setTetoriminoData->gapBlockY = y;
					setTetoriminoData->gapBlockX = MIN(x,setTetoriminoData->gapBlockX);
					set.flagY = 0;set.flagX++;
				}else{
					setTetoriminoData->gapBlockX = MIN(x,setTetoriminoData->gapBlockX);
					set.flagX++;
					if(set.flagX>=2)
						set.flag = 0;
				}
			}
			if(mapData[y*enumhTETLIS_BLOCK+x] == 2 && setTetoriminoData->gapBlockX == x){
				setTetoriminoData->gapBlockX--;
			}
		}
	}
	if(set.flag)setTetoriminoData->gapBlockX--;
}

void Tetrimino_nextBlock(TETRIMINO *tetorimino){

	TETORIMINODATA initialze ={ 0,0,0,(tetorimino->randTetris[0]-1),
								0,0,
								0,0};
	
	//描画
	//printf("next BLock\n");
	Tetrimino_draw_sprintf(&initialze,tetorimino);
	
	//initialze.z = (tetorimino->randTetris[1]-1);
	////printf("nextnext BLock\n");
	//Tetrimino_draw_sprintf(&initialze,tetorimino);
}

void Tetrimino_seeNextBlock(TETRIMINO *tetorimino){
	
}