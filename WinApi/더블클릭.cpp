// ����Ŭ��

case WM_LBUTTONDBLCLK:
	InvalidateRect(hWnd, NULL, TRUE);
	return 0;

// ȭ���� ����� ���� InvalidateRect �Լ��� ȣ���� �۾� 
// ���� ��ü�� ��ȿȭ���� ������ �ȴ�. Mouse ������ ���
// WM_PAINT �޽����� ó������ �ʰ� �ֱ� ������ ��ȿȭ ������
// ����� DefWindowProc�� WM_PAINT �޽����� ó���ϰ� �Ǹ�
// �� �������� �����츦 ä���ְ� �ȴ�.
// ���� �̰��� �ڵ忡 ���ٸ� WndClass.syle=CS_HREDRAW | CS_VREDRAW | CS_DBLCLKS;
// ��� �ǻ� ǥ�ø� �� �־�� �Ѵ�.