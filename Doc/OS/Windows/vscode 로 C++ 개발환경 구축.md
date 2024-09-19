# Windows에서 Visual Studio Code로 C++ 개발환경 구축하기

```markdown
0. 서문
```

## 0. 서문

0. 서문에서는 입문자들에게 다음의 설명을 합니다.

- C++ 환경을 구현할 이유
-

## 1. 서문

## 참고자료

- zip파일 바로 적용 https://sooseongcom.com/post/MinGW-w64-HowToInstall
- mingw 종류 설명 https://blog.naver.com/webos21/196800460
- mingw 종류 세부설명 및 추천 https://klutzy.github.io/blog/2015/03/05/mingw/

## task.json 세팅

가장 어려운 부분인데 걍 복사 붙여넣기를 해도 됩니다.

### 가장 기본형식

[공식 문서](https://code.visualstudio.com/docs/editor/tasks#vscode)

- tasks 안에 [ `{ ...1번째 작업 정보... }`, `{ ...2번째 작업 정보... }`, ... `{ ...n번째 작업 정보... }` ] 같은 형태로 작업 정보를 나열할 수 있습니다.

  ```json
  {
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

  // tasks.json 뒷 부분...
  ```

<br />

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
// tasks.json 뒷 부분...
```

<br />

#### CMD 명령프롬프트 > 컴파일

- cpps.txt 를 거쳐서 저장하는 방법

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
