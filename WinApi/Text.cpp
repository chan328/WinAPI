#include <windows.h>
#define WS_OVERLAPPEDWINDOW (WS_OVERLAPPED     | \
                             WS_CAPTION        | \
                             WS_SYSMENU        | \
                             WS_THICKFRAME     | \
                             WS_MINIMIZEBOX    | \
                             WS_MAXIMIZEBOX)

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
HINSTANCE g_hInst;
LPCTSTR lpszClass = L"TextOut"; // �����츦 ������
// �ν��Ͻ� �ڵ��̶�? : ���� �� ���α׷��� ��������� �� �ν��Ͻ� �ڵ��� ������ ������.
int APIENTRY WinMain(HINSTANCE hInstance/*���α׷��� �ν��Ͻ� �ڵ�, ���α׷� ��ü�� ���´� ������*/,
	HINSTANCE hPrevInstance /*�ٷ� �տ� ����� ���� ���α׷��� �ν��Ͻ� �ڵ�*/
	, LPSTR lpszCmdParam,
	int nCmdShow/*���α׷��� ����� �����̸� �ּ�ȭ, ������ ���� ���޵�*/)
{
	HWND hWnd;
	MSG Message;
	WNDCLASS WndClass;
	g_hInst = hInstance; // WinMain�� �μ��� ���޵� hinstance���� ���� ���� g_hlsnt�� ����
	// hInstance �μ��� ���η��� ���� �����̱� ������ WinMain�� �ۿ����� ����� �� ���� ����

	WndClass.cbClsExtra = 0;
	WndClass.cbWndExtra = 0;
	WndClass.hbrBackground = (HBRUSH)GetStockObject(BLACK_BRUSH); // ���� �ٲٱ� ����
	WndClass.hCursor = LoadCursor(NULL, IDC_CROSS);
	WndClass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	WndClass.hInstance = hInstance;
	WndClass.lpfnWndProc = (WNDPROC)WndProc;
	WndClass.lpszClassName = lpszClass;
	WndClass.lpszMenuName = NULL;
	WndClass.style = CS_HREDRAW | CS_VREDRAW;
	RegisterClass(&WndClass);

	hWnd = CreateWindow(lpszClass, L"Test", WS_OVERLAPPEDWINDOW,
		100, 100, 300, 200,
		NULL, (HMENU)NULL, hInstance, NULL);
	ShowWindow(hWnd, nCmdShow);

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
	switch (iMessage) {
	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;
	case WM_PAINT:
		hdc = BeginPaint(hWnd, &ps);
		SetTextAlign(hdc, TA_UPDATECP);
		TextOut(hdc, 100, 100, L"Beautiful Korea", 15);
		TextOut(hdc, 200, 70, L"One ", 4);
		EndPaint(hWnd, &ps);
		return 0;
	case WM_LBUTTONDOWN:
		hdc = GetDC(hWnd);
		TextOut(hdc, 100, 100, L"Beautiful Korea", 15);
		ReleaseDC(hWnd, hdc);
		return 0;
	}
	return(DefWindowProc(hWnd, iMessage, wParam, lParam));
}