// 배경색 바꾸기.
// 예제의 배경이 흰색인 이유는 WndClass에 있는 멤버중 배경색상을 지정하는
// hbrBackground가 흰색 브러시로 지정되있기 때문.

WndClass.hbrBackground = GetStockObject(WHITE_BRUSH);

// 위 코드에서 WHITE_BRUCH를 BLACK_BRUCH로 변경하면 검정색이 배경색으로 사용되고
// LTGRAY_BRUCH로 변경하면 옅은 회색 배경이 만들어진다.