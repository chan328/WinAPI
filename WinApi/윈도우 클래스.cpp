// 윈도우 클래스
#include<Windows.h>
typedef struct tagWNDCLASS
{
	// 윈도우 클래스는 windows.h에 다음과 같이 정의되있다.
	UINT style;
	// 윈도우의 스타일 즉, 어떤 형태를 가질지를 지정하는 멤버이다.
	// 가장 많이 사용하는 값이 CS_HREDRAW, CS_VREDRAW인데 이 두 값을 OR 연산을 연결하여 사용.
	// 이 둘의 의미는 윈도우의 크기(수직, 수평)이 변할 경우에는 윈도우를 다시 그린다는 뜻.
	WNDPROC lpfnWndProc;
	// 이 멤버는 윈도우의 메시지 처리 함수를 지정한다.
	// 메시지가 발생할 때마다 여기서 지정한 함수가 호출되고 이 함수는 모든 메세지를 처리한다.
	int cbClsExtra;
	int cbWndExtra;
	// 위 둘은 일종의 예약 영역이다. 윈도우즈가 내부적으로 사용하며 특수한 목적에만 사용되므로
	// 평소에는 0으로 지정해서 사용한다.
	HINSTANCE hinstance;
	// 이 윈도우 클래스를 사용하는 프로그램의 번호이며 이 값은 WinMain의 인수로 전달된
	// hinstance 값을 그대로 대입해주면 된다.
	HICON hicon;
	HCURSOR hCursor;
	// 윈도우가 사용할 마우스 커서와 최소화되었을 경우 출력될 아이콘을 지정한다.
	HBRUSH hbrBackground;
	// 윈도우의 배경 색상을 지정한다.
	LPCSTR lpszMenuName;
	// 이 프로그램이 사용할 메뉴를 지정한다. 메뉴는 코드에서 만드는 것이 아니라
	// 리소스 에디터에 의해 별도로 만들어진 후 링크시에 같이 합쳐진다.
	// 사용 안할 때에는 NULL값을 대입해준다.
	LPCSTR lpszClassName;
	// 윈도우 클래스의 이름을 정의한다.
};