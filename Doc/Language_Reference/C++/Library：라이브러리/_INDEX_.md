# Library：라이브러리

## GCC 외부 라이브러리 추가

### $\color{#FF9922} \footnotesize \textnormal{주의 사항 🚨}$

&nbsp; 라이브러리 파일의 버전이 여러 개일 경우 디렉토리 구조는 `『VERSION_NAME』/ include/` 인 경우가 많습니다. **이 경우엔 문제가 되지 않습니다.**

&nbsp; 가끔 디렉토리 구조가 독특하게 `.../include/『VERSION_NAME』/` 를 따를 경우가 있습니다. 이는 이전 버전과 최신 버전를 복합적으로 사용할 수 있도록 만들어주는 구조입니다. 문제는 이 구조의 라이브러리의 참조 경로는 조심스럽게 다루어야 한다는 부분입니다.

&nbsp; 통상적으로는 컴파일러에서 알아서 『VERSION_NAME』 폴더 경로부터 시작하여 헤더 파일을 찾아 냅니다. 그렇기에 하던데로 `/include` 를 참조 경로로 지정해도 문제가 생기지 않습니다.

&nbsp; 하지만 **gcc가 자동으로 인식하지 못하**거나, **버전별로 구체적인 디렉토리 구조를 가지는 라이브러리는 버전을 명시**해야만 합니다.

&nbsp; 따라서 이 경우에는 `.../include` 가 아니라 `.../include/『VERSION_NAME』` 가 참조 경로가 되어야 합니다. 정확하게는 라이브러리 이름과 동일한 폴더가 위치한 폴더까지가 참조경로가 됩니다.

&nbsp; 예를 들어서 exampleLib 라는 이름의 헤더파일의 디렉토리 구조가 C:/Program Files/exampleLib/include/exampleLib-3_14/folder1/folder2/**exampleLib**/... 같은 모습이라면 참조 경로는 `C:/Program Files/exampleLib/include/exampleLib-3_14/folder1/folder2/` 입니다.

&nbsp; 또한 버전별로 구체적인 디렉토리 구조를 가지는 라이브러리의 경우, 높은 확률로 라이브러리 파일 각각에도 버전이 명시되어 있습니다. 라이브러리 링크할 때, 이 점을 주의해 주세요.

&nbsp; 예를 들어서 `#include <exampleLib/exampleTool>` 라는 이름의 라이브러리를 사용하고 싶다면 `gcc ... -l『LIBRARY_FILE』` 로 -L 로 선언된 경로에서 링크할 파일을 선언해야합니다. 이 때, 라이브러리 파일명이 'lib'로 시작하고 '.a'(정적 라이브러리) 또는 '.so'(공유 라이브러리)로 끝나는 경우, 중간 부분만 지정할 수 있습니다. 예를 들어, libexample_tool.so는 `-lexample_tool`로 링크할 수 있습니다. 문제는 버전이 명시되어 있다면 파일명이 libexample_tool-x64-3_14.so 같은 느낌으로 x64의 3.14 버전임을 명시하기 때문에 파일명을 확인하시고 `-lexample_tool-x64-3_14` 로 선언해주셔야 합니다.

### 컴파일 시 외부 경로 추가

- 빌드 시에 gcc 명령어에 참조 경로를 추가할 수 있습니다.

```bash
g++ -std=c++11 -I"『/INCLUDE_PATH』" -L"『/LIBRARY_PATH』" 『INPUT_FILE_NAME』.cpp -o 『OUTPUT_FILE_NAME』.exe -l『LIBRARY_NAME』

# 예시
# -I"C:\boost\include"는 Boost 헤더 파일의 위치를 지정합니다.
# -L"C:\boost\lib"는 Boost 라이브러리 파일의 위치를 지정합니다.
# -lboost_system은 Boost.System 라이브러리를 링크합니다.

g++ -std=c++11 -I"C:\boost\include" -L"C:\boost\lib" your_program.cpp -o your_program.exe -lboost_system
```

### 개발 환경 전역적으로 외부 경로 추가

1. 환경변수 추가

GCC 개발 환경 자체에 참조 경로를 추가하려면 환경 변수를 설정해야 합니다.
다음의 환경변수들을 만들거나, 이미 있을 경우 편집하여 경로들을 추가해주세요.

- C 헤더 파일의 경로를 C_INCLUDE_PATH 환경 변수에 추가합니다.
- C++ 헤더 파일 경로를 CPLUS_INCLUDE_PATH 환경 변수에 추가합니다
- 라이브러리 파일의 경로를 LIBRARY_PATH 환경 변수에 추가합니다.

2. VSCode의 IntelliSense 설정

&nbsp; VSCode의 IntelliSense는 CPLUS_INCLUDE_PATH 환경 변수를 자동으로 인식하지 않을 수 있습니다. 이를 해결하기 위해서는 다음과 같이 설정을 추가해야 합니다.

- VSCode에서 Ctrl+Shift+P를 눌러 명령 팔레트를 엽니다.
- `C/C++: Edit Configurations (JSON)` 구성편집 항목을 검색하여 선택합니다.
- 생성된 c_cpp_properties.json 파일에 다음과 같이 includePath를 추가합니다

```json
{
  "configurations": [
    {
      "name": "Win32",
      "includePath": ["${workspaceFolder}/**", "『/INCLUDE_PATH』"]
      // ... 기타 설정들 ...
    }
  ],
  "version": 4
}
```

## 옵션

### -static：라이브러리를 정적으로 링크합니다.

```bash
g++ -static -static-libstdc++ main.cpp -o myprogram
```

- 컴파일러에게 모든 라이브러리를 정적으로 링크하도록 지시
- 이 옵션을 사용하면 실행 파일 크기가 커지지만, 운영 체제에 동일한 라이브러리가 설치되어 있지 않아도 프로그램이 실행될 수 있슴

- 단점

  - 프로그램 크기 증가: 정적 라이브러리를 사용하면 실행 파일 크기가 크게 증가할 수 있슴
  - 라이브러리 업데이트: 정적 라이브러리를 사용하면 라이브러리 업데이트 시 프로그램을 다시 컴파일해야 필요

- 장점

  - 운영 체제 의존성 감소: 정적 라이브러리를 사용하면 프로그램 실행에 필요한 모든 라이브러리가 실행 파일에 포함되어 있어 운영 체제에 동일한 라이브러리가 설치되어 있지 않아도 프로그램을 실행
  - 보안 강화: 정적 라이브러리를 사용하면 공유 라이브러리 공격과 같은 보안 취약점에 대한 위험을 줄일 수 있음
  - 성능 향상: 정적 라이브러리를 사용하면 프로그램 실행 속도를 향상시킬 수 있음

### -static-libstdc++：C++ 표준 라이브러리(libstdc++)를 정적으로 링크합니다.

```bash
g++ -static -static-libstdc++ main.cpp -o myprogram
```

- C++ 표준 라이브러리(libstdc++)를 정적으로 링크하도록 지시.
- 이 옵션은 -static 옵션과 함께 사용

### -l：특정 라이브러리를 정적 링크합니다

```bash
$ g++ <INPUT_NAME> -l<LIBRARY_NAME> -o <OUTPUT_NAME>
$ g++ <input.cpp> -lstdc++ -o <output.exe>
```

- 컴파일러에게 특정 라이브러리를 링크하도록 지시.
- 옵션 뒤에 라이브러리 이름을 지정. 예를 들어, -lstdc++은 C++ 표준 라이브러리를 링크.
- 뒤에 오는 라이브러리 이름은 관례에 따라 lib 접두사와 .a 확장자를 가진 정적 라이브러리 파일명

### { -Wl | –whole-archive }：모든 라이브러리를 정적 링크합니다

```bash
$ g++ <main.cpp> -lstdc++ { -Wl | -whole-archive } my_lib.a -o <myprogram.exe>
```

- 컴파일러에게 라이브러리에 있는 모든 객체 파일을 링크하도록 지시
- 이 옵션을 사용하면 라이브러리에 있는 모든 함수가 사용될 수 있음
