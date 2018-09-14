// 생성및 파괴

// 윈도우와 관련되 메시지 중 가장 간단한 메시지는 윈도우가 생성될 때
// 보내지는 WM_CREATE와 윈도우가 파괴될 때 보내는 WM_DESTROY 두가지가 있다.
// WM_CREATE는 윈도우가 생성될 때 보내지므로 초기화를 하기 적합하고
// DESTROY 메시지는 종료처리를 하기 적합하다.

// 이 메시지를 대신하는 법은 WinMain에서 직접 초기화와 종료 처리를 해주는 것이다.
// WM_CREATE 메시지는 CreateWindow 함수에 의해 메인 윈도우가 생성
// 된 직후에 보내지므로 CreateWindow 함수 호출문 다음에 초기화 코드를 작성해도
// 효과는 같다.

// WM_DESTROY 메시지는 메인 윈도우가 파괴되기 직전에 보내지는데 메인 윈도우 파괴후에는
// 메시지 루프가 끝나게 되므로 메시지 루프 다음에 종료 처리 코드를 작성해도 된다.

HANDLE hTimer, hTimer2;
char *str;

int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
	LPSTR lpszCmdParam, int nCmdShow)
{
	hWnd = CreateWindow(lpszClass, lpszClass, WS_OVERLAPPEDWINDOW,
		CS_USEDEFAULT, CS_USEDEFAULT, CS_USEDEFAULT, CS_USEDEFAULT,
		NULL, (HMENU)NULL, hInstance, NULL);
	ShowWindow(hWnd, nCmdShow);

	hTimer = (HANDLE)SetTimer(hWnd, 1, 1000, NULL);
	hTimer2 = (HANDLE)SetTimer(hWnd, 2, 5000, NULL);
	str = "";
	SendMessage(hWnd, WM_TIMER, 1, 0);

	while (getMessage(&Message, 0, 0, 0)) {
		TranslateMessage(&Message);
		DispatchMessage(&Message);
	}

	KillTimer(hWnd, 1);
	KillTimer(hWnd, 2);

	return Message.wParam;
}