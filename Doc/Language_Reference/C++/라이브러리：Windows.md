# 라이브러리：Windows

## 개요

### 커서

```cpp
void setCursor() {
  CONSOLE_CURSOR_INFO cursorInfo = {
      0,
  };
  cursorInfo.dwSize = 1;        // 커서 굵기 (1 ~ 100)
  cursorInfo.bVisible = false;  // 커서 Visible TRUE(보임) FALSE(숨김)
  SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);
}
```

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
