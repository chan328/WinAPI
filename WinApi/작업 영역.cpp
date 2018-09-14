// �۾� ����

// ������� �۾� ������ ���۾� ���� �� �κ����� �����Ǿ� �ִ�.
// �۾� �����̶� ���� ���ؼ� ������ �߾��� �� �κ��� ���ϸ� 
// ���۾� �����̶� �� ���� ������ ���Ѵ�.

// �۾�/���۾� ������ ������ �����츦 �����ϴµ� �߿��� ������ �����ϴµ�
// �� ������ ���α׷��ӿ��� ���α׷����� ����� �Ǵ°��� �۾� �������̱� �����̴�.

// ���ϴ� ��ġ�� ��Ȯ�ϰ� ����� �ϱ� ���ؼ��� �����찡 �����ϰ� �ִ�
// ������ ��ǥ�� �����ؾ� �ϴ� ���� �ƴ϶� �۾� ������ ��ǥ�� �����ؾ� �Ѵ�.

BOOL GetClinetRect(HWND, LPRECT ipRect);

// �̸� �״�� client�� �����ϰ� �ִ� Rect�� Get�ϴ� �Լ��̴�.
// ù��° �μ��� ��� ������ �ڵ��� �ְ� �ι�° �μ��� ���� ����
// �����ޱ� ���� Rect ����ü�� �����͸� �Ѱ��ָ� �ȴ�.
// �� �Լ� ȣ�� �Ŀ� Rect ����ü���� �۾� ������ ��ǥ�� ���ִµ�
// left, top�� �׻� 0�̸� right, bottomo�� ���ϴ��� ��ǥ�� ���Եȴ�.

#include <Windows.h>

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
HINSTANCE g_hInst;
LPSTR lpszClass = "Clinet";

int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hprecInstance
	, LPSTR lpszCmdParam, int nCmdShow)
{
	HWND hWnd;
	MSG Message;
	WNDCLASS WndClass;
	g_hInst = hInstance;

	WndClass.cbClsExtra = 0;
	WndClass.cbClsExtra = 0;
	WndClass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	WndClass.hCursor = LoadCursor(NULL, IDC_ARROW);
	WndClass.hIcon = LoadIcon(NULL, IDC_ARROW);
	WndClass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	WndClass.hInstance = hInstance;
	WndClass.lpfnWndProc = (WNDPROC)WndProc;
	WndClass.lpszClassName = lpszClass;
	WndClass.lpszMenuName = NULL;
	WndClass.style = CS_HREDRAW | CS_VREDRAW;
	RegisterClass(&WndClass);

	hWnd = CreateWindow(lpszClass, lpszClass, WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT,
		NULL, (HMENU)NULL, hInstance, NULL);
	ShowWindow(hWnd,nCmdShow);

	while (GetMessage(&Message, 0, 0, 0)) {
		TranslateMessage(&Message);
		DispatchMessage(&Message);
	}
	return Message.wParam;
}

LRESULT CALLBACK WndProc(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam)
{
	HDC hdc;
	PAINTSTRUCT ps;
	static RECT rt;
	switch (iMessage)
	{
	case WM_CREATE:
		GetClinetRect(hWnd, &rt);
		return 0;
	case WM_PAINT:
		hdc = BeginPaint(hWnd, &ps);
		SetTextAlign(hdc, TA_CENTER);
		TextOut(hdc, rt.right / 2, rt.bottom / 2, "Center String", 13);
		EndPaint(hWnd, &ps);
		return 0;
	case WM_DESTROY:
		PostQuitMessage(0);
	}
	return(DefWindowProc(hWnd, iMessage, wParam, lParam));
}