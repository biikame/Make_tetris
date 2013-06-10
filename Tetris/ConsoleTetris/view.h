/****************
* Include guard *
****************/
#ifndef __VIEW_H__
#define __VIEW_H__
/**********
* Include *
**********/
#include "pch.h"
#include "../Tetris/tetris.h"
/*******
* Enum *
*******/
enum {
        enumhVROW =22,
        enumhVCOL =12+10,
};
/***********
* Variable *
***********/

/********
* Struct *
********/
typedef struct VIEW{
	int data[enumhVROW][enumhVCOL];
	TETRIS *tetris;
}VIEW;
/*********************************
* Function prototype declaration *
*********************************/
VIEW *View_create	(TETRIS *tetris);
void View_destroy	(VIEW *view);

int	 View_getBlock	(VIEW *view,int y,int x);
void View_setBlock	(VIEW *view,int y,int x,int variable);

int View_paint		(VIEW *view);
void View_draw		(VIEW *view);
void View_setView	(VIEW *view);
void View_setViewNextBlock(VIEW *view);

//sprintf用
void View_draw_sprintf(VIEW *view);

void View_drawGameOver(VIEW *view);
void View_gameOver_mixDraw(VIEW *view);
//gameOver処理の部品
void View_gameOver_draw (VIEW *view);
void View_gameOver_draw2(VIEW *view);
void View_gameOver_draw3(VIEW *view);
#endif __VIEW_H__