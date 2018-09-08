// WndProc
// 메시지 처리 함수란 메시지가 발생할 대 반응을 처리하는 일을 하며
// WinMain 함수와는 별도로 WndProc이라는 이름으로 존재한다.
// 윈도우 프로시저(Window Procedure)라는 뜻을 가지고있지만, 윈드 프록이라고 읽는다.
// WndProc은 WinMain에서 호출하는 것이 아닌 윈도우즈에 의해 호출된다.

// WinMain내의 메시지 루프는 메시지를 메시지 처리 함수로 배내주기만 할 뿐이며
// WndProc은 메시지가 입력되면 윈도우즈에 의해 호출이 되어 메시지를 처리함.
// 이렇게 운영체제에 의해 호출되는 응용 프로그램내의 함수를 CallBakc(콜백 함수)라고 한다.

// WndProc의 인수는 모두 4개이며 MSG구조체의 멤버 4개와 동일하다.
// hWnd는 메시지를 받을 윈도우의 핸들이며
// iMessage는 어떤 종류의 메시지인가, 즉 어떤 변화가 발생했는가에 대한 정보를 가진다.
// ex) iMessage가 WM_MOVE면 윈도우의 위치가 변경되었음을 알리고 WM_DESTROY면 
// 윈도우가 파괴되었음을 알리는 것이다.
//wParam, IParam은 iMessage의 메시지에 따른 부가적인 정보를 가진다.

// WndProc의 구조는 대체로 다음과 같은 형태를 가진다. 메시지의 종류에 따라 
// 다중분기하여 메시지별로 처리를 진행한다.

switch (iMessage)
{
case Msg1: // Msg1 메시지가 전달되면 처리 1을 한 후 리턴하고 
	char "처리1";
		break;
case Msg2: // Msg2 메시지가 전달되면 처리 2를 한 후 리턴한다.
	char "처리2";
		break;
case Msg3: // case 문은 메시지가 전달된 만큼 반복된다.
	char "처리3";
		break;
default:
	return DefWindowProc(...);
	break; // DefWindwoProc 함수는 WndProc에서 처리하지 않은 나머지 메시지에 대한
		// 처리를 해준다.
}

// 예를 들어 시스템 메뉴를 더블클릭하면 프로그램이 종료되는데 이런 처리는 별도로
// 처리 하지 않아도 DefWindowProc으로 넘겨주기만 하면 된다.
// 예제의 메시지 처리 함수는 다음과 같이 되어있다.

LRESULT CALLBACK WndProc(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam)
{
	switch (iMessage)
	{
	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;
	}
	return(DefWindowProc(hWnd, iMessage, wParam, IParam));
}

// 위 예제는 WM_DESTROY 메시지만을 처리하고 있으며 나머지 메시지에 대해서는
// DefWindowProc에 맡긴다. WndProc에서 이 메시지가 발생하면 PostQuitMessage 함수를
// 호출하여 WM_QUIT 메시지를 보낸다. WM_QUIT 메시지가 입력되면 메시지 루프의
// GetMessage 함수 리턴값이 False가 되어 프로그램이 종료한다.

// WM_DESTROY 이외의 메시지는 모두 DefWindowProc 함수로 전달되며 이 함수에서
// 디폴트 처리를 수행해 준다. WndProc은 메시지를 처리했을 경우 반드시 0을 return
// 해줘야 한다.