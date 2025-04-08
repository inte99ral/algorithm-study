# GDB：디버거

## 준비 단계

- C/C++ 확장 프로그램을 VSCode에 설치합니다.
- GCC와 GDB를 시스템에 설치합니다.

## 설정 단계

1. 프로젝트 폴더에 launch.json 파일을 생성합니다.
2. launch.json 파일에 다음과 같은 설정을 추가합니다
   - "type": "cppdbg"
   - "request": "launch"
   - "program": "${workspaceFolder}/실행파일명"
   - "miDebuggerPath": "gdb.exe의 경로"
3. tasks.json 파일을 생성하고 컴파일 명령을 추가합니다. 이때 -g 옵션을 포함하여 디버깅 정보를 생성합니다.

## 디버깅 실행

소스 코드에 중단점(breakpoint)을 설정합니다.
F5 키를 눌러 디버깅을 시작합니다.

## 디버깅 기능

- F10: 한 줄씩 실행 (Step Over)
- F11: 함수 내부로 진입 (Step Into)
- Shift+F11: 함수에서 빠져나옴 (Step Out)
- F5: 다음 중단점까지 실행 (Continue)
- print 변수명: 변수 값 확인
