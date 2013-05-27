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
            {1,1,1,1,1,1,1,1,1,1,1,1,},
            {1,0,0,0,0,0,0,0,0,0,0,1,},
            {1,0,0,0,0,0,0,0,0,0,0,1,},
            {1,0,0,0,0,0,0,0,0,0,0,1,},
            {1,0,0,0,0,0,0,0,0,0,0,1,},
            {1,0,0,0,0,0,0,0,0,0,0,1,},
            {1,0,0,0,0,0,0,0,0,0,0,1,},
            {1,0,0,0,0,0,0,0,0,0,0,1,},
            {1,0,0,0,0,0,0,0,0,0,0,1,},
            {1,0,0,0,0,0,0,0,0,0,0,1,},
            {1,0,0,0,0,0,0,0,0,0,0,1,},
            {1,0,0,0,0,0,0,0,0,0,0,1,},
            {1,0,0,0,0,0,0,0,0,0,0,1,},
            {1,0,0,0,0,0,0,0,0,0,0,1,},
            {1,0,0,0,0,0,0,0,0,0,0,1,},
            {1,0,0,0,0,0,0,0,0,0,0,1,},
            {1,0,0,0,0,0,0,0,0,0,0,1,},
            {1,0,0,0,0,0,0,0,0,0,0,1,},
            {1,0,0,0,0,0,0,0,0,0,0,1,},
            {1,0,0,0,0,0,0,0,0,0,0,1,},
            {1,0,0,0,0,0,0,0,0,0,0,1,},
            {1,1,1,1,1,1,1,1,1,1,1,1,},
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
	printf("view\n");
	for(y=0;y<enumhVROW;y++){
		for(x=0;x<enumhVCOL;x++){
			switch( view->data[y][x] ){//view->data[y][x]
				case 0:
					printf("　");
					break;
				case 1:case 2:
					printf("■");
					break;
			}
		}
		printf("\n");
	}
}
void View_setView(VIEW *view,MODEL *model){
	int y,x;
	for(y=0;y<enumhMROW;y++){
		for(x=0;x<enumhMCOL;x++){
			view->data[y+1][x+1] = model->data[y][x];
		}
	}
}


