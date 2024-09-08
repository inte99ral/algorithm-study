# 명령 프롬프트：Command Prompt

- Microsoft Windows의 기본 유틸리티로, Windows NT 계열 OS의 커맨드라인 해석기(CLI)다.

## 배치 파일：Batch File

- 마이크로소프트사의 DOS 운영체제인 MS-DOS에서 명령어 입력이 번거롭거나 익숙하지 않은 사용자를 위해 만들어졌다.
- 사전에 명령어를 한번에 적어놓고 실행하는 명령어 스크립트이다.
- DB 관리와 백업, 업무 자동화, 서버 운영, 게임 실행 등 윈도우 11에 이른 현재까지도 다방면에서 굉장히 유용하게 사용된다.
- 텍스트 파일의 확장자를 bat 로 바꾸는 것으로 간편하게 만들수 있다.
- 동일한 역할을 수행하는 .cmd 확장자 파일도 있다. 똑같다고 봐도 좋으나 윈도우가 업그레이드 되는 과정에서 추가되거나 변경된 기능으로 인하여 bat 파일은 MS-DOS와 윈도우 9x 이전 환경에서 실행하고, cmd 파일은 윈도우 NT 이후의 환경에서만 실행하라고 나눠둔 것이다.
- 명령어는 대소문자를 구분하지 않습니다.

## 기본 형식

```bat
REM 주석은
: 다음과 같이
:: 지정할 수 있습니다.

:: Hello, world! 출력 예제
:: Echo off 옵션 시, C:\> echo "a" 같은 입력창은 보여주지 않고 출력값 "a" 만 보여준다.
@ECHO OFF

:: Echo 명령어는 뒷 줄의 문장을 출력한다.
ECHO Hello,

:: 한 줄을 Echo. 입력으로 띄울 수 있다.
ECHO.
ECHO world!

:: 다른 입력이 있을 때까지 정지. >nul 명령어가 붙으면 "계속하려면 아무 키나 누르십시오..." 출력 조차 하지 않고 정지한다.
PAUSE>NUL
EXIT
```

## 출력색 COLOR

[참고링크](https://velog.io/@joonpark/Makefile-%EA%BE%B8%EB%AF%B8%EA%B8%B0)

```bat
echo "Default!!"
@echo "\033[31m"
echo "\033[31mRed!!"
@echo "\033[32m"
echo "\033[32mGreen!!"
```

## 입출력

```bat
@ECHO OFF
SET var="The battery is charged 50%%"
ECHO %var%

@Echo off

:: * set 은 변수에 값을 입력하는 명령입니다.
:: set <variable>=<value>
set A=10
set B=20

:: * set /a 는 변수에 계산값을 입력하는 명령입니다.
:: set /a <variable>=<mathematical expression>
set /a C=A+B

:: * set /p 는 변수에 화면 입력된 값을 입력하는 명령입니다.
:: set /p <variable>=<message>
set /p D=Input D :
set /p E=" Input E : "

:: * echo 는 뒤의 메시지를 출력하는 명령어입니다.
:: %<variable>% 의 경우 그 값을 출력합니다.
echo [A : %A%] [B : %B%] [C : %C%]
echo [D : %D%] [E : %E%]

PAUSE>NUL
EXIT
```

## 조건문

- 컴퓨터가 사용자에게 컴퓨터를 끌것인가를 물어보고, 만약 대답이 "예" 라면 종료한다. 만약 대답이 "예"가 아니면 배치 파일을 종료한다. 참고로 이 배치 파일은 MS-DOS에서는 작동하지 않는다.

```bat
@echo off
echo 컴퓨터를 지금 끌까요? (예/아니요)
set /p "shutdown=>"
if %shutdown%== "예" goto shutdown
if not "%shutdown%" == "예" goto not
:not
echo 거부하셨습니다.
pause>nul
exit
:shutdown
shutdown -s -t 0
echo 컴퓨터를 종료합니다.
pause>nul
exit
```

## 반복문

```bat
@ECHO OFF

FOR /l %%i IN (1,1,5)

PAUSE>NUL
EXIT
```

- /l 옵션

```bat
@ECHO OFF

:: 기본 형식은 FOR /l {%%|%}<변수> IN (시작, 간격, 끝) DO <명령>
FOR /l %%i IN (5,-1,1) DO (ECHO "LOOP : %i%")

PAUSE>NUL
EXIT
```

## 확장과 치환：Expansions and Substitutions

&nbsp; 리눅스에선 먼저 명령문을 tokens (words) 으로 분리한 다음 해석해야할 표현식이 있을 경우에 변수확장, 산술확장, 명령치환을 거쳐 최종 변경된 명령문을 만들게 됩니다. 그리고나서 마지막으로 불필요한 quotes 을 삭제 처리하고 작업에 들어갑니다.

[참고 링크](https://mug896.github.io/bash-shell/expansions_and_substitutions.html)

리눅스의 확장(`Expansion, ${}, $(), $(())`) 은 left-to-right 순서로 동시처리 됩니다.

- parameter expansion (파라미터 확장) : $var or ${var}
- arithmetic expansion (산술 확장) : $((expression))
- command substitution (명령 대체) : $(command)
- Process substitution (작업 치환)

cmd 에서도 비슷하게 이를 구현하는 방법이 존재합니다.

### 파라미터 확장：Parameter expansion

[%와 %%의 차이](https://www.delftstack.com/ko/howto/batch/difference-between-and-in-batch/)
[%var 과 %var%의 차이](https://stackoverflow.com/questions/15428777/whats-the-difference-between-a-and-variable-variables)

&nbsp; 명령줄 셸에서 `%<variable>`은 교체 가능한 단일문자 매개변수를 지정합니다. MS-DOS는 대체 가능한 명령줄 매개변수로 `%1, %2, ... , %9` 을 사용합니다. `%1` 은 배치파일에 전달되는 첫번째 매개변수로 대체됩니다.

&nbsp; 다음의 예시를 통해 이해도를 높여봅시다.

```cmd
:: a 에 문자열 입력
SET a="Hello, world!"

:: "%a" 가 그대로 출력됨. 값이 출력되지 않음
ECHO %a
```

&nbsp; `%<variable>%`과 같이 양쪽에 퍼센트 기호를 사용하면 환경변수 역할을 하며 값을 대체합니다.

```cmd
:: a 에 문자열 입력
SET a="Hello, world!"

:: 값이 출력됨
ECHO %a%
```

파라미터 확장은 % (퍼센트 사인) 으로 구현하고 다음 세가지 규칙을 따릅니다.

1. 퍼센트 사인으로 변수를 지칭할 수 있습니다. `%<variable>`
2. 퍼센트 사인 사이에 변수명을 넣으면 그 값으로 치환합니다. `%<variable>%`
3. bat 배치파일에서는 퍼센트사인 두 개를 필요로 합니다 `%%<variable>`

- 예를 들어서 cmd 명령줄 셸에선 다음의 명령어

```bat
FOR /f %f IN ('dir /b .') DO somecommand %f
```

이를 배치 파일에서 사용하게되면 배치파일은 모든 명령을 왼쪽에서 오른쪽으로 읽으며 이 과정에서 "퍼센트 사인 사이에 변수명을 넣으면 그 값으로 치환" 조건으로 다음과 같이 이해하려고 합니다.

<b>FOR /f %`{f in ('dir /b .') DO somecommand }`%f</b>

따라서 배치파일에서는 %를 하나만 사용할 때는 역슬래시 //의 예시처럼 %% 로 사용하여야 제대로 인식됩니다.

다음의 예시는 %%가 배치파일이 명령어를 파싱하는 과정에서 %로 바뀌는 것을 보여줍니다.

```bat
@ECHO OFF
SET var="The battery is charged 50%%"
ECHO %var%

:: "The battery is charged 50%" 라고 퍼센트 기호 하나만 출력됩니다.

PAUSE>NUL
EXIT
```

- 파라미터 지연 확장

! 기호를 통하여 지연된 변수확장을 사용할 수도 있습니다.
이 경우엔 파싱 시점에 변수가 확장되지 않고 계산 실행 시점에서 변수가 확장됩니다.

지연된 확장을 활성화하려면 사전에 SETLOCAL EnableDelayedExpansion 명령을 사용해야 합니다.

예시는 다음과 같습니다.

```bat
@ECHO OFF


SET n=0
FOR /l %%G IN (1,1,5) DO (ECHO [!n!] & SET /a n+=1)
echo Total = %n%

PAUSE>NUL
EXIT
```

```bat
@echo off
setlocal EnableDelayedExpansion
:: count to 5, storing results in a variable
set n=0
FOR /l %%G in (1,1,5) Do (echo [!n!] & set /a n+=1)
echo Total = %n%
```

### 명령 대체：Command substitution

바로 for의 /f 옵션을 쓰는 것 입니다.

for는 다른 언어와 마찬가지로 루프문 역할을 수행하는데

이중에 /f 옵션이 파일 구문 분석을 의미합니다.

```bat
:: 기본 형식 1
for /f [<parsingkeywords>] {%%|%}<variable> in (<set>) do <command> [<commandlineoptions>]

:: 기본 형식 2
for /f [<parsingkeywords>] {%%|%}<variable> in (<literalstring>) do <command> [<commandlineoptions>]

:: 명령 대체：Command Substitution
for /f [<parsingkeywords>] {%%|%}<variable> in ('<command>') do <command> [<commandlineoptions>]


:: usebackq 옵션으로 파싱 키워드를 사용하는 경우
:: 기본 형식 1
for /f [usebackq <parsingkeywords>] {%%|%}<variable> in (<set>) do <command> [<commandlineoptions>]

:: 기본 형식 2
for /f [usebackq <parsingkeywords>] {%%|%}<variable> in ('<literalstring>') do <command> [<commandlineoptions>]

:: 명령 대체：Command Substitution
for /f [usebackq <parsingkeywords>] {%%|%}<variable> in (`<command>`) do <command> [<commandlineoptions>]
```

set 인수는 하나 이상의 파일 이름을 지정합니다.

띄어쓰기 기준으로 출력되는 tokens
선언문자 기준으로 앞뒤로 구분하는 delims

<center>

<table>
<tr>
  <th>
    키워드
  </th>
  <th>
    설명
  </th>
</tr>
<tr>
  <td>

```bash
eol=<c>
```

  </td>
  <td>
    한 줄의 끝 문자 (하나의 문자)를 지정합니다.
  </td>
</tr>
<tr>
  <td>

```bash
skip=<n>
```

  </td>
  <td>
    파일의 시작 부분에 표시 하지 않으려면 줄 수를 지정 합니다.
  </td>
</tr>
<tr>
  <td>

```bash
delims=<xxx>
```

  </td>
  <td>
    구분 기호 집합을 지정합니다. 이 작업 공간 및 탭의 기본 구분 기호 집합을 대체 합니다.
  </td>
</tr>
<tr>
  <td>

```bash
tokens=<x,y,m–n>
```

  </td>
  <td>
    전달 되는 각 줄의 토큰을 지정된 조건에 대하여 반복합니다. 결과적으로, 추가 변수 이름이 할당 됩니다. <b>m-n</b>은 mth부터 n번째 토큰까지의 범위를 지정합니다. 마지막 문자는 토큰 = 문자열은 별표 (\*), 추가 변수를 할당 하 고 구문 분석 된 마지막 토큰 뒤의 나머지 텍스트는 줄에 받을 합니다.
  </td>
</tr>
<tr>
  <td>

```bash
usebackq
```

  </td>
  <td>
    따옴표로 묶은 문자열을 명령으로 실행하거나, 작은따옴표로 묶은 문자열을 리터럴 문자열로 사용하거나, 공백이 포함된 긴 파일 이름의 경우 파일 이름을 &lt;set&gt; 각각 큰따옴표로 묶을 수 있도록 지정합니다.
  </td>
</tr>
</table>

</center>

공백이 포함된 긴 파일 이름의 경우 파일 이름을 `<set>`각각 큰따옴표로 묶을 수 있도록 지정합니다.

- 예제 1

```bat
::  C ~ Z 드라이브 중에 WIN51 이라는 파일을 포함하고 있다면 해당 드라이브를 CDROM 이라는 변수로 지정해줍니다.
FOR %%a IN (C: D: E: F: G: H: I: J: K: L: M: N: O: P: Q: R: S: T: U: V: W: X: Y: Z:) DO (
  IF EXIST %%a\WIN51 SET CDROM=%%a
)
```

## 템플릿

- 컴퓨터 종료 배치 파일

  ```bat
  @echo off
  echo 컴퓨터를 지금 끌까요? (예/아니요)
  set /p "shutdown=>"
  if %shutdown%== "예" goto shutdown
  if not "%shutdown%" == "예" goto not
  :not
  echo 거부하셨습니다.
  pause>nul
  exit
  :shutdown
  shutdown -s -t 0
  echo 컴퓨터를 종료합니다.
  pause>nul
  exit
  ```

<br />

- 파일을 확장자별로 분류해서 폴더에 넣어주는 배치 파일

  ```bat
  for %%i in (*.*) do if not "%~nx0"=="%%~nxi" (
  if not exist "%%~xi\" md "%%~xi"
  move "%%i" "%%~xi"
  )
  ```

## 정리필요

- 배우는 중 https://skdjjdje.tistory.com/3

- bat -> exe 변환 코드 https://sysdocu.tistory.com/1502

- 쉘 스크립트 [참고링크](https://codingdog.tistory.com/entry/%EB%A6%AC%EB%88%85%EC%8A%A4-%EC%89%98-%EC%8A%A4%ED%81%AC%EB%A6%BD%ED%8A%B8-%EC%99%80-%EC%97%90-%EB%8C%80%ED%95%B4-%EC%95%8C%EC%95%84%EB%B4%85%EC%8B%9C%EB%8B%A4)
- find -> dir /b | findstr /i "^[0-9][0-9]\*\.pdf$" [참고링크](https://stackoverflow.com/questions/1183659/windows-advanced-file-matching)
