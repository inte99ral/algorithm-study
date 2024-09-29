# Windows에서 Visual Studio Code로 C++ 개발환경 구축하기

## -1. 참고자료

[참고링크](https://basiclike.tistory.com/360)

- zip파일 바로 적용 https://sooseongcom.com/post/MinGW-w64-HowToInstall
- mingw 종류 설명 https://blog.naver.com/webos21/196800460
- mingw 종류 세부설명 및 추천 https://klutzy.github.io/blog/2015/03/05/mingw/

## 목차

```markdown
1. 서문
```

## 0. 서문

0. 서문에서는 입문자들에게 다음의 설명을 합니다.

- C++ 환경을 구현할 이유
-

## 1. 서문

- vscode 를 써야하는 이유

## 2. visual studio code 설치

## 3. 컴파일러 설치

GCC vs LLVM/Clang
각 리포지토리에 있는 모든 패키지를 빌드하는 데 사용되는 기본 컴파일러/툴체인입니다.

GCC 기반 환경:

현재 널리 테스트/사용됨
포트란 지원
MINGW 환경에도 Clang 패키지가 존재하지만, 이 패키지는 여전히 GNU 링커와 GNU C++ 라이브러리를 사용합니다. 예를 들어 업스트림에서 GCC보다 Clang을 선호하는 경우 Clang을 사용하여 패키지를 빌드하는 경우도 있습니다.
LLVM/Clang 기반 환경:

LLVM 도구만 사용하며, 링커로 LLD, C++ 표준 라이브러리로 LIBC++를 사용합니다.
Clang은 ASAN 지원 제공
TLS(Thread-local storage) 네이티브 지원
LLD는 LD보다 빠르지만 LD가 지원하는 모든 기능을 지원하지는 않습니다.
일부 도구는 동등한 GNU 도구와 기능 패리티가 부족합니다.
Microsoft Windows 10에서 ARM64/AArch64 아키텍처 지원

- GCC
  GNU Compiler Collection, GCC

GNU 프로젝트의 오픈 소스 컴파일러 컬렉션. 유닉스/리눅스 계열 플랫폼의 사실상 표준 컴파일러다. 리처드 스톨먼이 1987년에 만들었다.

처음에는 C 컴파일러였으며 'GNU C Compiler'의 약어였다. 하지만 기능이 추가되면서 C++ 같은 다른 언어도 지원하게 되었고, 'GNU Compiler Collection'으로 이름을 변경하였다. 물론 약어는 여전히 GCC이다. 공식적으로 지원하는 언어는 C(gcc), C++(g++), Objective-C(gobjc), Fortran(gfortran), Ada(gnat), Go(gccgo), D(gdc)이다. Java(gcj)는 GCC 7.1 버전부터 지원이 중단되었다. GNU 진영에서는 GCC로 컴파일을 하고 Make를 이용해 빌드하는 것이 일반적이다.

원래는 C로 구현되었으나 2013년에 구현 언어를 C++로 모두 변경하였다. # 만들어진지 수십년 된 컴파일러라 최적화는 매우 잘 되어 있지만, 기존 코드의 구조가 시대적 한계로 인해 오늘날 관점에서는 상당히 더러워서 신규 인력이 거의 유입되지 않았기 때문이다.

- MinGW

MinGW(Minimalist GNU for Windows)라는 윈도우용 포크도 존재하여 여러 오픈 소스 프로그램들을 윈도우에서 돌아가게 하는 데 일조하고 있다.

MinGW는 MSYS와의 결합으로 구동된다. MSYS는 Minimal SYStem의 약자로, 윈도우에서 유닉스의 터미널 환경을 제공해 주며 이를 통해 MinGW와 GCC를 설치하는 것이다. MSYS와 비슷한 형태를 가진 Cygwin은 단순 터미널이 아닌 일종의 가상머신으로, 윈도우 위에 POSIX 레이어를 새로 얹어 상당히 무거운 반면 MinGW는 POSIX 호환성을 포기한 대신 윈도우 환경과 네이티브로 연결되기 때문에 더 빠른 성능을 제공한다. 이런 이유로 유닉스에서 POSIX API를 이용하는 소스 코드를 작성했을 경우 MinGW로는 컴파일이 불가능하다. Windows 10 Anniversary Update에서는 WSL(Windows Subsystem for Linux)이라는 이름으로 리눅스 API가 윈도우 커널 내부에 직접 탑재되었으므로, 윈도우에서 POSIX 환경을 이용하고 싶다면 WSL을 이용하면 된다.

기존의 MSYS 1.0은 32비트 운영체제만 지원한다는 문제점이 있었는데, 이에 따라 MSYS2 기반의 MinGW-w64가 제작되어 64비트 윈도우 환경을 지원하게 되었다. 참고로 윈도우 환경에서의 GCC는 기존의 유닉스, 리눅스용 GCC와 동일하게 작동하지 않는 경우가 있다. 와이드바이트 관련 예약어나 함수(wchar_t, wprintf(), wcstok() 등)가 대표적인 예.

윈도우 파일 입출력 시 파일을 제대로 읽지 못하는 등의 문제가 있고, Visual Studio에서만 쓰이는 비표준 확장 함수도 제공하고 있기 때문에 C/C++ 입문자에게는 권장할 만한 것이 못 된다는 의견이 있으나, 이는 MS Windows의 로캘 문제에서 비롯된다. Windows의 경우 Windows 10 RS5에 표준 로캘을 UTF-8로 사용하는 옵션[1]이 베타로 추가되어 있으나 이 옵션은 기본값이 아니기에 전역 시스템 로캘은 별도로 설정된 로캘을 따르게 된다. Windows에서 유니코드 Aware한 프로그램을 작성하는 경우 기본적으로 wchar_t 와 같은 와이드바이트 형식 (Windows 에서는 UTF-16)을 사용하게 되며, 기본적으로는 시스템의 MBCS를 따르게 되어 일반적인 방법으로는 파일에 접근하는 방법이 전무하다. C의 fopen()의 프로토타입은 const char\* 형식만 존재하고 이는 MBCS를 따르기 때문에 로캘에서 벗어나는 파일명은 접근할 수 없다. MSVC의 경우 비표준 함수인 const wchar_t 오버라이드를 제공하고 있으나, 표준이 아닌 관계로 libc를 사용하는 GCC의 경우 이러한 파일에 접근할 수 있는 방법이 CreateFileW()와 같은 OS 자체의 API를 사용하는 것 이외에는 방법이 존재하지 않는다. 또한 콘솔의 wprintf() 또한 콘솔의 기본값은 역시나 시스템 로캘을 따르며 이 또한 로캘을 벗어나는 문자열의 정상적인 출력을 위해서는 WriteConsoleW()를 사용하여야 하는 등, Windows가 사용하는 MBCS의 문제점이지 MSYS 환경의 문제점이 아니다.

Cygwin의 기능은 WSL로 확실히 대체되었지만, MinGW는 윈도우 환경을 그대로 유지하되 리눅스 명령어만 사용해야 할 경우[2] 유용하게 쓰일 수 있어 여전히 필요성이 있는 소프트웨어이다.

### 3 > 설치과정

[공식 사이트](https://www.mingw-w64.org/)

minGW 의 패키지 구분은 3단계로 나뉘어집니다.

쓰레드 모델에 따라 posix 인지 win32인지, 예외처리에서 sjlj 인지 seh 인지에 따라 갈립니다.

### 3 > 간단 설명

ucrt-x86_64-posix-seh 다운로드 받으시면 됩니다.

### 3 > 상세 설명

#### Runtime：`MSVCRT` vs `UCRT`

C 표준 라이브러리에는 두 가지 변형이 있습니다.

##### ◎ Runtime > 단순 설명

[MSVCRT vs UCRT](https://wikidocs.net/219735)
어찌보면 msvcrt와 ucrt는 항상 ucrt를 사용하므로 동의어입니다.

[설명](https://forums.swift.org/t/proper-support-for-msvcrt-linkage/24423)
MSVCRT (Microsoft Visual C Runtime)

[설명](https://lifeisforu.tistory.com/310)
Universal CRT

Microsoft Windows의 C 표준 라이브러리에는 두 가지 변형이 있습니다.

MSVCRT(Microsoft Visual C++ Runtime)는 모든 Microsoft Windows 버전에서 기본적으로 사용할 수 있지만, 이전 버전과의 호환성 문제로 인해 C99와 호환되지 않으며 일부 기능이 누락되어 있습니다.

예를 들어 printf() 함수군과 같이 C99와 호환되지는 않지만...
mingw-w64는 많은 경우 C99와 호환되도록 대체 함수를 제공합니다.
UTF-8 로케일을 지원하지 않습니다.
내부 구조와 데이터 유형이 다르기 때문에 MSVCRT와 연결된 바이너리를 UCRT와 혼합해서는 안 됩니다. (더 엄밀히 말하면, 서로 다른 타깃용으로 빌드된 객체 파일이나 정적 라이브러리를 혼합해서는 안 됩니다. 서로 다른 CRT용으로 빌드된 DLL은 DLL 경계를 넘어 CRT 객체(예: FILE\*)를 공유하지 않는 한 혼합할 수 있습니다. MSVC 컴파일된 바이너리에도 동일한 규칙이 적용되는데, MSVC는 기본적으로 UCRT를 사용하기 때문입니다(변경하지 않은 경우).
모든 버전의 Microsoft Windows에서 기본적으로 작동합니다.
UCRT(유니버설 C 런타임)는 최신 버전으로 Microsoft Visual Studio에서도 기본적으로 사용됩니다. 코드가 MSVC로 컴파일된 것처럼 작동하고 동작합니다.

빌드 시와 런타임 모두에서 MSVC와의 호환성이 향상됩니다.
Windows 10에서만 기본적으로 제공되며 이전 버전에서는 직접 제공하거나 사용자가 설치해야 합니다.

#### CPU architecture：`x86_64` vs `i686`

##### ◎ CPU architecture > 단순 설명

&nbsp; x86_64는 64비트, i686은 32비트를 말하며 본인 컴퓨터에 맞는 걸 쓰시면 됩니다.

&nbsp; 다음의 두 방법으로 원도우가 몇 비트 기반인지를 확인할 수 있습니다.

- 윈도우키+R -> dxdiag, 운영체제 항목 확인
- 시작표시줄 윈도우 로고 우클릭 -> 시스템, 시스템 종류 항목 확인

##### ◎ CPU architecture > 상세 설명

&nbsp; 컴퓨터의 뇌인 CPU 의 종류와 컴퓨터의 수학연습공책인 레지스터 크기 차이에 따른 구분입니다.

&nbsp; 자세히 설명하면 레지스터란 CPU가 계산을 할 때 계산의 중간 결과를 일시적으로 저장하는 고속의 전용 영역을 말합니다. 32비트와 64비트 연산의 차이는 수학문제를 풀 때, 가로세로 3.2cm 종이조각에 문제를 푸는 것과 6.4cm 포스트잇에 문제를 푸는 것의 차이와 같습니다.

&nbsp; 당연히 숫자가 큰 것이 좋습니다. 32비트보다 64비트가 속도도 빠르고 더 많은 메모리 사용도 가능합니다. 하지만 운영체제가 32비트인 경우엔 64비트가 성능발휘를 못하여 오히려 문제가 생깁니다. 그렇기에 본인 운영체제나 플랫폼의 비트 기반을 따라가는 것이 맞습니다.

##### ◎ CPU architecture > TMI 설명

&nbsp; 의문이 생기시진 않았나요? 왜 그냥 32비트, 64비트라고 표현하지 않고 이상한 이름을 쓰는 걸까요? 코딩을 공부하면서 x86 이나 amd64 같은 표현도 본 적 있을 지 모릅니다.

&nbsp; 잠시 32비트와 64비트에 대해 끝없이 불어난 이 별명들에 얽힌 이야기를 풀겠습니다.

&nbsp; 범인은 인텔입니다. 세상이 16비트에서 32비트, 그리고 32비트를 넘어 64비트로 발전하는 과정에서 인텔이 고집을 부리는 바람에 별명이 엄청나게 많아진 겁니다. 이 시기에 인텔은 16비트 프로세서용 아키텍처인 IA-16, 32비트용 IA-32 다음 버전으로 64비트 시장을 노리며 IA-64(아이테니엄)라는 아키텍처를 출시합니다.

&nbsp; 여기서 인텔은 큰 실수를 합니다. 아이테니엄 IA-64는 32비트인 IA-32와의 호환성이 전혀 없는 상태로 출시되었습니다. 아직 64비트의 시대가 아니었기 때문에 32비트 프로그램이 대다수였고, IA-64는 32비트를 직접 구동할 수 없어 전부 에뮬레이션을 거쳐 실행했습니다. 당연히 이때마다 성능저하가 일어났습니다.

&nbsp; 이를 AMD에선 `AMD64`라는 이름으로, 기존 IA-32와 호환되면서도 64비트인 아키텍처를 출시합니다. 기존 32비트를 속도 하락 없이 그대로 구동하며 동시에 64비트 명령어를 사용할 수 있었으니 그야말로 모범답안이었습니다. 이렇게 AMD64는 현 시점에서도 절대다수의 CPU가 채택하는 64비트의 사실상 표준이 됩니다.

&nbsp; IA-64를 지지하며 고집을 부리던 인텔은 결국 포기하고 AMD64를 라이선스받아 자사 CPU에 탑재하기에 이릅니다. 이때 차마 AMD라는 이름은 쓸 수 없었으므로 `IA-32e`, `EM64T`, `Intel64` 등 명칭이 더 생겨납니다.

&nbsp; 인텔은 16비트 시절 전설과도 같은 칩셋 8086에 적용된 아키텍처, 그리고 그 호환 프로세서와 후속작을 x86이라고 불러왔습니다. i386(Intel 의 80386 CPU 계열의 CPU), i586(Intel 의 80586 CPU 계열의 Pentium CPU), i686(Intel 의 80686 CPU 계열의 Pentium Pro 이상의 CPU)이 이 x86에 해당합니다. 32비트 시대에도 해당 칩셋들은 x86 명령어셋을 사용했고 이 때문에 32비트 체계를 관습적으로 `x86`이라고 부르게 된 것입니다. 인텔은 32비트의 x86 명령어셋을 64비트로 확장했다는 의미로 `x86*64` 또는 `x86-64` 또는 `x86_64` 라고도 이름 붙였습니다.

&nbsp; x86이라는 이름을 통해 x와 숫자 두 개의 조합이 익숙해지니 사람들은 여기서 따와서 64비트를 `x64`라고 부르기 시작합니다. 또 다시 이것이 익다보니 "64비트가 x64 면, 32비트는?" 라는 인식이 생겨 32비트를 `x32` 라고도 부르게 됬습니다.

&nbsp; 이런 환장할 칩셋의 역사로 인하여 혼란스러워 하는 사람들이 많지만 통상적으로는 x32, x86, i386, i686, IA-32 와 같이 64 숫자가 없으면 32비트, x64, x86_64, amd64, EM64T, Intel64 처럼 64 숫자가 있으면 64비트 입니다.

==============================

- Posix Thread：`posix` vs `win32`

C++11 규격에 thread 지원이 포함된 이후로. 표준 규격에 부합하는 Compiler는 어떤 형태로든 Posix 규격에 맞는 Thread Mechanism을 제공해야 했습니다.
MinGW도 이에 따라 Thread 지원이 되기 시작하면서 버전이 나뉘었습니다.

- Exception Handling：`sjlj` vs `seh`

SEH (Structured Exception Handling, 구조적 예외 처리)

응용프로그램 실행을 종료하는 이벤트가 발생하는 시기를 제어할 수 있습니다. 이러한 이벤트를 구조적 예외 또는 짧게 예외라고 합니다. 이러한 예외를 처리하는 메커니즘을 SEH(구조적 예외 처리 )라고 합니다.

Java 같은 언어가 thread를 사용할 때, 언어 상에서는 Runnable 상속 객체로 간단히 구현되지만, 내부적으로는 Debugging을 위한 Stack Trace와 각 언어가 지원하는 Exception Handling과 맞물리며 복잡해집니다.

[window try catch](https://learn.microsoft.com/ko-kr/cpp/cpp/try-except-statement?view=msvc-170)
MinGW에서도 Posix 규격에 맞는 Thread를 지원하기 위하여, 이런 구현을 가지고 있는데,
특히 Windows는 c언어에서도 구조화된 Exception Handling을 지원하는 전용 확장까지 있습니다.

구조화된 예외 처리를 지원하는 Microsoft 전용 확장입니다.

Keyword를 가지고 있어서 Unix-like한 OS와는 다른 구조를 가지므로, 구현이 더 복잡해진다.

SJLJ 구현의 경우, Exception의 발생여부와 관계없이 항상 SJLJ 구문을 수행해야 하기 때문에 overhead가 있다는 의견이 대부분이다. Platform 호환성에 있어서는 좋지만, 성능에 민감하다면 일단 제외를 할 필요가 있다.

또한, Win32 Threading Model을 쓰던, Posix Threading Model을 쓰던, 결국은 표준에서 권장하는

사용방식에 따라 프로그램 구현을 해야 하고, 프로그램을 구현하는 입장에서는 두 방식의 차이가

두드러지지 않기 때문에 선호하는 것을 쓰면 된다.

보편적으로는 x86_64-posix-seh 씁니다.

## 4. 컴파일러 세팅

## N-1. VScode 세팅

### 키 바인딩

- tasks.json 에서 설정한 작업을 할 수 있도록 단축키화 시킵니다.

### tasks.json 세팅

가장 어려운 부분인데 걍 복사 붙여넣기를 해도 됩니다.

- `Ctrl + P` 입력 후, `>Tasks: Run Build Task` or `>Tasks: Run Test Task`

### tasks.json 설명

[공식 문서](https://code.visualstudio.com/docs/editor/tasks#vscode)

- tasks 안에 [ `{ ...1번째 작업 정보... }`, `{ ...2번째 작업 정보... }`, ... `{ ...n번째 작업 정보... }` ] 같은 형태로 작업 정보를 나열할 수 있습니다.

  ```json
  {
    // task.json 에 대한 공식문서 https://go.microsoft.com/fwlink/?LinkId=733558
    "version": "2.0.0",
    "tasks": [
      {
        // ...작업 1 에 대한 정보...
      },
      {
        // ...작업 2 에 대한 정보...
      },
      // ...
      {
        // ...작업 n 에 대한 정보...
      }
    ]
  }
  ```

<br />

- tasks 안에 [ `{ ...1번째 작업 정보... }`, `{ ...2번째 작업 정보... }`, ... `{ ...n번째 작업 정보... }` ] 같은 형태로 작업 정보를 나열할 수 있습니다.

  ```json
  // tasks.json 앞 부분...

  {
    // ...작업 1 에 대한 정보...
  },

  // ...tasks.json 뒷 부분
  ```

<br />

- 작업 예시

  ```json
  // 테스트용 Hello, world!
  {
    "label": "테스트 출력",
    "detail": "Hello, world! 를 출력합니다.",
    "type": "shell",
    "group": {
      "kind": "test",
      "isDefault": true
    },
    "command": "echo",
    "args": ["Hello, world!"]
  }
  ```

<br />

### tasks.json 상세설명 > command

- gcc 빌드에 대한 이해가 필요합니다.
- g++ gcc 차이 cout cin << 안되던데? 1 d return

- 다음의 예시는 include 폴더의 cpp 까지 포함하려면 명령어를 다음과 같이 바꿔야합니다.

  ```json
  // tasks.json 앞 부분...

  // C++ include 경로 빌드
  {
    "label": "C++: g++ - include",
    "detail": "-o 옵션으로 /include 폴더를 포함하여 빌드합니다.",
    "type": "cppbuild",
    "group": {
      "kind": "build",
      "isDefault": true
    },
    "command": "g++",
    "args": [
      "-std=c++17",
      "${fileDirname}\\**.cpp",
      "${fileDirname}\\include\\**.cpp",
      "-o",
      "${fileDirname}\\${fileBasenameNoExtension}.exe"
    ],
    "options": {
      "cwd": "${fileDirname}"
    },
    "problemMatcher": {
      "owner": "cpp",
      "fileLocation": ["relative", "${workspaceRoot}"],
      "pattern": {
        "regexp": "^(.*):(\\d+):(\\d+):\\s+(warning|error):\\s+(.*)$",
        "file": 1,
        "line": 2,
        "column": 3,
        "severity": 4,
        "message": 5
      }
    }
  },

  // ...tasks.json 뒷 부분
  ```

#### 가장 기본 형태

```json
{
  "label": "C: gcc 릴리즈 빌드",
  "detail": "-o 옵션으로 릴리즈 할 exe 파일을 빌드합니다.",
  "type": "cppbuild",
  "group": "build",
  "command": "gcc",
  "args": ["${file}", "-o", "${fileDirname}\\${fileBasenameNoExtension}"],
  "problemMatcher": ["$gcc"]
}
```

##### 1234기본 gcc 빌드 방법

### 기본 gcc 빌드 방법

```json
{
  // task.json 에 대한 공식문서 https://go.microsoft.com/fwlink/?LinkId=733558
  "version": "2.0.0",
  "tasks": [
    // C++ 디버그 빌드 및 세부 설명
    {
      // 작업의 이름(라벨명) : 우리가 보고 찾는 용도이므로 한 눈에 어떤 작업인지 파악하기 쉽도록 이름을 짓는 것이 좋습니다.
      "label": "C++: g++ 디버그 빌드",

      // 작업의 세부설명 : 작업의 세부설명입니다.
      "detail": "-g 옵션으로 표준 디버깅 정보를 포함하여 빌드합니다.",

      // 작업의 타입 : 이 작업이 어떠한 유형의 작업인지 서술합니다. 대표적으로 shell(해당 명령어를 쉘에 입력), process(프로그램을 구동), cppbuild(빌드 및 디버깅) 가 있습니다.
      "type": "cppbuild",

      // 작업의 그룹 : vscode가 해당 작업을 찾기 위한 작업의 태그입니다. 정해진 값 외에는 허용되지 않습니다. build(컴파일 및 빌드), test(테스트 구동), none(작업을 그룹에 할당 안 함) 가 있습니다.
      "group": {
        "kind": "build",
        // 디폴트 설정 : true로 지정한 작업이 있을 경우, 다른 false는 무시되고 해당 작업을 합니다. true 지정한 작업이 복수일 경우, false는 무시되고 true 인 작업들만 목록에 올라옵니다.
        "isDefault": true
      },

      // 명령어 시작경로 : 명령어의 맨 첫 단어, 즉 명령할 파일의 경로. 이 경우 g++ 컴파일러에 접근해야 하므로 MinGW bin 내부 g++.exe 주소를 "command": "D:\\Program Files\\Msys64\\mingw64\\bin\\g++.exe" 같이 직접 입력해도 좋습니다. g++ 를 입력하면 환경변수 설정을 했기 때문에 바로 g++.bin 에 접근합니다.
      "command": "g++",

      // 명령어 값 : 각 옵션과 입력값들을 적습니다. 배열로 여러 값들을 가독성 좋게 따로따로 적을 수 있습니다.
      "args": [
        "-std=c++17", // C++ 17 적용
        "-g", // 표준 디버깅 정보 포함 옵션
        "${fileDirname}/**.cpp",
        "-o", // 출력 옵션
        "${fileDirname}/${fileBasenameNoExtension}.exe"
      ],

      // 추가 옵션 : 명령에 추가적인 사항
      "options": {
        // 작업 디렉터리 주소 설정 옵션
        "cwd": "${fileDirname}",
        // 쉘 터미널 지정
        "shell": {
          }
        }
      },

      // 문제 상황 및 경고 문구 매칭 : 컴파일시 컴파일러에서 발생한 문제나 경고에 대한 문구를 매칭하여 vscode 편집기에 반영. 상세 설명 링크 https://code.visualstudio.com/docs/editor/tasks#_defining-a-problem-matcher
      "problemMatcher": {
        // 문제를 발생시킨 대상
        "owner": "cpp",
        // 문제의 발생지
        "fileLocation": ["relative", "${workspaceRoot}"],
        // 문제 상황 및 경고 문구의 패턴
        "pattern": {
          // 정규 표현식 : 정규 표현식으로 컴파일러의 문구를 분석합니다. (에러 테스트 예시: helloWorld.c:5:3: warning: implicit declaration of function 'prinft')
          "regexp": "^(.*):(\\d+):(\\d+):\\s+(warning|error):\\s+(.*)$",
          "file": 1,
          "line": 2,
          "column": 3,
          "severity": 4,
          "message": 5
        }
      }
    }
  ]
}
```

### CMD 명령프롬프트

- 다음은 cmd 명령프롬프트 창에 <b>SET var= "Hello, world!" & CALL ECHO %var%</b> 명령어를 입력하는 작업을 tasks.json에 입력한 것 입니다.
- <b>`SET var= "Hello, world!"` & CALL ECHO %var%</b>
- <b>SET var= "Hello, world!" & `CALL ECHO %var%`</b>

- args": ["/d", "/c"] 옵션 더 추가

```json
{
  "version": "2.0.0",
  "tasks": [
    {
      "label": "cmd 테스트",
      "detail": "cmd",
      "type": "shell",
      "group": {
        "kind": "test",
        "isDefault": true
      },
      // * cmd로 실행하는 옵션입니다
      "options": {
        "shell": {
          "executable": "C:\\Windows\\System32\\cmd.exe",
          "args": ["/d", "/c"]
        }
      },
      "command": "SET",
      "args": ["var=", "Hello, world!", "&", "CALL", "ECHO", "%var%"]
    }
  ]
}
```

- cppbuild 옵션

cppbuild 설명 https://github.com/microsoft/vscode-cpptools/issues/12110

```json
{
  "version": "2.0.0",
  "tasks": [
    {
      "label": "cmd 테스트",
      "detail": "cmd",
      // * cppbuild 란!
      "type": "cppbuild",
      "group": {
        "kind": "test",
        "isDefault": true
      },
      "command": "SET",
      "args": ["var=", "Hello, world!", "&", "CALL", "ECHO", "%var%"]
    }
  ]
}
```

<br />

#### 리눅스의 경우

- 리눅스 옵션
- 리눅스의 확장(Expansion) : ${}, $(), $(())
  parameter expansion (파라미터 확장) : $var or ${var}
  command substitution (명령 대체) : $(command)
  arithmetic expansion (산술 확장) : $((expression))

- "g++ -g $(find . -type f -iregex \".*.cpp\") -o ${fileDirname}\\${fileBasenameNoExtension}.exe"

  ```json
  // tasks.json 앞 부분...

  // * C++ 테스트
  {
    "label": "C++: ----------------------------------------",
    "detail": "--------------------------------------------",
    "type": "shell",
    "group": {
      "kind": "build",
      "isDefault": false
    },
    // 리눅스 체계 명령어 치환(Command Substitution) $(find) -> %dir /b | findstr% 윈도우 명령어 치환으로 바꿔야 사용가능
    "command": "g++ -g $(find . -type f -iregex \".*.cpp\") -o ${fileDirname}\\${fileBasenameNoExtension}.exe",
    "args": [
      "-g",
      "$(find",
      "${fileDirname}",
      "-type",
      "f",
      "-iregex",
      "'.*\\.cpp')",
      "-o",
      "${fileDirname}/${fileBasenameNoExtension}"
    ]
  },

  // ...tasks.json 뒷 부분
  ```

#### 디버깅 옵션

- g 디버깅 옵션

  ```json
  // tasks.json 앞 부분...

  // * C++ 테스트
  {
    "label": "C: gcc.exe 디버그 빌드",
    "detail": "-g 옵션으로 표준 디버깅 정보를 포함하여 빌드합니다.",
    "type": "cppbuild",
    "group": "build",
    "command": "gcc",
    "args": ["-g", "${file}", "-o", "${fileDirname}\\${fileBasenameNoExtension}"],
    "options": {
      "cwd": "${fileDirname}"
    },
    "problemMatcher": ["$gcc"]
  },

  // ...tasks.json 뒷 부분
  ```

<br />

#### CMD 명령프롬프트 > 백준 등 프로그래밍 문제 컴파일

- 백준 문제의 경우 단일 파일만 컴파일하면 됩니다.
- g++ Main.cc -o Main -O2 -Wall -lm -static -std=gnu++17 -DONLINE_JUDGE -DBOJ

  ```json
  // tasks.json 앞 부분...

  // 백준 채점용 C++ 컴파일
  {
    "label": "C++: 백준 풀이 빌드",
    "detail": "백준 C++17 표준옵션으로 컴파일합니다.",
    "type": "cppbuild",
    "group": {
      "kind": "build",
      "isDefault": true
    },
    "command": "g++",
    // g++ Main.cc -o Main -O2 -Wall -lm -static -std=gnu++17 -DONLINE_JUDGE -DBOJ
    "args": [
      "${fileDirname}\\**.cpp",
      "-o",
      "${fileDirname}\\${fileBasenameNoExtension}.exe",
      "-O2", // loop unrolling, function inlining, 메모리 및 속도희생을 제외한 모든 범위 최적화
      "-Wall", // 모든 모호한 코딩에 대해서 경고를 보내는 옵션
      "-lm", // math libarary 사용
      "-static", // 정적 라이브러리와 공유 라이브러리 중 정적을 우선한다. 속도는 빠르지만 파일 사이즈가 커짐
      "-std=gnu++17" // C++17 Clang GNU 확장기능 유효
    ],
  },
  // tasks.json 뒷 부분...
  ```

<br />

#### CMD 명령프롬프트 > 컴파일

cmd command substitution
https://learn.microsoft.com/ko-kr/windows-server/administration/windows-commands/for

%%a 란 a가 지명된 변수명을 의미함
for %%a in (A B C D E) do Echo %%a

변수명 따오기를 응용해서 그 값을 그대로 때와 command substitution 꼼수 구현
for /f %%x in ('date') do set "today=%%x"

for /f "usebackq tokens=\*" %%a in (`echo Test`) do my_command %%a

- cpps.txt 를 거쳐서 저장하는 방법

dir C:\Users\dkdld\Desktop\test0 /a-d /s /b | findstr /e "\.txt"

dir C:\Users\dkdld\Desktop\test0 /a-d /s /b | find ".txt"

/a-d 폴더명은 검색에서 제외
/s 하위폴더 파일도 검색
/b 복잡한 테이블말고 최소포맷인 결과만 보기

```json
{
  "version": "2.0.0",
  "tasks": [
    {
      "label": "테스트5=====",
      "detail": "cpp 모두 찾기",
      "type": "cppbuild",
      "group": {
        "kind": "test",
        "isDefault": true
      },
      "command": "(FOR",
      "args": [
        "/F",
        "\"usebackq\"",
        "%i",
        "IN",
        "(`dir/a-d/s/b",
        "${fileDirname}",
        "^|findstr/e",
        "\".cpp\"`)",
        "DO",
        "@<NUL",
        "SET/P=",
        "%i ",
        ">>${fileDirname}\\cpps.txt)",
        "&",
        "SET/P",
        "cpps=<${fileDirname}\\cpps.txt",
        "&",
        "@CALL",
        "ECHO",
        "%cpps%",
        "&",
        "DEL/Q",
        "${fileDirname}\\cpps.txt"
      ]
    }
  ]
}
```

<br />

- [CMD] .cpp 경로 출력

```json
{
  "version": "2.0.0",
  "tasks": [
    {
      "label": "[CMD] .cpp 경로 출력",
      "detail": ".cpp 파일들의 경로를 cpps 변수에 저장한 뒤 ECHO 로 출력합니다",
      "type": "cppbuild",
      "group": {
        "kind": "test",
        "isDefault": true
      },
      "command": "(FOR",
      "args": [
        "/F",
        "\"usebackq\"",
        "%i",
        "IN",
        "(`dir/a-d/s/b",
        "${fileDirname}",
        "^|findstr/e",
        "\".cpp\"`)",
        "DO",
        "@CALL",
        "SET",
        "cpps=%cpps%",
        "%i)",
        "&",
        "CALL",
        "ECHO",
        "%cpps:~7%"
      ]
    }
  ]
}
```

```json
{
  "version": "2.0.0",
  "tasks": [
    {
      "label": "테스트7=====",
      "detail": "gcc 출력",
      "type": "cppbuild",
      "group": {
        "kind": "test",
        "isDefault": true
      },
      "command": "(FOR",
      "args": [
        "/F", // cpps 변수에 .cpp 확장자 파일 목록 지정
        "\"usebackq\"",
        "%i",
        "IN",
        "(`dir/a-d/s/b",
        "${fileDirname}",
        "^|findstr/e",
        "\".cpp\"`)",
        "DO",
        "@CALL",
        "SET",
        "cpps=%cpps%",
        "%i)",
        "&", // g++ 호출
        "CALL",
        "g++",
        "%cpps:~7%",
        "-o",
        "${fileDirname}\\${fileBasenameNoExtension}.exe",
        "-O2",
        "-static",
        "-std=gnu++17"
      ]
    }
  ]
}
```

### 파워쉘

task.json 은 옵션을 통해 다른 쉘에게 명령을 넘기는 것도 가능합니다.

cmd 보다 파워쉘이 가진 기능이 많은 만큼 이쪽으로 g++ 명령을 호출하면 편리해집니다.

```json
{
  "version": "2.0.0",
  "tasks": [
    {
      "label": "파워쉘1",
      "detail": "파워파워쉘",
      "type": "shell",
      "group": {
        "kind": "test",
        "isDefault": true
      },
      // * 파워쉘로 실행하는 옵션입니다
      "options": {
        "shell": {
          "executable": "powershell.exe"
        }
      },
      "command": "dir"
    }
  ]
}
```

https://cloudsns.wordpress.com/2012/10/09/get-childitem%EC%9D%98-%EB%A7%A4%EA%B0%9C%EB%B3%80%EC%88%98%EC%9D%B8-filter%EC%99%80-include%EC%9D%98-%EC%B0%A8%EC%9D%B4%EC%A0%90/
Get-Childitem -Path $home -Recurse -Force -Filter \*.txt 가장 빠른 방법

- 파워쉘로 경로 출력

```json
{
  "version": "2.0.0",
  "tasks": [
    {
      "label": "[PS] 파워쉘 컴파일 범위 테스트 코드",
      "type": "shell",
      "group": {
        "kind": "test",
        "isDefault": true
      },
      "options": {
        "shell": {
          "executable": "powershell.exe"
        }
      },
      "command": "echo",
      "args": [
        "\"$((Get-ChildItem",
        "-Path",
        "${fileDirname}",
        "-Recurse",
        "-Include",
        "*.?pp).FullName)\""
      ]
    }
  ]
}
```

- 파워쉘로 컴파일

```json
{
  "version": "2.0.0",
  "tasks": [
    {
      "label": "[PS] 파워쉘 컴파일 코드",
      "type": "shell",
      "group": {
        "kind": "test",
        "isDefault": true
      },
      "command": "g++",
      "args": [
        "$((Get-ChildItem",
        "-Path",
        "${fileDirname}",
        "-Recurse",
        "-Force",
        "-Filter",
        "*.?pp).FullName)",
        "-o",
        "${fileDirname}\\${fileBasenameNoExtension}.exe",
        "-O2",
        "-Wall",
        "-static",
        "-std=gnu++17"
      ]
    }
  ]
}
```

### 실행

- 마찬가지로 실행시키는 작업을 만드시면 됩니다.

  ```json
  // tasks.json 앞 부분...
  { // * Execute 바이너리 실행(Windows)
    "label": "exe 파일 실행",
    "detail": "현재 폴더에서 cpp 파일과 같은 이름의 exe 파일을 구동합니다.",
    "type": "process",
    "group": {
      "kind": "test",
      "isDefault": true
    },
    "command": "${fileDirname}/${fileBasenameNoExtension}.exe"
  },
  // ...tasks.json 뒷 부분
  ```
