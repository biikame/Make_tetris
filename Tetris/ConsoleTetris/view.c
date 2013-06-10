/**********
* Include *
**********/
#include "pch.h"
#include "view.h"
#include "../Tetris/tetris.h"
/**********************
* Function definition *
**********************/
VIEW *View_create(TETRIS* tetris){
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
	VIEW *view;
	view = (VIEW *)(malloc(sizeof(*view)));
	*view = initialize;
	view->tetris = tetris;
	return view;
}
void View_destroy(VIEW *view){
	free(view);
}

int View_getBlock	(VIEW *view,int y,int x){
	return view->data[y][x];
}
void View_setBlock	(VIEW *view,int y,int x,int variable){
	view->data[y][x] = variable;
}
int View_paint(VIEW *view){
	View_setView(view);
	View_setViewNextBlock(view);
	if(!(view->tetris->isGameOver)){
		View_draw(view);
		return 0;
	}
	else{
		View_drawGameOver(view);
		return 1;
	}
}
void View_draw(VIEW *const view){
	int y,x;

	system("cls");

	//printf("view\n");
	for(y=0;y<enumhVROW;y++){
		for(x=0;x<enumhVCOL;x++){
			switch( view->data[y][x] ){//view->data[y][x]
				case 0:
					printf("　");
					break;
				case 1:case 2:
					printf("■");
					break;
				case 3:
					printf("◆");
					break;
				case 4:
					printf("Ｘ");
					break;
			}
		}
		printf("\n");
	}
}

void View_draw_sprintf(VIEW *view){

	int y,x;
	char *pstr = view->tetris->model->tetrominoData->tetromino->str;

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
	puts(view->tetris->model->tetrominoData->tetromino->str);//全体の描画
}
void View_setView(VIEW *view){
	int y,x;
	for(y=0;y<enumhMROW;y++){
		for(x=0;x<enumhMCOL;x++){
			view->data[y+1][x+1] = view->tetris->model->data[y][x];
		}
	}
}
void View_setViewNextBlock(VIEW *view){

	int y,x;
	for(y=0;y<enumhTETLIS_BLOCK;y++){
		for(x=0;x<enumhTETLIS_BLOCK;x++){
			view->data[y+1][10+x+2] = view->tetris->model->tetrominoData->tetromino->data[view->tetris->model->tetrominoData->tetromino->randTetris[0][0]-1].data[0].data[y][x];
		}
	}
	for(y=0;y<enumhTETLIS_BLOCK;y++){
		for(x=0;x<enumhTETLIS_BLOCK;x++){
			view->data[y+5][10+x+2] = view->tetris->model->tetrominoData->tetromino->data[view->tetris->model->tetrominoData->tetromino->randTetris[0][1]-1].data[0].data[y][x];
		}
	}
}

void View_drawGameOver(VIEW *view){
	View_gameOver_mixDraw(view);

	system("cls");

	printf("\n\
 　 　┏━━━━┓　 　 ┏━━┓　 　 ┏━┓　 　 ┏━┓┏━━━━━━┓ \n\
 　 ┏┛┏━━━┛　 ┏┛┏┓┗┓　 ┃　 ┗┓┏┛　 ┃┃　 ┏━━━━┛ \n\
 ┏┛┏┛　 　 　 　 ┏┛┏┛┗┓┗┓┃　 　 ┗┛　 　 ┃┃　 ┃ \n\
 ┃　 ┃┏━━━┓┃　 ┃　 　 ┃　 ┃┃　 　 　 　 　 　 ┃┃　 ┗━━━┓ \n\
 ┃　 ┃┗━┓　 ┃┃　 ┗━━┛　 ┃┃　 ┏┓┏┓　 ┃┃　 ┏━━━┛ \n\
 ┗┓┗┓　 ┃　 ┃┃　 ┏━━┓　 ┃┃　 ┃┗┛┃　 ┃┃　 ┃ \n\
 　 ┃　 ┗━┛　 ┃┃　 ┃　 　 ┃　 ┃┃　 ┃　 　 ┃　 ┃┃　 ┗━━━━┓ \n\
 　 ┗━━━━━┛┗━┛　 　 ┗━┛┗━┛　 　 ┗━┛┗━━━━━━┛ \n\
 　 ┏━━━━┓　 ┏━┓　 　 ┏━┓┏━━━━━━┓┏━━━━━┓ \n\
 ┏┛┏━━┓┗┓┃　 ┃　 　 ┃　 ┃┃　 ┏━━━━┛┃　 ┏━━┓┗┓ \n\
 ┃　 ┃　 　 ┃　 ┃┃　 ┃　 　 ┃　 ┃┃　 ┃　 　 　 　 　 ┃　 ┃　 　 ┃　 ┃ \n\
 ┃　 ┃　 　 ┃　 ┃┃　 ┗┓┏┛　 ┃┃　 ┗━━━┓　 ┃　 ┃　 ┏┛　 ┃ \n\
 ┃　 ┃　 　 ┃　 ┃┗┓　 ┗┛　 ┏┛┃　 ┏━━━┛　 ┃　 ┗━┛┏━┛ \n\
 ┃　 ┃　 　 ┃　 ┃　 ┗┓　 　 ┏┛　 ┃　 ┃　 　 　 　 　 ┃　 ┏┓　 ┗┓ \n\
 ┗┓┗━━┛┏┛　 　 ┗┓┏┛　 　 ┃　 ┗━━━━┓┃　 ┃┗┓　 ┗┓ \n\
 　 ┗━━━━┛　 　 　 　 ┗┛　 　 　 ┗━━━━━━┛┗━┛　 ┗━━┛ \n");

	printf("\n");
}
void View_gameOver_draw(VIEW *const view){

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
	View_draw(view);
	

	View_gameOver_draw(view);
}

void View_gameOver_draw2(VIEW *view){

	int y,x;
	for(y=0;y<enumhMROW;y++){
		for(x=0;x<enumhMCOL;x++){	
			switch(view->tetris->model->data[y][x]){
				case 0:break;
				default: view->data[y+1][x+1]= 3;break;
			}
		}
		Sleep(100);
		View_draw(view);
		
	}
}

void View_gameOver_draw3(VIEW *view){

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
	View_draw(view);
	

	View_gameOver_draw3(view);
}

void View_gameOver_mixDraw(VIEW *view){
	View_gameOver_draw2(view);
	View_gameOver_draw3(view);
	View_gameOver_draw(view);
}