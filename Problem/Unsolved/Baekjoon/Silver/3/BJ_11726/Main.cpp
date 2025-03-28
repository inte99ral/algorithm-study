#include <bits/stdc++.h>

#ifndef ONLINE_JUDGE
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

vector<int> factorial_memory(1001, 0);

int factorial(int num) {
  if (num <= 1) return 1;
  if (!factorial_memory[num]) factorial_memory[num] = num * factorial(num - 1);
  return factorial_memory[num];
}

int main(int argc, char* argv[]) {
  SET_IO("_INPUT_.txt");

  int N;
  int answer;
  
  cin >> N;
  answer = 2;

  { // * MEMO 00
    /**
     * N 이다 라고 했을때, x C y 계산을 어떻게 해야하는가?
     * N 이 짝수이면 y 가 카운터 i 가 될꺼고 i 은 최대 N 이었을것, 또한 2씩 올라가야한다.
     */
  }

  { // * TASK 00: 루프 연산

    for (int i = (N % 2) + 2; i < N; i += 2) {
      cout << "| = " << i << ", || = " << (N - i) / 2 << "\n";
    }
  }

  UNSET_IO();
  return 0;
}