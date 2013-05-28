/****************
* Include guard *
****************/
#ifndef __VIEW_H__
#define __VIEW_H__
/**********
* Include *
**********/
#include "pch.h"
#include "model.h"
#include "tetorimino.h"
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
* Strct *
********/
typedef struct VIEW{
	int data[enumhVROW][enumhVCOL];
}VIEW;
/*********************************
* Function prototype declaration *
*********************************/
void View_main		();
void View_init		(VIEW *view);//struct_init
void View_init2		(VIEW *view);//Assignment　代入

int	 View_getBlock	(VIEW *view,int y,int x);
void View_setBlock	(VIEW *view,int y,int x,int variable);

void View_draw		(const VIEW *view);
void View_setView	(VIEW *view,MODEL *model);

void View_gameOVer_mixDraw(VIEW *view,MODEL *model);
//gameOver処理の部品
void View_gameOVer_draw (VIEW *view,MODEL *model);
void View_gameOVer_draw2(VIEW *view,MODEL *model);
void View_gameOVer_draw3(VIEW *view,MODEL *model);
#endif __VIEW_H__