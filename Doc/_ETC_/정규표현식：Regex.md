[참고링크](https://co-no.tistory.com/entry/Linux-%EC%A0%95%EA%B7%9C%ED%91%9C%ED%98%84%EC%8B%9DRegex%EC%9D%98-%EA%B0%9C%EB%85%90%EA%B3%BC-%EA%B8%B0%EC%B4%88-%EB%AC%B8%EB%B2%95)

https://hitomis.tistory.com/68

https://blog.naver.com/rookiemodel/10139446205

- regex_iterator vs regex_token_iterator

## 사용 예시

### 괄호 안의 내용만 추출

```cpp
#include <bits/stdc++.h>

using namespace std;

int solution(string str1, string str2);

// # Prototype Declaration ====================

// # Implements Definition ====================

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  string rawInput;
  string str1;
  string str2;


  {
    freopen("Problem/Unsolved/Programmers/Level2/PG_17677/question/input.txt", "rt", stdin);

    getline(cin, rawInput);

    regex regExp("\\\"[^\\\"\\s]+");

    sregex_token_iterator iter;
    sregex_token_iterator end;

    iter = sregex_token_iterator(rawInput.begin(), rawInput.end(), regExp);

    str1 = ((string) *iter++).substr(1);
    str2 = ((string) *iter++).substr(1);
  }


  cout << solution(str1, str2);

  return 0;
}

int solution(string str1, string str2) {
  int answer = 0;

  cout << str1 << " - " << str2 << "\n";

  return answer;
}
```
