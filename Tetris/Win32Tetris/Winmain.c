/**********
* include *
**********/
#include "pch.h"
#include "../Tetris/tetris.h"
#include "view.h"

#define TIMER_ID     (100)      // 作成するタイマの識別ID
#define TIMER_ELAPSE (300)     // WM_TIMERの発生間隔

enum {
	ROLL_W = 50,
	ROLL_H = 50,
	WIDTH_MISS	= 18,
	HEIGHT_MISS	= 45, 
};
enum {
	//画面のマックス
	WINDOW_WIDTH_MAX = 1280,
	WINDOW_HEIGHT_MAX = 800,
	//描画の範囲
	WIDTH	= 500 +WIDTH_MISS +1,
	HEIGHT	= 500 +HEIGHT_MISS + 1,
	//リソースファイルの計算方法参照
	WINDOWX = (WINDOW_WIDTH_MAX-WIDTH)/2,
	WINDOWY = (WINDOW_HEIGHT_MAX-HEIGHT)/2,
	
};

//テトリスで必要なデータの置き場
static TETRIS *tetris;
static VIEW *view;
static MCIDEVICEID playID[2];

static int timer;

static LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
static char szClassNme[] = "ウィンドウクラス・ネーム";

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPreInst,
                   LPSTR lpszCmdLine, int nCmdShow)
{
    HWND hWnd;
    MSG msg;
    WNDCLASS myProg;
 
    AllocConsole(); //コンソール作成
	  freopen("CONOUT$", "w", stdout); //標準出力をコンソールにする
      freopen("CONIN$", "r", stdin);   //標準入力をコンソールにする
    if (!hPreInst) {
        myProg.style            =CS_HREDRAW | CS_VREDRAW;
        myProg.lpfnWndProc		=WndProc;
        myProg.cbClsExtra		=0;
        myProg.cbWndExtra       =0;
        myProg.hInstance        =hInstance;
        myProg.hIcon            =NULL;
        myProg.hCursor			=LoadCursor(NULL, IDC_ARROW);
        myProg.hbrBackground    =GetStockObject(NULL_BRUSH);
        myProg.lpszMenuName		=NULL;
        myProg.lpszClassName    =szClassNme;
        if (!RegisterClass(&myProg))
            return FALSE;
    }
    hWnd = CreateWindow(szClassNme,
        "Win32ホモリス！",
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

	// タイマを作成する
	SetTimer( hWnd, TIMER_ID, TIMER_ELAPSE, NULL );


    while (GetMessage(&msg, NULL, 0, 0)) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

	// タイマを破棄する
	KillTimer( hWnd, TIMER_ID );

    return (msg.wParam);
}

LRESULT CALLBACK WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	HDC hdc;
	PAINTSTRUCT ps;

    switch (msg) {
		case WM_CREATE://ウィンドウが作られたとき
			tetris = Tetris_create();
			view = View_create(tetris,hWnd);

		break;
		case WM_TIMER:
			if( wParam != TIMER_ID )
			{
				break;  // 識別IDが一致しないタイマメッセージはDefWindowProc()に任せる
			}

			Tetris_timer(tetris);
			InvalidateRect( hWnd, NULL, TRUE );

			return 0;

		break;
		case WM_PAINT:
			hdc = BeginPaint(hWnd,&ps);

			View_paint(view,hdc,hWnd);

			EndPaint(hWnd,&ps);
		break;
		case WM_KEYDOWN:
			Tetris_getKey(tetris,tolower(wParam));
			InvalidateRect( hWnd, NULL, TRUE );
		break;
        case WM_DESTROY:
			View_destroy(view);
			Tetris_destroy(tetris);
            PostQuitMessage(0);
        break;
        default:
            return(DefWindowProc(hWnd, msg, wParam, lParam));
    }
    return (0L);
}
