// �׷��� ���
// �׷��� ��¿����� ������ ���� �Լ��� ����Ѵ�.

COLORREF setPixel(hdc, nXpos, nYpos, clrref)
DWORD MoveToEx(hdc, x, y, ipPoint)
BOOL LineTo(hdc, xEnd, yEnd)
BOOL Rectangle(hdc, nLeftRect, nTopRect, nRightRect, nBottomRect)
BOOL Ellipse(hdc, nLeftRect, nTopRect, nRightRect, nBottomRect)

// ���ٽ��� ��� GDI �Լ��� ù �μ��� hdc�̹Ƿ� TextOut �Լ��� ����������
// DC�ڵ���� ���� �׷����� ����� �� �ִ�.

// �켱 setPixel �Լ��� ȭ�鿡 ���� ����ϴµ� nXPos, nYPos��ǥ�� 
// dlrref �������� ���� ����Ѵ�. ���� �⺻���� ������� �����ʴ´�.

// ���� ���� ���� MoveToEx �Լ��� LineTo �Լ��� ���� ����ϴµ�
// GDI�� �ؽ�Ʈ ����� Ŀ���� �ش��ϴ� Cp�� �׻� �����ϴµ� LineTo �Լ���
// Cp�κ��� ������ ��ǥ���� ���� ������ CP�� �������� �̵������ش�.

// MoveTo �Լ��� CP�� ������ ��ǥ�� �̵����� �ָ� �̵�����
// Cp ��ǥ�� ipPoint�� �������ִµ� �ʿ������ NULL���� �Ѱ��ָ� �ȴ�.

//ex) (A,B)���� (C, D)���� ���� �߰� �ʹٸ� ������ ���� �� �Լ��� ȣ�����ָ� �ȴ�.
MoveToEx(hdc, A, B, NULL);
LineTo(hdc, C, D);

// MoveToEx �Լ��� Cp�� ó�� ��ǥ�� �̵���Ų �� LineTo �Լ��� ȣ���ϸ� 
// ���� �׾�����.

// Rectangle �Լ��� Ellipse �Լ��� �� �� �μ��� �����ϴ�.
// Rectangle �Լ��� ������ �� ���� �밢������ �ϴ� �簢���� �׸��µ�
// ������ �޸� �簢���� ���θ� ä��ٴ� ���� �����ؾ� �Ѵ�.
// Ellipse �Լ��� ������ �簢���� �����ϴ� Ÿ���� �׸���.