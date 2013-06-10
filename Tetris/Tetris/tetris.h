/****************
* Include guard *
****************/
#ifndef __TETLIS_H__
#define __TETLIS_H__
/**********
* Include *
**********/
#include "pch.h"
#include "model.h"
/*******
* Enum *
*******/
/***********
* Variable *
***********/
/********
* Struct *
********/
typedef struct TETRIS{
	MODEL *model;
	int isGameOver;
	char *strFile;
}TETRIS;
/*********************************
* Function prototype declaration *
*********************************/
TETRIS *Tetris_create			(void);
void Tetris_init				(TETRIS *tetris);
void Tetris_initStage			(TETRIS *tetris);
void Tetris_initBlock			(TETRIS *tetris);
void Tetris_destroy				(TETRIS *tetris);
void Tetris_timer				(TETRIS *tetris);
void Tetris_draw				(TETRIS *tetris);

void Tetris_set					(TETRIS *tetris);
void Tetris_deleteBlock			(TETRIS *tetris);
int Tetris_checkBlockInModel	(TETRIS *tetris);
void Tetris_getKey				(TETRIS *tetris,int key);

void Tetris_deleteLine			(TETRIS *tetris);
int Tetris_gameOver				(TETRIS *tetris);
void Tetris_nextBlock			(TETRIS *tetris);

void Tetris_setNextRand			(TETRIS *tetris);
MCIDEVICEID playSound			(char *strFile);
void stopSound					(MCIDEVICEID stopID);

void Tetris_drawgameOver		(TETRIS *tetris);

#endif __TETLIS_H__