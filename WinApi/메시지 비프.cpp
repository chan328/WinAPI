// 문자열이나 그래픽, 메시지 상자처럼 간단한 출력도 있지만
// 비프음을 내는 들리는 종류의 출력도 있다.

BOOL MessageBox(UINT uType);

/*
	OXFFFFFFFF - PC의 스피커를 통해 음을 낸다.
	MB_ICONASTERISE - Asterisk 비프음
	MB_ICONEXCLAMATION - Exclamaition 비프음
	MB_ICONHAND - Hand 비프음.
	MB_ICONQUESTION - Question 비프음/
	MB_OK - 시스템 디폴트 비프음.
*/