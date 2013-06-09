/**********
* include *
**********/
#include "pch.h"
#include "../Tetris/tetlis.h"

#define TIMER_ID     (100)      // �쐬����^�C�}�̎���ID
#define TIMER_ELAPSE (300)     // WM_TIMER�̔����Ԋu

enum {
	ROLL_W = 50,
	ROLL_H = 50,
	WIDTH_MISS	= 18,
	HEIGHT_MISS	= 45, 
};
enum {
	//��ʂ̃}�b�N�X
	WINDOW_WIDTH_MAX = 1280,
	WINDOW_HEIGHT_MAX = 800,
	//�`��͈̔�
	WIDTH	= 500 +WIDTH_MISS +1,
	HEIGHT	= 500 +HEIGHT_MISS + 1,
	//���\�[�X�t�@�C���̌v�Z���@�Q��
	WINDOWX = (WINDOW_WIDTH_MAX-WIDTH)/2,
	WINDOWY = (WINDOW_HEIGHT_MAX-HEIGHT)/2,
	
};

//�e�g���X�ŕK�v�ȃf�[�^�̒u����
VIEW view;
MODEL model;
TETRIMINO tetorimino,nextBlock;
TETORIMINODATA tetoriminoData;
char *strFile;
MCIDEVICEID playID[2];

int timer;
int randflag;

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
char szClassNme[] = "�E�B���h�E�N���X�E�l�[��";

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPreInst,
                   LPSTR lpszCmdLine, int nCmdShow)
{
    HWND hWnd;
    MSG msg;
    WNDCLASS myProg;
 
    AllocConsole(); //�R���\�[���쐬
	  freopen("CONOUT$", "w", stdout); //�W���o�͂��R���\�[���ɂ���
      freopen("CONIN$", "r", stdin);   //�W�����͂��R���\�[���ɂ���
    if (!hPreInst) {
        myProg.style            =CS_HREDRAW | CS_VREDRAW;
        myProg.lpfnWndProc		=WndProc;
        myProg.cbClsExtra		=0;
        myProg.cbWndExtra       =0;
        myProg.hInstance        =hInstance;
        myProg.hIcon            =NULL;
        myProg.hCursor			=LoadCursor(NULL, IDC_ARROW);
        myProg.hbrBackground    =GetStockObject(WHITE_BRUSH);
        myProg.lpszMenuName		=NULL;
        myProg.lpszClassName    =szClassNme;
        if (!RegisterClass(&myProg))
            return FALSE;
    }
    hWnd = CreateWindow(szClassNme,
        "Win32�z�����X�I",
        WS_OVERLAPPED | WS_SYSMENU,
        WINDOWX,
        WINDOWY,
        WIDTH,
        HEIGHT,
        NULL,
        NULL,
        hInstance,
        NULL);
    ShowWindow(hWnd,nCmdShow);
    UpdateWindow(hWnd);

	// �^�C�}���쐬����
	SetTimer( hWnd, TIMER_ID, TIMER_ELAPSE, NULL );


    while (GetMessage(&msg, NULL, 0, 0)) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

	// �^�C�}��j������
	KillTimer( hWnd, TIMER_ID );

    return (msg.wParam);
}

LRESULT CALLBACK WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	HDC hdc;
	PAINTSTRUCT ps;

    switch (msg) {
		case WM_CREATE://�E�B���h�E�����ꂽ�Ƃ�
			if(!randflag){
				srand((unsigned int)time(NULL));
				randflag=1;
			}
			Tetlis_init(&view,&model,&tetorimino,&tetoriminoData);
			Tetlis_set(&view,&model,&tetorimino,&tetoriminoData);

			strFile = "../BGM/WaVKorobeyniki_polka.wav";

		break;
		case WM_TIMER:
			if( wParam != TIMER_ID )
			{
				break;  // ����ID����v���Ȃ��^�C�}���b�Z�[�W��DefWindowProc()�ɔC����
			}

			InvalidateRect( hWnd, NULL, TRUE );

			return 0;

		break;
		case WM_PAINT:
			hdc = BeginPaint(hWnd,&ps);

			Sleep(100);

			Tetlis_setNextRand(&tetorimino);

			Tetlis_draw(&view,&model,&tetorimino,&tetoriminoData,hdc,hWnd);

			if(Tetlis_gameOver(&view,&model,&tetorimino,&tetoriminoData)==0){
				Tetlis_drawgameOver(&view,&model,&tetorimino,&tetoriminoData,hdc,hWnd);
				DestroyWindow(hWnd);
			}

			Tetlis_deleteBlock(&view,&model,&tetorimino,&tetoriminoData);

			//�ꏡ��̃f�[�^���m�F�A�u���b�N������ΌŒ�
			if(Tetlis_checkBlockInModel(&view,&model,&tetorimino,&tetoriminoData)){
				Tetlis_set(&view,&model,&tetorimino,&tetoriminoData);
			}else{
				//�񂪑����Ă������������
				Tetlis_deleteLine(&view,&model,&tetorimino,&tetoriminoData);
				
				Tetlis_set(&view,&model,&tetorimino,&tetoriminoData);
				Tetlis_initBlock(&view,&model,&tetorimino,&tetoriminoData);
			}

			EndPaint(hWnd,&ps);
		break;
		case WM_KEYDOWN:
		
			 Tetlis_getKey(&view,&model,&tetorimino,&tetoriminoData,wParam);
			 InvalidateRect( hWnd, NULL, TRUE );
		break;
        case WM_DESTROY:
			
            PostQuitMessage(0);
        break;
        default:
            return(DefWindowProc(hWnd, msg, wParam, lParam));
    }
    return (0L);
}
