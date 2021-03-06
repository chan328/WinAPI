// DC란 Device Context라고 한다.

// 윈도우는 세 가지 동적 연결 라이브러리로 구성되어 있는데 메모리를 관리하고
// 프로그램을 실행시키는 커널, 인터페이스와 윈도우를 관리하는 USER,
// 그리고 화면처리와 그래픽을 담당하는 GDI(Graphic Device Interface)
// 등이 있다.

// DC란 출력에 필요한 모든 정보를 가지는 데이터 구조체이며 GDI 모듈
// 에 의해 관리된다. 어떤 폰트를 사용할 것인가, 선의 색상과 굵기,
// 채움 무늬와 색상, 출력 방법 등등이 모두 출력에 필요한 정보들이다.
// 화면 출력에 DC가 필요한 이유를 이해하기 위해 몇가지 예를 보자.

// 상황 1
// 화면에 선을 긋는 LineTo라는 함수를 생각해 보자. 선을 긋기 위해서
// 시작점과 끝점이 필요하다. 그러면 LineTo(X1, Y1, X2, Y2)
// 와 같이 함수를 호출하여 선을 그을 수 있을것이다.
// 그러나 저 정보말고도 여러가지 정보가 더 필요하다. 선의 색상, 굵기 등등
// 이런 정보들을 모두 인수로 넘겨준다면 LineTo 함수는 다음과 같은
// 모양이 될것이다.

LineTo(StartX, StartY, EndX, EndY, Color, Width, Shape, ROP, mode...);

// 사실 선을 긋기 위해서는 더 많은 정보가 필요하지만 일일이 인수로
// 전달할 것이 아니라 모아서 사용하는 것이 더 효율적이다.
// 그래서 이런 정보들을 모아서 DC라는 것을 만들고 그리기 함수에서는
// DC의 핸들만을 넘겨받아 그리기에 필요한 추가 정보들은 모두 DC에
// 정의되어 있는 값을 사용한다. 이런 방식을 사용하면 다음과 같이 사용할 수 있다.

LineTo(hDc, X, Y);

//상황 2
// DC가 또 필요한 예를 찾아보면, 윈도우는 여러개의 프로그램이 동시에
// 실행되는 멀티 태스킹 시스템이기 때문에 그리기 함수에 의해 실제
// 출력되는 모양은 주변환경에 따라 다르다. LineTo(hDC, 100, 100)
// 라는 명령을 내릴 때 화면상의 (100, 100)의 실제 화면상의 좌표는
// 알지 못하지만 DC에 의해 정확한 위치를 지정할 수 있게 된다.