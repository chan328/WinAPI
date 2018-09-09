// 윈도우 스타일
// CreateWindwo 함수의 네번째 인수 dwStyle은 윈도우즈의 여러가지 속성을
// 정의하는 32비트 정수 값이며 이 값을 변경함에 따라 다양한 모양으로
// 일단 dwStyle에 사용될 수 있는 값을 알아보자.
// 이 값들을 OR연산자를 통해 여러가지 속성을 같이 정의한다.

/*
WS_CAPTION - 타이틀 바를 가진다.
WS_HSCROLL - 수평 스크롤 바를 가진다.
WS_VSCROLL - 수직 스크롤 바를 가진다.
WS_MAXIMIZEBOX - 최대화 버튼을 가진다.
WS_MINIMIZEBOX - 최소화 버튼을 가진다.
WS_STSMENU - 시스템 메뉴를 가진다.
WS_THICKFRAME - 크기를 조절할 수 있는 경계선을 가진다.
*/

// 일단 예제를 보면
#define WS_OVERLAPPEDWINDOW (WS_OVERLAPPED |\
							 WS_CAPTION    |\
							 WS_SYSMENU    |\
							 WS_THICKFRAME |\		
							 WS_MINIMIZEBOX|\
							 WS_MAXIMIZEBOX)

// 여기서 WS_OVERLAPPED는 실제로 0이므로 의미가 없다.