// WM_SIZE

// 앞에서 만든 예제는 작업 영역에 문자열을 출력하는데 만약 글씨의 크기를 바꾸면
// 중앙에 있던 문자열의 위치가 바뀌게 된다.

// 문자열을 계속 작업 중앙에 두고 싶으면 윈도우의 크기가 변경될 때마다 다시 출력해
// 하는데, 이 때 사용되는 메시지가 WM_SIZE이다. 이 메시지는 윈도우의 크기가
// 변경되엇을 때 보내진다. 이 때 lParam에 하위 워드에는 변경된 후의 윈도우 폭이,
// 상위 워드에는 높이가 전달되며 wParam에는 이 메시지가 발생한 이유를 나타내는 
// 플레그가 전달된다.

/*
	SIZE_MAXHIDE - 다른 위도우가 최대화되어 이 윈도우가 가려졌다.
	SIZE_MAXMIZED - 최대화되었다.
	SIZE_MAXSHOW - 다른 윈도우가 원래 크기로 복구되어 이 윈도우가 드러났다.
	SIZE_MINIMIZED - 최소화되었다.
	SZIE_RESTORED - 크기가 변경되었다.
*/

LRESULT CALLBACK WndProc(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam)
{
	HDC hdc;
	PAINTSTRUCT ps;
	static RECT rt;
	switch (iMessage)
	{
	case WM_PAINT:
		hdc = BeginPaint(hWnd, &ps);
		SetTextAllign(hdc, TA_CENTER);
		TextOut(hdc, rt.right / 2, rt.bottom / 2, "Center String", 13);
		EndPaint(hWnd, &ps);
		return 0;
	case WM_SIZE:
		GetClinetRect(hWnd, &rt);
		InvalidateRect(hWnd, NULL, TRUE);
		return 0;
	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;
	default:
		break;
	}
	return (DefWindwProc(hWnd, iMessage, wParam, lParam));
}

// WM_CREATE 대신 WM_SIZE에서 윈도우 크기가 변경될 때마다 작업 영역의 크기를
// 다시 계산하고 화면을 다시 그리므로 문자열은 윈도우의 크기에 다시 조사하는데
// wParam으로 작업 영역의 크기가 전달되므로 다음과 같이 쓸 수도 있다.

case WM_SIZE:
	rt.right = LOWORD(lParam);
	rt.bottom = HIWORD(lParam);
	invalidateRect(hWnd, NULL, TRUE);
	return 0;

// WM_SIZE 메시지는 윈도우 크기에 상관없이 일정한 레이아웃을 유지하기 위해 사용됨.