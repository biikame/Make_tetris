/**********
* Include *
**********/
#include "pch.h"
#include "model.h"
#include "tetorimino.h"
/**********************
* Function definition *
**********************/
void Model_main(){
	MODEL model;
	Model_init2(&model);
	Model_draw(&model);
}
void Model_init(MODEL* model){
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
	*model = initialize;
}
void Model_init2(MODEL* model){
	int y,x;
	int data;
	for(y=0;y<enumhMROW;y++){
		for(x=0;x<enumhMCOL;x++){

			if( y==0				&& x==0				||
				y==0				&& x==enumhMCOL-1	||
				y == enumhMROW-1	&& x ==0			||
				y == enumhMROW-1	&& x == enumhMCOL-1
			)
				Model_setBlock(model,y,x,1);
			else{
				Model_setBlock(model,y,x,0);
			}
				
		}
	}
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
void Model_setBlockInModel(MODEL *model,TETRIMINO *tetorimino,TETORIMINODATA *tetoriminoData){
	int y,x;
	
	for(y=0;y<enumhTETLIS_BLOCK-tetoriminoData->gapBlockY;y++){
		for(x=0;x<enumhTETLIS_BLOCK-tetoriminoData->gapBlockX;x++){
			//printf("%d",tetorimino->data[tetoriminoData->z].data[tetoriminoData->roll].data[y][x]);
			
			model->data[y+tetoriminoData->blockY][x+tetoriminoData->blockX] += tetorimino->data[tetoriminoData->z].data[tetoriminoData->roll].data[y+tetoriminoData->gapBlockY][x+tetoriminoData->gapBlockX];
		}
		//printf("\n");
	}
}
void Model_deleteBlockInModel(MODEL *model,TETRIMINO *tetorimino,TETORIMINODATA *tetoriminoData){
	int y,x;
	
	for(y=0;y<enumhTETLIS_BLOCK-tetoriminoData->gapBlockY;y++){
		for(x=0;x<enumhTETLIS_BLOCK-tetoriminoData->gapBlockX;x++){
			//printf("%d",tetorimino->data[tetoriminoData->z].data[tetoriminoData->roll].data[y][x]);
			
			model->data[y+tetoriminoData->blockY][x+tetoriminoData->blockX] -= tetorimino->data[tetoriminoData->z].data[tetoriminoData->roll].data[y+tetoriminoData->gapBlockY][x+tetoriminoData->gapBlockX];
		}
		//printf("\n");
	}
}
int Model_checkBlockInModel(MODEL *model,TETRIMINO *tetorimino,TETORIMINODATA *tetoriminoData,int checkY,int checkX){
	int y,x;
	int *BlockData = &tetorimino->data[tetoriminoData->z].data[tetoriminoData->roll].data[tetoriminoData->y][tetoriminoData->x];
	for(y=0;y<enumhTETLIS_BLOCK;y++){
		for(x=0;x<enumhTETLIS_BLOCK;x++){
			
			if(tetorimino->data[tetoriminoData->z].data[tetoriminoData->roll].data[y][x]>0){//ブロックのある場所が
				
				if(model->data[y+checkY-tetoriminoData->gapBlockY][x+checkX-tetoriminoData->gapBlockX] > 0 ||
					(x+checkX-tetoriminoData->gapBlockX)>=enumhMCOL ||(x+checkX-tetoriminoData->gapBlockX)<0|| 
					(y+checkY-tetoriminoData->gapBlockY)>=enumhMROW ||(y+checkY-tetoriminoData->gapBlockY)<0)
				{//ステージデータ+check位置
					return 0;
				}
			}
		}
	}
	tetoriminoData->blockY = checkY;
	tetoriminoData->blockX = checkX;
	return 1;
}

void Model_moveBlock(MODEL *model,TETRIMINO *tetorimino,TETORIMINODATA *tetoriminoData){
	Model_setBlockInModel(model,tetorimino,tetoriminoData);
}
void Model_getkey(MODEL *model,TETRIMINO *tetorimino,TETORIMINODATA *tetoriminoData){
	int VX,VY;
	int key = getch();
	VX=0,VY=0;
	switch(key){
		case 'a':VX--;break;
		case 'd':VX++;break;
		//case 'w':VX--;break;
		//case 's':VX++;break;
		case ' ':Model_rotate(model,tetorimino,tetoriminoData);break;
	}
	Model_checkBlockInModel(model,tetorimino,tetoriminoData,tetoriminoData->blockY+VY,tetoriminoData->blockX+VX);
}
void Model_rotate(MODEL *model,TETRIMINO *tetorimino,TETORIMINODATA *tetoriminoData){
	if(tetoriminoData->roll == enumhROLL-1){
		tetoriminoData->roll = 0;
	}else{
		tetoriminoData->roll++;
	}
	
	Tetrimino_updateTetoriminoData(tetoriminoData,tetorimino);//ずれをあわせる

	if(Model_checkBlockInModel(model,tetorimino,tetoriminoData,tetoriminoData->blockY,tetoriminoData->blockX)==0){
		
		if(tetoriminoData->roll==0){//ここで２時間バグ取り
			tetoriminoData->roll=enumhROLL-1;
		}else{
			tetoriminoData->roll--;
		}
		Tetrimino_updateTetoriminoData(tetoriminoData,tetorimino);//ずれをあわせる
	
	
	}else{
		
		Tetrimino_updateTetoriminoData(tetoriminoData,tetorimino);//ずれをあわせる
	}
}
void Model_deleteLine(MODEL *model,TETRIMINO *tetorimino,TETORIMINODATA *tetoriminoData,int deleteLine){
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
void Model_checkLine(MODEL *model,TETRIMINO *tetorimino,TETORIMINODATA *tetoriminoData){
	int y,x;
	for(y=enumhMROW-1;y>0;y--){
		
		for(x=0;x<enumhMCOL;x++){
			if(model->data[y][x] == 0){
				break;
			}else if(x == enumhMCOL-1){//ブロックが一列揃っている
				Model_deleteLine(model,tetorimino,tetoriminoData,y);
				y++;
			}
		}
	}
}
int Model_gameOver(MODEL *model,TETRIMINO *tetorimino,TETORIMINODATA *tetoriminoData){
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
//enumhMROW = 20,
//	enumhMCOL = 10,