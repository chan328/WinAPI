#include <windows.h>
#define WS_OVERLAPPEDWINDOW (WS_OVERLAPPED     | \
                             WS_CAPTION        | \
                             WS_SYSMENU        | \
                             WS_THICKFRAME     | \
                             WS_MINIMIZEBOX    | \
                             WS_MAXIMIZEBOX)

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
HINSTANCE g_hInst;
LPCTSTR lpszClass = L"First"; // 윈도우를 정의함
// 인스턴스 핸들이란? : 같은 두 프로그램을 실행시켰을 때 인스턴스 핸들의 값으로 구별함.
int APIENTRY WinMain(HINSTANCE hInstance/*프로그램의 인스턴스 핸들, 프로그램 자체를 일컫는 정수값*/, 
	HINSTANCE hPrevInstance /*바로 앞에 실행된 현재 프로그램의 인스턴스 핸들*/
	, LPSTR lpszCmdParam, 
	int nCmdShow/*프로그램이 실행될 형태이며 최소화, 보통모양 등이 전달됨*/)
{
	HWND hWnd; // 윈도우 핸들을 이러한 윈도우를 제어할 때 쓰는 이름표라고 생각하면 되겠다.
	MSG Message;
	WNDCLASS WndClass;
	g_hInst = hInstance; // WinMain의 인수로 전달된 hinstance값을 전역 변수 g_hlsnt에 대입
	// hInstance 인수는 기억부류가 지역 변수이기 때문에 WinMain의 밖에서는 사용할 수 없기 때문

	WndClass.cbClsExtra = 0;
	WndClass.cbWndExtra = 0;
	WndClass.hbrBackground = (HBRUSH)GetStockObject(BLACK_BRUSH); // 배경색 바꾸기 참조
	WndClass.hCursor = LoadCursor(NULL, IDC_CROSS);
	WndClass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	WndClass.hInstance = hInstance;
	WndClass.lpfnWndProc = (WNDPROC)WndProc;
	WndClass.lpszClassName = lpszClass;
	WndClass.lpszMenuName = NULL;
	WndClass.style = CS_HREDRAW | CS_VREDRAW;
	RegisterClass(&WndClass);

	hWnd = CreateWindow(lpszClass, L"Test", WS_OVERLAPPEDWINDOW,
		100, 100, 300, 200,
		NULL, (HMENU)NULL, hInstance, NULL);
	ShowWindow(hWnd, nCmdShow);

	while (GetMessage(&Message, 0, 0, 0)) {
		TranslateMessage(&Message);
		DispatchMessage(&Message);
	}
	return Message.wParam;
}

LRESULT CALLBACK WndProc(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam)
{
	switch (iMessage) {
	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;
	}
	return(DefWindowProc(hWnd, iMessage, wParam, lParam));
}