// ������ ��Ÿ��
// CreateWindwo �Լ��� �׹�° �μ� dwStyle�� ���������� �������� �Ӽ���
// �����ϴ� 32��Ʈ ���� ���̸� �� ���� �����Կ� ���� �پ��� �������
// �ϴ� dwStyle�� ���� �� �ִ� ���� �˾ƺ���.
// �� ������ OR�����ڸ� ���� �������� �Ӽ��� ���� �����Ѵ�.

/*
WS_CAPTION - Ÿ��Ʋ �ٸ� ������.
WS_HSCROLL - ���� ��ũ�� �ٸ� ������.
WS_VSCROLL - ���� ��ũ�� �ٸ� ������.
WS_MAXIMIZEBOX - �ִ�ȭ ��ư�� ������.
WS_MINIMIZEBOX - �ּ�ȭ ��ư�� ������.
WS_STSMENU - �ý��� �޴��� ������.
WS_THICKFRAME - ũ�⸦ ������ �� �ִ� ��輱�� ������.
*/

// �ϴ� ������ ����
#define WS_OVERLAPPEDWINDOW (WS_OVERLAPPED |\
							 WS_CAPTION    |\
							 WS_SYSMENU    |\
							 WS_THICKFRAME |\		
							 WS_MINIMIZEBOX|\
							 WS_MAXIMIZEBOX)

// ���⼭ WS_OVERLAPPED�� ������ 0�̹Ƿ� �ǹ̰� ����.