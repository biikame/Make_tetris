/****************
* Include guard *
****************/
#ifndef __TETLIS_H__
#define __TETLIS_H__
/**********
* Include *
**********/
#include "pch.h"
#include "view.h"
#include "model.h"
#include "tetorimino.h"
#include <Windows.h>
#include<Mmsystem.h>
#pragma comment(lib,"winmm")// winmm.lib をリンクする
/*******
* Enum *
*******/
/***********
* Variable *
***********/
/********
* Strct *
********/
/*********************************
* Function prototype declaration *
*********************************/
void Tetlis_main();
void Tetlis_init				(VIEW *view,MODEL *model,TETRIMINO *tetorimino,TETORIMINODATA *setTetoriminoData);
void Tetlis_initStage			(VIEW *view,MODEL *model,TETRIMINO *tetorimino,TETORIMINODATA *setTetoriminoData);
void Tetlis_initBlock			(VIEW *view,MODEL *model,TETRIMINO *tetorimino,TETORIMINODATA *setTetoriminoData);
void Tetlis_draw				(VIEW *view,MODEL *model,TETRIMINO *tetorimino,TETORIMINODATA *setTetoriminoData,HDC hdc,HWND hWnd);

void Tetlis_set					(VIEW *view,MODEL *model,TETRIMINO *tetorimino,TETORIMINODATA *tetoriminoData);
void Tetlis_deleteBlock			(VIEW *view,MODEL *model,TETRIMINO *tetorimino,TETORIMINODATA *tetoriminoData);
int Tetlis_checkBlockInModel	(VIEW *view,MODEL *model,TETRIMINO *tetorimino,TETORIMINODATA *tetoriminoData);
void Tetlis_getKey				(VIEW *view,MODEL *model,TETRIMINO *tetorimino,TETORIMINODATA *tetoriminoData,WPARAM key);

void Tetlis_deleteLine			(VIEW *view,MODEL *model,TETRIMINO *tetorimino,TETORIMINODATA *tetoriminoData);
int Tetlis_gameOver				(VIEW *view,MODEL *model,TETRIMINO *tetorimino,TETORIMINODATA *tetoriminoData);
void Tetlis_nextBlock			(VIEW *view,MODEL *model,TETRIMINO *tetorimino,TETORIMINODATA *tetoriminoData);

void Tetlis_setNextRand			(TETRIMINO *tetorimino);
MCIDEVICEID playSound			(char *strFile);
void stopSound					(MCIDEVICEID stopID);

void Tetlis_drawgameOver		(VIEW *view,MODEL *model,TETRIMINO *tetorimino,TETORIMINODATA *tetoriminoData,HDC hdc,HWND hWnd);

#endif __TETLIS_H__