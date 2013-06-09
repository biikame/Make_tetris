/**********
* Include *
**********/
#include "pch.h"
#include "view.h"
#include "model.h"
#include "tetorimino.h"
#include "tetlis.h"
#include <Windows.h>
#include<Mmsystem.h>
#pragma comment(lib,"winmm")// winmm.lib をリンクする

/**********************
* Function definition *
**********************/
void Tetlis_main(){

	VIEW view;
	MODEL model;
	TETRIMINO tetorimino,nextBlock;
	TETORIMINODATA tetoriminoData;
	char *strFile;
	MCIDEVICEID playID[2];

	int timer;

	srand((unsigned int)time(NULL));

	Tetlis_init(&view,&model,&tetorimino,&tetoriminoData);
	Tetlis_set(&view,&model,&tetorimino,&tetoriminoData);
	strFile = "../BGM/WaVKorobeyniki_polka.wav";

	//playID[0]=playSound(strFile);

	while(1){

		/*for(timer=0;timer<=90000000;timer++){
			
		}*/
		Sleep(100);

		Tetlis_setNextRand(&tetorimino);

		Tetlis_draw(&view,&model,&tetorimino,&tetoriminoData);
		
		if(Tetlis_gameOver(&view,&model,&tetorimino,&tetoriminoData)==0)
			break;
		
		Tetlis_getKey(&view,&model,&tetorimino,&tetoriminoData);
	
		Tetlis_deleteBlock(&view,&model,&tetorimino,&tetoriminoData);
		//一升先のデータを確認、ブロックがあれば固定
		if(Tetlis_checkBlockInModel(&view,&model,&tetorimino,&tetoriminoData)){
			Tetlis_set(&view,&model,&tetorimino,&tetoriminoData);
		}else{
			//列が揃っていたら消す処理
			Tetlis_deleteLine(&view,&model,&tetorimino,&tetoriminoData);

			Tetlis_set(&view,&model,&tetorimino,&tetoriminoData);
			Tetlis_initBlock(&view,&model,&tetorimino,&tetoriminoData);
		}
	}
/////gameOver処理/////////////////////////////////////////////////////////////
	Tetlis_drawgameOver(&view,&model,&tetorimino,&tetoriminoData);
	//stopSound(playID[0]);
	//デバック用
	//Model_main();
	//View_main();
	//Tetrimino_main();
}

void Tetlis_init(VIEW *view,MODEL *model,TETRIMINO *tetorimino,TETORIMINODATA *setTetoriminoData){
	Tetlis_initStage(view,model,tetorimino,setTetoriminoData);
	Tetlis_initBlock(view,model,tetorimino,setTetoriminoData);
	View_setView(view,model,tetorimino,setTetoriminoData);
}

void Tetlis_initStage(VIEW *view,MODEL *model,TETRIMINO *tetorimino,TETORIMINODATA *setTetoriminoData){
	//ステージの初期化のみ
	View_init(view);
	Model_init(model);
	Tetrimino_init(tetorimino);
}
void Tetlis_initBlock(VIEW *view,MODEL *model,TETRIMINO *tetorimino,TETORIMINODATA *setTetoriminoData){
	//データのセット
	Tetrimino_setTetoriminoData(setTetoriminoData,tetorimino);
	Model_setBlockInModel(model,tetorimino,setTetoriminoData);//初期セット位置
}
void Tetlis_draw(VIEW *view,MODEL *model,TETRIMINO *tetorimino,TETORIMINODATA *setTetoriminoData){

	
	Tetlis_nextBlock(view,model,tetorimino,setTetoriminoData);
	View_draw(view);
	//View_draw_sprintf(view,tetorimino);
	//Model_draw(model);
	//Tetrimino_draw(setTetoriminoData,tetorimino);
}
void Tetlis_set(VIEW *view,MODEL *model,TETRIMINO *tetorimino,TETORIMINODATA *tetoriminoData){
	View_setView(view,model,tetorimino,tetoriminoData);
}
void Tetlis_deleteBlock	(VIEW *view,MODEL *model,TETRIMINO *tetorimino,TETORIMINODATA *tetoriminoData){	
	Model_deleteBlockInModel(model,tetorimino,tetoriminoData);
	View_setView(view,model,tetorimino,tetoriminoData);
}
int Tetlis_checkBlockInModel(VIEW *view,MODEL *model,TETRIMINO *tetorimino,TETORIMINODATA *tetoriminoData){	
	int ret = Model_checkBlockInModel(model,tetorimino,tetoriminoData,tetoriminoData->blockY+1,tetoriminoData->blockX);
	Model_moveBlock(model,tetorimino,tetoriminoData);
	return ret;
}
void Tetlis_getKey(VIEW *view,MODEL *model,TETRIMINO *tetorimino,TETORIMINODATA *tetoriminoData){

	Tetlis_deleteBlock(view,model,tetorimino,tetoriminoData);
	if(kbhit()){//毎回取得してくれる
		Model_getkey(model,tetorimino,tetoriminoData);
	}
	Model_moveBlock(model,tetorimino,tetoriminoData);

	Tetlis_set(view,model,tetorimino,tetoriminoData);
}

void Tetlis_deleteLine(VIEW *view,MODEL *model,TETRIMINO *tetorimino,TETORIMINODATA *tetoriminoData){
	Model_checkLine(model,tetorimino,tetoriminoData);
}
int Tetlis_gameOver(VIEW *view,MODEL *model,TETRIMINO *tetorimino,TETORIMINODATA *tetoriminoData){
	if(Model_gameOver(model,tetorimino,tetoriminoData)==0){
		return 0;
	}
}
void Tetlis_nextBlock(VIEW *view,MODEL *model,TETRIMINO *tetorimino,TETORIMINODATA *tetoriminoData){
	//Tetrimino_nextBlock(tetorimino);
	View_setViewNextBlock(view,model,tetorimino,tetoriminoData);
}

MCIDEVICEID playSound(char *strFile)
{
	static MCI_OPEN_PARMS mop;
	mop.dwCallback = (DWORD)NULL;
	mop.lpstrDeviceType = (LPCSTR)MCI_DEVTYPE_WAVEFORM_AUDIO;
	mop.lpstrElementName = strFile;
	mciSendCommand(0,MCI_OPEN,MCI_OPEN_TYPE|MCI_OPEN_TYPE_ID|MCI_OPEN_ELEMENT,(DWORD)&mop);
	mciSendCommand(mop.wDeviceID , MCI_PLAY , 0 , 0);
	return mop.wDeviceID;
}
void stopSound(MCIDEVICEID stopID)
{
	mciSendCommand(stopID , MCI_STOP , 0 , 0);
	return;
}

void Tetlis_drawgameOver(VIEW *view,MODEL *model,TETRIMINO *tetorimino,TETORIMINODATA *tetoriminoData){
	View_gameOVer_mixDraw(view,model);

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

void Tetlis_setNextRand(TETRIMINO *tetorimino){
	Tetrimino_setgetRandamTetris(tetorimino);
}
