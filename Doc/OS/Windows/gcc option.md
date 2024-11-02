### tasks.json 상세설명 > command

- gcc 빌드에 대한 이해가 필요합니다.
- g++ gcc 차이 cout cin << 안되던데? 1 d return

[참고 문헌 링크](https://gcc.gnu.org/onlinedocs/gcc/Invoking-GCC.html)

[참고 해설](https://velog.io/@hseop/gcc-compiler-Library)

[동작 과정](https://seamless.tistory.com/2)

gcc가 실행시키는 프로그램

- 전처리기 : cpp
- 컴파일러 : cc1
- 어셈블러 : as
- 링커 : ld

[gcc option](https://blog.naver.com/seojongbeom/220907637623)

#### gcc 간단한 사용법

<table>
<tr>
  <th>
    <center>항목</center>
  </th>
  <th>
    <center>옵션</center>
  </th>
  <th>
    <center>상세설명</center>
  </th>
</tr>
<tr>
  <th rowspan=2>
    <!-- # Input/Output Options ======================= -->
    Input/Output<br />：입출력 옵션
  </th>
  <td>
    -c
  </td>
  <td>

```bash
# Stop after creating object files, don't link
# linking단계 직전인 assembling까지만 진행하여, 실행파일을 만들지 말고 object file까지만 만들어라
g++ <INPUT_FILE> -c
```

  </td>
</tr>
<tr>
  <td><h3><b>"-o"</b></h3></td>
  <td>

```bash
# 컴파일 산출물 설정 옵션

# 지정한 file명으로 실행파일을 생성하라.

# 단일 파일 컴파일
g++ <INPUT_FILE> -o <OUTPUT_FILE>
# 예시: g++ Main.cpp -o Main.exe

# 복수의 파일 컴파일
g++ <INPUT_FILE_1> <INPUT_FILE_2> ... <INPUT_FILE_n> -o <OUTPUT_FILE>
```

  </td>
</tr>
<tr>
  <th rowspan=6>
    <!-- # Path Options =============================== -->
    Path<br />：경로 옵션
  </th>
  <td>
    -I
  </td>
  <td>

```bash
# 해당 <DIRECTORY_PATH> 경로의 디렉토리에서 header file을 cumulative하게(반복해서) 찾습니다.
# 자동적으로 링크되는 주소가 아닐 경우, 헤더파일의 탐색 경로를 추가해줍니다.
# 예를 들어 바탕화면에 위치한 main.h 를 #include "main.h" 로 호출하고 싶다면 바탕화면 주소를 추가해줘야합니다.
g++ -I<HEADER_DIRECTORY_PATH>

-I/data[...]/lib
```

  </td>
</tr>
<tr>
  <td>-L</td>
  <td>

```bash
# library 경로 지정(반복 탐색 후 전부 링크)
# 해당 <DIRECTORY_PATH> 경로의 디렉토리에서 library를 cumulative(반복해서) 찾습니다.
# https://docs.redhat.com/ko/documentation/red_hat_enterprise_linux/7/html/developer_guide/gcc-using-libraries_using-library-gcc

g++ -L<LIBRARY_DIRECTORY_PATH>

-L/data[...]/lib
```

  </td>
</tr>
<tr>
  <td>-l</td>
  <td>

```bash
# library 단일 파일 링크
# 컴파일러에게 특정 라이브러리를 링크하도록 지시.
# 옵션 뒤에 라이브러리 이름을 지정. 예를 들어, -lstdc++은 C++ 표준 라이브러리를 링크.
# 뒤에 오는 라이브러리 이름은 관례에 따라 lib 접두사와 .a 확장자를 가진 정적 라이브러리 파일명
# -lfoo：links to libfoo.so(shared library) if it exists, or to libfoo.a(static library) as a second choice
g++ -l<LIBRARY_NAME>

-lfoo  # (links libfoo.a or libfoo.so)
```

  </td>
</tr>
<tr>
  <td>-Wl</td>
  <td>

```bash
# -Wl,-whole-archive
# 1단계 소스 코드를 gcc를 거쳐 obj 로 만든뒤, 2단계 obj를 LD(링커)를 거쳐 elf 만드는 "분리된" 링킹과정을 실행하지 않고 소스코드 -> gcc -> elf 로 한번에 컴파일할 경우, linking 옵션을 주기 위해서는 -Wl 옵션이 필요하다
#  -Wl,[링크 옵션들] 옵션 : gcc를 거치지 않고 바로 링크에게 옵션을 정해주고자 할 때 사용한다.(사용법은 -Wa와 동일한다.)
# Wl 은 여러 옵션을 이을 수도 있음 -Wl,aaa,bbb,ccc
# 컴파일러에게 라이브러리에 있는 모든 객체 파일을 링크하도록 지시
# 이 옵션을 사용하면 라이브러리에 있는 모든 함수가 사용될 수 있음
# dll 정적링크 옵션 https://stackoverflow.com/questions/15852677/static-and-dynamic-shared-linking-with-mingw
gcc object1.o object2.o -lMyLib2 -Wl,-Bstatic -lMyLib1 -Wl,-Bdynamic -o output

# 형식
g++ <INPUT_FILE> -l<LIBRARY_NAME> {-Wl | --whole-archive} <LIBRARY_NAME> -o <OUTPUT_FILE>

# 예시
g++ main.cpp -lstdc++ -Wl my_lib.a -o myprogram

```

  </td>
</tr>
<tr>
  <td>-static</td>
  <td>

```bash
# 컴파일러에게 모든 라이브러리를 정적으로 링크하도록 지시
# 이 옵션을 사용하면 실행 파일 크기가 커지지만, 운영 체제에 동일한 라이브러리가 설치되어 있지 않아도 프로그램이 실행될 수 있습니다.

# 형식
g++ -static <INPUT_FILE> -o <OUTPUT_FILE>

# 예시
g++ -static -static-libstdc++ main.cpp -o myprogram

```

  </td>
</tr>
<tr>
  <td>-static-libstdc++</td>
  <td>

```bash
# C++ 표준 라이브러리(libstdc++)를 정적으로 링크하도록 지시.
# -static 옵션과 함께 사용

# 형식
g++ -static -static-<LIBRARY_NAME> <INPUT_FILE> -o <OUTPUT_FILE>

# 예시
g++ -static -static-libstdc++ main.cpp -o myprogram

```

  </td>
</tr>
<tr>
  <th rowspan=4>
    <!-- # Warning Options ============================ -->
    Warning<br />：경고 옵션
  </th>
  <td>
    -v
  </td>
  <td>

```bash
# gcc version 정보
g++ -v
# 또는
g++ --version

# -v：verbose mode. message 출력을 상세히 출력합니다.
g++ -v ...<OTHER_COMMAND>
```

  </td>
</tr>
<tr>
  <td>
    -w
  </td>
  <td>

```bash
# -w：Suppress warnings. message를 간략하게 출력합니다.
g++ -w
```

  </td>
</tr>
<tr>
  <td>
    -W
  </td>
  <td>

```bash
# -W：More verbose mode. message를 -v보다도 더 많이 찍어줘라
g++ -W
```

  </td>
</tr>
<tr>
  <td><h3><b>"-Wall"</b></h3></td>
  <td>

```bash
# tells it to print out all warnings
# -Wall：Show All Warning Message. 모든 warning을 찍어줘라
g++ -Wall
```

  </td>
</tr>
<tr>
  <th rowspan=5>
    <!-- # Control Options ============================ -->
    Control<br />：언어 제약 옵션
  </th>
  <td>
    -ansi
  </td>
  <td>

```bash
# c90이라는 문법 standard에 맞게 compile 합니다
gcc -ansi
```

  </td>
</tr>
<tr>
  <td>
    -pedantic
  </td>
  <td>

```bash
# 순수한 C언어 문법에만 맞도록 c standard에 있는 문법들만 사용하고, extension을 사용하지 않는 옵션입니다.
# Linux kernel을 compile할 때는 gcc extension을 많이 사용하기 때문에 -pedantic 옵션을 사용하면 안된다.
gcc -pedantic
```

  </td>
</tr>
<tr>
  <td><h3><b>"-std="</b></h3></td>
  <td>

```bash
# standard 코드 기준점을 맞추고 그에 맞게 컴파일합니다.
# 형식
gcc -std=<C_VERSION_NAME> ...<COMMAND_LINE>

# 예시
## c99에 맞게 compile하라.
gcc -std=c99

## C++ 17 적용
g++ -std=c++17
```

  </td>
</tr>
<tr>
  <td><h3><b>"-O"</b></h3></td>
  <td>

```bash
# -O<LEVEL_NUMBER>
# 최적화 level을 설정. (0, 1-default, 2, 3가 있는데, 2 level을 주로 사용한다)
gcc -O2
```

  </td>
</tr>
<tr>
  <td>
    -Os
  </td>
  <td>

```bash
# 속도를 위한 최적화가 아닌, size를 위한 최적화를 해라
gcc -Os
```

  </td>
</tr>
<tr>
  <th rowspan=2>
    <!-- # Debugging Options ========================== -->
    Debugging<br />：디버깅 옵션
  </th>
  <td>
    -g
  </td>
  <td>

```bash
# gdb의 정보를 포함
# adds symbolic information to hello for debugging
g++ -g
```

  </td>
</tr>
<tr>
  <td>
    -pg
  </td>
  <td>

```bash
# profiler의 정보를 포함
# profiler를 통해 어떤 함수의 어떤 부분에서 시간을 많이 소요하는지 정보를 얻을 수 있습니다.
g++ -pg
```

  </td>
</tr>
<tr>
  <th rowspan=3>
    <!-- # Preprocessor Options ======================= -->
    Preprocessor<br />：전처리기 옵션
  </th>
  <td>
    -E
  </td>
  <td>

```bash
# -E：Preprocessing only
# preprocessor 작업만 실행하고 그 다음 단계인 compiling, assembling, linking 과정을 거치지 않고 정지합니다.
# 예시：gcc hello.c -E > hello.i
g++ <INPUT_FILE> -E > <OUTPUT_FILE>
```

  </td>
</tr>
<tr>
  <td>
    -D
  </td>
  <td>

```bash
# -D：외부 define 매크로 사용
# Predefine name as a macro, with definition 1.
g++ -D<MACRO_NAME>

g++ -D<MACRO_NAME>=<DEFINITION_DETAIL
```

  </td>
</tr>
<tr>
  <td>
    -U
  </td>
  <td>

```bash
# -U：외부 define 매크로 사용 취소
# Cancel any previous definition of name, either built in or provided with a -D option.
g++ -U<MACRO_NAME>
```

  </td>
</tr>
</table>

#### 비주류 옵션

-rpath (runtime library path)

shared object(.so)파일의 path를 입력하면 프로그램 실행 시 입력한 path를 search한다.
