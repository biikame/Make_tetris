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
#define MAX(vo1,vo2)((vo1)>(vo2)? (vo1):(vo2))	//()は必ず書くと
#define MIN(vo1,vo2)((vo1)<(vo2)? (vo1):(vo2))	//()
/*********
* struct *
*********/
typedef struct  BLOCK{
	int data[enumhTETLIS_BLOCK][enumhTETLIS_BLOCK];
}BLOCK;
typedef struct TYPE{
	BLOCK data[enumhROLL];
}TYPE;
typedef struct TETROMINO{
	TYPE data[enumhTETORIMINO_NUM];
	int randTetris[2][enumhTETORIMINO_NUM];
	char str[1000];
}TETROMINO;
/*********************************
* Function prototype declaration *
*********************************/
TETROMINO *Tetromino_create(void);
void Tetromino_destroy(TETROMINO *tetromino);

void Tetromino_getRandamTetris(TETROMINO *tetromino);
void Tetromino_resetRandamTetris(TETROMINO *tetromino);
void Tetromino_setgetRandamTetris(TETROMINO *tetromino);

#endif __TETORIMINO__