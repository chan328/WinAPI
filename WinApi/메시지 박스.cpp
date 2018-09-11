// 메시지 박스
// 메시지 박스는 조그만 별도의 윈도우를 열어 사용자에게 정보를 전달하거나
// 질문을 하는 장치이며 MessageBox 함수 호출 한번으로 간단히 만들 수 있다.

int MessageBox(HWND hWnd, LPCTSTR ipText, LPCTSTR ipCaption, UINT uType);

// 첫 번째 인수 hWnd는 메시지 박스의 오너 윈도우다.
// 오너 윈도우란 메시지 상자를 소유한 윈도우를 말하며 메시지 박스는 오너 윈도우의 정중앙에 나타난다.
// 메시지 박스가 떠있는 동안 오너 윈도우는 사용할 수 없다.
// 두 번째 인수 ip Text는 메시지 박스에 출력한 문자열이며
// 세 번째 인수 ipCaption은 메시지 상자의 타이틀 바에 나타날 제목 문자열입니다.
// 네 번째 인수 uType는 메시지 상자에 어떤 종류의 버튼이 나타날 것인가를 지정하는 여러가지 플레그들이다.

/*	uType의 종류들
	
	MB_ABORTRETRYIGNORE - Abort, Retry, Ignore 세 개의 버튼이 나타난다.
	MB_OK - OK 버튼 하나만 나타난다.
	MB_OKCANCLE - OK + Cancle
	MB_RETRYCANCLE - RETRY + CANCLE
	MB_YESNO - YES + NO
	MB_YESNOCACLE - YES + NO + CANCLE
*/

// 전달사항을 단순히 전달하는 용도 외에 사용자에게 질문을 하고 대답받는 용도로 사용 가능하다.
/* 
	IDABORT - Abort버튼을 눌렀다.
	IDCANCLE - Cancle 버튼을 눌렀다.
	IDIGNORE - Ignore 버튼을 눌렀다.
	IDNO - No 버튼을 눌렀다.
	IDOK - OK 버튼을 눌렀다.
	IDRETRY - Retry 버튼을 눌렀다.
	IDYES - Yes 버튼을 눌렀다.
*/

// ex) 사용자에게 게임을 계속할 것인가 물을 때
if (MessageBox(hWnd, "게임을 계속 하실건가요?", "질문", MB_YESNO) == IDYES)
{
	// 게임 계속처리
}
else {
	// 게임 종료
}