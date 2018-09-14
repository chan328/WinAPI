// 콜백 함수

// 프로그램이 실행되는 동안 지속적으로 수행해야 할 작업이 있다고 해보자.

for (;;) {
	// 지속적인 작업
	// 기타 작업
}

// 무한 루프가 전체 프로그램 코드를 감싸고 있고
// 이 루프 안에서 지속적으로 해야할 작업과 그외 작업을 수행하고 있다.
// 도스에서는 이런식으로 프로그램을 작성하는 것이 가능하며 실제로 이렇게 한다.
// 그러나 윈도우같은 멀티 태스킹 환경에서는 이런 방식을 사용해서는 안된다.
// 왜냐하면 한 프로그램이 제어권을 독점하고 있어서는 안되며 다른 프로그램도

// 예제를 만들기 전에 잠깐 SetTimer의 네번째 인수에 대해 알아보자.
// 네번째 인수는 TIMERPROC ip TimerFunc라고 되어있는데 이 인수는 타이머
// 프로시저 함수의 포인터를 가리킨다.
// 이 인수가 NULL로 되어 있을 경우 첫번째 인수로 지정된 hWnd로 WM_TIMER
// 메시지가 전달되지만 이 인수에 타이머 함수가 지정되었을 경우
// 매 시간마다 이 함수가 대신 호출된다. 즉, 타이머 함수가 지정되면
// 메시지 대신 함수를 호출해준다. 타이머 함수는 다음과 같이 작성한다.

VOID CALLBACK TimerProc(HWND hwnd, UINT uMsg, UINT idEvent, DWORD
	dwTime);

// 첫번째 인수인 hWnd는 타이머를 소유한 윈도우의 핸들이며
// uMsg는 WM_TIMER, idEvent는 타이머ID, dwTime은 윈도우가 실행된 후의 경과시간이다.
// 이런 함수를 만든 후 SetTimer 함수의 네번 째 인수에 이 함수명을 적어주면
// 지정한 시간 간격으로 이 함수가 호출된다는 점이다.

#include <windows.h>

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
HINSTANCE g_hInst;
LPSTR lpszzClass = (LPSTR)"RnasGrp";

int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPrevinstance
	, LPSTR lpszCmdParam, int nCmdShow)
{
	HWND hWnd;
	MSG Message;
	WNDCLASS wndClass;
	g_hInst = hInstance;

	WndClass.cbClsExtra = 0;
	WndClass.cbWndExtra = 0;
	WndClass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	WndClass.hCursor = LoadCursor(NULL, IDC_ARROW);
	WndClass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	WndClass.hInstance = hInstance;
	WndClass.ipfnWndProc = (WNDPROC)WndProc;
	WndClass.IpszClassName = IpszClass;
	WndClass.lpszMenuNmae = NULL;
	WndClass.style - CS_HREDRAW | CS_VREDRAW;
	RegisterClass(&WndClass);

	hWnd = CreateWindow(IpszClassname, IpszClass, WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT,
		NULL, (HMENU)NULL, hInstance, NULL);
	ShowWindow(hWnd, nCmdShow);

	while (GetMessage(&Message, 0, 0, 0)) {
		TranslateMessage(&Message);
		DispatchMessage(&Message);
	}
	return Message.wParam;
}

void CALLBACK TimerProc(HWND hWnd, UINT uMsg, UINT idEvent, DWORD dwTime)
{
	HDC hdc;
	int i;
	hdc = GetDc(hWnd);
	for (i = 0; i < 100; i++)
		SetPixel(hdc, rand() % 500, rand() % 400,
			RGB(rand() % 256, rand() % 256, rand() % 256));
	ReleaseDC(hWnd, hdc);
}

LRESULT CALLBACK WndProc(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam)
{
	switch(iMessage)
	{
		case WM_CREATE:
			SetTimer(hWnd, 1, 100, (TIMERPROC)TimerProc);
			return 0;
		case WM_DESTROY:
			KillTimer(hWnd, 1);
			PostQuitMessage(0);
			return 0;
	}
	return(DefWindowProc(hWnd, iMessage, wParam, lParam));
}