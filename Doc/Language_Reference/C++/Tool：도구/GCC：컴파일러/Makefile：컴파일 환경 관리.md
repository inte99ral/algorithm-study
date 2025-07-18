# Makefile：컴파일 환경 관리

## 목차

- [Makefile：컴파일 환경 관리](#makefile컴파일-환경-관리)
  - [목차](#목차)
  - [개요](#개요)
  - [사용 방법](#사용-방법)
  - [Makefile 파일 작성법](#makefile-파일-작성법)
  - [Makefile 내장 변수](#makefile-내장-변수)
  - [Makefile 명령어](#makefile-명령어)
  - [Makefile 타겟팅](#makefile-타겟팅)
  - [Makefile 파일 디버깅](#makefile-파일-디버깅)
    - [ERROR "Makefile:4: \*\*\* missing separator. Stop."](#error-makefile4--missing-separator-stop)

## 개요

&nbsp; 개발 시에 컴파일러에게 어떻게 빌드해야 하는 지 명령을 줘야합니다. 여기에는 라이브러리 인터페이스 경로, 라이브러리 참조 경로 설정, 라이브러리 링크 목록, 컴파일 할 대상 코드 파일 목록, 빌드된 출력 파일 경로 등의 정보 등 여러 정보들이 들어갑니다.

&nbsp; 이걸 코딩 때 마다 하면 정말 귀찮습니다. Makefile Tools는 Visual Studio Code에서 Makefile로 관리하여 컴파일 환경 관리를 쉽게 만들어 줍니다.

## 사용 방법

1. VSCode 확장 마켓플레이스에서 "Makefile Tools" 확장을 검색하여 설치해주세요.
2. 프로젝트 **루트 디렉토리**에 "Makefile" 이라는 이름의 파일을 생성합니다
3. Makefile에 필요한 빌드 규칙과 타겟을 작성합니다. 상세설명은 밑에 별도로 하겠습니다.
4. `ctrl + ｀` 로 vscode 쉘을 열고 make 명령어를 입력하면 됩니다. 상세설명은 밑에 별도로 하겠습니다.

## Makefile 파일 작성법

Makefile은 프로젝트 빌드 자동화를 위한 도구입니다. 기본적인 Makefile 작성법은 다음과 같습니다.

```Makefile
variable

target: dependencies
    commands
```

- variable: 변수 정의
- target: 생성할 파일 이름
- dependencies: target을 만드는 데 필요한 파일들
- commands: target을 만들기 위해 실행할 명령어 (반드시 탭으로 들여쓰기)

- **변수 정의**

&nbsp; 변수 정의는 다음과 같이 `=` 등호로 정의합니다.

```Makefile
CC = gcc
CFLAGS = -Wall -g
```

&nbsp; 정의된 변수들은 `$` 를 이용해서 사용할 수 있습니다.

```Makefile
$(CC)
$(CFLAGS)
```

## Makefile 내장 변수

&nbsp; 미리 정의되어 있는 내장 변수들은 다음과 같이 쓸 수 있습니다.

- $@: 현재 타겟의 이름
- $<: 첫 번째 의존성 파일 이름
- $^: 모든 의존성 파일 이름

&nbsp; 예를 들면 다음과 같이 사용됩니다.

```Makefile
%.o: %.c
    $(CC) $(CFLAGS) -c $< -o $@
```

&nbsp; Makefile에서 첫 번째 의존성 이후의 의존성 값들을 얻으려면 `$(wordlist 2,$(words $^),$^)` 라는 정의로 단어를 추출할 수 있습니다. 이 방법은 $^ (모든 의존성)에서 두 번째 단어부터 마지막 단어까지를 추출합니다.

```makefile
echo1: dep1 dep2 dep3 dep4
    @echo "All dependencies: $^"
    @echo "Dependencies after the first: $(wordlist 2,$(words $^),$^)"
```

&nbsp; 또는 `$(filter-out $<,$^)` 라는 정의로 첫 번째 의존성만 필터링해서 제외하는 방법도 있습니다.

```makefile
echo2: dep1 dep2 dep3 dep4
    @echo "All dependencies: $^"
    @echo "All dependencies except the first: $(filter-out $<,$^)"
```

## Makefile 명령어

`make` 명령어를 입력하면 정해둔 빌드 규칙과 타겟대로 자동으로 컴파일을 진행합니다. 상세한 명령어는 다음과 같습니다.

- `make build`: 프로젝트를 빌드합니다. 기본 작업으로 설정되어 있기 때문에 `make` 만 입력해도 됩니다.
- `make clean`: 빌드 산출물을 정리합니다.
- `make run`: 프로그램을 실행합니다.
- `make debug`: 디버그 모드로 빌드합니다.

## Makefile 타겟팅

`make target` 으로 타겟팅하여 여러 명령어를 골라서 쓸 수 있습니다.

```Makefile
CC = gcc
CFLAGS = -Wall -g
OBJS = main.o helper.o
TARGET = myprogram

$(TARGET): $(OBJS)
    $(CC) $(OBJS) -o $(TARGET)

%.o: %.c
    $(CC) $(CFLAGS) -c $< -o $@

clean:
    rm -f $(OBJS) $(TARGET)

.PHONY: clean
```

- 타겟팅하지 않는다면 Makefile의 첫 번째로 언급된 타겟이 디폴트 값으로 실행대상이 됩니다. 단, 마침표(.)로 시작하는 타겟은 슬래시(/)를 포함하지 않는 한 기본 목표로 취급되지 않습니다
- 기본 목표를 명시적으로 지정하고 싶다면 .DEFAULT_GOAL 특수 변수를 사용할 수 있습니다

```Makefile
.DEFAULT_GOAL := mytarget
```

- 관례적으로 많은 Makefile에서는 'all'이라는 이름의 타겟을 첫 번째로 정의하여 기본 목표로 사용합니다. 이 'all' 타겟은 보통 프로젝트에서 빌드하고자 하는 모든 것들을 의존성으로 가집니다.

## Makefile 파일 디버깅

### ERROR "Makefile:4: \*\*\* missing separator. Stop."

&nbsp; commands 는 반드시 tab 으로만 구분되어야합니다. spacebar 로는 인식이 안됩니다. 반대의 경우로 target 과 dependencies 는 공백으로 구분되어야합니다. tab 이 입력되면 commands 와 혼동합니다. 다음의 구분자 차이가 섞일 경우 make 는 명령을 제대로 수행하지 못하여 위의 오류를 출력합니다.

&nbsp; 해결하기 위해서 우선 문장에 tab 이 사용되었는 지 구분하는 명령을 통해 체크할 수 있습니다.

- 줄 앞 문자(TAB/SPACE) 확인

  - 리눅스의 경우 : `cat -A Makefile`
  - 윈도우 파워쉘의 경우 : `` Get-Content Makefile | ForEach-Object { ($\_ -replace "`t", "[TAB]") -replace " ", "[SP]" } ``
  - 원도우 파워쉘에서 줄 번호까지 출력하기 :

    ```powershell
    Get-Content Makefile | ForEach-Object -Begin { $i=1 } -Process {
        "$i`t" + (($_ -replace "`t", "[TAB]") -replace " ", "[SP]")
        $i++
    }
    ```

- 변수 선언 줄 중 TAB 문자로 시작하는 줄 찾기

  - 리눅스의 경우 : `grep -Pn '^\t[A-Z_]+\s*:=' Makefile`
  - 윈도우 파워쉘의 경우 : `Select-String -Pattern "^\t[A-Z_]+\s*:=" -Path Makefile`
  - 원도우 파워쉘에서 줄 번호까지 출력하기 :

    ```powershell
    Get-Content Makefile | ForEach-Object -Begin { $i=1 } -Process {
        if ($_ -match "^\t[A-Z_]+\s*:=") { "$i: $_" }
        $i++
    }
    ```
