// DrawText

int DrawText(HDC, hDC, LPCTSTR ipstring, int nCount, LPRECT ipRect, UINT uFormat);
// 이 함수는 사각영역을 정의하여 영역안에 문자열을 출력할 수 있으며
// 여러가지 포멧을 설정할 수 있는 기능이 있다. 윈도우즈에서 사각 영역을 정의할 때는 RECT구조체를 사용해
// 다음과 같이 정의되어 있다.

typedef struct _RECT {
	LONG left;
	LONG top;
	LONG right;
	LONG bottom;
}RECT;

// DrawText의 4 번째 인수는 이 구조체의 포인터이며 문자열이 출력될
// 사각 영역을 지정한다. 
// 첫 번째 인수는 물론 hdc이며
// 두 번째 인수가 출력할 문자열
// 세 번째 인수는 출력할 문자열의 길이이되 -1이면 널 종료 문자열로 간주.
// 다섯 번째 인수 uFormat은 DrawText 함수가 문자열을 출력할 방법을 지정하는 플래그이다.

/*
	DT_LEFT - 수평 왼쪽 정렬을 한다.
	DT_RIGHT - 수평 오른쪽 정렬을 한다.
	DT_CENTER - 수평 중앙 정렬한다.
	DT_BOTTOM - 사각 영역의 바닥에서 문자열을 출력한다.
	DT_VCENTER - 사각 영역의 수직 중앙에 문자열을 출력한다.
	DT_WORDBREAK - 사각형역의 오른쪽 끝에서 자동개행
	DT_SINGLELINE - 한줄로 출력
	DT_NOCLIP - 사각 영역의 경계를 벗어나도 문자열을 자르지 않고 그대로 출력.

*/