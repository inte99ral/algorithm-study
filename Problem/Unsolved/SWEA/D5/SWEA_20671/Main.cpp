#define LOCAL_JUDGE 0 // <-- 로컬파일 입력용

#define TEST bits/stdc++.h

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

  { // * NOTE-01: 동적계획법과 점화식
    /**
     * 이 문제는 처음보면 경우의 수로 푸는 문제처럼 보입니다.
     * 하지만 카드 N 개의 앞,뒤 경우의 수만 따져도 2^N 이라는 기겁할 연산을 감당해야합니다. 카드가 100장이라면 여러분이 계산해야 되는 경우의 수는 2^100 개 = 1,267,650,600,228,229,401,496,703,205,376 개 입니다.
     * 무슨 효율적인 계산을 한다고 한들 저 연산횟수를 거치면 타임아웃입니다.
     * 
     * 이 풀이의 핵심은 어차피 카드의 값이 정해진 시점부터 이 숫자가 어느 십의 자리 값인지 정해졌다는 부분입니다.
     * "333 <-> 99"  카드가 있다고 할 때, 정답은 합산값이므로 (333 * 10^0) + (99 * 10^0) 의 값을 "10^9 + 7" 로 나눈 값 입니다.
     * 여기서 333 99 보다도 작은 숫자 11 이 추가된다고 생각해봅시다.
     * 11 은 앞에 나온 모든 숫자들 보다 반드시 앞으로 오게되므로 (11 * 10^3 + 333 * 10^0) + (11 * 10^2 + 99 * 10^0) 이 됩니다.
     * 이를 추가된 숫자 11에 대해서 정리하면 (11 * (10^3 + 10^2)) + ((333 * 10^0) + (99 * 10^0)) 가 됩니다.
     * 이는 곧 지금의 계산값은 ((추가된 숫자) * (이전 계산값 모든 경우의 수의 십의 거듭제곱 합)) + (이전의 계산값) 임을 의미합니다.
     * 위 규칙은 추가되는 카드의 숫자가 앞의 숫자보다 "반드시" 앞의 순서로 온다면 절대로 깨지지 않습니다.
     * 또한, 첫번째로 들어오는 숫자가 가장 크다면 첫번째 항에서도 적용됩니다. 방금의 예시에서는 99 <- 333 <- 11 순으로 들어온다고 보장하며, x 번째 정답을 n(x), x 번째에 추가되는 숫자를 d(x) 라고 하면
     * n(0) = 0
     * n(1) = 99*10^0 
     *      = d(1)*(10^0) + n(0)
     * n(2) = 333*10^0 + 99*10^0 
     *      = d(2) * (10^0) + n(1)
     * n(3) = (11 * (10^3 + 10^2)) + ((333 * 10^0) + (99 * 10^0)) 
     *      = d(3) * (10^3 + 10^2) + n(2)
     * 
     * 따라서 이제까지 적용된 숫자들의 십의 자릿수만 따로 기록해 놓는다면, 카드를 앞면, 뒷면으로 잘라낸 뒤에 내림차순으로 소팅하고 한 장 씩 넣으면서 계산해주면 정답이 도출 된다는 것을 알 수 있습니다.
     * 100장 이면 2의 100승을 볼 필요없이 100장만 순서대로 보면 됩니다.
     */
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

    cout << t << ": " << answer << "\n";
  }
  UNSET_IO();
  return 0;
}