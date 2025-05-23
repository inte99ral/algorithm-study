# Windows에서 Visual Studio Code로 C++ 개발환경 구축하기

## -1. 참고자료

[참고링크](https://basiclike.tistory.com/360)

- zip파일 바로 적용 https://sooseongcom.com/post/MinGW-w64-HowToInstall
- mingw 종류 설명 https://blog.naver.com/webos21/196800460
- mingw 종류 세부설명 및 추천 https://klutzy.github.io/blog/2015/03/05/mingw/

## 목차

```markdown
0. 서문
1. 서문
2. visual studio code 설치
3. 컴파일러 설치
```

## 0. 문서의 목적

### 0. > 서문

0장에서는 입문자들에게 다음의 설명을 합니다.

- C++ 환경을 구현할 이유

- Visual Studio Code의 설명

정보만 필요하시면 다른 단원으로 넘어가셔도 좋습니다.

### 0. > C++ 환경을 구현할 이유

&nbsp; 그 유명한 C언어를 ++, 말 그대로 업그레이드시킨 것으로 절차 지향, 객체 지향, 일반화 프로그래밍, 함수형 프로그래밍을 모두 지원하여 개발 설계의 자유도가 매우 높은 언어로 진짜 마음 내키는 데로 개발할 수 있습니다.

&nbsp; C++의 개발자이신 Bjarne Stroustrup 의 말을 빌리면 가볍게 추상화한 언어입니다. 배우기 어렵다는 단점 빼고 워낙 장점이 많은 언어이기에(무엇보다 요즘 세상에 연산이 빠르다라는 장점은 그 무엇과도 바꿀 수 없습니다.) 앞으로도 C++ 언어는 불멸이라 생각하셔도 좋습니다. 개인적으로는 C++ 보다 C#이 나은 언어라고 생각하지만... 대학교 시절에도 그렇고 요즘까지도 C++ 시대는 끝났다고 말하는 사람들이 분명 많이 보이지만... 결국 취업시장과 언어 점유율, 말이 필요없습니다. 숫자가 증명합니다.

&nbsp; 물론 임베디드 or 프로그램 개발 한정입니다. 통계나 AI 분야는 Python(사실 아직도 R 쓰는 곳 많습니다), 서버는 Java, 웹 프론트엔드는 Javascript(아직도 php 쓰는 곳 많습니다) 로 분야마다 강세인 언어가 다르기 때문에 목적에 맞게 선택해서 배우시길 추천드립니다.

&nbsp; 다음과 같은 이유로 본 문서는 `Windows 운영체제`에서 `Visual Studio Code`로 `MSYS2` 환경에서 `GCC`를 컴파일러로 사용하여 `c++` 개발 환경을 구축하는 과정을 다룹니다.

### 0. > Visual Studio Code의 설명

&nbsp; Visual Studio Code 와 Visual Studio 는 다릅니다.

## 1. 서문

- vscode 를 써야하는 이유

## 2. visual studio code 설치

## 3. 컴파일러 설치

### 컴파일러 선택

&nbsp; 먼저 컴파일러를 무엇으로 선택할 지를 결정해야합니다.

&nbsp; 주로 GNU 프로젝트의 GCC, LLVM 의 Clang 중 하나를 선택합니다.

<table>
  <tr>
    <th></th>
    <th>GCC</th>
    <th>LLVM/Clang</th>
  </tr>
  <tr>
    <td>특징</td>
    <td>
      <li>GNU 링커와 GNU C++ 라이브러리를 사용</li>
      <li>GNU 프로젝트의 컴파일러 컬렉션</li>
    </td>
    <td><li>링커로 LLD, 표준 라이브러리로 LIBC++를 사용</li>
    <li>LLVM 도구만 사용</li>
    </td>
  </tr>
  <tr>
    <td>장점</td>
    <td>
      <li>유닉스/리눅스 계열의 사실상 표준</li>
      <li>포트란까지 폭 넓은 언어 지원</li>
      <li>높은 호환성 및 안정성</li>
    </td>
    <td>
      <li>MIT 라이센스</li>
      <li>오류 메세지가 직관적이고 색상 강조</li>
      <li>최신식 설계로 컴파일이 빠르고 유지보수에 강함</li>
    </td>
  </tr>
  <tr>
    <td>단점</td>
    <td>
      <li>GPL 라이선스</li>
      <li>단일 모놀리식 구조로 모듈화가 제한적</li>
      <li>오류 메시지 출력 방식이 복잡함</li>
    </td>
    <td>
      <li>사용자 폭이 좁음</li>
      <li>일부 도구는 동등한 GNU 도구와 비교하면 부족함</li>
      <li>x86/64 환경에서 최적화 성능 부족</li>
    </td>
  </tr>
</table>

&nbsp; 둘 다 장단점이 존재하지만, 어차피 GNU 프로젝트의 GCC 를 윈도우즈 OS 에서 사용하기 위해서는 MinGW(Minimalist GNU for Windows) 라는 윈도우용 포크가 필요한데 이 MinGW 는 Clang 컴파일러 또한 지원합니다.

&nbsp; 그렇기 때문에 여기 설명에서는 더 확장성이 높은 GNU 프로젝트의 GCC 컴파일러를 기반으로 설명하겠습니다.

### 컴파일 환경 선택

&nbsp; 방금 말했듯이 C++ 언어 컴파일을 위해서는 컴파일러 뿐 아니라 MinGW 같이 그 기본 환경부터 맞춰주어야 합니다. 다음의 선택지가 있습니다.

- 아예 POSIX 호환 unix 환경을 통으로 윈도우즈에 구현하는 <b>cygwin</b>
- POSIX 호환은 못하나 unix 라이브러리를 제공하는 경량화 cygwin, <b>MSYS</b>
- 극단적으로 경량화하여 최소한의 컴파일러와 명령어를 탑재한 <b>MinGW</b>

&nbsp; POSIX 호환 unix 시스템을 윈도우에서 사용해야 하면 cygwin 이 필요합니다. 하지만 c++ 개발만 할 상황에 cygwin처럼 거대한 시스템을 설치할 이유는 없습니다.

&nbsp; 보통은 다양한 패키지를 지원하는 MSYS2 와 극단적으로 경량화한 MinGW 사이에서 고민하게 됩니다.

<table>
<tr>
  <th></th>
  <th>MinGW만 사용하는 경우</th>
  <th>MSYS2와 함께 사용하는 경우</th>
</tr>
<tr>
  <td><b>장점</b></td>
  <td>
    <li>설치가 간단하고 용량이 작음</li>
    <li>가볍고 빠른 실행 속도</li>
    <li>윈도우 네이티브 실행 파일 생성에 최적화</li>
  </td>
  <td>
    <li>GCC와 관련 도구들의 최신 버전 제공</li>
    <li>Pacman 으로 패키지 관리가 편함</li>
    <li>Linux와 유사해 POSIX 호환성이 뛰어남</li>
  </td>
</tr>
<tr>
  <td><b>단점</b></td>
  <td>
    <li>일부 POSIX 기능 지원 제한</li>
    <li>패키지 관리와 업데이트가 불편</li>
  </td>
  <td>
    <li>설치 용량이 더 큼</li>
    <li>초기 설정이 약간 복잡할 수 있음</li>
  </td>
</tr>
</table>

&nbsp; 알고리즘 문제 풀이 정도의 레벨에선 MinGW 만 써도 무관하나, 조금만 더 복잡한 프로그램을 개발하고 싶을 때 바로 발목이 잡히게 되므로 개인적으론 MSYS 환경을 추천합니다.

### 컴파일 환경(MSYS2) 설치

&nbsp; 64비트 환경의 MSYS, MSYS2는 [공식 사이트](https://www.msys2.org/)에서 설치파일을 다운로드 받을 수 있습니다.

&nbsp; 적절한 폴더를 지정하여 설치가 끝나셨다면 해당 폴더에 MSYS 가 지원하는 플랫폼들이 보일 것 입니다. 크게는 다음으로 정리됩니다.

<table>
  <tr>
    <th>⟍</th>
    <th>ucrt64</th>
    <th>mingw64</th>
    <th>clang64</th>
    <th>msys2</th>
  </tr>
  <tr>
    <td>특징</td>
    <td>최신 Windows(Windows 10 이상)에서 권장되는 환경입니다. Universal C Runtime(UCRT)을 사용합니다. 앞으로의 표준 환경으로 추천됩니다.</td>
    <td>오래된 MSVCRT(Microsoft Visual C++ Runtime)를 사용합니다. 구버전 Windows와의 호환성이 필요하다면 선택할 수 있습니다.</td>
    <td>LLVM/Clang 기반 컴파일러를 사용하는 환경입니다. 크로스 플랫폼 관리나 코드 결함을 크로스 체크할 때 선택됩니다.</td>
    <td>MSYS POSIX 환경을 실행하는 기본 터미널 런처입니다. 리눅스 명령어와 유닉스 도구를 사용할 수 있게 해줍니다</td>
  </tr>
    <tr>
    <td>바이너리 경로</td>
    <td>『설치된MSYS경로』\ucrt64\bin</td>
    <td>『설치된MSYS경로』\mingw64\bin</td>
    <td>『설치된MSYS경로』\clang64\bin</td>
    <td>『설치된MSYS경로』\usr\bin</td>
  </tr>
</table>

&nbsp; mingw64 도 문제없이 동작하지만 최신 환경에서는 ucrt64 를 사용하는 것이 권장됩니다. ucrt64 가 C++ 개발에 가장 무난한 선택입니다

&nbsp; 이제 Windows OS 터미널이 MSYS 에 접근할 수 있도록 경로를 알려줘야 합니다. Windows 는 환경변수 중 Path 라는 변수에 경로가 들어가있다면 필요할 때, 그 경로를 탐색하여 접근합니다.

&nbsp; 다음은 ucrt64 환경의 경로를 Path 환경 변수에 추가하는 방법입니다.

- 작업표시줄 윈도우 로고에 우클릭을 하면 나오는 메뉴에서 시스템을 클릭해 주세요.
- 시스템 창의 "고급 시스템 설정" 을 누르고 상단 탭 중에서 고급 항목에서 "환경 변수" 를 클릭하여 환경 변수를 수정할 수 있습니다.
- "Path" 라는 환경 변수를 클릭 후, "편집(I)" 버튼을 눌러 환경 변수 편집 창을 띄워주세요.
- 바이너리 경로 "『설치된 MSYS경로, 개개인마다 다르니 확인해주세요.』\ucrt64\bin" 를 추가합니다.

&nbsp; 각 플랫폼마다 별도의 패키지 저장소와 설치 경로를 사용하기 때문에 ucrt64 에서 설치한 패키지와 설정은 다른 플랫폼에 영향을 주지 않습니다.

&nbsp; 또한, 여러 환경을 동시에 PATH에 넣지 말고, 한 번에 하나의 환경만 사용해야 합니다. 그래야 컴파일러 충돌 없이 원하는 환경에서 빌드할 수 있습니다.

### 컴파일러(gcc) 설치

&nbsp; 리눅스나 우분투, 또는 윈도우즈를 처음 설치했을 때처럼 내부적으로는 설치된 것이 없습니다.

&nbsp; 이제 MSYS2 ucrt64 환경에서 우리의 목표 gcc 컴파일러를 설치하도록 하겠습니다.

&nbsp; MSYS 는 pacman 이라는 패키지매니저가 필요한 패키지를 설치 및 관리를 해줍니다.

&nbsp; 리눅스의 apt 이나 노드의 npm 같은 패키지관리자에 익숙하신 분은 다음의 명령어표를 보시면 이해하기 쉬우실 겁니다.

<details>
<summary>명령어 표</summary>
<table>
<tr>
  <th><center>⟍</center></th>
  <th>apt</th>
  <th>npm</th>
  <th>pacman</th>
</tr>
<tr>
  <td>이름 유래</td>
  <td>advanced package tool</td>
  <td>node pkgmakeinst</td>
  <td>package manager</td>
</tr>
<tr>
  <th colspan="4"><center>- 패키지 설치 및 제거 -</center></th>
</tr>
<tr>
  <td>패키지 설치</td>
  <td>sudo apt install 『패키지 이름』</td>
  <td>npm install 『패키지 이름』</td>
  <td>pacman -S 『패키지 이름』</td>
</tr>
<tr>
  <td>패키지 제거</td>
  <td>sudo apt remove 『패키지 이름』</td>
  <td>npm uninstall 『패키지 이름』</td>
  <td>pacman -R 『패키지 이름』</td>
</tr>
<tr>
  <td>패키지 설정/의존성까지 완전소거</td>
  <td>sudo apt purge 『패키지 이름』</td>
  <td>(uninstall 시 완전소거)</td>
  <td>pacman -Rns 『패키지 이름』</td>
</tr>
<tr>
  <td>필요 없는 패키지(고아 패키지) 제거</td>
  <td>sudo apt autoremove</td>
  <td>npm prune</td>
  <td>pacman -Rns $(pacman -Qdtq)</td>
</tr>
<tr>
  <td>패키지 캐시 삭제</td>
  <td>sudo apt clean</td>
  <td>npm cache clean --force</td>
  <td>pacman -Scc</td>
</tr>
<tr>
  <th colspan="4"><center>- 패키지 DB -</center></th>
</tr>
<tr>
  <td>패키지 DB 검색</td>
  <td>apt search 『검색어』</td>
  <td>npm search 『검색어』</td>
  <td>pacman -Ss 『검색어』</td>
</tr>
<tr>
  <td>패키지 DB 상세정보</td>
  <td>apt show 『패키지 이름』</td>
  <td>npm info 『패키지 이름』</td>
  <td>pacman -Si 『패키지 이름』</td>
</tr>
<tr>
  <td>패키지 DB 업데이트</td>
  <td>sudo apt update</td>
  <td>(항상 최신 DB)</td>
  <td>pacman -Sy</td>
</tr>
<tr>
  <th colspan="4"><center>- 설치된 패키지 관리 -</center></th>
</tr>
<tr>
  <td>설치된 패키지 목록</td>
  <td>apt list --installed</td>
  <td>npm list --global	</td>
  <td>pacman -Q</td>
</tr>
<tr>
  <td>설치된 패키지 검색</td>
  <td>apt list --installed 『검색어』</td>
  <td>npm ls 『검색어』</td>
  <td>pacman -Qs 『검색어』</td>
</tr>
<tr>
  <td>업그레이드 가능한 패키지 목록</td>
  <td>apt list --upgradable</td>
  <td>npm outdated</td>
  <td>pacman -Qu</td>
</tr>
<tr>
  <td>설치된 모든 패키지 업그레이드</td>
  <td>sudo apt upgrade</td>
  <td>npm update</td>
  <td>pacman -Su</td>
</tr>
<tr>
  <td>설치된 특정 패키지 업그레이드</td>
  <td>sudo apt install 『패키지 이름』</td>
  <td>npm update 『패키지 이름』</td>
  <td>pacman -S 『패키지 이름』</td>
</tr>
</table>
</details>

&nbsp; 따라서 gcc 를 설치하기 위해서 다음의 명령어를 입력해 주세요.

```bash
# 관련기능 전부 설치
pacman -S --needed base-devel mingw-w64-ucrt-x86_64-toolchain


# 최소한으로 gcc 만 설치
pacman -S mingw-w64-ucrt-x86_64-gcc

# 설치 및 버전 확인
g++ --v
gcc --v
```

## 4. 컴파일러 세팅

### Makefile Tools

- [참조링크](./Doc/Language_Reference/C++/GCC：컴파일러/Makefile：컴파일 환경 관리.md)

### tasks.json

&nbsp; vscode의 빌드자동화를 Makefile 를 거치지 않고 네이티브하게 직접 조정합니다.

&nbsp; vscode shell 에서 미리 정의되어 있는 내장 변수를 사용하거나 파이프, 리다이렉션등의 기능을 활용하여 더 복잡한 기능을 자동화 할 수 있습니다.

- 경로 관련 변수

  - ${workspaceFolder}: 현재 VSCode에서 열린 작업 폴더의 경로
  - ${workspaceFolderBasename}: 작업 폴더의 이름 (슬래시 없이)
  - ${file}: 현재 열린 파일의 전체 경로
  - ${fileWorkspaceFolder}: 현재 열린 파일이 속한 작업 폴더
  - ${relativeFile}: 작업 폴더를 기준으로 한 현재 파일의 상대 경로
  - ${fileDirname}: 현재 파일이 있는 디렉토리 경로
  - ${fileExtname}: 현재 파일의 확장자

- 파일명 관련 변수

  - ${fileBasename}: 현재 파일의 기본 이름 (확장자 포함)
  - ${fileBasenameNoExtension}: 현재 파일의 기본 이름 (확장자 제외)

- 에디터 관련 변수

  - ${lineNumber}: 현재 활성 파일에서 선택된 라인 번호
  - ${selectedText}: 현재 활성 파일에서 선택된 텍스트

- 시스템 관련 변수

  - ${userHome}: 사용자의 홈 폴더 경로
  - ${pathSeparator}: 운영 체제에 따른 경로 구분자 (macOS/Linux: '/', Windows: '')
  - ${execPath}: VSCode 실행 파일의 경로

- 기타 변수
  - ${env:Name}: 환경 변수 참조 (예: ${env:USERNAME})
  - ${config:Name}: VSCode 설정 참조 (예: ${config:editor.fontSize})

&nbsp; tasks.json 파일에서 tasks 리스트 내 객체의 type 항목은 작업의 실행 방식을 결정합니다. 주요 type으로는 cppbuild, process, shell이 있습니다.

- shell
  - 복잡한 명령어 또는 스크립트 실행에 적합합니다.
  - 시스템의 셸(예: bash, cmd.exe)을 통해 명령을 실행합니다.
  - 셸의 기능(파이프, 리다이렉션 등)을 사용할 수 있습니다.
  - 가장 유연하며, 복잡한 명령어 시퀀스를 실행할 수 있습니다.
  - 예시

```json
{
  "type": "shell",
  "label": "Run multiple commands",
  "command": "echo 'Building...' && make && echo 'Running...' && ./myprogram",
  "options": {
    "cwd": "${workspaceFolder}"
  },
  "group": "build"
}
```

- process

  - 단순한 프로그램 실행에 적합합니다.
  - 운영 체제의 프로세스를 직접 실행합니다.
  - 셸을 거치지 않고 프로그램을 직접 실행하므로 더 빠르고 안전할 수 있습니다.
  - 단일 프로그램을 직접 실행하며, 셸 기능은 사용할 수 없습니다.
  - 명령어와 인수를 분리하여 지정해야 합니다.
  - 예시

```json
{
  "type": "process",
  "label": "Run Python script",
  "command": "python",
  "args": ["${file}"],
  "options": {
    "cwd": "${workspaceFolder}"
  },
  "group": "test"
}
```

- cppbuild

  - 쉘 작업이 아니라 컴파일러를 실행하고 args 인자값을 넘겨주기에 process 타입과 같으나 C/C++ 프로젝트를 위한 특화된 빌드 작업 유형입니다.
  - 빌드에 최적화되어 있으며, 컴파일러 설정을 자동화합니다.
  - 컴파일러 경로와 인수를 자동으로 설정합니다.
  - 문제 매칭(problem matching)이 자동으로 구성됩니다.
  - 예시

```json
{
  "type": "cppbuild",
  "label": "C/C++: g++ build active file",
  "command": "/usr/bin/g++",
  "args": ["-g", "${file}", "-o", "${fileDirname}/${fileBasenameNoExtension}.exe"],
  "options": {
    "cwd": "${workspaceFolder}"
  },
  "problemMatcher": ["$gcc"],
  "group": {
    "kind": "build",
    "isDefault": true
  }
}
```

&nbsp; tasks.json 의 "type": "process"인 경우, command는 실행할 프로세스의 이름이며, 추가 인수는 args 항목에 지정합니다.

&nbsp; "type": "shell"인 경우, command는 셸에서 실행될 전체 명령줄입니다.

&nbsp; "type": "cppbuild" 는 매우 특이한 타입입니다. 자동으로 `cmd /c chcp 65001>nul && gcc ...` 옵션으로 상당히 네이티브하고 윈도우 오류가 적도록 빌드를 시도합니다.

"type": "shell"은 명령을 셸에서 실행함을 나타냅니다.
"label": 작업의 이름입니다. VSCode UI에서 이 이름으로 작업을 식별합니다.
"command": 실행할 명령어입니다. 여기서는 모두 "make"입니다.
"args": make 명령에 전달할 인수입니다.
"options": 작업 실행 옵션입니다. "cwd"는 작업 디렉토리를 지정합니다.
"problemMatcher": 컴파일러 출력을 파싱하여 오류와 경고를 표시합니다.
"group": 작업의 그룹을 지정합니다. "build" 그룹의 작업은 빌드 단축키로 실행할 수 있습니다.

&nbsp; 장점. 터미널 종류 등 세밀한 조정가능

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
  // ...tasks.json 앞 부분...

  {
    // ...작업 1 에 대한 정보...
  },

  // ...tasks.json 뒷 부분...
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

#### tasks.json 상세설명 > command > include 폴더 포함

- 특정 MinGW/MinGW-w64 배포판이 와일드카드 확장(wildcard expansion, globbing)을 자체적으로 지원하도록 빌드된 경우. 경로에 `**` 와일드 카드 적용이 가능합니다.

- 다음의 예시는 include 폴더의 cpp 까지 포함하려면 명령어를 다음과 같이 바꿔야합니다.

  ```bash
  g++ <FILE_NAME>.js
  ```

  ```json
  // ...tasks.json 앞 부분...

  // C++ include 경로 빌드
  {
    // ...작업정보 앞 부분...
    "command": "g++",
    "args": [
      "-std=c++17",
      "${fileDirname}\\**.cpp",
      "${fileDirname}\\include\\**.cpp",
      "-o",
      "${fileDirname}\\${fileBasenameNoExtension}.exe"
    ],
    // ...작업정보 뒷 부분...
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
    // * g++ Main.cc -o Main -O2 -Wall -lm -static -std=gnu++17 -DONLINE_JUDGE -DBOJ
    "command": "g++",
    "args": [
      "${fileDirname}\\**.cpp",
      "-o",
      "${fileDirname}\\${fileBasenameNoExtension}.exe",
      "-O2", // loop unrolling, function inlining, 메모리 및 속도희생을 제외한 모든 범위 최적화
      "-Wall", // 모든 모호한 코딩에 대해서 경고를 보내는 옵션
      "-lm", // libm.a (math libarary) 고속연산을 위한 정적 라이브러리 지정
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

#### CMD > 반복검색 빌드

```bash
g++ <INPUT_FILE_1> <INPUT_FILE_2> ... <INPUT_FILE_n> -o <OUTPUT_FILE>
```

```bat
:: # BAT：.cpp 파일들을 탐색합니다 ========================================
:: ## 상세 설명
:: dir     > 폴더 및 파일 리스트 출력
:: /a-d    > dir option. 폴더명은 검색에서 제외
:: /s      > dir option. 하위폴더 파일도 검색
:: /b      > dir option. 복잡한 테이블말고 최소포맷인 결과만 보기
:: %~dp0   > 탐색할 경로. 드라이브를 포함한 현재 bat 파일 경로
:: |       > 명령 간 데이터 전달 Pipe & Redirection
:: findstr > 텍스트의 패턴을 검색합니다.
:: /e      > findstr option. 줄의 끝에서 부터 검색합니다.
dir /a-d /s /b %~dp0 | findstr /e ".cpp"

:: # BAT：.cpp 파일들을 탐색한 후, 한 줄 씩 출력합니다 ======================
FOR /F "usebackq" %%a IN (`dir %~dp0 /a-d /s /b ^| findstr /e "\.cpp"`) DO (
  ECHO [CPP_PATH] = %%a
)


:: # BAT：.cpp 파일들을 탐색한 후, "변수"에 넣고 출력합니다 =================
:: ## <DIRECTORY_PATH> 경로 밑의 .cpp 파일들의 경로를 cpps 변수에 저장한 뒤 ECHO 로 출력합니다
(FOR /F "usebackq" %%i IN (`dir/a-d/s/b %~dp0 ^|findstr/e ".cpp"`) DO (SET cpps=!cpps! %%i)) & CALL ECHO "[CPP_PATH] = !cpps:~1!"

:: 다음 식은 bat 파일에선 정상적으로 돌아가지 않습니다.
::  이유 1. %~dp0은 batch 파일의 경로 값을 가진 인수입니다. cmd 명령줄 입력 시엔 %~dp0 을 쓸 수 없습니다.
::  이유 2. cmd 명령줄 입력 시엔 %<variable> 이 아니라 %%<variable> 를 사용합니다.
::  이유 3. bat 작업 중, 변수값이 명령 도중 변화할 경우엔 지연확장(DelayedExpansion)을 적용해야 합니다.
::  이유 4. cmd 명령줄 입력 시엔 cpps 변수가 선언된 적 없을 경우 "%cpps%" 라는 문자열로 인식하지만 bat 파일에선 비어있는 변수값 "" 으로 인식합니다.

:: 다음과 같은 차이를 감안하여 CMD에서 쓸 경우에는 다음과 같이 바꾸어주셔야 합니다.

:: # CMD：.cpp 파일들을 탐색한 후, "변수"에 넣고 출력합니다 =================
:: ## <DIRECTORY_PATH> 경로 밑의 .cpp 파일들의 경로를 cpps 변수에 저장한 뒤 ECHO 로 출력합니다
::(FOR /F "usebackq" %i IN (`dir/a-d/s/b <DIRECTORY_PATH> ^|findstr/e ".cpp"`) DO @(CALL SET cpps=%cpps% %i)) & CALL ECHO "[CPP_PATH] = %cpps:~7%"


:: # BAT：.cpp 파일들을 탐색한 후, "파일"에 넣고 출력합니다 =================
:: ## <DIRECTORY_PATH> 경로 밑의 .cpp 파일들의 경로를 cpps 파일에 저장한 뒤 ECHO 로 출력합니다
(FOR /F "usebackq" %%i IN (`dir/a-d/s/b %~dp0 ^|findstr/e ".cpp"`) DO (@<NUL SET/P= "%%i " >> cpps.txt)) & CALL SET/P cpps=<cpps.txt & @CALL ECHO "[CPP_PATH]: !cpps:~0,-1!" & DEL/Q cpps.txt

:: 위와 마찬가지로 CMD에서 쓸 경우에는 다음과 같이 바꾸어주셔야 합니다.

:: # CMD：.cpp 파일들을 탐색한 후, "변수"에 넣고 출력합니다 =================
:: ## <DIRECTORY_PATH> 경로 밑의 .cpp 파일들의 경로를 cpps 파일에 저장한 뒤 ECHO 로 출력합니다
::(FOR /F "usebackq" %i IN (`dir/a-d/s/b <DIRECTORY_PATH> ^|findstr/e ".cpp"`) DO @(@<NUL SET/P= "%i " >> cpps.txt)) & CALL SET/P cpps=<cpps.txt & CALL ECHO "[CPP_PATH]: %cpps:~0,-1%" & DEL/Q cpps.txt


:: # CMD：.cpp 파일들을 탐색한 후, "변수"에 넣고 gcc 로 빌드합니다 ==========
::(FOR /F "usebackq" %i IN (`dir/a-d/s/b <DIRECTORY_PATH> ^|findstr/e ".cpp"`) DO @(CALL SET cpps=%cpps% %i)) & CALL g++ %cpps:~7% -o ${fileDirname}\\${fileBasenameNoExtension}.exe
```

- <DIRECTORY_PATH> = ${fileDirname} 경로 맞춰주기

```json
{
  "version": "2.0.0",
  "tasks": [
    {
      "label": "[CMD] .cpp 경로 출력",
      "detail": ".cpp 파일들의 경로를 cpps 변수에 저장한 뒤 ECHO 로 출력합니다",
      "type": "cppbuild",
      "group": {
        "kind": "build",
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
        "@(CALL",
        "SET",
        "cpps=%cpps%",
        "%i))",
        "&",
        "CALL",
        "ECHO",
        "%cpps:~7%"
      ]
    }
  ]
}
```

- [CMD] .cpp 경로 출력

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

### gcc (g++)

- [라이브러리 추가](https://blog.naver.com/jodi999/220824963844)
- [라이브러리 추가 + 스택오버플로우](https://stackoverflow.com/questions/6141147/how-do-i-include-a-path-to-libraries-in-g)

```

```

## 추가내용.

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

  ```json
  {
    "configurations": [
      {
        "name": "Win32",
        "includePath": [
          "${workspaceFolder}/**",
          // msys64 설치 경로에 따라 수정할 것
          "C:/msys64/mingw64/include"
        ],
        "defines": ["_DEBUG", "UNICODE", "_UNICODE"],
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
