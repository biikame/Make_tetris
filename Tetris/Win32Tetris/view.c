/**********
* Include *
**********/
#include "pch.h"
#include "../Tetris/view.h"
#include "../Tetris/model.h"
/**********************
* Function definition *
**********************/
void View_main(){
	VIEW view;
	View_init2(&view);
	//View_draw(&view);
}
void View_init(VIEW *view){
	VIEW initialize = {
		{//配列の区別
            {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,},
            {1,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,1,},
            {1,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,1,},
            {1,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,1,},
            {1,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,1,},
            {1,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,1,},
            {1,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,1,},
            {1,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,1,},
            {1,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,1,},
            {1,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,1,},
            {1,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,1,},
            {1,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,1,},
            {1,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,1,},
            {1,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,1,},
            {1,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,1,},
            {1,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,1,},
            {1,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,1,},
            {1,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,1,},
            {1,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,1,},
            {1,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,1,},
            {1,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,1,},
            {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,},
        }
   };
   *view = initialize;
}

void View_init2	(VIEW *view){
	int y,x;
	for(y=0;y<enumhVROW;y++){
		for(x=0;x<enumhVCOL;x++){
			if(	y==0			||
				y==enumhVROW-1	||
				x==0			||
				x==enumhVCOL-1
			)
				View_setBlock(view,y,x,1);
			else
				View_setBlock(view,y,x,0);
		}
	}
}

int View_getBlock	(VIEW *view,int y,int x){
	return view->data[y][x];
}
void View_setBlock	(VIEW *view,int y,int x,int variable){
	view->data[y][x] = variable;
}
void View_draw(VIEW *const view,HDC hdc,HWND hWnd){

	typedef struct{
		HPEN hPen,hOldPen;
		HBRUSH hBrush,hOldBrush;
	}PEN;
	int y,x;
	PEN red,pinkred,yellow,blue,white;
	RECT rt;

	//system("cls");

	GetClientRect(hWnd,&rt);//rtにウィンドウの座標を取得してる

	//グリット線
	pinkred.hPen	= CreatePen(PS_SOLID,1,RGB(255,0,255));
	pinkred.hOldPen = (HPEN)SelectObject(hdc,pinkred.hPen);
	pinkred.hBrush	= CreateHatchBrush(HS_CROSS,RGB(0,255,0)); 
	pinkred.hOldBrush = (HBRUSH)SelectObject(hdc,pinkred.hBrush);

	for(x=rt.left;x<=rt.right;x +=20){
		MoveToEx(hdc,x,rt.top,NULL);
		LineTo(hdc,x,rt.bottom);
		//printf("%d回目 x = %d\n",x/ROLL_W,x);
	}
	for(y=rt.top;y<=rt.bottom;y +=20){
		MoveToEx(hdc,rt.left,y,NULL);
		LineTo(hdc,rt.right,y);
		//printf("%d回目 y = %d\n",y/ROLL_H,y);
	}

	SelectObject(hdc,pinkred.hOldPen);
	SelectObject(hdc,pinkred.hOldBrush);
	DeleteObject(pinkred.hPen);
	DeleteObject(pinkred.hBrush);


	//printf("view\n");
	for(y=0;y<enumhVROW;y++){
		for(x=0;x<enumhVCOL;x++){
			switch( view->data[y][x]){//view->data[y][x]
				case 0:
					white.hPen	= CreatePen(PS_SOLID,1,RGB(0,0,0));
					white.hOldPen = (HPEN)SelectObject(hdc,white.hPen);
					white.hBrush	= CreateSolidBrush(RGB(0,0,0)); 
					white.hOldBrush = (HBRUSH)SelectObject(hdc,white.hBrush);

					Rectangle(hdc,x*20,y*20,x*20+20,y*20+20);//Rect angle角度

					SelectObject(hdc,white.hOldPen);
					SelectObject(hdc,white.hOldBrush);
					DeleteObject(white.hPen);
					DeleteObject(white.hBrush);
					break;
				case 1:case 2:
					red.hPen	= CreatePen(PS_SOLID,1,RGB(255,0,0));
					red.hOldPen = (HPEN)SelectObject(hdc,red.hPen);
					red.hBrush	= CreateSolidBrush(RGB(255,0,0)); 
					red.hOldBrush = (HBRUSH)SelectObject(hdc,red.hBrush);

					Rectangle(hdc,x*20,y*20,x*20+20,y*20+20);//Rect angle角度

					SelectObject(hdc,red.hOldPen);
					SelectObject(hdc,red.hOldBrush);
					DeleteObject(red.hPen);
					DeleteObject(red.hBrush);
					break;
				case 3:
					yellow.hPen	= CreatePen(PS_SOLID,1,RGB(255,255,0));
					yellow.hOldPen = (HPEN)SelectObject(hdc,yellow.hPen);
					yellow.hBrush	= CreateSolidBrush(RGB(255,255,0)); 
					yellow.hOldBrush = (HBRUSH)SelectObject(hdc,yellow.hBrush);

					Rectangle(hdc,x*20,y*20,x*20+20,y*20+20);//Rect angle角度

					SelectObject(hdc,yellow.hOldPen);
					SelectObject(hdc,yellow.hOldBrush);
					DeleteObject(yellow.hPen);
					DeleteObject(yellow.hBrush);
					break;
				case 4:
					blue.hPen	= CreatePen(PS_SOLID,1,RGB(0,0,255));
					blue.hOldPen = (HPEN)SelectObject(hdc,blue.hPen);
					blue.hBrush	= CreateSolidBrush(RGB(0,0,255)); 
					blue.hOldBrush = (HBRUSH)SelectObject(hdc,blue.hBrush);

					Rectangle(hdc,x*20,y*20,x*20+20,y*20+20);//Rect angle角度

					SelectObject(hdc,blue.hOldPen);
					SelectObject(hdc,blue.hOldBrush);
					DeleteObject(blue.hPen);
					DeleteObject(blue.hBrush);
					break;
			}
		}
		//printf("\n");
	}
}

void View_draw_sprintf(VIEW *view,TETRIMINO *tetrimino){

	int y,x;
	char *pstr = tetrimino->str;

	for(y=0;y<enumhVROW;y++){
		for(x=0;x<enumhVCOL;x++){
			switch( view->data[y][x] ){//view->data[y][x]
				case 0:
					sprintf(pstr,"　");
					pstr+=2;
					break;
				case 1:case 2:
					sprintf(pstr,"■");
					pstr+=2;
					break;
				case 3:
					sprintf(pstr,"◆");
					pstr+=2;
					break;
				case 4:
					sprintf(pstr,"Ｘ");
					pstr+=2;
					break;
			}
		}
		sprintf(pstr,"\n");
		pstr++;
	}
	puts(tetrimino->str);//全体の描画
}
void View_setView(VIEW *view,MODEL *model,TETRIMINO *tetrimino,TETORIMINODATA *setTetoriminoData){
	int y,x;
	for(y=0;y<enumhMROW;y++){
		for(x=0;x<enumhMCOL;x++){
			view->data[y+1][x+1] = model->data[y][x];
		}
	}
}
void View_setViewNextBlock(VIEW *view,MODEL *model,TETRIMINO *tetrimino,TETORIMINODATA *setTetoriminoData){

	int y,x;
	for(y=0;y<enumhTETLIS_BLOCK;y++){
		for(x=0;x<enumhTETLIS_BLOCK;x++){
			view->data[y+1][10+x+2] = tetrimino->data[tetrimino->randTetris[0][0]-1].data[0].data[y][x];
		}
	}
	for(y=0;y<enumhTETLIS_BLOCK;y++){
		for(x=0;x<enumhTETLIS_BLOCK;x++){
			view->data[y+5][10+x+2] = tetrimino->data[tetrimino->randTetris[0][1]-1].data[0].data[y][x];
		}
	}
}
void View_gameOVer_draw(VIEW *const view,MODEL *model,HDC hdc,HWND hWnd){

	static int y,x,flag;

	if(y>=enumhMROW){
		return;
	}

	for(y=flag++;y<flag && y < enumhMROW;y++){
		for(x=0;x<enumhMCOL;x++){
			view->data[y+1][x+1] = 1;
		}
	}
	Sleep(100);
	View_draw(view,hdc,hWnd);	

	View_gameOVer_draw(view,model,hdc,hWnd);
}

void View_gameOVer_draw2(VIEW *view,MODEL *model,HDC hdc,HWND hWnd){

	int y,x;
	for(y=0;y<enumhMROW;y++){
		for(x=0;x<enumhMCOL;x++){	
			switch(model->data[y][x]){
				case 0:break;
				default: view->data[y+1][x+1]= 3;break;
			}
		}
		Sleep(100);
		View_draw(view,hdc,hWnd);
		
	}
}

void View_gameOVer_draw3(VIEW *view,MODEL *model,HDC hdc,HWND hWnd){

	static int y,x,flag;

	if(y>=enumhMROW){
		return;
	}

	for(y=flag++;y<flag && y < enumhMROW;y++){
		for(x=0;x<enumhMCOL;x++){
			if(view->data[y+1][x+1]==0){
				view->data[y+1][x+1] = 4;
			} 
		}
	}
	Sleep(100);
	View_draw(view,hdc,hWnd);
	

	View_gameOVer_draw3(view,model,hdc,hWnd);
}

void View_gameOVer_mixDraw(VIEW *view,MODEL *model,HDC hdc,HWND hWnd){
	View_gameOVer_draw2(view,model,hdc,hWnd);
	View_gameOVer_draw3(view,model,hdc,hWnd);
	View_gameOVer_draw(view,model,hdc,hWnd);
}