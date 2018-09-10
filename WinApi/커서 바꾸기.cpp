// 윈도우 타이틀 바꾸기
// 예제를 실행시켰을 때 First라는 문자열이 나타나는데 이 값은 우리가
// CreateWindow함수의 두번째 인수로 지정한 lpszClass 문자열이며
// 이는 또한 윈도우 클래스의 이름이다.

hWnd = CreateWindwo(lpszClass, "My First Program", WS_OBERLAPPEDWINDOW,
	CW_USEDFEAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT,
	NULL, (HMENU)NULL, hinstance, NULL);

// "My First Program" 부분을 바꿔주면 이름이 바뀐다.