// Mouse

// 마우스 입력에 대한 메시지는 다음과 같은 종류가 있다.

/*
	좌측 - WM_BUTTONDOWN 누름 | WM_BUTTONUP 놓음 | WM_BUTTONDBCLICK 더블클릭
	...
*/

// 마우스 메시지는 lParam의 상위 워드에 마우스 버튼이 눌러진 y좌표, 하위 워드에 x좌표를 가지며
// 좌표값을 검출해 내기 위해 HIWORD, LOWORD 등의 매크로 함수를 사용한다.
// 즉 마우스 메시지가 발생한 위치의 좌표는 (LOWORD(lParam)), HIWORD(lParam)이 된다.
// wParam에서는 마우스 버튼의 상태와 키보드 조합 키의 상태가 전달된다. 조합 키 상태는 다음 값의 비트 연산을 하면 알 수 있다.

/*
	MK_CONTROL - 컨트롤 키가 눌려있다.
	MK_LBUTTON - 마우스 왼쪽 버튼이 눌려있다.
	MK_RBUTTON - 마우스 오른쪽 버튼이 눌려있다.
	MK_MBUTTON - 마우스 중간 버튼이 눌려있다.
	MK_SHIFT - shift 키가 눌려있다.
*/