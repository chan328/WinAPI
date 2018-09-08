// WndProc
// �޽��� ó�� �Լ��� �޽����� �߻��� �� ������ ó���ϴ� ���� �ϸ�
// WinMain �Լ��ʹ� ������ WndProc�̶�� �̸����� �����Ѵ�.
// ������ ���ν���(Window Procedure)��� ���� ������������, ���� �����̶�� �д´�.
// WndProc�� WinMain���� ȣ���ϴ� ���� �ƴ� ������� ���� ȣ��ȴ�.

// WinMain���� �޽��� ������ �޽����� �޽��� ó�� �Լ��� �賻�ֱ⸸ �� ���̸�
// WndProc�� �޽����� �ԷµǸ� ������� ���� ȣ���� �Ǿ� �޽����� ó����.
// �̷��� �ü���� ���� ȣ��Ǵ� ���� ���α׷����� �Լ��� CallBakc(�ݹ� �Լ�)��� �Ѵ�.

// WndProc�� �μ��� ��� 4���̸� MSG����ü�� ��� 4���� �����ϴ�.
// hWnd�� �޽����� ���� �������� �ڵ��̸�
// iMessage�� � ������ �޽����ΰ�, �� � ��ȭ�� �߻��ߴ°��� ���� ������ ������.
// ex) iMessage�� WM_MOVE�� �������� ��ġ�� ����Ǿ����� �˸��� WM_DESTROY�� 
// �����찡 �ı��Ǿ����� �˸��� ���̴�.
//wParam, IParam�� iMessage�� �޽����� ���� �ΰ����� ������ ������.

// WndProc�� ������ ��ü�� ������ ���� ���¸� ������. �޽����� ������ ���� 
// ���ߺб��Ͽ� �޽������� ó���� �����Ѵ�.

switch (iMessage)
{
case Msg1: // Msg1 �޽����� ���޵Ǹ� ó�� 1�� �� �� �����ϰ� 
	char "ó��1";
		break;
case Msg2: // Msg2 �޽����� ���޵Ǹ� ó�� 2�� �� �� �����Ѵ�.
	char "ó��2";
		break;
case Msg3: // case ���� �޽����� ���޵� ��ŭ �ݺ��ȴ�.
	char "ó��3";
		break;
default:
	return DefWindowProc(...);
	break; // DefWindwoProc �Լ��� WndProc���� ó������ ���� ������ �޽����� ����
		// ó���� ���ش�.
}

// ���� ��� �ý��� �޴��� ����Ŭ���ϸ� ���α׷��� ����Ǵµ� �̷� ó���� ������
// ó�� ���� �ʾƵ� DefWindowProc���� �Ѱ��ֱ⸸ �ϸ� �ȴ�.
// ������ �޽��� ó�� �Լ��� ������ ���� �Ǿ��ִ�.

LRESULT CALLBACK WndProc(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam)
{
	switch (iMessage)
	{
	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;
	}
	return(DefWindowProc(hWnd, iMessage, wParam, IParam));
}

// �� ������ WM_DESTROY �޽������� ó���ϰ� ������ ������ �޽����� ���ؼ���
// DefWindowProc�� �ñ��. WndProc���� �� �޽����� �߻��ϸ� PostQuitMessage �Լ���
// ȣ���Ͽ� WM_QUIT �޽����� ������. WM_QUIT �޽����� �ԷµǸ� �޽��� ������
// GetMessage �Լ� ���ϰ��� False�� �Ǿ� ���α׷��� �����Ѵ�.

// WM_DESTROY �̿��� �޽����� ��� DefWindowProc �Լ��� ���޵Ǹ� �� �Լ�����
// ����Ʈ ó���� ������ �ش�. WndProc�� �޽����� ó������ ��� �ݵ�� 0�� return
// ����� �Ѵ�.