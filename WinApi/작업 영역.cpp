// 작업 영역

// 윈도우는 작업 영역과 비작업 영역 두 부분으로 구성되어 있다.
// 작업 영역이란 쉽게 말해서 윈도우 중앙의 휜 부분을 말하며 
// 비작업 영역이란 그 외의 영역을 말한다.

// 작업/비작업 영역의 구분은 윈도우를 이해하는데 중요한 비중을 차지하는데
// 그 이유는 프로그래머에게 프로그래밍의 대상이 되는것은 작업 영역뿐이기 때문이다.

// 원하는 위치에 정확하게 출력을 하기 위해서는 윈도우가 차지하고 있는
// 영역의 좌표를 조사해야 하는 것이 아니라 작업 영역의 좌표를 조사해야 한다.

BOOL GetClinetRect(HWND, LPRECT ipRect);

// 이름 그대로 client가 차지하고 있는 Rect를 Get하는 함수이다.
// 첫번째 인수로 대상 윈도우 핸들을 주고 두번째 인수로 리턴 값을
// 돌려받기 위한 Rect 구조체의 포인터를 넘겨주면 된다.
// 이 함수 호출 후에 Rect 구조체에는 작업 영역의 좌표가 들어가있는데
// left, top은 항상 0이며 right, bottomo에 우하단의 좌표가 대입된다.

#include <Windows.h>

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
HINSTANCE g_hInst;
LPSTR lpszClass = "Clinet";

int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hprecInstance
	, LPSTR lpszCmdParam, int nCmdShow)
{
	HWND hWnd;
	MSG Message;
	WNDCLASS WndClass;
	g_hInst = hInstance;

	WndClass.cbClsExtra = 0;
	WndClass.cbClsExtra = 0;
	WndClass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	WndClass.hCursor = LoadCursor(NULL, IDC_ARROW);
	WndClass.hIcon = LoadIcon(NULL, IDC_ARROW);
	WndClass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	WndClass.hInstance = hInstance;
	WndClass.lpfnWndProc = (WNDPROC)WndProc;
	WndClass.lpszClassName = lpszClass;
	WndClass.lpszMenuName = NULL;
	WndClass.style = CS_HREDRAW | CS_VREDRAW;
	RegisterClass(&WndClass);

	hWnd = CreateWindow(lpszClass, lpszClass, WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT,
		NULL, (HMENU)NULL, hInstance, NULL);
	ShowWindow(hWnd,nCmdShow);

	while (GetMessage(&Message, 0, 0, 0)) {
		TranslateMessage(&Message);
		DispatchMessage(&Message);
	}
	return Message.wParam;
}

LRESULT CALLBACK WndProc(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam)
{
	HDC hdc;
	PAINTSTRUCT ps;
	static RECT rt;
	switch (iMessage)
	{
	case WM_CREATE:
		GetClinetRect(hWnd, &rt);
		return 0;
	case WM_PAINT:
		hdc = BeginPaint(hWnd, &ps);
		SetTextAlign(hdc, TA_CENTER);
		TextOut(hdc, rt.right / 2, rt.bottom / 2, "Center String", 13);
		EndPaint(hWnd, &ps);
		return 0;
	case WM_DESTROY:
		PostQuitMessage(0);
	}
	return(DefWindowProc(hWnd, iMessage, wParam, lParam));
}