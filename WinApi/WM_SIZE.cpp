// WM_SIZE

// �տ��� ���� ������ �۾� ������ ���ڿ��� ����ϴµ� ���� �۾��� ũ�⸦ �ٲٸ�
// �߾ӿ� �ִ� ���ڿ��� ��ġ�� �ٲ�� �ȴ�.

// ���ڿ��� ��� �۾� �߾ӿ� �ΰ� ������ �������� ũ�Ⱑ ����� ������ �ٽ� �����
// �ϴµ�, �� �� ���Ǵ� �޽����� WM_SIZE�̴�. �� �޽����� �������� ũ�Ⱑ
// ����Ǿ��� �� ��������. �� �� lParam�� ���� ���忡�� ����� ���� ������ ����,
// ���� ���忡�� ���̰� ���޵Ǹ� wParam���� �� �޽����� �߻��� ������ ��Ÿ���� 
// �÷��װ� ���޵ȴ�.

/*
	SIZE_MAXHIDE - �ٸ� �����찡 �ִ�ȭ�Ǿ� �� �����찡 ��������.
	SIZE_MAXMIZED - �ִ�ȭ�Ǿ���.
	SIZE_MAXSHOW - �ٸ� �����찡 ���� ũ��� �����Ǿ� �� �����찡 �巯����.
	SIZE_MINIMIZED - �ּ�ȭ�Ǿ���.
	SZIE_RESTORED - ũ�Ⱑ ����Ǿ���.
*/

LRESULT CALLBACK WndProc(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam)
{
	HDC hdc;
	PAINTSTRUCT ps;
	static RECT rt;
	switch (iMessage)
	{
	case WM_PAINT:
		hdc = BeginPaint(hWnd, &ps);
		SetTextAllign(hdc, TA_CENTER);
		TextOut(hdc, rt.right / 2, rt.bottom / 2, "Center String", 13);
		EndPaint(hWnd, &ps);
		return 0;
	case WM_SIZE:
		GetClinetRect(hWnd, &rt);
		InvalidateRect(hWnd, NULL, TRUE);
		return 0;
	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;
	default:
		break;
	}
	return (DefWindwProc(hWnd, iMessage, wParam, lParam));
}

// WM_CREATE ��� WM_SIZE���� ������ ũ�Ⱑ ����� ������ �۾� ������ ũ�⸦
// �ٽ� ����ϰ� ȭ���� �ٽ� �׸��Ƿ� ���ڿ��� �������� ũ�⿡ �ٽ� �����ϴµ�
// wParam���� �۾� ������ ũ�Ⱑ ���޵ǹǷ� ������ ���� �� ���� �ִ�.

case WM_SIZE:
	rt.right = LOWORD(lParam);
	rt.bottom = HIWORD(lParam);
	invalidateRect(hWnd, NULL, TRUE);
	return 0;

// WM_SIZE �޽����� ������ ũ�⿡ ������� ������ ���̾ƿ��� �����ϱ� ���� ����.