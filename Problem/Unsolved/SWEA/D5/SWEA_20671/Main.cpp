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
  vector<long long> decMod();

  { // * BLOCK-00: 초기화
    cin >> T;

    // 10진수에 대한 나머지 값을 사전에 정의한다.

  }

  { // * NOTE-00: 동적계획법과 점화식
    /**
     * 이 문제는 처음보면 경우의 수로 푸는 문제처럼 보입니다.
     * 하지만 카드 N 개의 앞,뒤 경우의 수만 따져도 2^N 이라는 기겁할 연산을 감당해야합니다.
     * 이 풀이의 핵심은 어차피 카드의 값이 정해진 시점부터 이 숫자가 어느 십의 자리 값인지 정해졌다는 부분입니다.
     * 예를들어, "11 <-> 55" "22 <-> 33" 카드 두 개가 있다고 한다면, 22 라는 숫자를 기준으로 잡겠습니다. 22 는 위의 경우 "11 22" 로 앞에서 세 번째거나, "22 55" 로 맨 앞에서 시작합니다.
     * 문제에서 요구하는 정답은 합산값이므로 (11 * 10^2 + 22 * 10^0) + (22 * 10^2 + 55 * 10^0) 의 값을 "10^9 + 7" 로 나눈 값 입니다.
     * 만약 여기서 뒷장이 없는 카드 "66" 를 한 장 추가한다고 생각해봅시다.
     * 이젠 정답은 추가된 카드 66 이 논리상 가장 크게 만드는 수 이므로 맨 뒤로 보내지면서 다음의 결과가 됩니다. 
     * (11 * 10^4 + 22 * 10^2 + 66 * 10^0) + (22 * 10^4 + 55 * 10^2 + 66 * 10^0) 의 나머지 값이 되겠네요. 감이 오셨나요?
     * 위의 값을 정리하면 ((11 * 10^2 + 22 * 10^0) + (22 * 10^2 + 55 * 10^0)) * 10^2 + (66 * 10^0 + 66 * 10^0) 가 됩니다.
     * 이는 곧 (11 <-> 55, 22 <-> 33 카드로 계산했던 값) * 10^(추가된 카드 66 만큼의 십의 자릿값) + (이번에 추가된 카드값 66 * 이제까지의 경우의 수) 의 형태라는 사실!
     * 추가되는 카드의 숫자가 앞의 숫자보다 "반드시" 뒤에 온다면 위 규칙은 깨지지 않습니다.
     * 따라서 이를 미리 넣었던 카드에 까지 전부 적용하면, 카드를 앞면, 뒷면으로 잘라낸 뒤에 11 22 33 55 66 순으로 소팅하고 한 장 씩 넣으면서 계산해주면 정답이 도출 된다는 것을 알 수 있습니다.
     * 100장 이면 2의 100승을 볼 필요없이 100장만 순서대로 보면 됩니다.
     */

  }



  UNSET_IO();
  return 0;
}