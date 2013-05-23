/**********
* Include *
**********/
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
void Tetrimino_draw(TETORIMINODATA *setTetoriminoData,TETRIMINO *const tetorimino){
	int y,x;
	printf("tetorimino\n");
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
void Tetrimino_getRandamTetris(TETRIMINO *tetorimino){
	int i,j;
	int randData[enumhTETORIMINO_NUM+1];
	i=0,j=0;

	if(*(tetorimino->randTetris) == 0){

		while(j<enumhTETORIMINO_NUM+1){

			randData[j] = 0 + (int)(0 + rand() * ( (enumhTETORIMINO_NUM-1) - 0 + 1.0) / (1.0 + RAND_MAX) );

			for(i=1;i<j;i++){
				if(randData[i] == randData[j]){
					j--;
					break;
				}
			}
			j++;
			
		}
		for(i=0;i<enumhTETORIMINO_NUM;i++){
			tetorimino->randTetris[i] = randData[i+1];
		}
	}

}
void Tetrimino_resetRandamTetris(TETRIMINO *tetorimino){
	int i;
	for(i=1;i<enumhTETORIMINO_NUM;i++){
		tetorimino->randTetris[i-1] = tetorimino->randTetris[i];
		tetorimino->randTetris[i]	= 0;
	}
}
void Tetrimino_setTetoriminoData(TETORIMINODATA *tetoriminoData,TETRIMINO *tetorimino){

	TETORIMINODATA initialize = {0,0,0,0,
								 0,0,
								 3,0};

	Tetrimino_getRandamTetris(tetorimino);

	initialize.z = *(tetorimino->randTetris);
	
	*tetoriminoData = initialize;
	
	Tetrimino_resetRandamTetris(tetorimino);
	
	Tetrimino_updateTetoriminoData(tetoriminoData,tetorimino);
}

void Tetrimino_updateTetoriminoData(TETORIMINODATA *setTetoriminoData,TETRIMINO *tetorimino){
	
	int y,x;int i;
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