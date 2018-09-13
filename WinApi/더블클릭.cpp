// 더블클릭

case WM_LBUTTONDBLCLK:
	InvalidateRect(hWnd, NULL, TRUE);
	return 0;

// 화면을 지우는 법은 InvalidateRect 함수를 호출해 작업 
// 영역 전체를 무효화시켜 버리면 된다. Mouse 예제의 경우
// WM_PAINT 메시지를 처리하지 않고 있기 때문에 무효화 영역이
// 생기면 DefWindowProc이 WM_PAINT 메시지를 처리하게 되며
// 이 배경색으로 윈도우를 채워주게 된다.
// 만약 이것을 코드에 쓴다면 WndClass.syle=CS_HREDRAW | CS_VREDRAW | CS_DBLCLKS;
// 라는 의사 표시를 해 주어야 한다.