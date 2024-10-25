# 사칙연산：4 Basic Operations

## 곱하기：division

## 나누기：division

## 나머지：Modulo

### 나머지 연산 분배 법칙

- $10^9 + 7$ 이 왜 알고리즘 문제에 자주 나오는 지, 그리고 long 범위를 넘는 수를 어떻게 다룰 지에 대하여 알아봅시다.

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
