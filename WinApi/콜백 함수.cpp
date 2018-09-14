// �ݹ� �Լ�

// ���α׷��� ����Ǵ� ���� ���������� �����ؾ� �� �۾��� �ִٰ� �غ���.

for (;;) {
	// �������� �۾�
	// ��Ÿ �۾�
}

// ���� ������ ��ü ���α׷� �ڵ带 ���ΰ� �ְ�
// �� ���� �ȿ��� ���������� �ؾ��� �۾��� �׿� �۾��� �����ϰ� �ִ�.
// ���������� �̷������� ���α׷��� �ۼ��ϴ� ���� �����ϸ� ������ �̷��� �Ѵ�.
// �׷��� �����찰�� ��Ƽ �½�ŷ ȯ�濡���� �̷� ����� ����ؼ��� �ȵȴ�.
// �ֳ��ϸ� �� ���α׷��� ������� �����ϰ� �־�� �ȵǸ� �ٸ� ���α׷���

// ������ ����� ���� ��� SetTimer�� �׹�° �μ��� ���� �˾ƺ���.
// �׹�° �μ��� TIMERPROC ip TimerFunc��� �Ǿ��ִµ� �� �μ��� Ÿ�̸�
// ���ν��� �Լ��� �����͸� ����Ų��.
// �� �μ��� NULL�� �Ǿ� ���� ��� ù��° �μ��� ������ hWnd�� WM_TIMER
// �޽����� ���޵����� �� �μ��� Ÿ�̸� �Լ��� �����Ǿ��� ���
// �� �ð����� �� �Լ��� ��� ȣ��ȴ�. ��, Ÿ�̸� �Լ��� �����Ǹ�
// �޽��� ��� �Լ��� ȣ�����ش�. Ÿ�̸� �Լ��� ������ ���� �ۼ��Ѵ�.

VOID CALLBACK TimerProc(HWND hwnd, UINT uMsg, UINT idEvent, DWORD
	dwTime);

// ù��° �μ��� hWnd�� Ÿ�̸Ӹ� ������ �������� �ڵ��̸�
// uMsg�� WM_TIMER, idEvent�� Ÿ�̸�ID, dwTime�� �����찡 ����� ���� ����ð��̴�.
// �̷� �Լ��� ���� �� SetTimer �Լ��� �׹� ° �μ��� �� �Լ����� �����ָ�
// ������ �ð� �������� �� �Լ��� ȣ��ȴٴ� ���̴�.

#include <windows.h>

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
HINSTANCE g_hInst;
LPSTR lpszzClass = (LPSTR)"RnasGrp";

int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPrevinstance
	, LPSTR lpszCmdParam, int nCmdShow)
{
	HWND hWnd;
	MSG Message;
	WNDCLASS wndClass;
	g_hInst = hInstance;

	WndClass.cbClsExtra = 0;
	WndClass.cbWndExtra = 0;
	WndClass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	WndClass.hCursor = LoadCursor(NULL, IDC_ARROW);
	WndClass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	WndClass.hInstance = hInstance;
	WndClass.ipfnWndProc = (WNDPROC)WndProc;
	WndClass.IpszClassName = IpszClass;
	WndClass.lpszMenuNmae = NULL;
	WndClass.style - CS_HREDRAW | CS_VREDRAW;
	RegisterClass(&WndClass);

	hWnd = CreateWindow(IpszClassname, IpszClass, WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT,
		NULL, (HMENU)NULL, hInstance, NULL);
	ShowWindow(hWnd, nCmdShow);

	while (GetMessage(&Message, 0, 0, 0)) {
		TranslateMessage(&Message);
		DispatchMessage(&Message);
	}
	return Message.wParam;
}

void CALLBACK TimerProc(HWND hWnd, UINT uMsg, UINT idEvent, DWORD dwTime)
{
	HDC hdc;
	int i;
	hdc = GetDc(hWnd);
	for (i = 0; i < 100; i++)
		SetPixel(hdc, rand() % 500, rand() % 400,
			RGB(rand() % 256, rand() % 256, rand() % 256));
	ReleaseDC(hWnd, hdc);
}

LRESULT CALLBACK WndProc(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam)
{
	switch(iMessage)
	{
		case WM_CREATE:
			SetTimer(hWnd, 1, 100, (TIMERPROC)TimerProc);
			return 0;
		case WM_DESTROY:
			KillTimer(hWnd, 1);
			PostQuitMessage(0);
			return 0;
	}
	return(DefWindowProc(hWnd, iMessage, wParam, lParam));
}