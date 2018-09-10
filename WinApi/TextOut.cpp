// TextOut
// 데이터를 가공하여 결과를 보여주어야 하는 일이 프로그램의
// 당연한 임무라고 할 때 외부로부터 데이터를 받아들이는 
// 입력(input)과 외부로 보여주는 출력(output)은 가장 기본적이다.

BOOL TextOut(hdc, nXStart, nYStart, lpszString, cbString);

// 첫 번째 인수는 DC의 핸들인 hdc이다. 이 함수뿐만이 아니라
// 화면에 무엇인가를 출력하는 모든 함수들의 처음은 무조건
// hdc이다. 이 DC는 GetDC나 BeginPaint 함수에 의해 구해졌을 것이다.
// (nXStart, nYStart)는 문자열이 출력될 좌표이며 lpszStirng이
// 출력할 문자열을 담고 있는 문자열 포인터이며 cbString이 
// 출력할 문자열의 길이이다. TextOut 함수는 널종료 문자열을
// 사용하지 않으므로 문자열의 길이를 인수로 반드시 밝혀주어야 한다.

TextOut(hdc, 100, 100, "Beautiful Korea", 15);

// 이 호출문은 뷰티풀 코리아라는 15자 길이의 문자열을 100, 100좌표에 출력하되
// 출력에 필요한 모든 정보들은 모두 hdc에서 지정하는 정보를 가용하라는
// 뜻이다.

UINT SetTextAlign(HDC hdc, UINT fMode);

// 이 함수도 첫 번째 인수로 DC의 핸들 hdc를 받아들인다. 
// 두 번째 인수인 fMode가 지정하는 정렬 정보에 따라 hdc의
// 정렬 상태를 변경하게 되며 이후로부터 hdc를 참조하여 출력되는
// 모든 문자열은 이 함수가 지정한 정렬상태를 따르게 된다.
// fMode의 값은 다음과 같으며 두 개 이상의 플레그를 OR로 연결하여
// 사용한다.

/*
	TA_TOP - 지정한 좌표가 상단좌표가 된다.
	TA_BOTTOM - 지정한 좌표가 하단 좌표가 된다.
	TA_CENTER - 지정한 좌표가 수평 중앙 좌표가 된다.
	TA_LEFT - 지정한 좌표가 수평 왼쪽 좌표가 된다.
	TA_RIGHT - 지정한 좌표가 수평 오른쪽 좌표가 된다.
	TA_UPDATECP - 지정한 좌표대신 CP를 사용하며 문자열 출력 후
	Cp를 변경한다.
	TA_NOUPDATACP - CP를 사용하지 않고 지정한 좌표를 사용하며 CP를 
	변경하지 않는다.
*/