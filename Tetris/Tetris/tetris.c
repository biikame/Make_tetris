/**********
* Include *
**********/
#include "pch.h"
#include "model.h"
#include "tetrominoData.h"
#include "tetris.h"
/**********************
* Function definition *
**********************/
TETRIS *Tetris_create(void){
	TETRIS *tetris;
	tetris = (TETRIS *)(malloc(sizeof(*tetris)));
	srand((unsigned int)time(NULL));
	Tetris_init(tetris);
	Tetris_set(tetris);

	tetris->isGameOver = 0;
	tetris->strFile = "../BGM/WaVKorobeyniki_polka.wav";
}
void Tetris_init(TETRIS *tetris){
	Tetris_initStage(tetris);
	Tetris_initBlock(tetris);
}
void Tetris_initStage(TETRIS *tetris){
	//ステージの初期化のみ
	tetris->model = Model_create();
}
void Tetris_initBlock(TETRIS *tetris){
	//データのセット
	TetrominoData_set(tetris->model->tetrominoData);
	Model_setBlockInModel(tetris->model);//初期セット位置
}
void Tetris_destroy(TETRIS *tetris){
	Model_destroy(tetris->model);
	free(tetris);
}
void Tetris_timer(TETRIS *tetris){
	Tetris_setNextRand(tetris);

	Tetris_draw(tetris);

	if(Tetris_gameOver(tetris)==0){
		tetris->isGameOver = 1;
		return;
	}

	Tetris_deleteBlock(tetris);

	//一升先のデータを確認、ブロックがあれば固定
	if(Tetris_checkBlockInModel(tetris)){
		Tetris_set(tetris);
	}else{
		//列が揃っていたら消す処理
		Tetris_deleteLine(tetris);
				
		Tetris_set(tetris);
		Tetris_initBlock(tetris);
	}
}
void Tetris_draw(TETRIS *tetris){

	
	Tetris_nextBlock(tetris);
	//View_draw_sprintf(view,tetromino);
	//Model_draw(model);
	//Tetromino_draw(tetrominoData,tetromino);
}
void Tetris_set(TETRIS *tetris){
}
void Tetris_deleteBlock	(TETRIS *tetris){	
	Model_deleteBlockInModel(tetris->model);
}
int Tetris_checkBlockInModel(TETRIS *tetris){	
	int ret = Model_checkBlockInModel(tetris->model,tetris->model->tetrominoData->blockY+1,tetris->model->tetrominoData->blockX);
	Model_moveBlock(tetris->model);
	return ret;
}
void Tetris_getKey(TETRIS *tetris,int key){

	Tetris_deleteBlock(tetris);
	//if(kbhit()){//毎回取得してくれる
	Model_getkey(tetris->model,key);
	//}
	Model_moveBlock(tetris->model);

	Tetris_set(tetris);
}

void Tetris_deleteLine(TETRIS *tetris){
	Model_checkLine(tetris->model);
}
int Tetris_gameOver(TETRIS *tetris){
	if(Model_gameOver(tetris->model)==0){
		return 0;
	}
}
void Tetris_nextBlock(TETRIS *tetris){
	//Tetromino_nextBlock(tetromino);
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

void Tetris_setNextRand(TETRIS *tetris){
	Tetromino_setgetRandamTetris(tetris->model->tetrominoData->tetromino);
}
