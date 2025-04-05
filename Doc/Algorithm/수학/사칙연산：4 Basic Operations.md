# 사칙연산：4 Basic Operations

## 곱하기：division

## 나누기：division

## 나머지：Modulo

### 나머지 > 정의

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

### 페르마의 소정리

#### 페르마의 소정리 > 개념

&nbsp; 페르마의 소정리란 임의의 소수 p 와 임의의 정수 a 에 대하여, a 의 p 제곱을 p 으로 나눈 나머지는 a 를 p 로 나눈 나머지와 같다는 정리입니다.

<b>① 다음과 같이 표기하는 수학적인 약속 하에</b>

- $\mathbb{P}$는 임의의 소수들의 집합입니다.
- $\mathbb{Z}$가 임의의 정수들의 집합입니다.

$\begin{cases} p∈\mathbb{P} \\ a∈\mathbb{Z} \end{cases} ⟹ a^p≡a \; (\text{mod } p)$

<b>② 다음과 같이 표기하는 수학적인 약속 하에</b>

- 임의의 수 x, y 에 대하여 y∣x 표기는 x가 y로 나누어 떨어짐을 의미한다.
- 임의의 수 x, y 에 대하여 y⊥x 표기는 x와 y는 서로소임을 의미한다.

$\begin{cases} p∈\mathbb{P} \\ p \perp a∈\mathbb{Z} \end{cases} ⟹ a^{p-1}≡1 \; (\text{mod } p)$

&nbsp; 위 공식들은 $64^{70}$ 을 $71$로 나눈 나머지는 1이라는 것을 순식간에 알 수 있는 놀라운 정리입니다.

#### 페르마의 소정리 > 증명

&nbsp; 나누어 지지 않는 소수 p 와 정수 a 에 대하여 a 의 배수들에 대해서 생각해 볼 수 있습니다.

&nbsp; p 가 1 과 자신 외에는 나누어 떨어지지 않는 소수이므로 a 가 p 로 나누어 떨어지지 않는다면, a 의 p 보다 작은 배수 또한 p 로 나누어 떨어지지 않습니다. 또한 나머지의 정의에 따라 a 의 배수를 p 로 나눈 나머지는 p 보다 클 수 없습니다. 이를 정리하면 다음과 같습니다.

<b>정리① : <u>0 보다 크고 p 보다는 작은 임의의 자연수 x 에 대하여 (a\*x) % p 의 나머지 값은 0 보다는 크고 p 보다는 작은 자연수 입니다.</b></u>

&nbsp; 또한, 0 보다 크고 p 보다는 작은 임의의 자연수 x 에 대하여 (a\*x) % p 값이 중복되는 값이 다른 x 는 존재하지 않습니다.

&nbsp; 귀류법을 이용하여 증명할 수 있습니다. 만일 0 < x<sub>1</sub> < x<sub>2</sub> < p 이고 (a\*x<sub>1</sub>) % p = (a\*x<sub>2</sub>) % p 성립하는 두 x 값이 있다고 해봅시다.

&nbsp; 나누기의 몫과 나머지의 정의를 생각하면 (나눌 수) = (나눈 몫) \* (나누는 수) + (나머지값) 입니다. 따라서

- a\*x<sub>1</sub> = (a\*x<sub>1</sub> / p) \* p + (a\*x<sub>1</sub> % p)
- a\*x<sub>2</sub> = (a\*x<sub>2</sub> / p) \* p + (a\*x<sub>2</sub> % p)

더 큰 값인 x<sub>2</sub> 의 항에서 x<sub>1</sub> 항을 빼게 되면

- a\*(x<sub>2</sub> - x<sub>1</sub>) ={ (a\*x<sub>2</sub> / p) - (a\*x<sub>1</sub> / p) } \* p + <b>{ (a\*x<sub>2</sub> % p) - (a\*x<sub>1</sub> % p) }</b>

이 때 (a\*x<sub>1</sub>) % p = (a\*x<sub>2</sub>) % p 라고 한다면 두 값의 차이는 당연히 0 이 됩니다.

- a\*(x<sub>2</sub> - x<sub>1</sub>) ={ (a\*x<sub>2</sub> / p) - (a\*x<sub>1</sub> / p) } \* p

이는 (x<sub>2</sub> - x<sub>1</sub>) 에 대한 a 의 배수가 p 로 깔끔하게 나누어 진다는 것을 말하며, 이는 위에서 찾은 <b>정리①</b> 에 모순됩니다. 따라서 다음의 사실을 알 수 있습니다.

<b>정리② : <u>0 보다 크고 p 보다는 작은 임의의 자연수 x<sub>1</sub> 에 대하여 (a\*x<sub>1</sub>) % p 의 나머지 값들은 다른 x<sub>2</sub> 에 대한 나머지 값과 중복되지 않습니다.</b></u>

&nbsp; 정리①, 정리② 에 근거하면 1 부터 p-1 까지 x 에 대입하여 나오는 (a\*x) % p 의 값들은 p 보다 작으며 모두 달라야 하므로 1 부터 p -1 까지의 모든 수가 나오게 됩니다. 이 모든 항을 곱하고 양쪽 항의 나머지를 구하면 등식이 성립합니다.

{ (a \* 1) \* ... \* (a \* (p-1)) } % p = { 1 \* ... \* (p-1) } % p

&nbsp; 그렇기 때문에 양변을 p 로 나누는 (mod p) 조건이 주어지면 다음의 등식이 성립됩니다.

a<sup>p-1</sup> \* (p-1)! ≡ (p-1)!&nbsp;&nbsp;(mod p)

&nbsp; 소수인 p와 (p-1)! 은 공통되는 소인수가 없으므로 반드시 서로소입니다. 따라서 후에 설명되는 합동식의 성질에 따라 (p-1)! 로 양변을 나눌 수 있습니다.

<b>증명① : $\begin{cases} p∈\mathbb{P} \\ a∈\mathbb{Z} \end{cases} ⟹ a^p≡a \; (\text{mod } p)$</b>

&nbsp; 이 때, a⊥p (a와 p는 서로소이다.) 이면 양쪽 항을 a 로 나눌 수 있습니다. 그 이유는 합동식의 성질에 기반합니다.

&nbsp; y∣x (x가 y로 나누어 떨어짐) 라는 표기를 이용하여 합동식의 성질을 표기하면 다음과 같습니다. $a \equiv b \; (\text{mod } m) \iff m \mid (a - b)$

&nbsp; 이를 페르마의 소정리에 적용한다면 $a^p \equiv a \; (\text{mod } m) \iff p \mid (a^p - a) = a * (a^{p-1} - 1)$ 이 됩니다. a⊥p 라면 반드시 $(a^{p-1} - 1)$ 가 p 의 배수일 수 밖에 없습니다.

&nbsp; 따라서 $p \mid (a^{p-1} - 1)$ 임이 명백하며 $p \mid (a^{p-1} - 1) \iff a^{p-1} \equiv 1 \; (\text{mod } p)$ 가 항상 성립합니다.

<b>증명② : $\begin{cases} p∈\mathbb{P} \\ p \perp a∈\mathbb{Z} \end{cases} ⟹ a^{p-1}≡1 \; (\text{mod } p)$</b>

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
