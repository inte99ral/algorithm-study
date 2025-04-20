# `D5` [SWEA 20671](https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AY5gD-HaQ-MDFAVL)：숫자 카드：오답노트

## 힌트

- ~ ~도저히 모르겠어서 포인트 벌고 재도전하기~~
- ~~정직하게 모든 조합을 찾으려고하면 가짓수만 2의 n 승 입니다.~~

## 오답

### C++：2025-04-15：동적계획법을 사용하여 연산의 최소화

- | 메모리 |   시간   | 코드 길이 |
  | :----: | :------: | :-------: |
  |   -    | 시간초과 |     -     |

- 나머지 연산의 분배법칙을 활용하여 큰 수를 10진수 숫자들로 분리하여 연산을 시도했습니다.
- 10진수 숫자의 경우 동적계획법을 통해 10^n = 10 \* 10^(n - 1) 을 활용하여 풀었습니다.
- 허나 2^n 의 경우의 수 자체가 압박이었던 나머지 시간초과가 발생하였습니다.

```cpp
#define LOCAL_JUDGE 0 // <-- 로컬파일 입력용

// # 제한 시간 초과남

#include <bits/stdc++.h>

#ifdef LOCAL_JUDGE
  #define SET_IO(INPUT_DATA) \
    std::ios::sync_with_stdio(false); \
    std::cin.tie(nullptr); \
    std::cout.tie(nullptr); \
    std::istream* IO_S = (std::filesystem::exists(INPUT_DATA)) \
      ? (std::istream*) new std::ifstream(INPUT_DATA) \
      : (std::istream*) new std::stringstream(INPUT_DATA); \
    std::streambuf* IO_BACKUP = std::cin.rdbuf(IO_S->rdbuf())

  #define UNSET_IO() \
    std::cin.rdbuf(IO_BACKUP); \
    delete IO_S

#else
  #define SET_IO(INPUT_DATA) \
    std::ios::sync_with_stdio(false); \
    std::cin.tie(nullptr); \
    std::cout.tie(nullptr)

  #define UNSET_IO() ((void) 0)
#endif

using namespace std;

const long long MOD_NUM = 1000000007;
vector<long long> decExpVec(3001, -1);

long long decExpMod(int i) {
  if (decExpVec[i] == -1) decExpVec[i] = (i == 0) ? 1 : ((10 * decExpMod(i - 1)) % MOD_NUM);
  return decExpVec[i];
}

long long strMod(string str) {
  long long sum = 0;

  for (int i = 0; i < (int) str.size(); i++) {
    sum += ((str.at(i) - '0') * decExpMod((int) str.size() - i - 1)) % MOD_NUM;
  }

  return sum % MOD_NUM;
}

int main(int argc, char* argv[]) {
	SET_IO("_INPUT_.txt");
	int T;
  cin >> T;

	for(int t = 1; t <= T; t++) {
    int N;
    long long answer;

    cin >> N;
    answer = 0;

    vector<string> strVec(N * 2, "");

    for (int n = 0; n < N; n++) {
      cin >> strVec[n * 2];
      cin >> strVec[n * 2 + 1];
    }

    vector<int> data(N, 0);
    int size = 0;

    while (data[0] != 2) {
      if (size == N) {
        string str = "";
        multiset<string> strSet;
        for (int n = 0; n < N; n++) strSet.insert(strVec[n * 2 + data[n]]);
        for (string s : strSet) str += s;
        answer += strMod(str);

        size--;
        data[size]++;
        continue;
      }

      if (data[size] == 2) {
        data[size] = 0;
        size--;
        data[size]++;
        continue;
      }

      size++;
    }

    cout << '#' << t << ' ' << answer % MOD_NUM << "\n";
	}

	UNSET_IO();
	return 0;
}
```
