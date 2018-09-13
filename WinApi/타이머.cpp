// Ÿ�̸�

// Ÿ�̸� �޽����� ��ǥ���� ���� WM_TIMER�� �� �� �ִ�.
// �� �޽����� �ѹ� ������ ���⸸ �ϸ� ������� ���۰��� 
// ��� ���� �߻��ϴ� �޽����� �ִ�.	

#include<windows.h>

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM)
HINSTANCE g_hinst;
LPSTR lpszClass = "MyTimer";

int APIENTRY WinMain(HINSTANCE hinstance, HINSTANCE hPrevinstance.
	LPSTR lpszCmdParam, int nCmdShow)
{
	HWND hWnd;
	MSG message;
	WNDCLASS WndClass;
	g_hinst = hinstance;

	WndClass.cbClsExtra = 0;
	WndClass.cbWndExtra = 0;
	WndClass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	WndClass.hCursor = LoadCursor(NULL, IDC_ARROW);
	WndClass.hIcon = LoadIcon(NULL, IDC_ARROW);
	WndClass.hInstance = hinstance;
	WndClass.lpfnWndProc = (WNDPROC)WndProc;
	WndClass.lpszClassName = lpszClass;
	WndClass.lpszMenuName = NULL;
	WndClass.style = CS_HREDRAW | CS_VREDRAW;
	RegisterClass(&WndClass);

	hWnd = CreateWindow(lpszClass, lpszClass, WS_EX_OVERLAPPEDWINDOW,
		CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT,
		NULL, (HMENU)NULL, hinstance, NULL);
	ShowWindow(hWnd, nCmdShow);

	while (GetMessage(&Message, 0, 0, 0)
	{
		TranslateMessage(&Message);
		DispatchMessage(&Message);
	}
	return Message.wParam;
}

#includ
LRESULT CALLBACK WndProc(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam)
{
	HDC hdc;
	PAINTSTRUCT ps;
	time_t mytime;
	static HANDLE hTime;
	static char *str;
	switch (iMessage)
	{
	case WM_CREATE:
		hTimer = (Handle)SetTimer(hWnd, 1, 1000, NULL);
		str = "";
		return 0;
	case WM_TIMER:
		time(&mytime);
		str = ctime(&mytime);
		InvalidateRect(hWnd, NULL, TRUE);
		return 0;
	case WM_PAINT:
		hdc = BeginPaint(hWnd, &ps);
		TextOut(hdc, 100, 100, str, strlen(str) - 1);
		EndPaint(hWnd, &ps);
		return 0;
	case WM_DESTRY:
		KillTimer(hWnd, 1);
		PostQuitMessage(0);
		return 0;
	}
	return(DefWindowProc(hWnd, iMessage, wParam, lParam));
}

// �ð��� ���õ� �Լ����� ����ϹǷ� time.h�� ���Խ��ѳ��Ҵ�.
// WndProc���� ù ��°�� ó���ϴ� �޽����� WM_CREATE �޽�����.
// WM_CREATE �޽����� �����찡 ó�� ������ �� �߻��ϴµ�
// �� �޽������� ���α׷� ���۽� �ѹ��� �ʱ�ȭ�ؾ��� ó���� ���ش�.

UINT SetTimer(HWND hWnd, UINT nIDEvent, UINT uElapse, TIMERPROC
	ipTimerFunc);

// HWND �μ��� Ÿ�̸� �޽����� ���� �������ε� ��� WndProc�� �μ���
// ���޵Ǵ� hWnd�� �״�� �� �ָ� �ȴ�
// �� ��° �μ��� nIDEvent�� Ÿ�̸��� ��ȣ�� �����Ѵ�. �ϳ��� Ÿ�̸Ӹ� ����� ���
// 1�� �ָ� �Ǹ� �������� Ÿ�̸Ӹ� ����Ѵٸ� nidEvent�� ��ġ�� �ʵ���
// ��ȣ�� �ο����ָ� �ȴ�.

// �� ��° �μ� uElapase�� 1 / 1000�� ������ Ÿ�̸��� �ֱ⸦ �����Ѵ�.
// �� ���� 1000�̸� Ÿ�̸� �޽����� 1�ʿ� �ѹ��� hWnd�� �������� �ɰ��̰�
// 10000�̸� 10�ʿ� �ѹ��� Ÿ�̸� �޽����� �߻��� ���̴�.
// ������� ���� ��쿡�� NULL�� ����� �ָ� �ȴ�.

// �� ���������� WM_CREATE���� Ÿ�̸� ��ȣ 1������ 1�ʿ� �ѹ���
// Ÿ�̸� �޽����� hWnd�� �����ֵ��� Ÿ�̸Ӹ� �����Ͽ���.
// ���� hWnd �����쿡 WM_TIMER �޽����� ���޵� ���̴�.

// WM_TIMER �޽����� wParam���� Ÿ�̸� ID�� ���޹����� lParam���� Ÿ�̸�
// �޽��� �߻��� ȣ��� �Լ��� ������ ���޵ȴ�.
// WM_TIMER �޽����� �߻��ϸ� time �Լ��� �ð��� ������ ��
// ctime�Լ��� ���ڿ��� �ٲ� �� ���ڿ� str�� ������ �д�.

time_t time(time_t *timer); char *ctime(const time_t *timer);

// time �Լ��� ���� �ð��� �������ش�.
// ctime�� time_t �����κ��� ���� ��¥�� �ð��� ����Ͽ� ��Ȯ�ϰ�
// ���ڿ��� ������ �ָ� �� ���ڿ��� �������ش�.
// WM_TIMER���� �ð��� ���ŵ� �� ���� ȭ���� �ٲٱ� ���� invalidateRect
// �Լ��� ȣ���ϰ� �ִ�.

// ���������� �� �־�� �� ���� WM_DESTROY �޽������� ��ġ��
// Ÿ�̸Ӹ� ������ �ִ� ���̸� �� ���� KillTimer �Լ��� ����Ѵ�.

BOOL KillTimer(HWND hWnd, UINT uIDEvent);

// Ÿ�̸Ӵ� �ý��� ���� �ڿ��̹Ƿ� �ѹ� ������ ������ �����찡 �ı��Ǿ
// �ı����� �ʰ� ��� ���� �ְ� �ȴ�. �׷��� ���α׷��� ����� ��
// �ڽ��� ������ ź�̸Ӵ� �ڽ��� �ı������ �Ѵ�.
// killTimer�� ù��° �μ��� �� Ÿ�̸Ӹ� ������ ������ �ڵ��� �Ѱ��ָ�
// �� ��° �Ӽ��� Ÿ�̸� ID�� �Ѱ��ش�.