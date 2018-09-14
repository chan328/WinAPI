// 두 개의 타이머

// 타이머는 한꺼번에 여러개를 설치하여 사용할 수도 있다.
// 필요한 만큼 SetTimer를 호출하되 두번째 인수인 타이머 ID를
// 각각 다르게 설정해 주어야 하며 타이머 간격은 타이머에 따라
// 설정해 주면 된다. 
// 하나의 타이머를 설치했을 때처럼 여러개의 타이머도 전달되는 메시지는
// WM_TIMER 하나뿐이다. 어떤 타이머에 의해 WM_TIMER 메시지가 발생했는지는
// wParam으로 전달되는 타이머의 ID로 구분한다.
// 이 타이머 ID는 곧 SetTimer 함수가 타이머를 설치할 때 
// 두번째 인수로 지정한 값이다.

#include <Windows.h>

long FAR PASCAL WndProc(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam)
{
	HDC hdc;
	PAINTSTRUCT ps;
	time_t mytime;
	static HANDLE hTimer, hTimer2;
	static char *str;
	static RECT rt = { 100, 100, 400, 120 };
	switch (iMessage)
	{
	case WM_CREATE:
		hTimer = (Handle)SetTimer(hWnd. 1, 1000, NULL); // 1초에 한번씩 호출
		hTimer2 = (Handle)SetTimer(hWnd, 2, 5000, NULL); // 5초에 한번씩 호출
		str = "";
		SendMessage(hWnd.WM_TIMER, 1, 0);
		return 0;
	case WM_TIMER:
		switch (wParam)
		{
		case 1:
			time(&mytime);
			str = ctime(&mytime);
			InvalidateRect(hWnd, &rt, TRUE);
			break;
		case 2:
			MessageBeep(MB_OK);
			break;
		}
		return 0;
	case WM_PAINT:
		hdc = BeginPaint(hWnd.&ps);
		TextOut(hdc, 100, 100, str, strlen(str) - 1);
		EndPaint(hWnd, &ps);
		return 0;
	case WM_DESTROY:
		KillTimer(hWnd, 1);
		KillTimer(hWnd, 2);
		PostQuitMessage(0);
		return 0;
	}
	return(DefWindowProc(hWnd, iMessage, wParam, lParam));
}