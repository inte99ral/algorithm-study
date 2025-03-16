# 사칙연산：4 Basic Operations

## 곱하기：division

## 나누기：division

## 나머지：Modulo

&nbsp; 수 A, B, Q, R 에 대하여 A = (B \* Q) + R 가 성립하면서 동시에 0 <= R < B 가 성립하여 R을 B의 배수로 표현이 불가능하다면 이 조건 하에,

- A 는 <b>피제수(被除數, 나누어지는 수)</b>,
- B 는 <b>제수(除數, 나누는 수)</b>,
- Q 는 <b>나눗셈의 몫</b>,
- R 를 <b>나머지(또는 잉여, 剩餘, Remainder)</b>

라고 부릅니다.

&nbsp; 이 때, 나머지 연산 기호 "%" 에 대하여 다음과 같이 표현합니다.

<center>

```txt
A % B = R

A / B = Q
A = (B * Q) + R
```

</center>

&nbsp; 다른 사칙연산들과 동일하게 다항식에 대하여 확장이 가능하며 이를 <b>나머지 정리(Polynomial Remainder Theorem)</b>라고 합니다. 정식 A(x) 를 정식 B(x) 로 나누었을 때 (단 deg B(x) >= deg A(x). deg는 방정식 최고차항 차수를 뜻한다.), B(x) = A(x)Q(x) + R(x), (0 <= deg R(x) < deg A(x)) 를 만족시키는 정식 Q(x), R(x) 가 유일하게 존재한다면, 이 경우에

- Q(x) 를 몫
- R(x) 를 나머지

라고 부릅니다.

### 나머지 연산 분배 법칙

- $10^9 + 7$ 이 왜 알고리즘 문제에 자주 나오는 지, 그리고 long 범위를 넘는 수를 어떻게 다룰 지에 대하여 정리합니다.

[1](https://velog.io/@gidskql6671/%EB%82%98%EB%A8%B8%EC%A7%80Modulo-%EC%97%B0%EC%82%B0-%EB%B6%84%EB%B0%B0%EB%B2%95%EC%B9%99)
[2](https://velog.io/@brucehan/%ED%81%B0-%EC%88%98%EC%97%90%EC%84%9C-%EB%82%98%EB%A8%B8%EC%A7%80-%EA%B5%AC%ED%95%98%EB%8A%94-%EB%B0%A9%EB%B2%95)

```txt
(A + B) % p = ((A % p) + (B % p)) % p
(A * B) % p = ((A % p) * (B % p)) % p
(A - B) % p = ((A % p) - (B % p) + p) % p
(A / B) % p = (A * B^(p-2)) % p = ((A % p) * (B^(p-2) % p)) % p
```

나머지 값은 임의의 정수 Q, R과 변수 x, y에 대하여 $x = Qy + R$ 가 성립할 경우의 R값

### 나머지 연산 분배 법칙 > 덧셈

```text
(A + B) % p = ((A % p) + (B % p)) % p
```

나머지 연산의 정의에 따라 x % M = Rx 에 대하여 x = (M \* Qx) + Rx 이 성립한다.

x % M = Rx = x - (M \* Qx), y % M = Ry = y - (M \* Qy) 이며

(x % M + y % M) = (Rx + Ry) = x + y + (Qx + Qy) \* M + Rxy

이때 x + y 가 M 보다 클 수 있기 때문에

(x + y + (Qx + Qy) \* M + Rxy) % M 을 해준다면 완전히 (x + y) % M 과 같아진다.

### 나머지 연산 분배 법칙 > 뺄셈

덧셈과 같으나 음수를 막기위해 마지막에 M을 더해줄것

### 나머지 연산 분배 법칙 > 나눗셈

```txt
(A / B) % p = (A * B^(p-2)) % p = ((A % p) * (B^(p-2) % p)) % p
```

### 나머지 연산 분배 법칙 > 곱셈

```cpp
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
```
