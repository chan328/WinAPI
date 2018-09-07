#include<Windows.h>
// 메시지 루프
// 윈도우즈는 메시지 구동 시스템(Message Driven System)이라고 한다.
// 도스와 달리 윈도우즈는 명령의 실행 순서가 명확하게 정해져 있지 않다.

// 메시지란? : 사용자나 시스템 내부적인 동작에 의해 발생된 변화의 정보를 뜻한다.
// 윈도우즈 프로그램에서 메시지를 처리하는 부분을 메시지 루프라고 하며 보통
// WinMain 함수의 끝에 다음과 같은 형식으로 존재한다.

while (GetMessage(&Message, 0, 0, 0)) {
	TranslateMessage(&Message);
	DispatchMessage(&Message);
}

BOOL GetMessage(LPMSG ipMsg, HWND hWnd, UINT wMsgFilterMin, UINT wMsgFilterMax);
// 이 함수는 시스템이 유지하는 메시지 큐에서 메시지를 읽어들인다.
// 읽어들인 메시지는 첫번째 인수가 지정하는 MSG 구조체에 저장된다.
// 이 함수는 프로그램을 종료하라는 WM_QUIT일 경우 False를 리턴하며 그 외의 메시지면 
// True를 리턴한다.

LONG DispatchMessage(CONST MSG *lpmsg);
// 시스템 큐에서 꺼낸 메시지를 프로그램의 메시지 처리 함수(WndProc)로 전달한다.
// 이 함수가 메시지를 프로그램으로 전달하며 프로그램에서는 전달된 메시지를 점검해 다음 동작을 수행

typedef struct tagMSG
{
	HWND hwnd;
	// 메시지를 받을 윈도우 핸들이다.
	UINT message;
	// 어떤 종류의 메시지인가를 나타낸다.
	WPARAM wParam;
	// 전달된 메시지에 대한 부가적인 정보를 가진다.
	LPARAM lParam;
	// 전달된 메시지에 대한 부가적인 정보를 가진다.
	DWORD time;
	// 메시지가 발생한 시간이다.
	POINT pt;
	// 메시지가 발생했을 때의 마우스 위치이다.
} MSG;

// 자주 사용하는 메시지 종류.
VM_QUIT // 프로그램을 끝낼 때 발생하는 메시지이다.
VM_LBUTTONDOWN // 마우스의 좌측 버튼을 누를 경우 발생한다.
VM_CHAR // 키보드로부터 문자가 입력될 때 발생한다.
VM_PAINT // 화면을 다시 그려야 할 필요가 있을 때 발생한다.
VM_DESTROY // 윈도우가 메모리에서 파괴될 때 발생한다.
VM_CREATE // 윈도우가 처음 만들어질 때 발생한다.