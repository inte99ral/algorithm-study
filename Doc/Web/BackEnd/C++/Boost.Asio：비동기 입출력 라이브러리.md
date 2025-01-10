# Boost.Asio：비동기 입출력 라이브러리

## 개념 설명

&nbsp; Boost는 표준 C++ 라이브러리를 보완하고 확장하도록 설계된 오픈 소스 라이브러리 모음입니다.

&nbsp; 이중에서 저희가 다룰 Asio 는 Boost 의 Async I/O (비동기 입출력) I/O 통신 서버 클라이언트 라이브러리 입니다.

&nbsp; OS 에 따라서 서버 포트포워딩을 시도할 때, 리눅스에서는 EPOLL, 윈도우에서는 IOCP 를 사용하듯 개발하는 플랫폼 마다 차이가 생깁니다. 크로스 플랫폼을 지원하여 Boost.Asio 는 다른 운영체제에서도 정상적인 동작을 보장합니다.

## 사용 방법

### 사용 방법 > 컴파일 명령어

- C++ 버전 명시

  - `-std=c++11`: C++11 표준을 사용합니다. (Boost.Asio는 C++11 이상을 권장)

- 컴파일할 인풋 소스 파일입니다.

  - `your_file.cpp`: 컴파일할 소스 파일입니다.

- 출력할 아웃풋 실행 파일입니다.

  - `-o your_program.exe`: 출력 실행 파일의 이름을 지정합니다.

- 참조할 라이브러리 공개 인터페이스 헤더 파일(.h, .hpp) 경로

  - `-I"D:\Program Files\boost\include"`: Boost 헤더 파일의 위치를 지정합니다.

- 참조할 라이브러리 실제 구현 코드 파일(.a, .lib, .so, .dll) 경로

  - `-L"D:\Program Files\boost\lib"`: Boost 라이브러리 파일의 위치를 지정합니다.

- Asio의 의존성 라이브러리 링크
  - $\color{#FF9922} \footnotesize \textnormal{주의 사항 🚨}$
    - 실제 라이브러리 파일 이름은 컴파일러와 Boost 버전에 따라 다를 수 있습니다
    - `-lboost_system` 이 아니라 `-l"libboost_system-mgw8-mt-x64-1_87.a"` 같은 형식일 수도 있습니다.
  - `-lboost_system`: Boost.System 라이브러리 (Asio의 의존성)
  - `-lboost_thread`: Boost.Thread 라이브러리 (멀티스레딩 지원에 필요)
  - `-lwsock32`: Windows 소켓 API
  - `-lws2_32`: Windows 소켓 2 API

### 사용 방법 > 명령줄 인자처리
