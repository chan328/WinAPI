// 그래픽 출력
// 그래픽 출력에서는 다음과 같은 함수를 사용한다.

COLORREF setPixel(hdc, nXpos, nYpos, clrref)
DWORD MoveToEx(hdc, x, y, ipPoint)
BOOL LineTo(hdc, xEnd, yEnd)
BOOL Rectangle(hdc, nLeftRect, nTopRect, nRightRect, nBottomRect)
BOOL Ellipse(hdc, nLeftRect, nTopRect, nRightRect, nBottomRect)

// 보다시피 모든 GDI 함수의 첫 인수는 hdc이므로 TextOut 함수와 마찬가지로
// DC핸들부터 얻어야 그래픽을 출력할 수 있다.

// 우선 setPixel 함수는 화면에 점을 출력하는데 nXPos, nYPos좌표에 
// dlrref 색상으로 점을 출력한다. 점은 기본적인 요소지만 쓰지않는다.

// 선을 그을 때는 MoveToEx 함수와 LineTo 함수를 같이 써야하는데
// GDI는 텍스트 모드의 커서를 해당하는 Cp를 항상 유지하는데 LineTo 함수는
// Cp로부터 지정한 좌표까지 선을 그으며 CP를 끝점으로 이동시켜준다.

// MoveTo 함수는 CP를 일정한 좌표로 이동시켜 주며 이동전의
// Cp 좌표를 ipPoint에 대입해주는데 필요없으면 NULL값을 넘겨주면 된다.

//ex) (A,B)에서 (C, D)까지 선을 긋고 싶다면 다음과 같이 두 함수를 호출해주면 된다.
MoveToEx(hdc, A, B, NULL);
LineTo(hdc, C, D);

// MoveToEx 함수로 Cp를 처음 좌표로 이동시킨 후 LineTo 함수를 호출하면 
// 선이 그어진다.

// Rectangle 함수와 Ellipse 함수느 둘 다 인수가 동일하다.
// Rectangle 함수는 지정한 두 점을 대각선으로 하는 사각형을 그리는데
// 도스와 달리 사각형의 내부만 채운다는 점을 조심해야 한다.
// Ellipse 함수는 지정한 사각형에 내접하는 타원을 그린다.