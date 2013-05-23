/****************
* Include guard *
****************/
#ifndef __MODEL_H__
#define __MODEL_H__
/**********
* Include *
**********/
#include "pch.h"
#include "tetorimino.h"
/*******
* Enum *
*******/
enum{//enumh = enumhackData用 通常はenum識別子にします
	enumhMROW = 20,
	enumhMCOL = 10,
};
/***********
* Variable *
***********/
/********
* Strct *
********/
typedef struct MODEL{

	//enum{//とりあえずぶっこんでみた errorになるぞよ classならいいらしいけど構造体無理ゲー？
	//	enumhROW = 20,
	//	enumhCOL = 10,
	//};

	//static const int ROW = 20;	//参考:http://d.hatena.ne.jp/pknight/20090802/1249211249
	//static const int COL = 10;

	int data[enumhMROW][enumhMCOL];//内枠 20 10
}MODEL;

/*********************************
* Function prototype declaration *
*********************************/
//MODEL渡すのめんどいけど、構造体の練習。この場合はグローバルの方がよさげ。
void Model_main					();
void Model_init					(MODEL *model);//struct_init
void Model_init2				(MODEL *model);//Assignment　代入

int	 Model_getBlock				(MODEL *model,int y,int x);
void Model_setBlock				(MODEL *model,int y,int x,int variable);

void Model_draw					(MODEL *const model);
	
void Model_setBlockInModel		(MODEL *model,TETRIMINO *tetorimino,TETORIMINODATA *tetoriminoData);
void Model_deleteBlockInModel	(MODEL *model,TETRIMINO *tetorimino,TETORIMINODATA *tetoriminoData);

int Model_checkBlockInModel		(MODEL *model,TETRIMINO *tetorimino,TETORIMINODATA *tetoriminoData,int checkY,int checkX);
void Model_moveBlock			(MODEL *model,TETRIMINO *tetorimino,TETORIMINODATA *tetoriminoData);

void Model_getkey				(MODEL *model,TETRIMINO *tetorimino,TETORIMINODATA *tetoriminoData);

void Model_rotate				(MODEL *model,TETRIMINO *tetorimino,TETORIMINODATA *tetoriminoData);
void Model_checkLine			(MODEL *model,TETRIMINO *tetorimino,TETORIMINODATA *tetoriminoData);
void Model_deleteLine			(MODEL *model,TETRIMINO *tetorimino,TETORIMINODATA *tetoriminoData,int deleteLine);
int Model_gameOver				(MODEL *model,TETRIMINO *tetorimino,TETORIMINODATA *tetoriminoData);


#endif __MODEL_H__//省略可能
