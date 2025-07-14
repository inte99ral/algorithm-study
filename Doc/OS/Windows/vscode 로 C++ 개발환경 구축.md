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

<!-- BOOKMARK -->

## 3. 컴파일러 설치

&nbsp; 사전에 설명드리자면, 이 글에서는 <u><b>MSYS</u></b> 와 <u><b>GCC</u></b> 를 선택합니다. 다른 컴파일러를 적용할 계획이시거나 상세한 설명을 보고 싶지 않으시면 이 단락을 넘어가셔도 좋습니다.

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

&nbsp; 그렇기 때문에 여기 설명에서는 더 확장성이 높은 GNU 프로젝트의 <u><b>GCC 컴파일러</u></b>를 기반으로 설명하겠습니다.

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

&nbsp; 알고리즘 문제 풀이 정도의 레벨에선 MinGW 만 써도 무관하나, 조금만 더 복잡한 프로그램을 개발하고 싶을 때 곧바로 발목이 잡히게 되므로 개인적으론 <u><b>MSYS 환경</u></b>을 추천합니다.

### 컴파일 환경(MSYS2) 설치

> [!Note]
>
> &nbsp; MSYS2 설치과정은 MSYS 쉘과 파워쉘, 그리고 탐색기를 왔다갔다하는 귀찮은 과정이 있습니다. MSYS tool ([깃허브 주소](https://github.com/inte99ral/msys-tool-installer)) 을 사용하면 조금 덜 귀찮게 이 단락의 과정을 넘길 수 있습니다.

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
# 아래 두 명령어 중에서 하나를 입력해주세요.
## 1) gcc 관련기능 전부 설치 (추천)
pacman -S --needed base-devel mingw-w64-ucrt-x86_64-toolchain
## 2) gcc 최소한의 기능만 설치
pacman -S mingw-w64-ucrt-x86_64-gcc

# 설치 및 버전 확인
g++ --v
gcc --v
```

## 4. 컴파일러 세팅

&nbsp; gcc 컴파일러에 이제 명령어를 입력하면 .cpp 파일을 exe 실행파일로 만들 수 있습니다.

&nbsp; 컴파일할 파일들과 라이브러리 경로들을 지정하면 명령어가 상당히 길어지기 때문에 관리하기 어려워집니다.

&nbsp; task.json 이나 Makefile 를 이용하면 자동화나 관리나 간편해집니다. 차례대로 순수하게 gcc(g++) 명령어만 사용하는 방법, task.json 을 사용하는 방법, Makefile 을 사용하는 방법을 순서대로 알려드리겠습니다.

- ① g++ only
- ② tasks.json
- ③ Makefile Tools

&nbsp; <b>각각 장단점이 다를 뿐, 셋 중 하나만</b> 알고 있어도 됩니다.

### ① g++ only

&nbsp; 깔끔하게 gcc 컴파일러만 사용해서 컴파일합니다. 명령어가 길어지면 관리가 힘들지만 추가적인 설치나 설정이 필요없기에 편합니다. 단일 파일 빌드라면 이 쪽을 선호합니다.

- ① output.exe 실행파일로 컴파일 하려는 input.cpp 파일이 있는 곳에서 터미널을 엽니다.
- ② 다음의 명령어를 입력하면 끝입니다.

  ```bash
  g++ input.cpp -o output.exe
  ```

### ② tasks.json

- [tasks.json 공식 문서](https://code.visualstudio.com/docs/editor/tasks#vscode)

&nbsp; vscode 는 귀찮은 반복작업들을 매크로화 시키는 것이 가능합니다. 이는 gcc 명령어에서도 동일합니다. 한번 작성해두면 기나긴 대상 파일들과 옵션 값들을 매번 컴파일 할 때 마다 입력하지 않아도 됩니다.

&nbsp; 장점으로는 후술할 make 도구와 같이 컴파일의 <u><b><sup>(장점1)</sup>자동화</u></b>가 가능하다는 부분입니다. 또한, cmd 명령어 매크로에 불과하기 때문에 대충 <u><b><sup>(장점2)</sup>한번 이해하면 어려운 부분이 없습니다</u></b>.

&nbsp; vscode의 빌드자동화를 네이티브로 직접 조정하기 때문에 vscode 에서 미리 정의되어 있는 자동변수들을 사용하거나 파이프, 리다이렉션등 <u><b><sup>(장점3)</sup>쉘 기능을 직접 활용할 수 있기에 더 복잡한 동작을 세밀하게 자동화</u></b> 할 수 있습니다.

&nbsp; tasks.json 및 vscode 환경에서 사용가능한 자동변수 목록과 그 정의는 다음과 같습니다.

<table>
<tr>
<th>분류</th>
<th>변수명</th>
<th>변수값</th>
</tr>
<tr>
<td rowspan="8">경로 관련 변수</td>
</tr>
<tr>
<td>${workspaceFolder}</td>
<td>현재 VSCode에서 열린 작업 폴더의 경로</td>
</tr>
<tr>
<td>${workspaceFolderBasename}</td>
<td>작업 폴더의 이름 (슬래시 없이)</td>
</tr>
<tr>
<td>${file}</td>
<td>현재 열린 파일의 전체 경로</td>
</tr>
<tr>
<td>${fileWorkspaceFolder}</td>
<td>현재 열린 파일이 속한 작업 폴더</td>
</tr>
<tr>
<td>${relativeFile}</td>
<td>작업 폴더를 기준으로 한 현재 파일의 상대 경로</td>
</tr>
<tr>
<td>${fileDirname}</td>
<td>현재 파일이 있는 디렉토리 경로</td>
</tr>
<tr>
<td>${fileExtname}</td>
<td>현재 파일의 확장자</td>
</tr>
<tr>
<td rowspan="3">파일명 관련 변수</td>
</tr>
<tr>
<td>${fileBasename}</td>
<td>현재 파일의 기본 이름 (확장자 포함)</td>
</tr>
<tr>
<td>${fileBasenameNoExtension}</td>
<td>현재 파일의 기본 이름 (확장자 제외)</td>
</tr>
<tr>
<td rowspan="3">에디터 관련 변수</td>
</tr>
<tr>
<td>${lineNumber}</td>
<td>현재 활성 파일에서 선택된 라인 번호</td>
</tr>
<tr>
<td>${selectedText}</td>
<td>현재 활성 파일에서 선택된 텍스트</td>
</tr>
<tr>
<td rowspan="4">시스템 관련 변수</td>
</tr>
<tr>
<td>${userHome}</td>
<td>사용자의 홈 폴더 경로</td>
</tr>
<tr>
<td>${pathSeparator}</td>
<td>운영 체제에 따른 경로 구분자 (macOS/Linux: '/', Windows: '')</td>
</tr>
<tr>
<td>${execPath}</td>
<td>VSCode 실행 파일의 경로</td>
</tr>
<tr>
<td rowspan="3">기타 변수</td>
</tr>
<tr>
<td>${env:Name}</td>
<td>환경 변수 참조 (예: ${env:USERNAME})</td>
</tr>
<tr>
<td>${config:Name}</td>
<td>VSCode 설정 참조 (예: ${config:editor.fontSize})</td>
</tr>

</table>

<br />

&nbsp; 단점으로는 후술할 make 도구와는 다르게 <u><b><sup>(단점1)</sup>가독성이 크게 떨어지며</u></b>, 소스코드에 작은 수정을 할 때 마다, <u><b><sup>(단점2)</sup>전체를 다시 컴파일하기 때문에 속도가 늦습니다</u></b>.

#### tasks.json 매크로 작업 정보 파일 생성

&nbsp; vscode 에서는 tasks.json 이라는 매크로 작업 정보만 있으면 바로 매크로를 사용할 수 있습니다.

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

&nbsp; 다음과 같이 tasks.json 의 tasks 안에 [ `{ ...1번째 작업 정보... }`, `{ ...2번째 작업 정보... }`, ... `{ ...n번째 작업 정보... }` ] 같은 형태로 작업 정보를 나열할 수 있습니다.

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

<br/>

&nbsp; 다음과 같이 tasks.json 의 tasks 안에서 작업정보는 다음과 같이 작성됩니다.

```json
{
  // task.json 에 대한 공식문서 https://go.microsoft.com/fwlink/?LinkId=733558
  "version": "2.0.0",
  "tasks": [
    {
      "label": "테스트 출력", // 작업 이름
      "detail": "Hello, world 를 출력합니다.", // 작업 상세설명
      "type": "shell", // 작업하는 동작의 성격
      "group": {
        "kind": "test", // 작업 분류
        "isDefault": true // 작업 우선순위
      },
      "command": "echo", // 작업 명령어
      "args": ["Hello, world!"] // 작업 명령어에 할당할 인자
    }
  ]
}
```

<br/>

&nbsp; 각 tasks 작업 오브젝트를 구분하는 이름에는 라벨과 타입, 그리고 그룹이 있습니다.

&nbsp; tasks.json 파일에서 tasks 리스트 내 객체의 <u><b>label 항목</u></b>은 작업의 이름 라벨입니다. 사용자가 구분하기 위해서 이름을 붙이는 것 이기 때문에 맘대로 정하면 됩니다.

<br/>

&nbsp; tasks.json 파일에서 tasks 리스트 내 객체의 <u><b>type 항목</u></b>은 작업의 실행 방식을 결정합니다. 주요 type으로는 shell, process, cppbuild이 있습니다.

<table>
<tr>
<th>타입</th>
<th>설명</th>
<th>예시</th>
</th>
<tr>
<td><b>shell</b></td>
<td>

- 복잡한 명령어 또는 스크립트 실행에 적합합니다.
- 시스템의 셸(예: bash, cmd.exe)을 통해 명령을 실행합니다.
- 셸의 기능(파이프, 리다이렉션 등)을 사용할 수 있습니다.
- 가장 유연하며, 복잡한 명령어 시퀀스를 실행할 수 있습니다.

</td>
<td>

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

</td>
</tr>
<tr>
<td><b>process</b></td>
<td>

- 단순한 프로그램 실행에 적합합니다.
- 운영 체제의 프로세스를 직접 실행합니다.
- 셸을 거치지 않고 프로그램을 직접 실행하므로 더 빠르고 안전할 수 있습니다.
- 단일 프로그램을 직접 실행하며, 셸 기능은 사용할 수 없습니다.
- 명령어와 인수를 분리하여 지정해야 합니다.

</td>
<td>

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

</td>
</tr>
<tr>
<td><b>cppbuild</b></td>
<td>

- 쉘 작업이 아니라 컴파일러를 실행하고 args 인자값을 넘겨주기에 process 타입과 같으나 C/C++ 프로젝트를 위한 특화된 빌드 작업 유형입니다.
- `cmd /c chcp 65001>nul && ...` 를 기반으로 명령어를 실행합니다.
- 빌드에 최적화되어 있으며, 컴파일러 설정을 자동화합니다.
- 컴파일러 경로와 인수를 자동으로 설정합니다.
- 문제 매칭(problem matching)이 자동으로 구성됩니다.

</td>
<td>

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

</td>
</tr>
</table>

<br/>

&nbsp; tasks.json 파일에서 tasks 리스트 내 객체의 <u><b>group 항목</u></b>은 vscode 가 해당 작업을 찾을 때에 쓰이는 작업의 태그입니다.

정해진 값 외에는 허용되지 않습니다. group 으로 사용되는 값은 다음의 세 종류입니다.

- build(컴파일 및 빌드)
- test(vscode 터미널에서 테스트 구동)
- none(작업을 그룹에 할당 안 함)

후술하겠지만 이렇게 그룹으로 잘 정리된 작업들은 단축키로 호출이 가능합니다.

#### tasks.json 매크로 예시

##### tasks.json 매크로 예시 > Hello, world 출력

&nbsp; tasks.json 의 tasks 값 안에 예시로 echo "Hello, world" 작업을 실행하는 매크로를 만들고 실행해보겠습니다.

```json
{
  "version": "2.0.0",
  "tasks": [
    {
      "label": "테스트 출력", // 작업 이름
      "detail": "Hello, world 를 출력합니다.", // 작업 상세설명
      "type": "shell", // 작업하는 동작의 성격
      "group": {
        "kind": "test", // 작업 분류
        "isDefault": true // 작업 우선순위
      },
      "command": "echo", // 작업 명령어
      "args": ["Hello, world!"] // 작업 명령어에 할당할 인자
    }
  ]
}
```

&nbsp; tasks.json 매크로는 다음의 방법으로 실행시킬 수 있습니다.

- ① `Ctrl+Shift+P` 또는 `F1` 을 눌러 명령 팔레트를 엽니다.
- ② `> Tasks: Run Task` 검색을 통해 해당 목록을 선택해주세요.
- ③ 우리가 만든 작업의 이름 `테스트 출력` 을 목록에서 찾아 선택해주세요.
- 쉘에 "Hello, world!" 가 출력됩니다.

<br />

##### tasks.json 매크로 예시 > CMD 변수 입출력

&nbsp; CMD 에 더 복잡한 명령도 자동화 시킬 수 있습니다.

<center>

<b>`SET var= "Hello, world!"` & CALL ECHO %var%</b>

</center>

&nbsp; SET 명령으로 var 이라는 변수에 "Hello, world!" 를 입력한 뒤에

<center>

<b>SET var= "Hello, world!" & `CALL ECHO %var%`</b>

</center>

&nbsp; ECHO 명령으로 var 이라는 변수의 값을 출력하여 보겠습니다.

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
      // * cmd로 실행할 것을 명시합니다.
      "options": {
        "shell": {
          "executable": "C:\\Windows\\System32\\cmd.exe",
          "args": ["/d", "/c"] // cmd 옵션입니다. d옵션: autorun 무시, c옵션: 명령 실행 후 작동 종료
        }
      },
      // SET var= "Hello, world!" & CALL ECHO %var%
      "command": "SET",
      "args": ["var=", "Hello, world!", "&", "CALL", "ECHO", "%var%"]
    }
  ]
}
```

&nbsp; tasks.json 매크로는 다음의 방법으로 실행시켜주세요.

- ① `Ctrl+Shift+P` 또는 `F1` 을 눌러 명령 팔레트를 엽니다.
- ② `> Tasks: Run Task` 검색을 통해 해당 목록을 선택해주세요.
- ③ 우리가 만든 작업의 이름 `cmd 테스트` 을 목록에서 찾아 선택해주세요.
- 쉘에 "Hello, world!" 가 출력됩니다.

<br />

#### tasks.json 으로 컴파일하기

> [!Warning]
>
> &nbsp; 특정 MinGW/MinGW-w64 배포판의 gcc 는 와일드카드 확장(wildcard expansion, globbing)을 자체적으로 지원하도록 빌드되어 있습니다. 이 경우에만 경로에 `**` 와일드 카드 적용이 가능합니다.
>
> &nbsp; `**.cpp` 라고 선언하면 cpp 확장자인 모든 소스코드를 의미하게 됩니다.
>
> &nbsp; 문제는 현 시점에서는 <b><u>일반적인 MSYS64 나 MinGW 의 gcc 는 와일드카드를 지원하지 않습니다.</b></u>
>
> &nbsp; 인터넷에서 `**.cpp` 를 사용한 예제도 있기 때문에 혼동할 우려가 있어 미리 말씀드립니다.

##### 기본 형태

&nbsp; main.cpp 를 같은 이름의 main.exe 실행파일로 만드는 가장 기본 형태

<center>

`g++ main.cpp -o main.exe`

</center>

&nbsp; 이 명령어를 tasks.json 에 작성하면 다음과 같은 형태입니다.

```json
{
  "version": "2.0.0",
  "tasks": [
    {
      "label": "C++: g++ 빌드",
      "detail": "-o 옵션으로 해당 파일을 컴파일합니다.",
      "type": "cppbuild",
      "group": "build",
      "command": "g++",
      "args": ["${file}", "-o", "${fileDirname}\\${fileBasenameNoExtension}"]
    }
  ]
}
```

##### 부가 옵션 형태

&nbsp; 컴파일 명령은 다음과 같이 부가 옵션이 더 많이 들어가는 경우가 있습니다.

&nbsp; 다음은 백준 등 프로그래밍 문제 사이트에서 여러 옵션과 함께 문제풀이가 담긴 단일 파일을 컴파일하는 명령어 입니다.

<center>

`g++ Main.cpp -o Main -O2 -Wall -lm -static -g -std=gnu++17`

</center>

&nbsp; 옵션들은 args 인자 리스트에 넣어주면 되며, options 항목을 통하여 작업 디렉토리 위치나 작업할 쉘까지 지정할 수 있습니다. 또한 problemMatcher 항목으로 에러 리포트를 정규표현식으로 정리하여 vscode 쉘에서 정리할 수 있습니다.

&nbsp; 이 명령어를 tasks.json 에 작성하면 다음과 같은 형태입니다.

```json
// # tasks.json
{
  "version": "2.0.0",
  "tasks": [
    // ## C++ 디버그 빌드 및 상세 설명
    {
      // ### Label: 작업의 이름(라벨명), 우리가 보고 찾는 용도이므로 한 눈에 어떤 작업인지 파악하기 쉽도록 이름을 짓는 것이 좋습니다.
      "label": "C++: g++ 디버그 빌드 (상세설명)",

      // ### Detail: 작업의 세부설명, 작업의 세부설명입니다.
      "detail": "-g 옵션으로 표준 디버깅 정보를 포함하여 빌드합니다.",

      // ### Type: 작업의 타입, 이 작업이 어떠한 유형의 작업인지 서술합니다. 대표적으로 shell(해당 명령어를 쉘에서 실행), process(해당 프로그램을 구동), cppbuild(파일 빌드 및 디버깅) 가 있습니다.
      "type": "cppbuild",

      // ### Group: 작업의 그룹, vscode가 해당 작업을 찾기 위한 작업의 태그입니다. 정해진 값 외에는 허용되지 않습니다. build(컴파일 및 빌드), test(vscode 터미널에서 테스트 구동), none(작업을 그룹에 할당 안 함) 가 있습니다.
      "group": {
        "kind": "build",
        // #### isDefault: 작업 우선순위 설정, true로 지정한 작업이 있을 경우, 다른 false는 무시되고 해당 작업을 합니다. true 지정한 작업이 복수일 경우, false는 무시되고 true 인 작업들만 목록에 올라옵니다.
        "isDefault": true
      },

      // ### Command: 작업시 실행할 명령어.
      "command": "g++",

      // ### Arguments: 작업 실행할 명령어 인자값, 각 옵션과 입력값들을 적습니다.
      "args": [
        "${file}", // 현재 vscode에서 열고있는 파일, 즉 Main.cpp
        "-o", // 출력 옵션
        "${fileDirname}/${fileBasenameNoExtension}.exe" // {Main.cpp 와 같은경로}/{Main.cpp 와 같은이름}.exe
        "-O2", //최적화 레벨 명시: O2 옵션은 loop unrolling, function inlining, 메모리 및 속도희생을 제외한 모든 범위 최적화하는 옵션
        "-Wall", // 경고 레벨 명시: Wall 은 모든 모호한 코딩에 대해서 경고를 보내는 옵션
        "-lm", // 컴파일시 라이브러리 링크 명시: lm 은 libm.a (math libarary) 고속연산을 위한 정적 라이브러리를 컴파일시 링크 한다는 옵션
        "-static", // 정적 동적 선택 명시: static 은 정적 라이브러리와 공유 라이브러리 중 정적을 우선합니다. 속도는 빠르지만 파일 사이즈가 커짐
        "-g", // 표준 디버깅 정보 포함 옵션
        "-std=c++17", // 언어 버전 명시: C++ 의 C++17 Clang GNU 확장기능을 적용한다고 선언
      ],

      // ### Options: 작업 실행 옵션, 작업 설정 등 추가적인 사항
      "options": {
        // 작업 디렉터리 주소 설정 옵션
        "cwd": "${fileDirname}",
        // 쉘 터미널 지정
        "shell": {
          }
        }
      },

      // ### Problem Matcher: 문제 상황 및 경고 문구 매칭 : 컴파일러 출력을 파싱하여 오류와 경고를 표시합니다. https://code.visualstudio.com/docs/editor/tasks#_defining-a-problem-matcher
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

##### CMD 명령프롬프트 기반 더 복잡한 명령하기

&nbsp; 개발을 하다보면 복수 개의 파일을 빌드하거나 여러 헤더파일을 링크시켜야 하는 경우가 있습니다.

<center>

`g++ <INPUT_FILE_1> <INPUT_FILE_2> ... <INPUT_FILE_n> -o <OUTPUT_FILE>`

</center>

&nbsp; 이를 위해서 쉘에서 빌드할 파일들(`<INPUT_FILE_1> <INPUT_FILE_2> ... <INPUT_FILE_n>`)을 검색해서 g++ 옵션에 기입하는 방법을 사용할 수 있습니다.

&nbsp; 예를 들어서 자체적으로 명령대체(command substitution) 가 되는 리눅스에서는 다음과 같은 명령으로 .cpp 확장자 파일을 find 함수로 검색한 결과를 g++ 명령에 집어 넣을 수 있습니다.

<center>

`g++ -g $(find . -type f -iregex \".*.cpp\") -o ${fileDirname}\\${fileBasenameNoExtension}.exe`

</center>

&nbsp; windows OS 의 파워쉘에서도 마찬가지로 다음과 같이 명령대체가 가능합니다.

<center>

`g++ $((Get-ChildItem -Path ${fileDirname} -Recurse -Force -Filter *.?pp).FullName) -o ${fileDirname}\\${fileBasenameNoExtension}.exe`

</center>

&nbsp; windows OS 의 CMD 에서는 명령대체가 훨씬 길고 복잡합니다. FOR 루프의 /F 옵션을 이용해서 구현하며 중간마다 오류나 변수값 초기화 등에서 여러가지 문제를 가지고 있습니다.

위를 windows OS 의 CMD 에서 구현하면 다음과 같은 명령어가 됩니다.

- @( ... ) 로 echo 출력을 제어하고, 2^>nul 로 에러 출력을 제어합니다.
- srcs 변수에 " " 값으로 초기화 합니다..
- FOR /F 명령대체로 srcs 변수에 파일 경로를 집어 넣습니다.
- g++ 에서 srcs 변수를 경로로써 호출합니다.

<center>

```bash
@(CALL SET "srcs= ") && (FOR /F "usebackq" %i IN (`DIR/A-D/S/B ${fileDirname}\\src 2^>nul ^|findstr/e ".cpp"`) DO @(CALL SET "srcs=%srcs% %i")) && CALL g++ %srcs:~2% ${file} -o ${fileDirname}\\${fileBasenameNoExtension}.exe
```

</center>

이를 tasks.json 에 맞춰서 폼을 변경하면 다음과 같습니다.

```json
{
  "command": "@(CALL",
  "args": [
    // * cpp 파일 목록 초기화
    "SET",
    "\"srcs= \")",
    "&&",
    // * FOR
    "(FOR",
    "/F",
    "\"usebackq\"",
    "%i",
    "IN",
    // ** FOR > dir cpp 파일 검색
    "(`DIR/A-D/S/B",
    "${fileDirname}\\src",
    // ** FOR > 에러 출력 리다이렉션
    "2^>nul",
    "^|findstr/e",
    "\".cpp\"`)",
    "DO",
    "@(CALL",
    "SET",
    "\"srcs=%srcs% %i\"",
    "))",
    "&",
    // * g++
    "CALL",
    "g++",
    // ** g++ > 타겟팅
    "%srcs:~2%",
    "${file}",
    "-o${fileDirname}\\${fileBasenameNoExtension}.exe",
    // ** g++ > 옵션
    "-O2",
    "-Wall",
    "-static",
    "-std=gnu++17",
    // ** g++ > 참조 설정
    "-ID:\\Program Files\\boost\\include\\boost-1_87",
    "-LD:\\Program Files\\boost\\lib",
    "-lboost_system-mgw14-mt-d-x64-1_87",
    "-lboost_thread-mgw14-mt-d-x64-1_87",
    "-lwsock32",
    "-lws2_32"
  ]
},
```

<br />

&nbsp; 경로가 제대로 적용되는지 확인하고 싶다면, 다음과 같이 cpps 라는 변수가 아니라 cpps.txt 라는 파일을 생성하여 확인해 볼 수 있습니다.

```json
{
  "version": "2.0.0",
  "tasks": [
    {
      "label": "cpp 모든 경로 파악",
      "detail": "경로 밑의 .cpp 파일을 찾은 후에 경로를 파일에 저장합니다.",
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
          "kind": "build",
          "isDefault": true
        },
        "options": {
          "cwd": "${workspaceFolder}"
        },
        "problemMatcher": []
      }
    ]
  }
  ```

## 5. visual studio code 보조 세팅

1. 환경변수 추가

GCC 개발 환경 자체에 참조 경로를 추가하려면 환경 변수를 설정해야 합니다.
다음의 환경변수들을 만들거나, 이미 있을 경우 편집하여 경로들을 추가해주세요.

- C 헤더 파일의 경로를 C_INCLUDE_PATH 환경 변수에 추가합니다.
- C++ 헤더 파일 경로를 CPLUS_INCLUDE_PATH 환경 변수에 추가합니다
- 라이브러리 파일의 경로를 LIBRARY_PATH 환경 변수에 추가합니다.

2. VSCode의 IntelliSense 설정

&nbsp; VSCode의 IntelliSense는 지능형 코드 완성 도구입니다. 반복되는 코드를 자동완성 해주며 빌드 전에 오탈자를 점검해주고 잠재적인 오류를 경고해줍니다.

&nbsp; 컴파일러의 경로나 앞으로 참고하는 헤더파일 경로들을 자동으로 인식하는 데에 실패하는 경우가 있습니다. 이 경우엔 올바른 코드를 작성해도 vscode 에서 오류라고 경고합니다. 이를 해결하기 위해서는 다음과 같이 설정을 직접 변경해주셔야 합니다.

- VSCode에서 Ctrl+Shift+P를 눌러 명령 팔레트를 엽니다.
- `C/C++: Edit Configurations (JSON)` 구성편집 항목을 검색하여 선택합니다.
- 생성된 c_cpp_properties.json 파일에 다음과 같이 compilerPath, includePath에 올바른 컴파일러 경로『/COMPILER_PATH』 와 별도로 참조해야할 경로『/INCLUDE_PATH』를 기입해주세요.

```json
{
  "configurations": [
    {
      "name": "Win32",
      "compilerPath": "『/COMPILER_PATH』",
      "includePath": ["${workspaceFolder}/**", "『/INCLUDE_PATH』"]
      // ... 기타 설정들 ...
    }
  ],
  "version": 4
}
```

## 6. 총정리
