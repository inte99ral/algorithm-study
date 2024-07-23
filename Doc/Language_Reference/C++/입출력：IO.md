# 입출력

</br>

- 내부 문자열을 입출력 스트림에 집어넣기

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

- 정렬 조건 적용 (bool 함수 선언)

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

https://nextcoder.tistory.com/22
