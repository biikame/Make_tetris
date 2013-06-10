/****************
* Include guard *
****************/
#ifndef __MODEL_H__
#define __MODEL_H__
/**********
* Include *
**********/
#include "pch.h"
#include "tetrominoData.h"
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
* Struct *
********/
typedef struct MODEL{

	//enum{//とりあえずぶっこんでみた errorになるぞよ classならいいらしいけど構造体無理ゲー？
	//	enumhROW = 20,
	//	enumhCOL = 10,
	//};

	//static const int ROW = 20;	//参考:http://d.hatena.ne.jp/pknight/20090802/1249211249
	//static const int COL = 10;

	int data[enumhMROW][enumhMCOL];//内枠 20 10
	TETROMINODATA *tetrominoData;
}MODEL;

/*********************************
* Function prototype declaration *
*********************************/
//MODEL渡すのめんどいけど、構造体の練習。この場合はグローバルの方がよさげ。
MODEL *Model_create				(void);//struct_init
void Model_destroy				(MODEL *model);

int	 Model_getBlock				(MODEL *model,int y,int x);
void Model_setBlock				(MODEL *model,int y,int x,int variable);

void Model_draw					(MODEL *const model);
	
void Model_setBlockInModel		(MODEL *model);
void Model_deleteBlockInModel	(MODEL *model);

int Model_checkBlockInModel		(MODEL *model,int checkY,int checkX);
void Model_moveBlock			(MODEL *model);

void Model_getkey				(MODEL *model,int key);

void Model_rotate				(MODEL *model,int flag);
void Model_checkLine			(MODEL *model);
void Model_deleteLine			(MODEL *model,int deleteLine);
int Model_gameOver				(MODEL *model);

void Model_sound(int sound);

#endif __MODEL_H__//省略可能
