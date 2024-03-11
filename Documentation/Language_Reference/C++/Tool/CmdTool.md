# CmdTool

## 선언부

```cpp
#ifndef CMD_TOOL_HPP
#define CMD_TOOL_HPP

// color상수 지정 #define BLACK 0 #define BLUE 1 #define GREEN 2 #define CYAN 3 #define RED 4 #define MAGENTA 5 #define BROWN 6 #define LIGHTGRAY 7 #define DARKGRAY 8 #define LIGHTBLUE 9 #define LIGHTGREEN 10 #define LIGHTCYAN 11 #define LIGHTRED 12 #define LIGHTMAGENTA 13 #define YELLOW 14 #define WHITE 15 

#include <windows.h>

// Prototype Declaration ====================
// CmdTool ======================
class CmdTool {
 private:

 public:
  void setTextColor(int foreground, int background);
};
#endif
```

## 구현부

```cpp
#include "CmdTool.hpp"

// Implements Definition ====================
// CmdTool ======================
void setTextColor(int foreground, int background) {
  int color = foreground + background * 16;
  SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}
```
