# Algorithm Study Convention

- Problem site name
  - Problem name
    - /assets
    - problem.md
    - answer.java
    - input.txt

<br />

## test 00

<details>
  <summary>테스트 00</summary>

  <div align="center">
    <img src="./.asset/0.svg" width="400" height="400" alt="css-in-readme">
  </div>

</details>

<details>
  <summary>테스트 01</summary>

  <div align="center">
    <a href="#">
      <img src="./.asset/2.svg" width="400" height="400" alt="css-in-readme">
    </a>
  </div>

</details>

<details>
  <summary>테스트 02</summary>

  <div align="center">
    <a>
      <img src="./.asset/2.svg" width="400" height="400" alt="css-in-readme">
    </a>
  </div>

</details>

## How To Set

g++ 컴파일러를 내장한 Msys2 와 mingw64 를 설치해야함

vscode는 관리하는 디렉토리의 .vscode 폴더 안의 파일로 환경설정이 가능하다

- tasks.json: 컴파일러 빌드 세팅

  ```
  {
    "version": "2.0.0",
    "runner": "terminal",
    "type": "shell",
    "echoCommand": true,
    "presentation": {
        "reveal": "always"
    },
    "tasks": [
      // c++ compile
      {
        "label": "save and compile for C++",
        "command": "g++",
        "args": [
          "${file}",
          "-o",
          "${fileDirname}/${fileBasenameNoExtension}"
        ],
        "group": "build",
        "problemMatcher": {
          "fileLocation": [
            "relative",
            "${workspaceRoot}"
          ],
          "pattern": {
            "regexp": "^(.*):(\\d+):(\\d+):\\s+(warning error):\\s+(.*)$",
            "file": 1,
            "line": 2,
            "column": 3,
            "severity": 4,
            "message": 5
          }
        }
      },
      // c comile
      {
        "label": "save and compile for C",
        "command": "gcc",
        "args": [
          "${file}",
          "-o",
          "${fileDirname}/${fileBasenameNoExtension}"
        ],
        "group": "build",
        "problemMatcher": {
          "fileLocation": [
            "relative",
            "${workspaceRoot}"
          ],
          "pattern": {
            "regexp": "^(.*):(\\d+):(\\d+):\\s+(warning error):\\s+(.*)$",
            "file": 1,
            "line": 2,
            "column": 3,
            "severity": 4,
            "message": 5
          }
        }
      },
      // 파일 실행
      {
        "label": "execute",
        "command": "cmd",
        "group": "test",
        "args": [
          "/C",
          "${fileDirname}\\${fileBasenameNoExtension}"
        ]
      },
      // 파일 빌드
      {
        "type": "cppbuild",
        "label": "C/C++: gcc.exe build active file",
        "command": "C:\\msys64\\mingw64\\bin\\gcc.exe",
        "args": [
          "-fdiagnostics-color=always",
          "-g",
          "${file}",
          "-o",
          "${fileDirname}\\${fileBasenameNoExtension}.exe"
        ],
        "options": {
          "cwd": "C:\\msys64\\mingw64\\bin"
        },
        "problemMatcher": [
          "$gcc"
        ],
        "group": {
          "kind": "build",
          "isDefault": true
        },
        "detail": "compiler: C:\\msys64\\mingw64\\bin\\gcc.exe"
      }
    ]
  }
  ```

- launch.json: 디버거 세팅

  ```
  // 상단 메뉴바에서 실행 -> 구성추가 -> C++ (GDB/LLDB) 선택해서 구성 추가하면 자동생성됨
  {
    // IntelliSense를 사용하여 가능한 특성에 대해 알아보세요.
    // 기존 특성에 대한 설명을 보려면 가리킵니다.
    // 자세한 내용을 보려면 https://go.microsoft.com/fwlink/?linkid=830387을(를) 방문하세요.
    "version": "0.2.0",
    "configurations": [
      {
        "name": "gcc.exe - Build and debug active file",
        "type": "cppdbg",
        "request": "launch",
        "program": "${fileDirname}\\${fileBasenameNoExtension}.exe",
        "args": [],
        "stopAtEntry": false,
        "cwd": "C:\\msys64\\mingw64\\bin", # 각자 msys64\\mingw64\\bin의 경로에 맞게 수정
        "environment": [],
        "externalConsole": false,
        "MIMode": "gdb",
        "miDebuggerPath": "C:\\msys64\\mingw64\\bin\\gdb.exe", # 여기도 경로에 맞게 수정
        "setupCommands": [
          {
            "description": "Enable pretty-printing for gdb",
            "text": "-enable-pretty-printing",
            "ignoreFailures": true
          },
          {
            "description": "Set Disassembly Flavor to Intel",
            "text": "-gdb-set disassembly-flavor intel",
            "ignoreFailures": true
          }
        ],
        "preLaunchTask": "C/C++: gcc.exe build active file"
      }
    ]
  }
  ```

- c_cpp_properties.json: 컴파일러 path 세팅, intellisense 세팅

  ```
  {
    "configurations": [
      {
        "name": "Win32",
        "includePath": [
          "${workspaceFolder}/**",
          // msys64 설치 경로에 따라 수정할 것
          "C:/msys64/mingw64/include"
        ],
        "defines": [
          "_DEBUG",
          "UNICODE",
          "_UNICODE"
        ],
        "windowsSdkVersion": "10.0.18362.0",
        // msys64 설치 경로에 따라 수정할 것
        "compilerPath": "C:/msys64/mingw64/bin/gcc.exe",
        "cStandard": "c11",
        "cppStandard": "c++17",
        // windows-msvc-x64 에서 아래와 같이 변경
        "intelliSenseMode": "windows-gcc-x64"
      }
    ],
    "version": 4
  }
  ```

<br />

# How To Run

- 해당 문제 경로에 터미널로 접근 후에 명령어로 구동(우클릭 -> 통합 터미널에서 열기)

  - cpp 파일은 코드러너로 우클릭 기동 또는 "ctrl + alt + c" 로 빌드 후, "ctrl + alt + r" 로 구동
  - java 파일은 `java Main.java`
  - js 파일은 `node Main.js`

- javascript 코딩 시, fs 모듈을 사용하기 위하여 `npm install fs` 필요함
- 코드의 자세한 형태는 example 참고

<br />

# Copyright Information

- [백준](https://help.acmicpc.net/rule)
- [프로그래머스](https://programmers.zendesk.com/hc/ko/articles/360034546572-%ED%94%84%EB%A1%9C%EA%B7%B8%EB%9E%98%EB%A8%B8%EC%8A%A4%EC%9D%98-%EB%AC%B8%EC%A0%9C%EB%A5%BC-%EC%99%B8%EB%B6%80%EC%97%90-%EA%B2%8C%EC%8B%9C%ED%95%A0-%EC%88%98-%EC%9E%88%EB%82%98%EC%9A%94-)
