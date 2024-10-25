#include <bits/stdc++.h>

using namespace std;

// # Prototype Declaration ==============================

// # Global Variable & Constant =========================
const long long MOD_NUM = 1000000007; // 보편적으로 나누는 값
const long long MAX_DIGIT = 10; // 나머지를 구할 수의 최대 자릿수
vector<long long> MOD_RESULT(MAX_DIGIT); // 미리 계산해둔 십진법 자릿수에 대한 MOD_NUM 나머지

// # Implements Definition ==============================
// ## Main
int main() {
  // * MOD_RESULT INITIALIZE 껍질 미리 깐 십진수 나머지 (즐겁다)
  MOD_RESULT[0] = 1;
  for(int i = 1; i < MAX_DIGIT; i++) MOD_RESULT[i] = (MOD_RESULT[i-1] * 10) % MOD_NUM;
  // 나머지 분배 공식에 의하여, N+1번째 값 = 10^(N+1) % M =  (10^N * 10) % M = ((10^N % M) * (10 % M)) % M = ((n번째 값) * 10) % M


  string str = "2147483647";
  string str2 = "5";


  for (char c : str) {
    // 십진법의 수 "abc ... m" 는 곧 (a * 10^N) + (b * 10^(N - 1)) + ... + (m * 10^(0)) 와 같으며,
    // 나누는 숫자 제수를 M이라고 하면 덧셈에 대한 나머지 분배 공식이 적용되어 (abc ... m) % M = (((a * 10^N) % M) + (b * 10^(N - 1)) % M) + ... + ((m * 10^(0) % M)) % M 과 같다.
    // 또한 각 더해지는 항 중, 임의의 x번째 항 (x * 10^(N - x)) % M) 에는 곱셈에 대한 분배 공식이 적용되어 (x * 10^(N - x)) % M) = ((x % M) * (십진법 N-x 자릿수의 나머지값)) % M
    cout << c - '0' << "\n";
  }

  return 0;
}