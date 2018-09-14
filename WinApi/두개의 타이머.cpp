// �� ���� Ÿ�̸�

// Ÿ�̸Ӵ� �Ѳ����� �������� ��ġ�Ͽ� ����� ���� �ִ�.
// �ʿ��� ��ŭ SetTimer�� ȣ���ϵ� �ι�° �μ��� Ÿ�̸� ID��
// ���� �ٸ��� ������ �־�� �ϸ� Ÿ�̸� ������ Ÿ�̸ӿ� ����
// ������ �ָ� �ȴ�. 
// �ϳ��� Ÿ�̸Ӹ� ��ġ���� ��ó�� �������� Ÿ�̸ӵ� ���޵Ǵ� �޽�����
// WM_TIMER �ϳ����̴�. � Ÿ�̸ӿ� ���� WM_TIMER �޽����� �߻��ߴ�����
// wParam���� ���޵Ǵ� Ÿ�̸��� ID�� �����Ѵ�.
// �� Ÿ�̸� ID�� �� SetTimer �Լ��� Ÿ�̸Ӹ� ��ġ�� �� 
// �ι�° �μ��� ������ ���̴�.

#include <Windows.h>

long FAR PASCAL WndProc(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam)
{
	HDC hdc;
	PAINTSTRUCT ps;
	time_t mytime;
	static HANDLE hTimer, hTimer2;
	static char *str;
	static RECT rt = { 100, 100, 400, 120 };
	switch (iMessage)
	{
	case WM_CREATE:
		hTimer = (Handle)SetTimer(hWnd. 1, 1000, NULL); // 1�ʿ� �ѹ��� ȣ��
		hTimer2 = (Handle)SetTimer(hWnd, 2, 5000, NULL); // 5�ʿ� �ѹ��� ȣ��
		str = "";
		SendMessage(hWnd.WM_TIMER, 1, 0);
		return 0;
	case WM_TIMER:
		switch (wParam)
		{
		case 1:
			time(&mytime);
			str = ctime(&mytime);
			InvalidateRect(hWnd, &rt, TRUE);
			break;
		case 2:
			MessageBeep(MB_OK);
			break;
		}
		return 0;
	case WM_PAINT:
		hdc = BeginPaint(hWnd.&ps);
		TextOut(hdc, 100, 100, str, strlen(str) - 1);
		EndPaint(hWnd, &ps);
		return 0;
	case WM_DESTROY:
		KillTimer(hWnd, 1);
		KillTimer(hWnd, 2);
		PostQuitMessage(0);
		return 0;
	}
	return(DefWindowProc(hWnd, iMessage, wParam, lParam));
}