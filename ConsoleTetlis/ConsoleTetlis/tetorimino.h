/****************
* Include guard *
****************/
#ifndef __TETORIMINO__
#define __TETORIMINO__
/**********
* Include *
**********/
#include "pch.h"
/*******
* Enum *
*******/
enum{
	enumhTETORIMINO_NUM	= 7,		//ブロックの個数
	enumhROLL			= 4,		//回転数
	enumhARRAY2D 		= 25,		//ブロックデータの中身

	enumhTETLIS_BLOCK	= 5,		//5x5のブロックの一辺 
};
/***********
* Variable *
***********/
/*****************
* Macro function *
*****************/
#define MAX(vo1,vo2)(vo1>vo2? vo1:vo2)	//()は必ず書くと
#define MIN(vo1,vo2)(vo1<vo2? vo1:vo2)	//()
/*********
* struct *
*********/
typedef struct  BLOCK{
	int data[enumhTETLIS_BLOCK][enumhTETLIS_BLOCK];
}BLOCK;
typedef struct TYPE{
	BLOCK data[enumhROLL];
}TYPE;
typedef struct TETRIMINO{
	TYPE data[enumhTETORIMINO_NUM];
	int randTetris[2][enumhTETORIMINO_NUM+1];
	char str[1000];
}TETRIMINO;
typedef struct TETORIMINODATA{
	int x,y,roll,z;//４次元配列用
	int gapBlockX,gapBlockY;//ブロックとの誤差
	int blockX,blockY;//現在のブロックの位置
}TETORIMINODATA;
/*********************************
* Function prototype declaration *
*********************************/
void Tetrimino_main();
void Tetrimino_init(TETRIMINO *tetorimino);
void Tetrimino_init2(TETRIMINO *tetorimino);

void Tetrimino_draw(TETORIMINODATA *setTetoriminoData,const TETRIMINO *tetorimino);

void Tetrimino_draw_sprintf(TETORIMINODATA *setTetoriminoData, TETRIMINO *tetorimino);

void Tetrimino_getRandamTetris(TETRIMINO *tetorimino);
void Tetrimino_resetRandamTetris(TETRIMINO *tetorimino);
void Tetrimino_setgetRandamTetris(TETRIMINO *tetorimino);

void Tetrimino_setTetoriminoData(TETORIMINODATA *setTetoriminoData,TETRIMINO *tetorimino);
void Tetrimino_updateTetoriminoData(TETORIMINODATA *setTetoriminoData,TETRIMINO *tetorimino);

void Tetrimino_setBlock(TETRIMINO *tetorimino);

void Tetrimino_nextBlock(TETRIMINO *tetorimino);
void Tetrimino_seeNextBlock(TETRIMINO *tetorimino);

#endif __TETORIMINO__