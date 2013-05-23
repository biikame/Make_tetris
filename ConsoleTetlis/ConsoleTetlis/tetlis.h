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
void Tetlis_draw				(VIEW *view,MODEL *model,TETRIMINO *tetorimino,TETORIMINODATA *setTetoriminoData);

void Tetlis_set					(VIEW *view,MODEL *model,TETRIMINO *tetorimino,TETORIMINODATA *tetoriminoData);
void Tetlis_deleteBlock			(VIEW *view,MODEL *model,TETRIMINO *tetorimino,TETORIMINODATA *tetoriminoData);
int Tetlis_checkBlockInModel	(VIEW *view,MODEL *model,TETRIMINO *tetorimino,TETORIMINODATA *tetoriminoData);
void Tetlis_getKey				(VIEW *view,MODEL *model,TETRIMINO *tetorimino,TETORIMINODATA *tetoriminoData);

void Tetlis_rotate				(VIEW *view,MODEL *model,TETRIMINO *tetorimino,TETORIMINODATA *tetoriminoData);
void Tetlis_deleteLine			(VIEW *view,MODEL *model,TETRIMINO *tetorimino,TETORIMINODATA *tetoriminoData);
int Tetlis_gameOver			(VIEW *view,MODEL *model,TETRIMINO *tetorimino,TETORIMINODATA *tetoriminoData);

#endif __TETLIS_H__