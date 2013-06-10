/*****************************************
* Tetlis                                 *
*                                        *
*                                        *
*                      2013/05/17 16:58  *
*****************************************/

/**********
* Include *
**********/
#include "pch.h"//プリコンパイル済みヘッダー
#include "../Tetris/tetris.h"
#include "view.h"

/*******
* Main *
*******/

int main(void){

	TETRIS *tetris;
	VIEW *view;
	char *strFile;
	MCIDEVICEID playID[2];

	int timer;

	tetris = Tetris_create();
	view = View_create(tetris);

	//playID[0]=playSound(strFile);

	while(1){

		/*for(timer=0;timer<=90000000;timer++){
			
		}*/
		Sleep(100);
		
		if(kbhit()){
			Tetris_getKey(tetris,getch());
		}

		Tetris_timer(tetris);
		if(View_paint(view)){
			break;
		}
	}
	//stopSound(playID[0]);
	//デバック用
	//Model_main();
	//View_main();
	//Tetromino_main();

	return 0;
}
