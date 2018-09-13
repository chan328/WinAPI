// SendMessage

case WM_CREATE:
	htimer - SetTimer(hWnd, 1, 1000, NULL);
	str = "";
	SendMessage(hWnd, 1, 1000, NULL);
	return 0;

// 메시지는 사용자의 동작에 의해서나 시스템의 상황 변경에 따라
// 발생하는 것이 원칙이지만 강제로 메시지가 발생한 것처럼 만들어야
// 할 때는 이 함수를 사용하여 hWnd 윈도우로 Msg 메시지를 보내게 될 것이다.
// 그러면 hWnd는 Msg 메시지가 발생한 것으로 인식하고 필요한 처리를 할 것이다.

// 타이머를 설치한 직후에 SendMessage로 WM_TIMER 메시지를 보내주어
// 곧바로 시간을 조사한 후 조사한 시간을 화면에 출력하도록 하였다.

// SendMessage의 세번째, 네번째 인수는 메시지의 추가 정보인 wParam, lParam
// 이며 물론 보내는 메시지에 따라 의미는 달라진다. 
// WM_TIMER 메시지는 wParam으로 타이머ID를 보내도록 되어 있으므로
// SendMessage의 세번째 인수에 타이머 ID인 1을 넘겨 주었다.
// SendMessage의 리턴값도 물론 메시지에 따라 다르다.

// 메시지 기반의 운영체제인 윈도우즈에서 SendMessage 함수는 아주
// 빈전하게 사용되는 중요한 함수이다. WM_TIMER 메시지를 강제로 보내기 위해
// 어떤 종류의 메시지라도 누구에게나 보낼 수 있으며 SendMessage의 이런 기능은
// 차일드 컨트롤을 프로그래밍하는 아주 중요한 수단으로 사용된다.

// 이 프로그램이 가지는 문제점은 시간이 바뀔 때마다 화면이 깜박거린다는 점이다.
// 왜 그러냐면 WM_TIMER 메시지에서 시간을 변경한 후 화면을 다시 그리기 위해
// 다음과 같이 함수를 호출하기 때문이다.

	InvalidateRect(hWnd, NULL, TRUE);

// hWnd 윈도우를 무효화시키되 두번째 인수가 NULL이므로 화면 전체가 무효화된다.
// 세번째 인수가 TRUE이므로 일단 화면을 지운 후 다시 그리게 된다.
// 화면 전체가 몽땅 다 지워졌다가 다시 출력되기 때문에 깜빡거리는 것이 보이는 것이다.

// 이럴 경우 무효화 영역을 최소화하여 꼭 필요한 부분만 무효화 하도록
// 해 주어야 한다, 
	long FAR PASCAL WndProc(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam)
	{
		static RECT rt = { 100, 100, 400, 120 };
		switch (iMessage)
		{
		case WM_TIMER:
			time(&mytime);
			str = ctime(&mytime);
			invalidateRect(hWnd, &rt, TRUE);
			return 0;
		}
		{
		default:
			break;
		}
}