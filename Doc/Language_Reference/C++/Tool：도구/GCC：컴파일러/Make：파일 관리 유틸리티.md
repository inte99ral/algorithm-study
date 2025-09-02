# Make：파일 관리 유틸리티

## 목차

## 개요

&nbsp; make는 파일 관리 유틸리티 도구로 makefile 명칭이 붙은 기술파일에 적힌대로 컴파일러에 명령하여 SHELL 명령이 순차적으로 실행될 수 있게 합니다.

&nbsp; 장점으로는 tasks.json 매크로처럼 반복적 명령을 <u><b>자동화</b></u> 합니다. 또한 tasks.json 이 단순히 명령만 실행했던 것과 다르게 makefile 기술파일의 <u><b>가독성이 더 높고</b></u>, 무엇보다 강력한 기능은 자동으로 타임스탬프를 확인하여 수정 흔적이 있는 <u><b>특정 오브젝트 파일만 재컴파일</b></u> 하여 컴파일 시간을 단축시킬 수 있습니다.

&nbsp; 단점으로는 와일드카드처리는 가능하지만 <u><b>자체적으로는 정규표현식을 사용한 섬세한 작업은 불가</b></u>하므로 cmd 쉘의 도움을 받아야한다는 점, 컴파일하는 <u><b>환경마다 makefile 파일을 만들어서 설정</b></u>해주어야 한다는 점, 거기에다 이미 높은 학습곡선을 생각하면 tasks.json 에 cmd 쉘 사용법에 나아가 <u><b>make 도구 사용법을 추가로 학습</b></u>해야한다는 점이 있습니다.

## 문법

### 자동 변수

- [참고링크](https://www.gnu.org/software/make/manual/html_node/Automatic-Variables.html)

<table>
<tr>
  <th>자동 변수</th>
  <th>의미</th>
</tr>
<tr>
  <td align="center">

`%`

  </td>
  <td align="left">

&nbsp; 패턴규칙을 의미하는 문법입니다. <br/>
&nbsp; 예를 들어서 `%.o: %.cpp` 로 정의한 규칙이 있다면 example.o 로 끝나는 타겟에서는 example.cpp 를 찾아서 해당 규칙이 적용됩니다.

  </td>
</tr>
<tr>
  <td align="center">

`$@`

  </td>
  <td align="left">

&nbsp; 현재 규칙의 타겟(target) 파일 이름을 의미합니다.<br/>
&nbsp; 예를 들어 `%.o: %.cpp` 규칙에서 main.o 를 만들 때, `$@` 는 main.o 가 됩니다.

  </td>
</tr>
<tr>
  <td align="center">

`$*`

  </td>
  <td align="left">

&nbsp; 현재 규칙의 타겟(target) 파일 이름에서 확장자가 없는 이름을 의미합니다.<br/>
&nbsp; 예를 들어 `%.o: %.cpp` 규칙에서 main.o 를 만들 때, `$*` 는 main 이 됩니다.

  </td>
</tr>
<tr>
  <td align="center">

`$<`

  </td>
  <td align="left">

&nbsp; 현재 타겟의 의존성 중 첫 번째 파일을 의미합니다.<br/>
&nbsp; 예를 들어 `program: main.o hello.o` 에서 `$<` 는 main.o 가 됩니다.

  </td>
</tr>
<tr>
  <td align="center">

`$+`

  </td>
  <td align="left">

&nbsp; 현재 타겟의 모든 의존성들을 중복을 포함하여 공백으로 구분한 값입니다.<br/>
&nbsp; 여러 개의 의존 파일이 있을 때, 공백으로 구분된 전체 목록을 나타냅니다.<br/>
&nbsp; 예를 들어 `program: main.o hello.o` 에서 `$^`는 main.o hello.o main.o 가 됩니다.

  </td>
</tr>
<tr>
  <td align="center">

`$^`

  </td>
  <td align="left">

&nbsp; 현재 타겟의 모든 의존성들을 중복은 제외하고 공백으로 구분한 값입니다.<br/>
&nbsp; 여러 개의 의존 파일이 있을 때, 공백으로 구분된 전체 목록을 나타냅니다.<br/>
&nbsp; 예를 들어 `program: main.o hello.o main.o` 에서 `$^`는 main.o hello.o가 됩니다.<br/>
&nbsp; make 의 함수를 이용하여 `$(word 2, $^)` 이런 방법으로 특정 인덱스(저 경우 2번째 의존성) 의존성 값만 얻어낼 수도 있습니다.

  </td>
</tr>
</table>

### 특수 문법

<table>
<tr>
  <th>특수 문법</th>
  <th>의미</th>
</tr>
<tr>
  <td>
  
`dir 문자열`
  
  </td>
  <td>
  
&nbsp; 문자열에서 경로 부분만 추출합니다. <br/>
&nbsp; 예를 들어서 `dir src/example.cpp` 는 `src/` 가 됩니다.<br/>

  </td>
</tr>
<tr>
  <td>
  
`$(addsuffix 접미사, 문자열)`
  
  </td>
  <td>
  
&nbsp; 문자열의 뒤에 접미사를 붙입니다. <br/>
&nbsp; 예를 들어서 `$(addsufix  .c, memo  main)` 는 `memo.c   main.c` 가 됩니다.

  </td>
</tr>
<tr>
  <td>
  
`$(addprefix 접두어, 문자열)`
  
  </td>
  <td>
  
&nbsp; 문자열의 앞에 접두사를 붙입니다. <br/>
&nbsp; 예를 들어서 `$(addprefix src/, memo main)` 는 `src/memo   src/main` 가 됩니다.

  </td>
</tr>
<tr>
  <td>
  
`$(shell <shell-command>)`
  
  </td>
  <td>
  
&nbsp; shell 명령에 대한 결과값이 명령대체 됩니다. <br/>
&nbsp; 예를 들어서 `SH = $(shell ls *.c)` 이라고 하면 SH 변수에 .c 로 끝나는 파일들을 검색한 ls 명령 결과값이 입력됩니다.

  </td>
</tr>
<tr>
  <td>
  
`$(subst 찾을 문자, 변경할 문자, 대상 문자)`
  
  </td>
  <td>
  
&nbsp; "대상문자"에서 "찾을 문자"를 "변경할 문자"로 변경해 줍니다.<br/>
&nbsp; `$(subst /,\,$(dir $@))` cmd 와 unix-like 환경 사이에서 경로의 역슬래시와 슬래시를 바꾸는 것 또한 다음과 같이 쉽게 가능합니다.

  </td>
</tr>
<tr>
  <td>
  
`$(patsubst 찾을 패턴, 변경할 패턴, 대상 문자)`
  
  </td>
  <td>
  
&nbsp; subst와 기능은 동일하나 확장자를 바꿀때 사용합니다.

  </td>
</tr>
<tr>
  <td>
  
`$(strip 대상문자)`
  
  </td>
  <td>
  
&nbsp; 대상문자에서 모든 공백을 1칸으로 줄여줍니다. 여백이 많아도 모두 1칸으로 변경됩니다.

  </td>
</tr>
<tr>
  <td>
  
`$(filter 찾을 문자, 대상문자)`
  
  </td>
  <td>
  
&nbsp; 대상문자에서 찾을 문자를 포함한 문자들을 찾아서 저장합니다.

  </td>
</tr>
<tr>
  <td>
  
`$(filter-out 찾을 문자, 대상문자)`
  
  </td>
  <td>
  
&nbsp; filter와 반대로 찾을 문자가 있는 경우를 제외하고 저장합니다.

  </td>
</tr>
<tr>
  <td>
  
`$(join 원본문자, 붙일문자)`
  
  </td>
  <td>
  
&nbsp; 원본문자와 붙일문자를 붙여서 한 문자로 만듭니다.

  </td>
</tr>
<tr>
  <td>
  
`$(dir 대상문자)`
  
  </td>
  <td>
  
&nbsp; 대상문자에서 파일문자를 제외한 경로명만 추출합니다.

  </td>
</tr>
<tr>
  <td>
  
`$(notdir 대상문자)`
  
  </td>
  <td>
  
&nbsp; 대상문자에서 파일명만 추출합니다.

  </td>
</tr>
<tr>
  <td>
  
`$(baseanme 대상문자)`
  
  </td>
  <td>
  
&nbsp; 대상문자에서 확장자를 제외한 문자를 알려준다.

  </td>
</tr>
</table>

## 설치과정

### ③ Makefile Tools

&nbsp; make는 파일 관리 유틸리티 도구로 makefile 명칭이 붙은 기술파일에 적힌대로 컴파일러에 명령하여 SHELL 명령이 순차적으로 실행될 수 있게 합니다.

&nbsp; 장점으로는 tasks.json 매크로처럼 반복적 명령을 <u><b>자동화</b></u> 합니다. 또한 tasks.json 이 단순히 명령만 실행했던 것과 다르게 makefile 기술파일의 <u><b>가독성이 더 높고</b></u>, 무엇보다 강력한 기능은 자동으로 타임스탬프를 확인하여 수정 흔적이 있는 <u><b>특정 오브젝트 파일만 재컴파일</b></u> 하여 컴파일 시간을 단축시킬 수 있습니다.

&nbsp; 단점으로는 와일드카드처리는 가능하지만 <u><b>자체적으로는 정규표현식을 사용한 섬세한 작업은 불가</b></u>하므로 cmd 쉘의 도움을 받아야한다는 점, 컴파일하는 <u><b>환경마다 makefile 파일을 만들어서 설정</b></u>해주어야 한다는 점, 거기에다 이미 높은 학습곡선을 생각하면 tasks.json 에 cmd 쉘 사용법에 나아가 <u><b>make 도구 사용법을 추가로 학습</b></u>해야한다는 점이 있습니다.

#### Make 설치 및 확인

&nbsp; MSYS 쉘에서 다음의 명령어들을 통하여 MSYS 에 make 도구가 설치되어 있는지 확인할 수 있습니다.

```bash
# 다음 3가지 방법 중 하나로 확인이 가능합니다.
## 1) 설치된 make 가 있다면 그 버전 확인
make --version

## 2) 설치된 패키지 중에서 make 명령어로 호출되는 패키지 확인
pacman -Q | grep make

## 3) 설치된 패키지 중에서 다음의 패키지가 있는지 확인
pacman -Q mingw-w64-ucrt-x86_64-make
```

&nbsp; 위 명령어로 make 가 설치되어 있지 않은 상태라면 MSYS 쉘에서 다음의 명령어를 통하여 설치할 수 있습니다.

```bash
pacman -S mingw-w64-ucrt-x86_64-make
```

&nbsp; 파워쉘에서도 msys 의 bin 폴더가 환경변수 Path 에 연결되어 있다면 "mingw32-make.exe" 실행파일의 이름을 사용하여 다음과 같이 make 에 접근할 수 있습니다.

```powershell
mingw32-make --version
```

#### Makefile Tools 설치 및 확인

&nbsp; vscode 에서 Makefile Tools 확장 앱을 설치해주세요.

#### Make 사용

&nbsp; make 명령어를 실행하면, 현재 작업 디렉토리에 위치한 Makefile 관련 파일을 찾아서 파일 내부의 명령어를 기본 쉘(기본적으로는 윈도우 cmd) 에서 수행합니다.

&nbsp; Makefile 관련 파일은 파일명이 아래과 같은 파일들을 말합니다.

- GNUmakefile

- makefile

- Makefile

&nbsp; 위의 목록은 우선도 순으로 나열한 것으로, 만약 터미널이 작업하는 위치에 "GNUmakefile" 파일과 "Makefile" 파일이 동시에 있다면 "GNUmakefile" 파일이 선택됩니다.

#### Make 사용 > Makefile 파일 생성

&nbsp; vscode 에서 폴더에 우클릭 후 나오는 메뉴에서 `새 파일...` 을 클릭하여 확장자 없이 "Makefile" 이라는 이름의 파일을 만들어주세요.

&nbsp; 그 후, Makefile 파일에 다음의 내용을 작성해주세요.

```makefile
run0:
	@echo "hello, world 0"

run1:
	@echo "hello, world 1"
```

&nbsp; Make 도구는 Makefile 파일에 있는 문장을 다음과 같이 인식합니다.

```makefile
『타겟명칭 TARGET』: 『의존성 DEPENDENCY』
  『타겟호출시 실행명령 RECIPE』
```

지금 makefile 파일의 run0 를 예시로 설명하면, run0 타겟을 요청하면 이 타겟에 의존성(먼저 실행되는 것이 보장되어야 하는 것)은 없으며 hello, world0 을 출력하라는 것으로 make 는 이해합니다.

&nbsp; 변수도 변수명에 `:=` (단순 확장, Simple Expansion) 과 `=` (재귀적 확장, Recursive Expansion) 으로 값을 선언하는 것이 가능합니다. 단순 확장은 선언 시점에서 값이 결정됩니다. 이와 다르게 재귀적 확장은 다른 언어에서 마치 참조에 의한 호출처럼 변수값을 사용하는 시점에서 그 값이 무엇인지 결정됩니다.

&nbsp; 변수를 사용할 때는 $(『Variable』) 로 사용할 수 있으며 다음과 같은 자동 변수(automatic variables) 또한 사용할 수 있습니다.

<table>
<tr>
  <th>자동 변수</th>
  <th>의미</th>
</tr>
<tr>
  <td align="center">

`$@`

  </td>
  <td align="left">

현재 규칙의 타겟(target) 파일 이름을 의미합니다.<br/>
예를 들어 `%.o: %.cpp` 규칙에서 main.o 를 만들 때, `$@` 는 main.o가 됩니다.

  </td>
</tr>
<tr>
  <td align="center">

`$+`

  </td>
  <td align="left">

현재 타겟의 모든 의존성들을 중복을 포함하여 공백으로 구분한 값입니다.<br/>
여러 개의 의존 파일이 있을 때, 공백으로 구분된 전체 목록을 나타냅니다.<br/>
예를 들어 `program: main.o hello.o main.o` 에서 `$^`는 main.o hello.o main.o가 됩니다.

  </td>
</tr>
<tr>
  <td align="center">

`$^`

  </td>
  <td align="left">

현재 타겟의 모든 의존성들을 중복은 제외하고 공백으로 구분한 값입니다.<br/>
여러 개의 의존 파일이 있을 때, 공백으로 구분된 전체 목록을 나타냅니다.<br/>
예를 들어 `program: main.o hello.o main.o` 에서 `$^`는 main.o hello.o가 됩니다.<br/>
make 의 함수를 이용하여 `$(word 2, $^)` 이런 방법으로 특정 인덱스(저 경우 2번째 의존성) 의존성 값만 얻어낼 수도 있습니다.

  </td>
</tr>
<tr>
  <td align="center">

`$<`

  </td>
  <td align="left">

현재 타겟의 의존성 중 첫 번째 파일을 의미합니다.<br/>
예를 들어 `%.o: %.cpp` 규칙에서 main.o를 만들 때, `$<` 는 main.cpp가 됩니다.

  </td>
</tr>
</table>

```makefile
# Makefile
## Variable
TEMP = 1
RUN0NUM = $(TEMP)
RUN1NUM := $(TEMP)
TEMP = 0

run0:
	@echo "hello, world $(RUN0NUM)"

run1:
	@echo "hello, world $(RUN1NUM)"
```

&nbsp; 이제 vscode 의 터미널을 열어주세요. 다음의 두 가지 방법 중 하나를 선택하시면 됩니다.

- 최상단 메뉴바에 `터미널(T)` 를 누르고 `새 터미널` 선택
- 또는, `` ctrl + shift + ` `` 단축키 입력하기

&nbsp; 터미널에서 `mingw32-make run1` 라고 입력하면 "hello, world 1" 가 출력됩니다.

&nbsp; 또한, 터미널에서 `mingw32-make run0` 또는 `mingw32-make` 라고 입력하면 "hello, world 0" 가 출력됩니다. 가장 먼저 선언된 run0 명령어가 자동으로 디폴트로 취급되기 때문입니다.

&nbsp; 가끔 자동적인 디폴트 설정에서 원치 않는 동작을 하거나 변수명과 폴더명의 겹치는 상황 등으로 인하여 불안정한 동작을 할 수 있습니다.

&nbsp; 다음 두가지 방법을 사용하면 안정적으로 동작시킬 수 있습니다.

- `.PHONY` 는 다음에 오는 명령어가 파일 이름이나 타겟 이름이 겹치는 상황이어도 충돌 방지하여 이것이 실제 파일 이름이 아니라 거짓된 타겟 이름이라는 것을 확실시합니다.
- `default` 는 별도의 타겟 호출이 없이 make, mingw32-make 명령어만 입력시에 구동하는 디폴트 타겟이 무엇인지를 확실시합니다.

```bash
# Makefile
## Default Setting
.PHONY: default
default: run1

## Variable
TEMP = 1
RUN0NUM = $(TEMP)
RUN1NUM := $(TEMP)
TEMP = 0

run0:
	@echo "hello, world $(RUN0NUM)"

run1:
	@echo "hello, world $(RUN1NUM)"
```

위 명령어로 명확하게 디폴트가 run1 이기 때문에 `mingw32-make` 입력시 "hello, world 1" 이 출력됩니다.

#### Make 사용 > 컴파일 예시

&nbsp; vscode 에서 폴더에 우클릭 후 나오는 메뉴에서 `새 파일...` 을 클릭하여 "Main.cpp" 이라는 이름의 파일을 만들고 다음과 같이 코드를 작성해주세요.

```cpp
#include <iostream>
int main () {
  std::cout << "\"Hello, world\" from c++";
  return 0;
}
```

&nbsp; vscode 에서 폴더에 우클릭 후 나오는 메뉴에서 `새 파일...` 을 클릭하여 확장자 없이 "Makefile" 이라는 이름의 파일을 만들고 다음과 같이 코드를 작성해주세요.

```makefile
.PHONY: default
default: run

run:
	g++ Main.cpp -o Main.exe
```

&nbsp; vscode 의 터미널을 열어주세요. 다음의 두 가지 방법 중 하나를 선택하시면 됩니다.

- 최상단 메뉴바에 `터미널(T)` 를 누르고 `새 터미널` 선택
- 또는, `` ctrl + shift + ` `` 단축키 입력하기

&nbsp; 터미널에서 `mingw32-make` 라고 입력하면 Main.exe 가 생성됩니다.

&nbsp; 터미널에서 `./Main.exe` 라고 입력하면 ""Hello, world" from c++" 가 출력됩니다.

#### Make 사용 > 컴파일 표준

다음과 같은 포맷이 파일을 빌드할 때 사용되는 makefile 의 스탠다드 형태입니다.

```makefile
# Makefile
## Default Setting
### .PHONY 타겟 선언 (실제 파일과 구분)
.PHONY: default all run clean

### 기본 타겟 설정
default: run


## Variable
### 컴파일러 선택
CXX      := g++

### 컴파일러 옵션
CXXFLAGS := -Wall -Wextra -Werror -std=c++11 -g

### 소스 파일
SRC      := Main.cpp

### 오브젝트 파일(example0.cpp example1.cpp -> example0.o example1.o 를 의미하는 문법입니다.)
OBJ      := $(SRC:.cpp=.o)

### 실행 파일 이름
OUTPUT   := outputfile


## Target
### 기본 타겟: 실행 파일 생성
all: $(OUTPUT)

### 실행 파일 빌드
$(OUTPUT): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $^

#### 오브젝트 파일 생성(패턴규칙을 의미하는 문법입니다. .o 로 끝나는 타겟에 전부 적용됩니다.)
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

### 실행 파일 실행
run: all
	./$(OUTPUT)

### 오브젝트 파일 및 실행 파일 삭제
clean:
	rm -f $(OBJ) $(OUTPUT)
```

#### Make 사용 > tasks.json 생성

&nbsp; mingw32-make 라는 터미널 명령어로 실행이 가능하므로 make 작업에도 tasks.json 매크로를 적용할 수 있습니다.

&nbsp; vscode 프로그램 전역에 설정을 적용할 것 인지, 지금 작업중인 폴더에만 적용할 것인지에 따라서 다음의 두 가지 방법 중에서 하나를 선택해서 따라주세요.

- vscode 전체에 적용하기

  - ① `Ctrl+Shift+P` 또는 `F1` 을 눌러 명령 팔레트를 엽니다.
  - ② `> Tasks: Open User Tasks` 검색을 통해 해당 목록을 선택해주세요.
  - ③ `Others` 를 선택해주세요.
  - 가장 기본 형태의 tasks.json 템플릿이 "C:\Users\ ... \AppData\Roaming\Code\User" 경로에 생성됩니다.

- 작업중인 폴더에만 한정해서 적용하기

  - ① `Ctrl+Shift+P` 또는 `F1` 을 눌러 명령 팔레트를 엽니다.
  - ② `> Tasks: Configure Task` 검색을 통해 해당 목록을 선택해주세요.
  - ③ `템플릿에서 tasks.json 파일 만들기(Create tasks.json file from template)` 검색을 통해 목록을 선택해주세요.
  - ④ `Others` 를 선택해주세요.
  - 가장 기본 형태의 tasks.json 템플릿이 지금 작업 중인 최상위 폴더의 ".vscode/" 라는 vscode 설정 폴더 안에 생성됩니다.

#### Make 사용 > tasks.json 설정

- [참조링크](./Doc/Language_Reference/C++/GCC：컴파일러/Makefile：컴파일 환경 관리.md)

- tasks.json 에 다음과 같이 입력합니다.

  ```json
  {
    "version": "2.0.0",
    "tasks": [
      {
        "label": "Makefile Build",
        "type": "shell",
        "command": "mingw32-make",
        "args": [],
        "group": {
          "isDefault": true,
          // "isDefault": false,
          "kind": "build"
        },
        "options": {
          "cwd": "${fileDirname}"
        },
        "problemMatcher": []
      }
    ]
  }
  ```
