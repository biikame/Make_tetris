/****************
* Include guard *
****************/
#ifndef __TETORIMINO_DATA__
#define __TETORIMINO_DATA__
/**********
* Include *
**********/
#include "pch.h"
#include "tetromino.h"
/*********
* struct *
*********/
typedef struct TETROMINODATA{
	int x,y,roll,z;//�S�����z��p
	int gapBlockX,gapBlockY;//�u���b�N�Ƃ̌덷
	int blockX,blockY;//���݂̃u���b�N�̈ʒu
	TETROMINO *tetromino;
}TETROMINODATA;
/*********************************
* Function prototype declaration *
*********************************/
TETROMINODATA *TetrominoData_create(void);
void TetrominoData_destroy(TETROMINODATA *tetrominoData);

void TetrominoData_set(TETROMINODATA *tetrominoData);
void TetrominoData_update(TETROMINODATA *tetrominoData);

void TetrominoData_draw(TETROMINODATA *tetrominoData);

void TetrominoData_draw_sprintf(TETROMINODATA *tetrominoData);

#endif