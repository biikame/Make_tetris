/**********
* Include *
**********/
#include "pch.h"
#include "view.h"
#include "model.h"
#include "tetorimino.h"
#include "tetlis.h"
/**********************
* Function definition *
**********************/
void Tetlis_main(){

	VIEW view;
	MODEL model;
	TETRIMINO tetorimino;
	TETORIMINODATA tetoriminoData;

	int timer;

	srand((unsigned int)time(NULL));

	Tetlis_init(&view,&model,&tetorimino,&tetoriminoData);
	Tetlis_set(&view,&model,&tetorimino,&tetoriminoData);
	while(1){

		for(timer=0;timer<=90000000;timer++){
			
		}
		Tetlis_draw(&view,&model,&tetorimino,&tetoriminoData);
		
		Tetlis_getKey(&view,&model,&tetorimino,&tetoriminoData);
	
		Tetlis_deleteBlock(&view,&model,&tetorimino,&tetoriminoData);

		if(Tetlis_checkBlockInModel(&view,&model,&tetorimino,&tetoriminoData)){
			Tetlis_set(&view,&model,&tetorimino,&tetoriminoData);
		}else{
			Tetlis_set(&view,&model,&tetorimino,&tetoriminoData);
			Tetlis_initBlock(&view,&model,&tetorimino,&tetoriminoData);
		}
	}
	//デバック用
	//Model_main();
	//View_main();
	//Tetrimino_main();
}

void Tetlis_init(VIEW *view,MODEL *model,TETRIMINO *tetorimino,TETORIMINODATA *setTetoriminoData){
	Tetlis_initStage(view,model,tetorimino,setTetoriminoData);
	Tetlis_initBlock(view,model,tetorimino,setTetoriminoData);
	View_setView(view,model);
}

void Tetlis_initStage(VIEW *view,MODEL *model,TETRIMINO *tetorimino,TETORIMINODATA *setTetoriminoData){
	//ステージの初期化のみ
	View_init(view);
	Model_init(model);
	Tetrimino_init(tetorimino);
}
void Tetlis_initBlock(VIEW *view,MODEL *model,TETRIMINO *tetorimino,TETORIMINODATA *setTetoriminoData){
	//データのセット
	Tetrimino_setTetoriminoData(setTetoriminoData,tetorimino);
	Model_setBlockInModel(model,tetorimino,setTetoriminoData);//初期セット位置
}
void Tetlis_draw(VIEW *view,MODEL *model,TETRIMINO *tetorimino,TETORIMINODATA *setTetoriminoData){

	//system("cls");

	View_draw(view);
	//Model_draw(model);
	//Tetrimino_draw(setTetoriminoData,tetorimino);
}
void Tetlis_set(VIEW *view,MODEL *model,TETRIMINO *tetorimino,TETORIMINODATA *tetoriminoData){
	
	View_setView(view,model);
}


void Tetlis_deleteBlock	(VIEW *view,MODEL *model,TETRIMINO *tetorimino,TETORIMINODATA *tetoriminoData){	
	Model_deleteBlockInModel(model,tetorimino,tetoriminoData);
	View_setView(view,model);
}
int Tetlis_checkBlockInModel(VIEW *view,MODEL *model,TETRIMINO *tetorimino,TETORIMINODATA *tetoriminoData){	
	if(Model_checkBlockInModel(model,tetorimino,tetoriminoData,tetoriminoData->blockY+1,tetoriminoData->blockX)){
		Model_moveBlock(model,tetorimino,tetoriminoData);
		return 1;
	}else{
		Model_moveBlock(model,tetorimino,tetoriminoData);
		return 0;
	}	
}

void Tetlis_getKey(VIEW *view,MODEL *model,TETRIMINO *tetorimino,TETORIMINODATA *tetoriminoData){

	Tetlis_deleteBlock(view,model,tetorimino,tetoriminoData);
	//if(kbhit()){
		Model_getkey(model,tetorimino,tetoriminoData);
	//}
	Model_moveBlock(model,tetorimino,tetoriminoData);

	Tetlis_set(view,model,tetorimino,tetoriminoData);
}

void Tetlis_rotate(VIEW *view,MODEL *model,TETRIMINO *tetorimino,TETORIMINODATA *tetoriminoData){
	Model_rotate(model,tetorimino,tetoriminoData);
	Model_setBlockInModel(model,tetorimino,tetoriminoData);
}