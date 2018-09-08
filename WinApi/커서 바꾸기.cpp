// 커서 바꾸기

// 예제의 윈도우위에 마우스 커서를 위치시키면 화살표 모양의 커서가 나타난다.
// 이 커서가 사용되는 이유는 WndClass에서 커서를 지정하는 멤버가 다음과 같이 정의되있기 때문이다.

WndClass.hCursor = LoadCursor(NULL, IDC_ARROW);

// HCURSOR LoadCursor(HINSTANCE hinstance, LPCTSTR ipCursorName);
// 첫 번째 인수인 hinstance는 커서를 가지고 있는 프로그램의 인스턴스 핸들이며 윈도우가 제공하는
// 디폴트 커서를 사용하면 이 값을 NULL로 해주면 된다.
// 윈도우즈가 디폴트로 제공하는 커서는 다음과 같은 종류가 있다.

/*
IDC_ARROW - 화살표 모양
IDC_CROSS - 십자 모양
IDC_IBEAM - I자 모양
IDC_NO - 원안에 빗금이 쳐진 모양
IDC-WAIT - 모래시계 모양
*/