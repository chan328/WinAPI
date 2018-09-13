// 타이머

// 타이머 메시지중 대표적인 것은 WM_TIMER를 들 수 있다.
// 이 메시지는 한번 지정해 놓기만 하면 사용자의 동작과는 
// 상관 없이 발생하는 메시지도 있다.	

#include<windows.h>

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM)
HINSTANCE g_hinst;
LPSTR lpszClass = "MyTimer";

int APIENTRY WinMain(HINSTANCE hinstance, HINSTANCE hPrevinstance.
	LPSTR lpszCmdParam, int nCmdShow)
{
	HWND hWnd;
	MSG message;
	WNDCLASS WndClass;
	g_hinst = hinstance;

	WndClass.cbClsExtra = 0;
	WndClass.cbWndExtra = 0;
	WndClass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	WndClass.hCursor = LoadCursor(NULL, IDC_ARROW);
	WndClass.hIcon = LoadIcon(NULL, IDC_ARROW);
	WndClass.hInstance = hinstance;
	WndClass.lpfnWndProc = (WNDPROC)WndProc;
	WndClass.lpszClassName = lpszClass;
	WndClass.lpszMenuName = NULL;
	WndClass.style = CS_HREDRAW | CS_VREDRAW;
	RegisterClass(&WndClass);

	hWnd = CreateWindow(lpszClass, lpszClass, WS_EX_OVERLAPPEDWINDOW,
		CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT,
		NULL, (HMENU)NULL, hinstance, NULL);
	ShowWindow(hWnd, nCmdShow);

	while (GetMessage(&Message, 0, 0, 0)
	{
		TranslateMessage(&Message);
		DispatchMessage(&Message);
	}
	return Message.wParam;
}

#includ
LRESULT CALLBACK WndProc(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam)
{
	HDC hdc;
	PAINTSTRUCT ps;
	time_t mytime;
	static HANDLE hTime;
	static char *str;
	switch (iMessage)
	{
	case WM_CREATE:
		hTimer = (Handle)SetTimer(hWnd, 1, 1000, NULL);
		str = "";
		return 0;
	case WM_TIMER:
		time(&mytime);
		str = ctime(&mytime);
		InvalidateRect(hWnd, NULL, TRUE);
		return 0;
	case WM_PAINT:
		hdc = BeginPaint(hWnd, &ps);
		TextOut(hdc, 100, 100, str, strlen(str) - 1);
		EndPaint(hWnd, &ps);
		return 0;
	case WM_DESTRY:
		KillTimer(hWnd, 1);
		PostQuitMessage(0);
		return 0;
	}
	return(DefWindowProc(hWnd, iMessage, wParam, lParam));
}

// 시간과 관련된 함수들을 사용하므로 time.h를 포함시켜놓았다.
// WndProc에서 첫 번째로 처리하는 메시지는 WM_CREATE 메시지다.
// WM_CREATE 메시지는 윈도우가 처음 생성될 때 발생하는데
// 이 메시지에서 프로그램 시작시 한번만 초기화해야할 처리를 해준다.

UINT SetTimer(HWND hWnd, UINT nIDEvent, UINT uElapse, TIMERPROC
	ipTimerFunc);

// HWND 인수는 타이머 메시지를 받을 윈도우인데 통상 WndProc의 인수로
// 전달되는 hWnd를 그대로 써 주면 된다
// 두 번째 인수는 nIDEvent는 타이머의 번호를 지정한다. 하나의 타이머를 사용할 경우
// 1을 주면 되며 여러개의 타이머를 사용한다면 nidEvent에 겹치지 않도록
// 번호를 부여해주면 된다.

// 세 번째 인수 uElapase는 1 / 1000초 단위로 타이머의 주기를 설정한다.
// 이 값이 1000이면 타이머 메시지가 1초에 한번씩 hWnd로 보내지게 될것이고
// 10000이면 10초에 한번씩 타이머 메시지가 발생할 것이다.
// 사용하지 않을 경우에는 NULL을 사용해 주면 된다.

// 이 예제에서는 WM_CREATE에서 타이머 번호 1번으로 1초에 한번씩
// 타이머 메시지를 hWnd로 보내주도록 타이머를 설정하였다.
// 이제 hWnd 윈도우에 WM_TIMER 메시지가 전달될 것이다.

// WM_TIMER 메시지는 wParam으로 타이머 ID를 전달받으며 lParam으로 타이머
// 메시지 발생시 호출될 함수의 번지가 전달된다.
// WM_TIMER 메시지가 발생하면 time 함수로 시간을 조사한 후
// ctime함수로 문자열을 바꾼 후 문자열 str에 저장해 둔다.

time_t time(time_t *timer); char *ctime(const time_t *timer);

// time 함수는 현재 시간을 조사해준다.
// ctime은 time_t 값으로부터 현재 날짜와 시간을 계산하여 정확하게
// 문자열로 변경해 주며 그 문자열을 리턴해준다.
// WM_TIMER에서 시간이 갱신될 때 마다 화면을 바꾸기 위해 invalidateRect
// 함수를 호출하고 있다.

// 마지막으로 해 주어야 할 일은 WM_DESTROY 메시제에서 설치된
// 타이머를 제거해 주는 것이며 이 때는 KillTimer 함수를 사용한다.

BOOL KillTimer(HWND hWnd, UINT uIDEvent);

// 타이머는 시스템 전역 자원이므로 한번 설정해 놓으면 윈도우가 파괴되어도
// 파괴되지 않고 계속 남아 있게 된다. 그래서 프로그램이 종료될 때
// 자신이 설정한 탄이머는 자신이 파괴해줘야 한다.
// killTimer의 첫번째 인수로 이 타이머를 소유한 윈도우 핸들을 넘겨주며
// 두 번째 임수로 타이머 ID를 넘겨준다.