// 윈도우의 크기 바꾸기
// 윈도우의 크기를 지정하는 값은 CreateWindwo의 4 ~ 7번째 인수이며
// 예제에서는 CW_USEDEFAULT를 사용해 윈도우즈가 정해주는대로 크기와
// 위치를 사용했다.

hWnd = CreateWindwo(lpszClass, "My First Program", WS_OBERLAPPEDWINDOW,
	100, 100, 300, 200
	NULL, (HMENU)NULL, hinstance, NULL);

// 100, 100 위치에 윈도우가 나타나고 폭은 300 높이는 200이 된다.