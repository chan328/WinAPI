// DC�� ��� ���
// ȭ������ ����� �ϱ� ���ؼ��� �ݵ�� DC�� �־�� �ϸ�
// DC�� ��� ������� �ΰ��� ����� �ִ�.
// GetDC�Լ��� ����� DC�� ��� �� ReleaseDC�� �����ϴ� ���̴�.

HDC GetDC(HWND hWnd);
int ReleaseDC(HWND hwnd, HDC, hDC);

// DC�� �ַ� �ϳ��� ������� �����Ǵ� ��������� ������.
// �׷��� �μ��� � �����쿡 ���� DC�� �ʿ��Ѱ��� �����־��
// �Ѵ�. GetDC�� hWnd�� ����Ű�� �����쿡 ���� ������ DC�� 
// ����� �� �ڵ��� �ݳ��Ѵ�. ���� ���������� �� �ڵ��� HDC����
// hdc ���켼 ������ �� �� �ڵ鰪�� TextOut �Լ��� ù ��°
// �μ��� ����Ͽ���. GetDC�� ���� ����� �ڵ��� ��� ��
// �ݵ�� ReleaseDC �Լ��� ���� ��ü�Ǿ�� �Ѵ�.

// DC�� ��� �� ��° ����� VM_PAINT �޽��� ��ƾ������ ����� ��
// �ִ�. VM_PAINT �޽��� ó�� ��ƾ������ DC �ڵ��� GetDC�� 
// ���� �ʰ� BeginPaint �Լ��� ������ �ڵ��� ������ ���� EndPaint
// �Լ��� ����Ѵ�. 

HDC BeginPaint(HWND hwnd, LPPAINTSTRUCT ipPatin);
BOOL EndPaint(HWND hWnd, CONST PAINTSTRUCT *ipPaint);

// BeginPaint �Լ��� ������ �ڵ� �ܿ��� ����Ʈ ���� ����ü�� �μ���
// �䱸�ϸ� �� ����ü�� �׸� �׸��⿡ �ʿ��� ������ ��´�.

typedef struct tagPAINTSTRUCT
{
	HDC hdc;
	BOOL fErase;
	RECT rePaint;
	BOOL fRestore;
	BOOL fincUpdate;
	BYTE rgbReserved[16];
} PAINTSTRUCT;