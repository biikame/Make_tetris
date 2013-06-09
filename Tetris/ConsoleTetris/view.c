/**********
* Include *
**********/
#include "pch.h"
#include "view.h"
#include "model.h"
/**********************
* Function definition *
**********************/
void View_main(){
	VIEW view;
	View_init2(&view);
	View_draw(&view);
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
void View_gameOVer_draw(VIEW *const view,MODEL *model){

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
	

	View_gameOVer_draw(view,model);
}

void View_gameOVer_draw2(VIEW *view,MODEL *model){

	int y,x;
	for(y=0;y<enumhMROW;y++){
		for(x=0;x<enumhMCOL;x++){	
			switch(model->data[y][x]){
				case 0:break;
				default: view->data[y+1][x+1]= 3;break;
			}
		}
		Sleep(100);
		View_draw(view);
		
	}
}

void View_gameOVer_draw3(VIEW *view,MODEL *model){

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
	

	View_gameOVer_draw3(view,model);
}

void View_gameOVer_mixDraw(VIEW *view,MODEL *model){
	View_gameOVer_draw2(view,model);
	View_gameOVer_draw3(view,model);
	View_gameOVer_draw(view,model);
}