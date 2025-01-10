# Boost：확장 오픈 소스 라이브러리

## 개념 설명

&nbsp; Boost는 표준 C++ 라이브러리를 보완하고 확장하도록 설계된 오픈 소스 라이브러리 모음입니다.

&nbsp; 크로스 플랫폼, 네트워크 프로그래밍, 선형 대수, 멀티스레딩, 이미지 처리, 정규 표현식을 구현하는 160개 이상의 개별 라이브러리로 구성되어 있으며 많은 부분이 C++ 표준 라이브러리에 포함되거나 영향을 미쳤을 정도로 C++ 발전에 큰 기여를 했습니다.

&nbsp; Boost는 C++ 개발자들에게 이런 강력하고 유연한 도구를 제공하여 생산성을 높이고 고품질의 코드를 작성할 수 있도록 돕습니다.

## 사용 방법

1. boost 공식사이트에서 최신버전 압축파일을 내려받습니다.

[공식 사이트](https://www.boost.org/)

2. 자기구동 파일 bootstrap.bat 으로 빌드준비를 합니다.

압축을 해제하고 최상단 디렉토리 (bootstrap.bat 이 위치한 디렉토리) 에서 터미널을 열고 다음의 명령어를 입력합니다.

```bash
bootstrap.bat gcc
# 또는
.\bootstrap.bat gcc
```

3. b2 (Backblaze B2 Cloud Storage) 커맨드라인 도구로 boost 라이브러리를 빌드합니다.

- powershell 환경에서 Backblaze B2 API를 사용하기 위해선 PS.B2 모듈이 필요합니다. 이 모듈을 사용하면 PowerShell 환경에서도 B2 클라우드 스토리지를 관리할 수 있습니다.

```ps
Install-Module -Name PS.B2
```

```bash
b2 --build-dir="C:\temp\boost_build" --prefix="C:\boost" toolset=gcc install

b2 --build-dir="C:\temp\boost_build" --prefix="D:\Program Files\boost" toolset=gcc install
```

4. gcc 에선 빌드 시에 경로를 잡아줘야 합니다.

- C 헤더 파일의 경우 C_INCLUDE_PATH 환경 변수를 설정합니다.
- C++ 헤더 파일의 경우 CPLUS_INCLUDE_PATH 환경 변수를 설정합니다.
- 라이브러리 파일의 경로는 LIBRARY_PATH 환경 변수에서 추가합니다.

```bash
g++ -std=c++11 -I"C:\boost\include" -L"C:\boost\lib" your_program.cpp -o your_program.exe -lboost_system
```

- -I"C:\boost\include"는 Boost 헤더 파일의 위치를 지정합니다.
- -L"C:\boost\lib"는 Boost 라이브러리 파일의 위치를 지정합니다.
- -lboost_system은 Boost.System 라이브러리를 링크합니다5.
