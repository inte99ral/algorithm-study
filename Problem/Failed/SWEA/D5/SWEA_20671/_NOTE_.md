# `D5` [SWEA 20671](https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AY5gD-HaQ-MDFAVL)：숫자 카드：오답노트

## 힌트

-   ~~정직하게 모든 조합을 찾으려고하면 가짓수만 2의 n 승 입니다.~~
-   ~~동적계획법을 사용하기.~~
-   ~~카드가 N 개라면 N 번만 루프를 돌면 된다.~~

## 오답

### C++：2025-04-15：동적계획법을 사용하여 연산의 최소화

-   | 메모리 |   시간   | 코드 길이 |
    | :----: | :------: | :-------: |
    |   -    | 시간초과 |     -     |

-   나머지 연산의 분배법칙을 활용하여 큰 수를 10진수 숫자들로 분리하여 연산을 시도했습니다.
-   10진수 숫자의 경우 동적계획법을 통해 10^n = 10 \* 10^(n - 1) 을 활용하여 풀었습니다.
-   허나 2^n 의 경우의 수 자체가 압박이었던 나머지 시간초과가 발생하였습니다.

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

## 정답

### C++：2025-04-28：동적계획법과 점화식

-   | 메모리  | 시간  | 코드 길이 |
    | :-----: | :---: | :-------: |
    | 6012 kb | 12 ms |   2444    |

&nbsp; 이 문제는 처음보면 경우의 수로 푸는 문제처럼 보입니다. 하지만 카드 N 개의 앞,뒤 경우의 수만 따져도 $2^N$ 이라는 기겁할 연산을 감당해야합니다. 카드가 100장이라면 여러분이 계산해야 되는 경우의 수는 $2^{100} = 1,267,650,600,228,229,401,496,703,205,376$ 개 입니다. 어떠한 효율적인 계산을 한다고 한들 저 연산횟수를 거치면 타임아웃입니다.

&nbsp; 이 문제의 핵심은 어차피 카드의 값이 정해진 시점부터 순서대로 배치되기 때문에 매번 새로 순서를 구할 필요가 없으며 각 숫자가 십의 자리 어디에 위치하는 지 이미 결정되었다는 부분입니다.

&nbsp; 예를 들어 `333 <-> 99` 양면 카드가 있다고 할 때, 정답은 합산값이므로 $333 + 99 = (\color{green}333 \times 10^0\color{black}) + (\color{red}99 \times 10^0\color{black})$ 의 값을 $10^9 + 7$ 로 나눈 값 입니다.

&nbsp; 여기서 단면 숫자 `11` 카드가 추가된다고 가정해봅시다. 문제의 조건대로 33311 이라는 숫자보다도 11333 이 더 작으며, 9911 보다 1199 가 더 작습니다.

&nbsp; 이때의 합산값은 $11333 + 1199 = (11 \times 10^3 + 333 \times 10^0) + (11 \times 10^2 + 99 \times 10^0)$ 이 됩니다. 이를 각각의 카드의 숫자들에 대해서 정리하면 $(\color{orange} 11 \times (10^3 + 10^2) \color{black}) + (\color{green}333 \times 10^0\color{black}) + (\color{red}99 \times 10^0\color{black})$ 입니다. 감이 오시나요?

&nbsp; 단면 숫자 `11` 카드가 아니라 `11 <-> 4` 양면 카드가 추가된다고 가정해봅시다. 이제 전과 마찬가지로 양면을 잘라 단면으로 분할시켜 보겠습니다. 이제 단면 카드 99 <- 4 <- 333 <- 11 순서로 들어오겠네요. 아까와 마찬가지로 x 번째 카드가 들어왔을 때의 총합을 a<sub>n</sub> , x 번째에 추가되는 단면 카드의 숫자를 d<sub>n</sub> 라고 하면 다음과 같습니다.

-   $a_0 = 0$

-   $a_1 = 99$ <br/>
    $\quad\, = 99 \times (10^0)$ <br/>

-   $a_2 = 499$ <br/>
    $\quad\, = (99 \times (10^0)) + (4 \times (10^2))$ <br/>

-   $a_3 = 3334 + 499$ <br/>
    $\quad\, = (99 \times (10^0)) + (4 \times (10^2 + 10^0)) + (333 \times (10^1))$ <br/>

-   $a_4 = 11333 + 1199 + 3334 + 499$ <br/>
    $\quad\, = (99 \times (10^0 + 10^0)) + (4 \times (10^2 + 10^0)) + (333 \times (10^1 + 10^0)) + (11 \times (10^2 + 10^3))$ <br/>

&nbsp; 이는 곧 최종 정답은 각 카드마다 ((카드 숫자) \* (모든 경우의 수의 십의 거듭제곱의 합)) 을 구하고 더해주면 답이 나온다는 것을 의미합니다.

&nbsp; 추가되는 카드의 숫자가 앞의 숫자보다 "반드시" 앞의 순서로 온다면 (모든 경우의 수의 십의 거듭제곱의 합) 을 좀 더 쉽게 구할 수 있습니다. 이 경우엔 순서가 역전되는 경우가 없기 때문에 연산이 전의 계산으로 부터 계속 누적되도록 계산할 수 있습니다.

&nbsp; 모든 경우의 수는 n개 카드의 앞,뒤를 상정한다면 2<sup>n</sup> 개가 됩니다. n 개 카드의 앞 숫자과 뒤의 숫자의 십의 자릿수를 기록해두는 n 개의 {int , int} 공간을 마련해두고 전부 0 으로 초기화하고 ( 예를들어, 반드시 첫번째로 들어오는 숫자 `99999` 가 있다고 생각해보면 $(99999 \times (10^0 + 10^0 + ... + 10^0))$ 겠죠? ) 숫자가 들어올 때마다 갱신해준다면 현재 시점에서 <b>'모든 경우의 수의 십의 거듭제곱의 합'</b> 을 구할 수 있습니다.

&nbsp; 결과적으로 이제까지 적용된 숫자들의 십의 자릿수만 따로 기록해 놓는다면, 카드를 앞면, 뒷면으로 잘라낸 뒤에 내림차순으로 소팅하고 한 장 씩 넣으면서 계산해주면 정답이 도출 된다는 것을 알 수 있습니다.

&nbsp; 100장 이면 2의 100승을 볼 필요없이 100장만 순서대로 보면 됩니다.

```cpp
#define LOCAL_JUDGE 0 // <-- 로컬파일 입력용

// # 『DIRECTORY_PATH』

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


int main(int argc, char* argv[]) {
  SET_IO("_INPUT_.txt");

  int T;
  vector<long long> decMod(35, 1);

  for (int i = 1; i < 35; i++) {
    decMod[i] = (decMod[i - 1] * 10) % MOD_NUM;
  }

  cin >> T;

  for (int t = 1; t <= T; t++) {
    int N; cin >> N;
    long long answer = 0;
    vector<pair<int, string>> card((N * 2), {-1, ""});
    vector<pair<int, int>> decSize(N, {0, 0});

    for (int n = 0; n < N; n++) {
      card[n * 2].first = n;
      cin >> card[n * 2].second;

      card[n * 2 + 1].first = n;
      cin >> card[n * 2 + 1].second;
    }

    sort(card.begin(), card.end(), [](auto o1, auto o2) -> bool { return o1.second + o2.second > o2.second + o1.second; });

    for (int n = 0; n < N * 2; n++) {
      // * (이전 계산값 모든 경우의 수의 십의 거듭제곱 합)
      long long decSizeAll = 1;
      for (int i = 0; i < N; i++) {
        if (i == card[n].first) continue; // 앞,뒷면 동시에 있을 순 없으므로 넘기기

        decSizeAll = (decSizeAll * ((decMod[decSize[i].first] + decMod[decSize[i].second])) % MOD_NUM) % MOD_NUM;
      }

      // * (추가된 숫자)
      long long num = 0;
      for (char c : card[n].second) num = ((num * 10) + (c - '0')) % MOD_NUM;

      // * (이번 계산값) = (이전의 계산값) + ((추가된 숫자) * (이전 계산값 모든 경우의 수의 십의 거듭제곱 합))
      answer = (answer + ((num * decSizeAll) % MOD_NUM)) % MOD_NUM;

      // * 동적계획법을 위해 이제까지의 십의 거듭제곱 데이터 남기기
      if (decSize[card[n].first].first == 0)
        decSize[card[n].first].first = card[n].second.size();
      else
        decSize[card[n].first].second = card[n].second.size();
    }

    cout << '#' << t << ' ' << answer << "\n";
  }
  UNSET_IO();
  return 0;
}
```
