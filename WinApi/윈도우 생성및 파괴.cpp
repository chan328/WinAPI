// ������ �ı�

// ������� ���õ� �޽��� �� ���� ������ �޽����� �����찡 ������ ��
// �������� WM_CREATE�� �����찡 �ı��� �� ������ WM_DESTROY �ΰ����� �ִ�.
// WM_CREATE�� �����찡 ������ �� �������Ƿ� �ʱ�ȭ�� �ϱ� �����ϰ�
// DESTROY �޽����� ����ó���� �ϱ� �����ϴ�.

// �� �޽����� ����ϴ� ���� WinMain���� ���� �ʱ�ȭ�� ���� ó���� ���ִ� ���̴�.
// WM_CREATE �޽����� CreateWindow �Լ��� ���� ���� �����찡 ����
// �� ���Ŀ� �������Ƿ� CreateWindow �Լ� ȣ�⹮ ������ �ʱ�ȭ �ڵ带 �ۼ��ص�
// ȿ���� ����.

// WM_DESTROY �޽����� ���� �����찡 �ı��Ǳ� ������ �������µ� ���� ������ �ı��Ŀ���
// �޽��� ������ ������ �ǹǷ� �޽��� ���� ������ ���� ó�� �ڵ带 �ۼ��ص� �ȴ�.

HANDLE hTimer, hTimer2;
char *str;

int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
	LPSTR lpszCmdParam, int nCmdShow)
{
	hWnd = CreateWindow(lpszClass, lpszClass, WS_OVERLAPPEDWINDOW,
		CS_USEDEFAULT, CS_USEDEFAULT, CS_USEDEFAULT, CS_USEDEFAULT,
		NULL, (HMENU)NULL, hInstance, NULL);
	ShowWindow(hWnd, nCmdShow);

	hTimer = (HANDLE)SetTimer(hWnd, 1, 1000, NULL);
	hTimer2 = (HANDLE)SetTimer(hWnd, 2, 5000, NULL);
	str = "";
	SendMessage(hWnd, WM_TIMER, 1, 0);

	while (getMessage(&Message, 0, 0, 0)) {
		TranslateMessage(&Message);
		DispatchMessage(&Message);
	}

	KillTimer(hWnd, 1);
	KillTimer(hWnd, 2);

	return Message.wParam;
}