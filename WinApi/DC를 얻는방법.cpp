// DC를 얻는 방법
// 화면으로 출력을 하기 위해서는 반드시 DC가 있어야 하며
// DC를 얻는 방법에는 두가지 방법이 있다.
// GetDC함수를 사용해 DC를 사용 후 ReleaseDC로 해제하는 것이다.

HDC GetDC(HWND hWnd);
int ReleaseDC(HWND hwnd, HDC, hDC);

// DC는 주로 하나의 윈도우와 연관되는 출력정보를 가진다.
// 그래서 인수로 어떤 윈도우에 대한 DC가 필요한가를 밝혀주어야
// 한다. GetDC는 hWnd가 가리키는 윈도우에 대한 적당한 DC를 
// 만들어 그 핸들을 반납한다. 앞의 예제에서는 이 핸들을 HDC형의
// hdc 변우세 대입한 후 이 핸들값을 TextOut 함수의 첫 번째
// 인수로 사용하였다. GetDC에 의해 얻어진 핸들은 사용 후
// 반드시 ReleaseDC 함수에 의해 해체되어야 한다.

// DC를 얻는 두 번째 방법은 VM_PAINT 메시지 루틴에서만 사용할 수
// 있다. VM_PAINT 메시지 처리 루틴에서는 DC 핸들을 GetDC로 
// 얻지 않고 BeginPaint 함수로 얻으며 핸들을 해제할 때는 EndPaint
// 함수를 사용한다. 

HDC BeginPaint(HWND hwnd, LPPAINTSTRUCT ipPatin);
BOOL EndPaint(HWND hWnd, CONST PAINTSTRUCT *ipPaint);

// BeginPaint 함수는 윈도우 핸들 외에도 패인트 정보 구조체를 인수로
// 요구하며 이 구조체는 그림 그리기에 필요한 정보를 담는다.

typedef struct tagPAINTSTRUCT
{
	HDC hdc;
	BOOL fErase;
	RECT rePaint;
	BOOL fRestore;
	BOOL fincUpdate;
	BYTE rgbReserved[16];
} PAINTSTRUCT;