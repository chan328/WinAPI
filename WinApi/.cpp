// WMLKEYDOWN

// 키보드로 문자를 입력받고자 할 경우에는 WM_CHAR이란 메시지를 사용하면 된다.
// 그러나 문자 외의 키를 입력받기 위해서는 WM_CHAR으로는 안된다.
// 이때는 WM_KEYDOWN을 사용해야한다.

// WM_KEYDOWN 메시지는 wParam에 문자 코드가 아닌 가상 키코드라는 것을
// 전달해 준다. 가상 키코드란 시스템에 장착된 키보드의 종류에 상관없이
// 키를 입력받기 위해 만들어진 코드값이며 다음과 같이 정의되어있다.

/*
	VK_BACK
	VK_TAB
	VK_RETURN
	VK_SHIFT
	VK_CONTROL
	VK_MENU
	VK_PAUSE
	VK_CAPITAL
	....
*/