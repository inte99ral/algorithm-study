[참고링크](https://modoocode.com/196)

# 람다식：Lambda

- 람다식이란?
- 람다식의 구성
- 람다식의 활용

<br />

## 람다식이란?

함수에 접근하여 값을 반환값을 얻어와 계산하는 기존의 함수는 일회용 함수에도 저장공간을 할당해줘야 하는 불편함이 있습니다.

람다식을 선언하면 선언한 시점에서 메모리 상에 임시적으로 존재하는 클로져 (Closure) 객체가 생성됩니다. 이 클로져 객체는 함수 객체(function object) 처럼 행동합니다.

<br />

## 람다식의 구성

<center>

```cpp
// 나눗셈의 람다식
[x2](int x1) -> int { return x1 % x2; }

// compare 람다식
[](int* o1, int* o2) -> bool { return o1[2] < o2[2]; }
```

</center>
c++의 람다식은 4 개의 부분으로 구성되어 있습니다.

<br/>

1. 개시자 (`[x2]` // introducer capture)
2. 인자 (`(int x1)` // parameters)
3. 반환 타입 (`-> int` // return type)
   - 람다함수의 반환 타입을 명시한다.
4. 함수 동작 (`{return x1 % x2;}` // statement)
   - 실행할 내용을 적는다.

<br />

### 1. 개시자：Introducer Capture

<center>

<b> `[x2]`(int x1) -> int { return x1 % x2; } </b>

</center>

- 외부 변수를 기입하면 람다함수가 이를 캡쳐하여 사용할 수 있게 됩니다.
- 옵션 `&`

  ```cpp
  [&](int x1) -> int { return x1 * x2; }
  ```

  - 외부의 모든 변수를 참조에 의한 호출(Call by reference)로 가져옵니다.

  <br/>

  ```cpp
  [&x2](int x1) -> int { return x1 * x2; }
  ```

  - 특정 변수 앞에 &를 붙이면 해당 변수를 참조에 의한 호출로 가져옵니다.

  <br/>

  ```cpp
  [&, x2, x3](int x1) -> int { return x1 * x2 * x3; }
  ```

  - & 뒤에 특정 변수(위 예시에서는 x2, x3)를 별도 기입하는 것으로 특정 변수 만을 값에 의한 호출로 가져올 수 있습니다.

<br/>

- 옵션 `=`

  ```cpp
  [=](int x1) -> void { x3 = x2 * x1; }
  [=, &x2, &x3](int x1) -> void { x3 = x2 * x1; }
  ```

  - 외부의 모든 변수를 값에 의한 호출(Call by value)로 가져옵니다.
  - 특정 변수(위 예시에서는 x2, x3)를 별도 기입하는 것으로 특정 변수 만을 참조에 의한 호출로 가져올 수 있습니다.

<br />

### 2. 인자

<center>

<b> [x2]`(int x1)` -> int { return x1 % x2; } </b>

</center>

- 람다함수 실행 시 받을 매개변수들을 기입합니다.

<br />

### 3. 반환 타입

<center>

<b> [x2](int x1) `-> int` { return x1 % x2; } </b>

</center>

- 람다함수의 반환 타입을 명시해줍니다.
- 화살표를 생략하면 반환타입을 추론합니다.

  <center>

  ```cpp
  // 화살표 생략, 반환 타입 추론
  function<int()> func1 = []() { return 0; };

  // 반환 타입 명시
  function<int()> func1 = []() -> int { return 0; };
  ```

  </center>

<br />

- return type이 void 인 경우 생략하여 다음과 같이 쓸 수 있습니다.
  <center>

  ```cpp
  []() { cout << "Hello, world!" << endl; }
  ```

  </center>

<br />

### 4. 함수 성명 Statement

<center>

<b> [x2](int x1) -> int `{ return x1 % x2; }` </b>

</center>

- 함수의 동작 방침을 서술합니다.

<br />

## 람다식의 활용

```cpp
function<int()> func1 = []() -> int { return 0; };
```

<br />

- c++ 23 부터는 deducing this 를 이용하여 람다 객체에 스스로 접근할 수 있습니다.

```cpp
auto factorial = [](this auto&& self, int n) {
    if (n <= 1)
        return 1;
    return n * self(n - 1);
};

// 사용 예
int result = factorial(5);
```
