// �޽��� �ڽ�
// �޽��� �ڽ��� ���׸� ������ �����츦 ���� ����ڿ��� ������ �����ϰų�
// ������ �ϴ� ��ġ�̸� MessageBox �Լ� ȣ�� �ѹ����� ������ ���� �� �ִ�.

int MessageBox(HWND hWnd, LPCTSTR ipText, LPCTSTR ipCaption, UINT uType);

// ù ��° �μ� hWnd�� �޽��� �ڽ��� ���� �������.
// ���� ������� �޽��� ���ڸ� ������ �����츦 ���ϸ� �޽��� �ڽ��� ���� �������� ���߾ӿ� ��Ÿ����.
// �޽��� �ڽ��� ���ִ� ���� ���� ������� ����� �� ����.
// �� ��° �μ� ip Text�� �޽��� �ڽ��� ����� ���ڿ��̸�
// �� ��° �μ� ipCaption�� �޽��� ������ Ÿ��Ʋ �ٿ� ��Ÿ�� ���� ���ڿ��Դϴ�.
// �� ��° �μ� uType�� �޽��� ���ڿ� � ������ ��ư�� ��Ÿ�� ���ΰ��� �����ϴ� �������� �÷��׵��̴�.

/*	uType�� ������
	
	MB_ABORTRETRYIGNORE - Abort, Retry, Ignore �� ���� ��ư�� ��Ÿ����.
	MB_OK - OK ��ư �ϳ��� ��Ÿ����.
	MB_OKCANCLE - OK + Cancle
	MB_RETRYCANCLE - RETRY + CANCLE
	MB_YESNO - YES + NO
	MB_YESNOCACLE - YES + NO + CANCLE
*/

// ���޻����� �ܼ��� �����ϴ� �뵵 �ܿ� ����ڿ��� ������ �ϰ� ���޴� �뵵�� ��� �����ϴ�.
/* 
	IDABORT - Abort��ư�� ������.
	IDCANCLE - Cancle ��ư�� ������.
	IDIGNORE - Ignore ��ư�� ������.
	IDNO - No ��ư�� ������.
	IDOK - OK ��ư�� ������.
	IDRETRY - Retry ��ư�� ������.
	IDYES - Yes ��ư�� ������.
*/

// ex) ����ڿ��� ������ ����� ���ΰ� ���� ��
if (MessageBox(hWnd, "������ ��� �Ͻǰǰ���?", "����", MB_YESNO) == IDYES)
{
	// ���� ���ó��
}
else {
	// ���� ����
}