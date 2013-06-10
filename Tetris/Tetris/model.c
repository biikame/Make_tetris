/**********
* Include *
**********/
#include "pch.h"
#include "model.h"
#include "tetromino.h"

/*******
* Enum *
*******/
enum soundData{
	BOTTON,
};

/**********************
* Function definition *
**********************/
MODEL *Model_create(void){
	MODEL initialize = {
		{//配列の区別
			{0,0,0,0,0,0,0,0,0,0,},
            {0,0,0,0,0,0,0,0,0,0,},
            {0,0,0,0,0,0,0,0,0,0,},
            {0,0,0,0,0,0,0,0,0,0,},
            {0,0,0,0,0,0,0,0,0,0,},
            {0,0,0,0,0,0,0,0,0,0,},
            {0,0,0,0,0,0,0,0,0,0,},
            {0,0,0,0,0,0,0,0,0,0,},
            {0,0,0,0,0,0,0,0,0,0,},
            {0,0,0,0,0,0,0,0,0,0,},
            {0,0,0,0,0,0,0,0,0,0,},
            {0,0,0,0,0,0,0,0,0,0,},
            {0,0,0,0,0,0,0,0,0,0,},
            {0,0,0,0,0,0,0,0,0,0,},
            {0,0,0,0,0,0,0,0,0,0,},
            {0,0,0,0,0,0,0,0,0,0,},
            {0,0,0,0,0,0,0,0,0,0,},
            {0,0,0,0,0,0,0,0,0,0,},
            {0,0,0,0,0,0,0,0,0,0,},
            {0,0,0,0,0,0,0,0,0,0,},
		},
	};
	MODEL *model;
	model = (MODEL *)(malloc(sizeof(*model)));
	*model = initialize;
	model->tetrominoData = TetrominoData_create();
	return model;
}
void Model_destroy(MODEL *model){
	TetrominoData_destroy(model->tetrominoData);
	free(model);
}
void Model_setBlock	(MODEL* model,int y,int x,int variable){
	model->data[y][x] = variable;
}
int Model_getBlock(MODEL* model,int y,int x){
	return model->data[y][x];
}
void Model_draw(MODEL* const model){
	int y,x;
	printf("model\n");
	for(y=0;y<enumhMROW;y++){
		for(x=0;x<enumhMCOL;x++){
			switch( *(*(model->data+y)+x) ){//model->data[i][j]
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
void Model_setBlockInModel(MODEL *model){
	int y,x;
	
	for(y=0;y<enumhTETLIS_BLOCK-model->tetrominoData->gapBlockY;y++){
		for(x=0;x<enumhTETLIS_BLOCK-model->tetrominoData->gapBlockX;x++){
			//printf("%d",tetromino->data[model->tetrominoData->z].data[model->tetrominoData->roll].data[y][x]);
			
			model->data[y+model->tetrominoData->blockY][x+model->tetrominoData->blockX] += model->tetrominoData->tetromino->data[model->tetrominoData->z].data[model->tetrominoData->roll].data[y+model->tetrominoData->gapBlockY][x+model->tetrominoData->gapBlockX];
		}
		//printf("\n");
	}
}
void Model_deleteBlockInModel(MODEL *model){
	int y,x;
	
	for(y=0;y<enumhTETLIS_BLOCK-model->tetrominoData->gapBlockY;y++){
		for(x=0;x<enumhTETLIS_BLOCK-model->tetrominoData->gapBlockX;x++){
			//printf("%d",tetromino->data[model->tetrominoData->z].data[model->tetrominoData->roll].data[y][x]);
			
			model->data[y+model->tetrominoData->blockY][x+model->tetrominoData->blockX] -= model->tetrominoData->tetromino->data[model->tetrominoData->z].data[model->tetrominoData->roll].data[y+model->tetrominoData->gapBlockY][x+model->tetrominoData->gapBlockX];
		}
		//printf("\n");
	}
}
int Model_checkBlockInModel(MODEL *model,int checkY,int checkX){
	int y,x;
	int *BlockData = &model->tetrominoData->tetromino->data[model->tetrominoData->z].data[model->tetrominoData->roll].data[model->tetrominoData->y][model->tetrominoData->x];
	for(y=0;y<enumhTETLIS_BLOCK;y++){
		for(x=0;x<enumhTETLIS_BLOCK;x++){
			
			if(model->tetrominoData->tetromino->data[model->tetrominoData->z].data[model->tetrominoData->roll].data[y][x]>0){//ブロックのある場所が
				
				if(model->data[y+checkY-model->tetrominoData->gapBlockY][x+checkX-model->tetrominoData->gapBlockX] > 0 ||
					(x+checkX-model->tetrominoData->gapBlockX)>=enumhMCOL ||(x+checkX-model->tetrominoData->gapBlockX)<0|| 
					(y+checkY-model->tetrominoData->gapBlockY)>=enumhMROW ||(y+checkY-model->tetrominoData->gapBlockY)<0)
				{//ステージデータ+check位置
					return 0;
				}
			}
		}
	}
	model->tetrominoData->blockY = checkY;
	model->tetrominoData->blockX = checkX;
	return 1;
}
void Model_moveBlock(MODEL *model){
	Model_setBlockInModel(model);
}
void Model_getkey(MODEL *model,int key){
	int VX,VY;
	VX=0,VY=0;
	switch(key){
		case 'a':VX--;break;
		case 'd':VX++;break;
		//case 'w':VX--;break;
		//case 's':VX++;break;
		case 'f':Model_rotate(model,1);Model_sound(BOTTON);break;
		case 'c':Model_rotate(model,0);Model_sound(BOTTON);break;
	}
	Model_checkBlockInModel(model,model->tetrominoData->blockY+VY,model->tetrominoData->blockX+VX);
}
void Model_rotate(MODEL *model,int flag){
	if(flag){
		if(model->tetrominoData->roll == enumhROLL-1){
			model->tetrominoData->roll = 0;
		}else{
			model->tetrominoData->roll++;
		}
	}else{
		if(model->tetrominoData->roll == 0){
			model->tetrominoData->roll = 3;
		}else{
			model->tetrominoData->roll--;
		}
	}
	TetrominoData_update(model->tetrominoData);//ずれをあわせる

	if(Model_checkBlockInModel(model,model->tetrominoData->blockY,model->tetrominoData->blockX)==0){
		
		if(model->tetrominoData->roll==0){//ここで２時間バグ取り
			model->tetrominoData->roll=enumhROLL-1;
		}else{
			model->tetrominoData->roll--;
		}
		TetrominoData_update(model->tetrominoData);//ずれをあわせる
	}else{
		TetrominoData_update(model->tetrominoData);//ずれをあわせる
	}
}
void Model_deleteLine(MODEL *model,int deleteLine){
	int x,y;
	//for(x=0;x<enumhMCOL;x++){//一列揃ったデータを消してます
	//	model->data[deleteLine][x] = 0;
	//}
	for(y=deleteLine-1;y>=0;y--){
		for(x=0;x<enumhMCOL;x++){
			if(y){//0の時の1の処理してない　いいポイント
				Model_setBlock(model,y+1,x,model->data[y][x]);
			}else{
				//0の時の1の処理してない所を直した
				Model_setBlock(model,y+1,x,model->data[y][x]);
				Model_setBlock(model,y,x,0);
			}
		}
	}
}
void Model_checkLine(MODEL *model){
	int y,x;
	for(y=enumhMROW-1;y>0;y--){
		
		for(x=0;x<enumhMCOL;x++){
			if(model->data[y][x] == 0){
				break;
			}else if(x == enumhMCOL-1){//ブロックが一列揃っている
				Model_deleteLine(model,y);
				y++;
			}
		}
	}
}
int Model_gameOver(MODEL *model){
	int y,x;
	for(y=0;y<enumhMROW;y++){
		for(x=0;x<enumhMCOL;x++){
			if(model->data[y][x] > 2){
				return 0;
			}
		}
	}
	return 1;
}
void Model_sound(int sound){

	switch(sound){
		case BOTTON:
			PlaySound("../BGM/WaVbotan_b46.wav",NULL,SND_FILENAME| SND_ASYNC);
		break;
	}
}