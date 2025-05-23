# 명령 프롬프트：Command Prompt

- Microsoft Windows의 기본 유틸리티로, Windows NT 계열 OS의 커맨드라인 해석기(CLI)다.

- [공식 문서](https://learn.microsoft.com/en-us/windows-server/administration/windows-commands/cmd)

## 배치 파일：Batch File

- 마이크로소프트사의 DOS 운영체제인 MS-DOS에서 명령어 입력이 번거롭거나 익숙하지 않은 사용자를 위해 만들어졌다.
- 사전에 명령어를 한번에 적어놓고 실행하는 명령어 스크립트이다.
- DB 관리와 백업, 업무 자동화, 서버 운영, 게임 실행 등 윈도우 11에 이른 현재까지도 다방면에서 굉장히 유용하게 사용된다.
- 텍스트 파일의 확장자를 bat 로 바꾸는 것으로 간편하게 만들수 있다.
- 동일한 역할을 수행하는 .cmd 확장자 파일도 있다. 똑같다고 봐도 좋으나 윈도우가 업그레이드 되는 과정에서 추가되거나 변경된 기능으로 인하여 bat 파일은 MS-DOS와 윈도우 9x 이전 환경에서 실행하고, cmd 파일은 윈도우 NT 이후의 환경에서만 실행하라고 나눠둔 것이다.
- 명령어는 대소문자를 구분하지 않습니다.

## @

어떤 명령어 앞에서 @를 붙이게 되면 해당 명령을 복창하지 말라는 의미가 됩니다.

## 기본 형식

```bat
REM 주석은
@REM 다음과 같이
: 지정할 수
:: 있습니다.

:: Hello, world! 출력 예제
:: Echo off 옵션 시, C:\> echo "a" 같은 입력된 명령은 보여주지 않고 출력값 "a" 만 보여준다.
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

## 파일 경로 파악

```bat
@ECHO OFF
CHCP 65001>NUL
SETLOCAL ENABLEDELAYEDEXPANSION

:: 파일전체경로
:: ==============================
ECHO "[파일전체경로] %0"

:: 드라이브 경로
:: ==============================
ECHO "[드라이브경로] %~dp0"

:: 드라이브 명
:: ==============================
ECHO "[드라이브　명] %~d0"

:: 경로
:: ==============================
ECHO "[경　　　　로] %~p0"

:: 파일 명
:: ==============================
ECHO "[파일　　　명] %~n0"

:: 확장자 명
:: ==============================
ECHO "[확장자　　명] %~x0"

PAUSE>NUL
EXIT
```

## 출력색 COLOR

[참고링크](https://velog.io/@joonpark/Makefile-%EA%BE%B8%EB%AF%B8%EA%B8%B0)
[참고링크](https://fredhur.tistory.com/5)

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
::   사이에 공백이 있어선 안됩니다.
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

### 파일로 출력

Just repeat the echo and >> for lines after the first. >> means that it should append to a file instead of creating a new file (or overwriting an existing file):

```bat
(
echo Here is my first line
echo Here is my second line
echo Here is my third line
)>"myNewTextFile.txt"
pause
```

```bat
echo Here is my first line > myNewTextFile.txt
echo Here is my second line >> myNewTextFile.txt
echo Here is my third line >> myNewTextFile.txt
pause
```

## 변수

[%와 %%의 차이](https://www.delftstack.com/ko/howto/batch/difference-between-and-in-batch/)
[%var 과 %var%의 차이](https://stackoverflow.com/questions/15428777/whats-the-difference-between-a-and-variable-variables)

&nbsp; 명령줄 셸에서 `%<variable>`은 교체 가능한 단일문자 매개변수를 지정합니다. MS-DOS는 대체 가능한 명령줄 매개변수로 `%1, %2, ... , %9` 을 사용합니다. `%1` 은 배치파일에 전달되는 첫번째 매개변수로 대체됩니다.

[단일인자 매개변수](https://www.metacode9.com/entry/%EB%B0%B0%EC%B9%98%ED%8C%8C%EC%9D%BC-%EB%AC%B8%EB%B2%95-1-n1-p1)

&nbsp; 다음의 예시를 통해 이해도를 높여봅시다.

```cmd
:: 명령 프롬프트 창에 명령을 직접 입력해주세요.
:: a 에 문자열 입력합니다.
SET a="Hello, world!"

:: "%a" 가 그대로 출력되고 값은 출력되지 않습니다.
ECHO "input = %a"
```

&nbsp; `%<variable>%`과 같이 양쪽에 퍼센트 기호를 사용하면 환경변수 역할을 하며 값을 대체합니다.

```cmd
:: 명령 프롬프트 창에 명령을 직접 입력해주세요.
:: a 에 문자열 입력합니다.
SET a="Hello, world!"

:: "%a" 값이 출력됩니다.
ECHO "input = %a%"
```

&nbsp; bat 배치파일에서는 cmd 프롬프트 창에 직접 입력할 때와는 다르게 퍼센트사인 두 개를 필요로 합니다 `%%<variable>`

&nbsp; 그 이유는 bat과 cmd 창 입력이 명령을 읽는 과정이 다르기 때문입니다. 예를 들어서 cmd 명령줄 셸에선 다음의 명령어를 봅시다.

<center>

<b>SET /A x=12 % (110 % 100)</b>

</center>
<br />

이를 배치 파일에서 사용하게되면 배치파일은 모든 명령을 왼쪽에서 오른쪽으로 읽으며 이 과정에서 `%<variable>%` 조건으로 다음과 같이 이해하려고 합니다.

<center>

<b>SET /A x=12 `% (110 %` 100)</b>

</center>
<br />

" (110 " 이라는 이름의 변수는 없으므로 해당 명령을 제대로 수행하지 못합니다. 따라서 배치파일에서는 %를 하나만 사용할 때는 역슬래시를 //로 사용하는 것 처럼 %% 로 사용하여야 합니다.

다음의 예시는 %%가 배치파일이 명령어를 처리하기 전에 파싱하는 과정에서 %로 바뀌는 것을 보여줍니다.

```bat
@ECHO OFF

:: "The battery is charged 50%" 라고 퍼센트 기호 하나만 출력됩니다.
SET var="The battery is charged 50%%"
ECHO %var%

:: 12를 10으로 나눈 나머지 값은 2
SET /A x=12 %% 10
ECHO %x%

PAUSE>NUL
EXIT
```

## 배열

```bat
@ECHO OFF
CHCP 65001>NUL
SETLOCAL ENABLEDELAYEDEXPANSION

SET arr1[0]=9
SET arr1[1]=8
SET arr1[1]=7

FOR /L %%i IN (0,1,5) DO (
  ECHO !arr1[%%i]!
)
ECHO.

:: ==============================
:: 배열 선언 1. 길이 계산
SET x=0
:LOOP_00
IF DEFINED arr1[%x%] (
  CALL ECHO %%arr1[%x%]%%
  SET /A x+=1
  GOTO LOOP_00
)

ECHO "배열길이: " %x%
ECHO.


:: ==============================
:: 배열 선언 2

SET arr2=1 2 3 4

FOR %%a IN (%arr2%) DO (ECHO %%a)

PAUSE>NUL
EXIT
```

## 명령줄 이동：GOTO, CALL

### 라벨 호출 CALL

```bat
@ECHO OFF
CHCP 65001>NUL
SETLOCAL ENABLEDELAYEDEXPANSION

:: # Global Variable & Constant =========================

:: # Implements Definition ==============================
CALL :FUNC_01

CALL :FUNC_02 9 10 11

ECHO 아래구문입니다.

PAUSE>NUL
EXIT

:: # Prototype Declaration ==============================
:FUNC_01
ECHO 함수 1번
GOTO :eof

:FUNC_02
ECHO 함수 2번

SET /A tempSum=%~1+%~2+%~3
ECHO 총합: %tempSum%
GOTO :eof
```

### 파일 및 함수 호출 CALL

```bat
:: CALL [drive:][path] filename [batch-parameters]
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

### 파라미터 지연 확장

! 기호를 통하여 지연된 변수확장을 사용할 수도 있습니다.
이 경우엔 파싱 시점에 변수가 확장되지 않고 계산 실행 시점에서 변수가 확장됩니다.

지연된 확장을 활성화하려면 사전에 SETLOCAL EnableDelayedExpansion 명령을 사용해야 합니다.

예시는 다음과 같습니다.

```bat
@ECHO OFF
:: n이 0이었기 때문에 "value: %n%" 이 파싱될 때 "value: 0"이 됩니다.

ECHO "sum 1 to 5"
ECHO.

SET n=0
FOR /l %%i in (1,1,5) DO (SET /a n+=%%i & ECHO "value: %n%")
ECHO.

ECHO "answer = %n%"
ECHO.

ECHO ============================
:: SETLOCAL ENABLEDELAYEDEXPANSION 명령 없이는 적용되지 않습니다.

ECHO "sum 1 to 5"
ECHO.

SET n=0
FOR /l %%i in (1,1,5) DO (SET /a n+=%%i & ECHO "value: !n!")
ECHO.

ECHO "answer = %n%"
ECHO.

ECHO ============================
:: SETLOCAL ENABLEDELAYEDEXPANSION 명령 이후에만 동작합니다.
SETLOCAL ENABLEDELAYEDEXPANSION

ECHO "sum 1 to 5"
ECHO.

SET n=0
FOR /l %%i in (1,1,5) DO (SET /a n+=%%i & ECHO "value: !n!")
ECHO.

ECHO "answer = %n%"

PAUSE>NUL
EXIT
```

- CALL 을 이용하는 방법도 있습니다.

```bat
@ECHO OFF
CHCP 65001>NUL
SETLOCAL ENABLEDELAYEDEXPANSION

:: a 변수가 적용되기 전이므로 word2 만 나옵니다.
SET a=word1 && ECHO word2 %a%

:: word2 word1
SET b=word1 && ECHO word2 !b!

:: word2 word1
SET c=word1 && CALL ECHO word2 %%c%%

PAUSE>NUL
EXIT
```

### /L 옵션

/L 옵션은 연속된 값을 의미합니다.

```bat
@ECHO OFF

:: 기본 형식은 FOR /l {%%|%}<변수> IN (시작, 간격, 끝) DO <명령>
:: FOR /L %변수 IN (시작,단계,끝) DO 명령 [명령-매개 변수]
FOR /l %%i IN (5,-1,1) DO (ECHO "LOOP : %%i")

:: 000 ~ 999 출력
FOR /L %%i IN (0,1,9) DO (
  FOR /L %%j IN (0,1,9) DO (
    FOR /L %%k IN (0,1,9) DO (
      ECHO %%i%%j%%k
    )
  )
)

PAUSE>NUL
EXIT
```

### /F 옵션

/f 옵션은 파일 구문 분석을 의미합니다.

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

#### delims：구분문자

- Delim는 텍스트나 데이터를 구분하고 구별하는 데 사용되는 문자 또는 문자열을 의미합니다. 일반적으로 컴퓨터 프로그래밍 및 데이터 처리에 사용됩니다.

#### usebackq：백틱 명령어 인식

```bat
@ECHO OFF
CHCP 65001>NUL
SETLOCAL ENABLEDELAYEDEXPANSION

:: usebackq 옵션이 없다면 `ECHO "Hello, world!"`를 문자열로 인식합니다
::answer=`ECHO
::answer="Hello, world"`
FOR %%z IN (`ECHO "Hello, world!"`) DO (
  ECHO answer=%%z
)

ECHO.

:: "Hello, world!" 를 인식하고 ' ' 로 분리하여 첫번째 토큰값인 "Hello, 만 출력합니다
:: answer="Hello,
FOR /F "usebackq" %%a IN (`ECHO "Hello, world!"`) DO (
  ECHO answer=%%a
)

ECHO.

:: 토큰 token의 시작을 디폴트인 1말고 2부터로 지정합니다
:: answer=world"
FOR /F "usebackq tokens=2" %%a IN (`ECHO "Hello, world!"`) DO (
  ECHO answer=%%a
)

ECHO.

:: 구분문자 delimiter를 디폴트인 ' '말고 ':' 로 지정합니다
:: answer="Hello, world"
FOR /F "usebackq delims=:" %%a IN (`ECHO "Hello, world!"`) DO (
  ECHO answer=%%a
)

PAUSE>NUL
EXIT
```

- 파일 폴더 검색

```bat
:: dir     > 폴더 및 파일 리스트 출력
:: %~dp0   > 같은 경로상에 있는 모든 파일
:: /a-d    > dir option. 폴더명은 검색에서 제외
:: /s      > dir option. 하위폴더 파일도 검색
:: /b      > dir option. 복잡한 테이블말고 최소포맷인 결과만 보기
:: |       > 명령 간 데이터 전달 Pipe & Redirection
:: findstr > 텍스트의 패턴을 검색합니다.
:: /e      > 줄의 끝에서 부터 검색합니다.
dir %~dp0 /a-d /s /b | findstr /e "\.txt"

dir /a-d /s /b %~dp0 | findstr /e ".cpp"


FOR /F "usebackq" %%a IN (`dir %~dp0 /a-d /s /b ^| findstr /e "\.txt"`) DO (
  ECHO TEST = %%a
)
```

#### 응용 : 검색 예제

```txt
1:감자
2:고구마
3:사과
4:귤
5:배추
6:양파
7:호박
8:딸기
9:바나나
```

```bat
@ECHO OFF
CHCP 65001>NUL
SETLOCAL ENABLEDELAYEDEXPANSION

SET /P no="번호를 입력해주세요: "

FOR /F "tokens=1,2 delims=:" %%a in (list.txt) DO (
  if "%%a"=="%no%" (
    SET item=%%b
  )
)
ECHO no=%no%
ECHO item=%item%

PAUSE>NUL
EXIT
```

#### token과 명시적으로 선언 변수

%i 에 명시적으로 선언 되는 에 대 한 문입니다. %j 및 %k 를 사용 하 여 암시적으로 선언 된 토큰 =합니다. 토큰=을 사용하여 문자 z 또는 Z보다 높은 변수를 선언하려고 시도하지 않는 경우 최대 26개의 토큰을 지정할 수 있습니다.

```bat
@ECHO OFF
CHCP 65001>NUL
SETLOCAL ENABLEDELAYEDEXPANSION

FOR /F "tokens=1-4 delims=:" %%a IN ("Hello,:World!:안녕,:세계!") DO (
  ECHO %%a
  ECHO %%b
  ECHO %%c
  ECHO %%d
)

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

### 명령 대체：Command substitution

바로 for의 /f 옵션을 쓰는 것 입니다.

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

- 예제 2

<h1>파일을 탐색하는 명령어를 명령대체하는 예시입니다.</h1>

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
```

## 괄호와 캐롯

[참고링크](https://learn.microsoft.com/ko-kr/windows-server/administration/windows-commands/echo)

블록 내에서 괄호()()로 종료되는 경우 여는 괄호와 닫는 괄호 모두 각 괄호 바로 앞에 있는 캐리트(^)를 사용하여 이스케이프해야 합니다. 예를 들어 올바르게 This is ^(now^) correct 표시됩니다 This is (now) correct.

## 인코딩 방식 변환

&nbsp; 현 윈도우즈는 대부분 EUC-KR의 확장형 cp949 방식의 인코딩을 사용합니다. 하지만 대부분의 프로그램은 가장 보편적으로 사용되는 가변길이 유니코드 체계인 utf-8 으로 인코딩하기 때문에 한글 입력이 깨질 때가 있습니다.

&nbsp; 윈도우즈의 설정에서 utf-8 으로 시스템 인코딩 체계를 변경할 수 있지만 이 경우엔 cp949 인코딩을 참조하는 기존 프로그램들이 말썽을 일으킬 수 있습니다.

&nbsp; 이를 단편적으로 해결하기 위해 `chcp 65001` 명령어로 현재 창의 인코딩 방식을 UTF-8 로 바꿀 수 있습니다. 다시 cmd창을 키면 초기화되어 cp949로 실행됩니다.

```bat
@ECHO OFF
ECHO "안녕, 세계!"

:: 다음과 같이 출력됩니다.
:: "?덈뀞, ?멸퀎!"

PAUSE>NUL
EXIT
```

```bat
@ECHO OFF
CHCP 65001
ECHO "안녕, 세계!"

:: 다음과 같이 출력됩니다.
:: Active code page: 65001
:: "안녕, 세계!"

PAUSE>NUL
EXIT
```

&nbsp; Active code page: 65001 메시지가 보기 싫다면 PAUSE>NUL 과 마찬가지로 chcp 65001>nul 로 메시지를 제거할 수 있습니다.

## 무작위

%RANDOM% 은 0부터 32767 사이의 값을 가집니다.

따라서 1부터 6까지 주사위 값을 보고 싶다면 다음의 코드를 사용할 수 있습니다.

```bat
@ECHO OFF
CHCP 65001>NUL
SETLOCAL ENABLEDELAYEDEXPANSION

FOR /L %%i IN (1,1,6) DO (
  SET /A d6=^(!RANDOM! %% 6^) + 1
  ECHO 주사위 결과 = !d6!
)

PAUSE>NUL
EXIT
```

## 템플릿

### 파워쉘에 파싱

#### 파워쉘에 일반적 파싱

```bat
@ECHO OFF
cd /d "%~dp0"

:: 파일 대기 루프
:wait
if not exist "%CD%\code.ps1" (
  ECHO "NOW LOADING..."
  timeout /t 1 >nul
  goto wait
)

:: 파싱 코드
powershell.exe -ExecutionPolicy Bypass -File "%CD%\code.ps1"
```

#### 파워쉘에 관리자 권한 파싱

- -ArgumentList에 '...'로 감싸진 문자열이 들어가면,
  내부의 "%CD%\co de.ps1"은 이미 따옴표로 감싸진 상태이므로
  PowerShell이 이를 하나의 인자로 인식할 수 있어야 합니다.

&nbsp; 문제는 관리자 권한 실행을 위해서는 외부 파워쉘(Start-Process powershell) -> 내부 파워쉘(powershell -Command) 인자를 넘기는 이중처리가 필요하며, Windows 명령줄 인자 파서와 PowerShell의 파서를 거치며 이 과정에서 인자 내부 따옴표가 사라집니다.

&nbsp; 공백이 있을 경우

&nbsp; 역슬래시+따옴표를 해두면 실제 따옴표로 변환되어 하나의 인자로 전달됩니다.

```bat
`powershell -Command "Start-Process powershell -ArgumentList '-ExecutionPolicy Bypass -File "%CD%\example.ps1"' -Verb RunAs"`


:: 띄어쓰기 있을 시 역슬래시
`powershell -Command "Start-Process powershell -ArgumentList '-ExecutionPolicy Bypass -File \"%CD%\exa mple.ps1\"' -Verb RunAs"`
```

### 컴퓨터 종료 배치 파일

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

## 데이터 리디렉션

https://superuser.com/questions/1695080/how-does-work-within-a-batch-cmd-script

|, <, >, 2>, etc.

Conditional Execution
|| and &&

## 정리필요

- 배우는 중 https://skdjjdje.tistory.com/3

- bat -> exe 변환 코드 https://sysdocu.tistory.com/1502

- 쉘 스크립트 [참고링크](https://codingdog.tistory.com/entry/%EB%A6%AC%EB%88%85%EC%8A%A4-%EC%89%98-%EC%8A%A4%ED%81%AC%EB%A6%BD%ED%8A%B8-%EC%99%80-%EC%97%90-%EB%8C%80%ED%95%B4-%EC%95%8C%EC%95%84%EB%B4%85%EC%8B%9C%EB%8B%A4)
- find -> dir /b | findstr /i "^[0-9][0-9]\*\.pdf$" [참고링크](https://stackoverflow.com/questions/1183659/windows-advanced-file-matching)
