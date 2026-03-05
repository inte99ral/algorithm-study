# 입출력：IO

</br>

## sync_with_stdio: C++ 스트림과 C 입출력과의 동기화

nbsp; C++ 언어는 입출력 시에 C++ 표준 입출력 스트림(Standard I/O Streams)을 권장합니다.

nbsp; 동시에 `printf`, `scanf` 같은 C 언어의 C 표준 입출력(stdio) 또한 지원합니다.

nbsp; 이 과정에서 printf와 cout을 섞어 써도 문제가 없이 출력 순서가 보장되도록, 기본적으로 C++의 iostream은 C의 stdio와 버퍼를 공유하며 동기화되어 있습니다.

nbsp; 이 동기화 과정에서 성능 저하(오버헤드)가 매우 심하게 발생합니다.

nbsp; 다음의 명령어를 통하여 동기화를 해제하면 이런 성능 저하를 막을 수 있습니다.

```cpp
ios_base::sync_with_stdio(false);
```

nbsp; C++ 언어에서는 입출력 클래스의 가장 기초가 되는 부모 클래스 ios_base 에서 스트림의 상태 플래그, 서식 제어, 그리고 질문하신 sync_with_stdio와 같은 모든 스트림에 공통적인 독립적 기능들을 정의합니다.

nbsp; ios_base 클래스에 정적(static) 멤버 함수로 정의되어 있는 sync_with_stdio 라는 함수가 C 입출력 버퍼와의 동기화를 {true | false} 로 변경할 수 있는 함수 입니다.

nbsp; ios_base를 상속받은 클래스 ios (`basic_ios<char>의 별칭`) 에서도 `ios::sync_with_stdio(false);` 처럼 사용할 수 있으나 타입에 무관하게 일반적이며 원형이 정의되어있는 클래스 이름을 직접 사용하는 것이 더 명확하며 권장됩니다.

nbsp; 대다수의 알고리즘 문제 풀이(PS)나 표준 문서에서는 가장 상위 클래스인 ios_base를 명시함으로써 "이 설정은 모든 입출력 스트림의 기초 설정을 건드리는 것이다" 라는 의미를 전달하는 것이 관습적인 표준이기도 합니다.

nbsp; 참고로, sync_with_stdio(false)를 선언한 상태에서 `endl` 을 사용하는 것은 고속도로를 닦아놓고 10미터마다 브레이크를 밟는 것과 같습니다.

nbsp; `cout << endl` 은 단순히 줄을 바꾸는 게 아니라, 출력 버퍼를 강제로 비우는 flush 연산을 수행합니다. 버퍼의 잉여 데이터 없는 출력과 줄바꿈을 보장하지만 매번 버퍼를 정리하는 것은 비효율적입니다. 줄바꿈 상황에선 `cout << \n` 면 충분합니다.

버퍼 연동을 해제하여 매 순간 OS 가 처리하는 버퍼 작업을 막기위해 sync 를 해제한 것인데, endl 으로 OS 에게 버퍼 정리를 명령하면 의미가 없어집니다.

시스템의 출력은 프로그램 내부 연산보다 훨씬 비싼 OS 작업입니다.

최대한 출력할 내용들을 버퍼에 많이 모았다가 한 번에 OS 시스템 콜(System Call)을 호출하는 것이 훨씬 빠릅니다.

-   \n을 쓰면 10000번의 출력을 1~2번의 시스템 콜로 끝낼 수 있습니다.
-   endl을 쓰면 10000번의 출력을 10,000번의 시스템 콜로 처리합니다.

## 입력스트림에서 한 줄 받기

입력스트림으로 부터 한 줄을 받아오는 방법은 크게 두 가지가 있습니다.

-   `cin.getline` istream 객체 멤버함수

  다음이 `cin.getline` 함수의 기본 형태입니다.

  ```cpp
  getline(char* s, streamsize n);

  getline(char* s, streamsize n, char delim);
  ```

  별도의 delim 의 parameter 값을 주지 않았다면 기본 delimiter(구분 문자) 는 `\n` 입니다.

  입력의 흐름으로부터 길이 n 까지, 또는 delim 에 닿을 때 까지 <u><b>char *s</b></u> 에 저장합니다. 

-   `std::getline` std 일반 함수

  다음은 `getline` 함수의 기본 형태입니다.

  ```cpp
  getline(isstream& is, string& str);

  getline(isstream& is, string& str, char delim);
  ```

  마찬가지로 별도의 delim 를 지정하지 않았다면 기본 delimiter(구분 문자) 는 `\n` 입니다.

  입력스트림에 대한 함수로 입력스트림 is 에서 구분문자에 닿을 때 까지의 데이터를 <u><b>string</b></u> 에 저장합니다.

## 응용 예시

### 입출력 스트림 조건 바꾸기

```cpp
#include <bits/stdc++.h>

#ifndef ONLINE_JUDGE
#define SET_IO(INPUT_DATA) \
  std::ios::sync_with_stdio(false); \
  std::cin.tie(nullptr); \
  std::cout.tie(nullptr); \
  std::ifstream *IO_FS = new std::ifstream(INPUT_DATA); \
  std::streambuf *IO_BACKUP = std::cin.rdbuf( \
    (IO_FS -> is_open()) \
      ? ((std::istream*) IO_FS) -> rdbuf() \
      : ((std::istream*) new std::stringstream(INPUT_DATA)) -> rdbuf() \
  )
#define UNSET_IO() std::cin.rdbuf(IO_BACKUP)

#else
#define SET_IO(INPUT_DATA) \
  std::ios::sync_with_stdio(false); \
  std::cin.tie(nullptr); \
  std::cout.tie(nullptr)
#define UNSET_IO() ((void) 0)
#endif

using namespace std;

int main() {
  SET_IO("_INPUT_.txt");

  int T;
  cin >> T;
  cin.ignore();

  for (int t = 0; t < T; t++) {
    string cLine;
    cin >> cLine;
    for (char c : cLine) {
      cout << c << "-";
    }
    cout << "\b \n";
  }

  UNSET_IO();
  return 0;
}
```

### 특정 조건에 맞춰서 입출력 스트림 조건 바꾸기

```cpp
#ifndef ONLINE_JUDGE

#define SET_IO(INPUT_DATA) std::ios::sync_with_stdio(false);std::cin.tie(nullptr);std::cout.tie(nullptr);std::ifstream IO_FS(INPUT_DATA);std::streambuf *IO_BACKUP=std::cin.rdbuf(IO_FS.is_open()?((std::istream*)&IO_FS)->rdbuf():((std::istream*)new std::stringstream(INPUT_DATA))->rdbuf())

#define UNSET_IO() std::cin.rdbuf(IO_BACKUP)

#else

#define SET_IO(INPUT_PATH) std::ios::sync_with_stdio(false);std::cin.tie(nullptr);std::cout.tie(nullptr)

#define UNSET_IO() ((void) 0)

#endif
```

### 내부 문자열을 입출력 스트림에 집어넣기

```cpp
#include <iostream>  // for cin
#include <sstream>   // for istringstream, stringbuf, streambuf

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  // 문자열 리터럴 암시적 문자열 연결
  string input =
      "testdata1 testdata2\n"
      "testdata3 testdata4";

  // 문자열을 버퍼로 변경, istringstream is(input) 후에 sb = is.rdbuf() 식으로 스트림으로 먼저 바꾸고 버퍼를 얻어도 무관함
  stringbuf sb(input);

  // cin의 버퍼를 rdbuf 함수로 리턴받아 backup 스트림에 연결, cin 버퍼에는 rdbuf 함수의 인수로 받은 sb 을 연결
  streambuf *backup = cin.rdbuf(&sb);

  // cin 스트림 버퍼를 더 이상 못 받을 때까지 하나씩 받아와서 출력
  string buffer;
  while (cin >> buffer) cout << buffer << '\n';

  // sb 버퍼에 연결되어 있던 cin을 초기화, 다시 backup 에 남겨둔 stdin cin 버퍼에 연결
  cin.clear();
  cin.rdbuf(backup);

  // txt 파일을 입력받아 stdin cin 버퍼에 정상적으로 연결되었는지 확인
  freopen("Test\\input.txt", "rt", stdin);

  // cin 스트림 버퍼를 더 이상 못 받을 때까지 하나씩 받아와서 출력
  while (cin >> buffer) cout << buffer << '\n';
}
```

</br>

### 내부 문자열을 입출력 스트림에 집어넣기 매크로화

-   c++ 다형성을 이용하여 `INPUT_DATA` 경로에 파일이 있을 경우엔 `ifstream` 의 스트림버퍼를 가져옵니다. 없을 경우에는 `INPUT_DATA` 문자열에 대한 `stringstream` 의 스트림버퍼를 적용하는 매크로를 생성합니다.
-   `*IO_BACKUP` 이라는 포인터 변수에 cin 쉘 입출력 스트림을 백업 해두고 `UNSET_IO()` 매크로에서 백업된 입출력스트림을 다시 cin 에 연결시킵니다.

```cpp
#include <iostream>
#include <sstream>
#include <fstream>

#ifndef ONLINE_JUDGE
#define SET_IO(INPUT_DATA) std::ios::sync_with_stdio(false);std::cin.tie(nullptr);std::cout.tie(nullptr);std::ifstream IO_FS(INPUT_DATA);std::streambuf *IO_BACKUP=std::cin.rdbuf(IO_FS.is_open()?((std::istream*)&IO_FS)->rdbuf():((std::istream*)new std::stringstream(INPUT_DATA))->rdbuf())
#define UNSET_IO() std::cin.rdbuf(IO_BACKUP)
#else
#define SET_IO(INPUT_PATH) std::ios::sync_with_stdio(false);std::cin.tie(nullptr);std::cout.tie(nullptr)
#define UNSET_IO() ((void) 0)
#endif


using namespace std;

int main() {
  // SET_IO(
  //   "INNER1 \n"
  //   "INNER2 \n"
  //   "INNER3 \n"
  // );

  SET_IO("_INPUT_.txt");

  for (string buf; cin >> buf;) {
    cout << buf << endl;
  }

  return 0;
}
```

### 정렬 조건 적용 (bool 함수 선언)

```cpp
bool compare(int a, int b) { return a > b; }

int main() {
  int a[10] = {9, 3, 5, 4, 1, 10, 8, 6, 7, 2};
  sort(a, a + 10, compare);
  return 0;
}
```

</br>

## 채우기

```cpp
// # OUTPUT
  {
    for (int y = 1; y < Y + 1; y++) {
      for (int x = 1; x < X + 1; x++) {
        if (matrix[y][x] == 0) {
          cout << "   ";
          continue;
        }

        cout.width(2);
        cout.fill(' ');
        cout << matrix[y][x] << ' ';
      }
      cout << endl;
    }
  }
```

## 소수점 출력

<https://nextcoder.tistory.com/22>
