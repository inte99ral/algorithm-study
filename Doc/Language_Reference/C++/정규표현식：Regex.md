# 정규표현식 - Regex

- [참고링크](https://koreanfoodie.me/959)
- [regex 라이브러리](http://www.cplusplus.com/reference/regex/)
- [ECMAScript Grammar](http://www.cplusplus.com/reference/regex/ECMAScript/)
- [참고링크](https://caniro.tistory.com/196)

## 정규표현식과 일치유무 | regex_match

```cpp
#include <iostream>
#include <regex>
#include <vector>

using namespace std;

int main() {
  vector<string> file_names = {"db-123-log.txt",
                               "db-124-log.txt",
                               "not-db-log.txt",
                               "db-12-log.txt",
                               "db-12-log.jpg"};

  regex regExp("db-\\d*-log\\.txt");

  for (const auto &file_name : file_names) cout << file_name << ": " << boolalpha << regex_match(file_name, regExp) << '\n';

  return 0;
}
```

## 정규표현식의 사용 예시

```cpp
#include <iostream>
#include <regex>

int main() {
  using namespace std;

  regex re("\\d");
  // regex   re("[ab]");
  // regex   re("[[:digit:]]{3}");
  // regex   re("[A-Z]+");
  // regex   re("[A-Z]{3}");
  // regex   re("[A-Z]{1, 5}");
  // regex   re("([0-9]{1})([-]?)([0-9]{1,4})");
  // regex   re("([0]{1}[1]{1}[0-9]{1})([-]?)([0-9]{3,4})([-]?)([0-9]{4})");
  // regex   re("([[:digit:][:alpha:]]+)([@]{1})([[:digit:][:alpha:]]+)([.]{1})([[:alpha:]]+)");

  string str;

  while (true) {
    getline(cin, str);

    if (std::regex_match(str, re))
      cout << "Match\n";
    else
      cout << "No match\n";

    auto begin = std::sregex_iterator(str.begin(), str.end(), re);
    auto end = std::sregex_iterator();
    for (auto itr = begin; itr != end; ++itr) {
      std::smatch match = *itr;
      cout << match.str() << ' ';
    }
    cout << endl;
  }
}

/* stdin
1
2
123
*/

/* stdout stderr
Match
1
Match
2
No match
1 2 3
*/
```

</br>

## cregex_token_iterator

### \[0-9\]+ char 배열 체크 예제

```cpp
#include <iostream>
#include <regex>
#include <typeinfo>
#include <vector>

#define VERSION 3.1f

using namespace std;

int main() {
  cout << "[VERSION]: " << VERSION << '\n';

  char cArr[] = "db-123-456-789-log.txt";

  regex regExp1("[0-9]+", regex::optimize);
  regex regExp2("db-\\d*-log\\.txt");

  cout << (string)cArr << " : " << sizeof(cArr) / sizeof(char) << " : " << boolalpha << regex_match(&cArr[0], &cArr[14], regExp2) << '\n';

  cregex_token_iterator iter(cArr, cArr + 15, regExp1), end;

  while (iter != end) {
    cout << stoi(*iter++) << '\n'
  }

  return 0;
}

```

## sregex_token_iterator

### \[0-9\]+ 숫자만 추출하는 예제

```cpp
#include <bits/stdc++.h>

using namespace std;

// -- Header =========================
int solution(vector<vector<int>> targets);

// -- Local Input ====================
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  vector<vector<int>> input;

  {
    string rawInput;
    string buffer;
    regex regExp("[0-9]+");


    freopen(".example\\Programmers\\question\\input.txt", "rt", stdin);
    getline(cin, rawInput);

    sregex_token_iterator iter(
      rawInput.begin(),
      rawInput.end(),
      regExp
    ), end;

    while(iter != end) {
      vector<int> tempVec = {stoi(*iter++), stoi(*iter++)};
      input.push_back(tempVec);
    }
  }

  cout << "[answer]: " + to_string(solution(input)) << '\n';
  return 0;
}

// -- Solution =======================
/**
 * 2차원 배열 데이터 전용
 */
int solution(vector<vector<int>> targets) {
  int answer = 0;

  for(vector<int> target : targets) {
    cout << "[" << target[0] << ", " << target[1] << "]" << "\n";
  }

  return answer;
}
```
