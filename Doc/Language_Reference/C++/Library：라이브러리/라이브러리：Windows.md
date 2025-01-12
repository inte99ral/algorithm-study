# 라이브러리：Windows

## 개요

### 화면

#### 화면 지우기

- [system("cls")는 좋은 방법이 아니다](https://cplusplus.com/forum/articles/10515/)

```cpp
#include <conio.h>
#include <iostream>
#include <stdlib.h> // * NEEDED
#include <Windows.h>

using namespace std;

void setCursorPos(int Y, int X) {
  COORD Pos;
  Pos.Y = Y;
  Pos.X = X;
  SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}

int main() {
	system("cls"); // * WINDOW SHELL CLEAR
	system("color B4");

	while(1) {

		int Y, X;
		cout << "Input Y:\nInput X:";
		setCursorPos(0, 10);
		cin >> Y;
		setCursorPos(1, 10);
		cin >> X;

		if(Y < 2) Y = 2;

		system("cls"); // * WINDOW SHELL CLEAR
		setCursorPos(Y, X);
		cout << "┌ ┬ ┐";
		setCursorPos(Y + 1, X);
		cout << "├─┼─┤";
		setCursorPos(Y + 2, X);
		cout << "└ ┴ ┘";
		setCursorPos(0, 0);
	}

	return 0;
}
```

#### 색상

##### Windows.h SetConsoleTextAttribute 에서 바꾸기

```cpp
#include<iostream>
#include<Windows.h>

using namespace std;

int main() {
  // * 숫자 직접 기입 Using Number Directly
  for (int k = 1; k < 255; k++){
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), k);
    cout << k << "The Quick Brown Fox Jumps Over The Lazy Dog" << endl;
  }

  // * 미리 정의된 매크로 Using Predefined-macros
  SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_BLUE | BACKGROUND_GREEN);
	cout << "The Quick Brown Fox Jumps Over The Lazy Dog\n";

	return 0;
}
```

##### System 에서 바꾸기

```cpp
#include<iostream>

using namespace std;

int main() {
	system("color B4");

	// "color <background><foreground>"
	// For background and foreground, type in a number from 0 - 9 or a letter from A - F.
	// 0 = 검은색  8 = 회색
  // 1 = 파란색  9 = 연한 파란색
  // 2 = 녹색    A = 연한 녹색
  // 3 = 청록색  B = 연한 청록색
  // 4 = 빨간색  C = 연한 빨간색
	// 5 = 자주색  D = 연한 자주색
  // 6 = 노란색  E = 연한 노란색
  // 7 = 흰색    F = 밝은 흰색

	cout << "TEST\n";

	// * 설명서 출력
	system("color %");
	return 0;
}
```

### 커서

#### 커서 크기 및 가시성 조정

```cpp
#include<iostream>
#include<Windows.h>

using namespace std;

void setCursor(bool isVisible, int size) {
	CONSOLE_CURSOR_INFO cursorInfo = { 0, };
	cursorInfo.dwSize = size; // 커서 굵기 % 비율 {1 ~ 100}
	cursorInfo.bVisible = isVisible; // 커서 보이게 할지 말지 {TRUE(보임) | FALSE(숨김)}
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);
}

int main()
{
	int key;
	bool visibility=true;
	int cursorSize = 50;

	while (key != 5) {
		system("cls");
		cout << "┌────────────────────────────────────────────────┐\n";
		cout << "│ 1. 커서 보임　　　　　　                       │\n";
		cout << "│ 2. 커서 안 보임　　　　　                      │\n";
		cout << "│ 3. 커서 작게(to 1%)　　　　　　                │\n";
		cout << "│ 4. 커서 크게(to 100%)　　　　　　              │\n";
		cout << "│ 5. 종료　　　　　　　　                        │\n";
		cout << "└────────────────────────────────────────────────┘\n";
		cout << "메뉴를 고르세요 : ";

		cin >> key;

		switch (key) {
			case 1:
				visibility = true;
			 	break;
			case 2:
				visibility = false;
				break;
			case 3:
				cursorSize = 1;
				break;
			case 4:
				cursorSize = 100;
				break;
			case 5:
				break;
		}

		setCursor(visibility, cursorSize);
	}
	return 0;
}
```

#### 커서 위치 변경

### 콘솔 입력 및 출력：GetAsyncKeyState

```cpp
#include <Windows.h>
#include <conio.h>
#include <iostream>

#define KEY_DOWN(vk_code) ((GetAsyncKeyState(vk_code) & 0x8000) ? 1 : 0)
#define KEY_UP(vk_code) ((GetAsyncKeyState(vk_code) & 0x8000) ? 0 : 1)

using namespace std;

const char *SYSTEM_SETTING = "mode con: cols=100 lines=100 | title Cpp-Platformer v0.1";
const int MAX_Y = 50;
const int MAX_X = 50;

int characterY = 0;
int characterX = 0;

int getKeyDown() {
  if (_kbhit() == 0) return 0;  // 입력감지

  if (KEY_DOWN(VK_LEFT)) {
    if (characterX > 0)
      characterX--;
  }
  if (KEY_DOWN(VK_RIGHT)) {
    if (characterX < MAX_X)
      characterX++;
  }
  if (KEY_DOWN(VK_UP)) {
    if (characterY > 0)
      characterY--;
  }
  if (KEY_DOWN(VK_DOWN)) {
    if (characterY < MAX_Y)
      characterY++;
  }

  return _getch();
}


int main() {
  while(true) {
    int input = getKeyDown();
    if(input) cout << input << endl;
  }

  return 0;
}
```
