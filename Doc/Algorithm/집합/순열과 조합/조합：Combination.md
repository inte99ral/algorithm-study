# 조합：Combination combination · 組合

## 목차

- 중복순열이란?
- [1. 수학적 경우의 수 계산](./중복순열：Permutation%20With%20Repetition.md#1-수학적-경우의-수-계산)

## 중복조합：Combination With Repetition

### 중복조합 > 정의

&nbsp; 서로 다른 n개의 원소에서 r (단, 0 < r ≤ n)개를 중복을 허용하면서 순서를 고려하지 않고 선택하는 것을 중복조합(Permutation With Combination)이라고 합니다.

### 중복조합 > 구현 0：수학적 경우의 수 계산：Mathematical Calculation

&nbsp; 가장 직관적으로 이해할 수 있습니다. 번호가 적혀져있는 N 개의 구슬을 뽑고 다시 섞은 뒤에 뽑는 것을 R 번 반복하면 나오는 경우의 수는 N 의 R제곱일 것 입니다.

<div align=center>

$_{n}\mathrm{H}_{r} = C'(n, r) = \binom{n+r-1}{r} = \binom{n+r-1}{n-1}$

</div>

## 조합

### 조합 > 정의

&nbsp; 서로 다른 n개의 원소에서 r (단, 0 < r ≤ n)개를 중복 없이, 순서를 고려하지 않고 선택하는 것을 조합이라고 합니다.

&nbsp; 순열과는 다르게 순서에 전혀 무관하며 원소 종류만 판단하기 때문에, 일반 직순열에 순서가 중복되는 케이스가 추가되는 원순열과 염주순열 같은 별개의 개념은 필요하지 않습니다.

### 조합 > 구현 0：수학적 경우의 수 계산：Mathematical Calculation

&nbsp; 가장 직관적으로 이해할 수 있습니다. 번호가 적혀져있는 N 개의 구슬을 뽑고 다시 섞은 뒤에 뽑는 것을 R 번 반복하면 나오는 경우의 수는 N 의 R제곱일 것 입니다.

<center>

$_{n}\mathrm{C}_{r} = C(n, r) = \binom{n}{r} = \frac{n!}{r!(n-r)!}$

</center>

```cpp
#include <iostream>
#include <sstream>
#include <fstream>

#define SET_IO(INPUT_DATA) std::ios::sync_with_stdio(false);std::cin.tie(nullptr);std::cout.tie(nullptr);std::ifstream fs(INPUT_DATA);std::stringstream ss(INPUT_DATA);if(fs.is_open())std::cin.rdbuf(fs.rdbuf());else std::cin.rdbuf(ss.rdbuf())

using namespace std;

int factorial(int x) { return (x == 1) || (x == 0) ? 1 : x * factorial(x - 1); }

int main() {
  SET_IO("5 3");

  int N;
  int R;
  int count;
  int *origin;

  cin >> N;
  cin >> R;
  count = 0;
  origin = new int[N];
  for (int n = 1; n <= N; n++) origin[n - 1] = n;

  cout << "[CASES]: Don't know!" << "\n";

  {
    // ### 0. Mathematical Calculation
    count = (factorial(N) / factorial(N - R)) / factorial(R);
  }

  delete[] origin;

  cout << "\n";
  cout << "[NUMBER]: " << count << "\n";

  return 0;
}
```

### 조합 > 구현 1：지역적 풀이 - For 루프：Inline Solution - For Loop Based

&nbsp; 지역적으로 뽑을 수 만큼 직접 For 루프 코드를 작성하여 중복되지 않는 경우의 수를 모두 구현합니다.

&nbsp; 예를 들어 3번 뽑는다면 for 루프를 3중으로 만들면 됩니다.

&nbsp; 선택된 원소들보다 인덱스가 작은 원소를 선택하지 않도록 유지하면 원소 간의 순서가 바뀌지 않으므로 순서만 다르고 원소의 조합이 중복된 선택을 막을 수 있습니다.

&nbsp; 일일히 만들어줘야 하는 구조상, 뽑는 수 R 을 유동적으로 변경할 수 없습니다.

&nbsp; 코드로는 다음과 같이 만들 수 있습니다.

#### 조합 > 구현 1 > C++

```cpp
#include <iostream>
#include <sstream>
#include <fstream>

#define SET_IO(INPUT_DATA) std::ios::sync_with_stdio(false);std::cin.tie(nullptr);std::cout.tie(nullptr);std::ifstream fs(INPUT_DATA);std::stringstream ss(INPUT_DATA);if(fs.is_open())std::cin.rdbuf(fs.rdbuf());else std::cin.rdbuf(ss.rdbuf())

using namespace std;

int main() {
  SET_IO("5");

  int N;
  int R;
  int count;
  int *origin;

  cin >> N;
  R = 3;
  count = 0;
  origin = new int[N];
  for (int n = 1; n <= N; n++) origin[n - 1] = n;

  cout << "[CASES]:\n";

  {
    // ### 1. Local Solution - For Loop Based
    int *select = new int[R];

    for (int i = 0; i < N - 2; i++) {
      select[0] = origin[i];

      for (int j = i + 1; j < N - 1; j++) {
        if (j == i) continue;
        select[1] = origin[j];

        for (int k = j + 1; k < N; k++) {
          if (k == i || k == j) continue;
          select[2] = origin[k];

          count++;
          for (int r = 0; r < R; r++) cout << select[r] << ' ';
          cout << '\n';
        }
      }
    }

    delete[] select;
  }

  delete[] origin;

  cout << "\n";
  cout << "[NUMBER]: " << count << "\n";

  return 0;
}
```

#### 조합 > 구현 1 > Java

```java
public class Main {
	static int N, R;
	static int[] data;
	static int[] sel; // 선택된 것

	public static void main(String[] args) {
		N = 6;
		R = 3;
		data = new int[] {1, 2, 3, 4, 5, 6};
		sel = new int[R];

		comb();
	}

	private static void comb() {
		for(int i = 0; i < N - 2; i++) {
			sel[0] = data[i];
			for(int j = (i + 1); j < N - 1; j++) {
				sel[1] = data[j];
				for(int k = (j + 1); k < N; k++) {
					sel[2] = data[k];
					System.out.println(Arrays.toString(sel));
				}
			}
		}
	}
}
```

### 조합 > 구현 2：지역적 풀이 - While 루프：Inline Solution - While Loop Based

&nbsp; 알고리즘은 For 루프와 완벽히 똑같습니다. i 루프, j 루프... 루프 안으로 들어가는 상황과 루프 밖으로 나오는 상황을 if 문으로 구현하기 때문에 전체 원소 수 N 값과 뽑을 수 R 값을 유동적으로 바꿀 수 있다.

&nbsp; data[] 배열은 for 루프의 각 i, j, ... 깊이 마다의 변수에 해당하는 값입니다.

&nbsp; size 값은 select 된 배열의 크기이면서 동시에 for 루프의 깊이를 의미합니다.

&nbsp; for(int 변수 = 0 ... ) 를 `data[size]` 값을 확인하면서 체크하는 것으로 구현합니다.

&nbsp; 순서를 작은 인덱스 -> 큰 인덱스 순으로 고정할 것이기 때문에 `data[size]` 에서 `size++` 상황이라면 이전에 `data[size + 1] = data[size] + 1` 처럼 다음 `size` 의 루프는 이전 인덱스보다 더 큰 인덱스 부터 시작하도록 만들어줍시다.

&nbsp; 코드로는 다음과 같이 만들 수 있습니다.

#### 조합 > 구현 2 > C++

```cpp
#include <iostream>
#include <sstream>
#include <fstream>

#define SET_IO(INPUT_DATA) std::ios::sync_with_stdio(false);std::cin.tie(nullptr);std::cout.tie(nullptr);std::ifstream fs(INPUT_DATA);std::stringstream ss(INPUT_DATA);if(fs.is_open())std::cin.rdbuf(fs.rdbuf());else std::cin.rdbuf(ss.rdbuf())

using namespace std;

int main() {
  SET_IO("5 2");

  int N;
  int R;
  int count;
  int *origin;

  cin >> N;
  cin >> R;
  count = 0;
  origin = new int[N];
  for (int n = 1; n <= N; n++) origin[n - 1] = n;

  cout << "[CASES]:\n";

  {
    // ### 2. Inline Solution - While Loop Based
    int *select = new int[R]();
    int *data = new int[R + 1]();
    int size = 0;

    while (data[0] < N - R + 1) {
      if (size == R) {
        count++;
        for (int r = 0; r < R; r++) cout << select[r] << ' ';
        cout << '\n';

        size--;
        data[size]++;
        continue;
      }

      if (data[size] == N - R + 1 + size) {
        data[size] = 0;
        size--;
        data[size]++;
        continue;
      }

      // * don't go to smaller index
      select[size] = origin[data[size]];
      data[size + 1] = data[size] + 1;
      size++;
    }

    delete[] data;
    delete[] select;
  }

  delete[] origin;

  cout << "\n";
  cout << "[NUMBER]: " << count << "\n";

  return 0;
}
```

### 조합 > 구현 3：지역적 풀이 - 스택 & 비트연산자：Inline Solution - Stack & Bitmask Based

&nbsp; 3의 풀이는 while 루프 하나가 매 상황 분기마다 i, k, j... 루프 상태를 구현하기 위해 과하게 복잡한 구조를 가지는 것이 보입니다.

&nbsp; 스택을 활용하여 DFS 알고리즘으로 한 요소를 다루는 상황 당, 해당 순서의 요소를 선택하지 않는 경우의 수와 선택하는 경우의 수를 스택에 쌓고, 쌓인 순서의 역순으로 빼내며 작업을 처리하면 코드 구조가 매우 단순해 집니다.

&nbsp; 구현 2번에서는 이미 선택했던 요소인지 확인하기 위하여 전체를 for 루프로 훑어봐야만 했습니다. 불리언 배열 형태에 선택유무를 저장하면 이 부분의 연산이 더 깔끔해집니다.

&nbsp; 32자리 2진값인 int 는 최대 32자리인 bool[] 처럼 쓸 수 있기 때문에 비트 연산자를 활용하면 메모리도 가벼워지며 스택에 쌓일 다른 데이터들이 int 값이므로 `array<int, 3>` 으로 쉽게 묶을 수 있습니다. 32 자리 이상의 연산을 할 경우엔 `array<int, 2 + N>`, `vector<int>` 를 사용하거나 bool[] 와 int 값 두 개를 묶은 struct 나 class 를 만들어주면 됩니다.

&nbsp; 아래의 예시에서 stack 대신 deque를 쓴 것에는 큰 이유가 없습니다. deque 가 상위 클래스로 가볍고 연산이 빠른 이유로 사용됬기 때문에 deque 만 stack 으로 바꾸면 똑같이 사용하실 수 있습니다.

&nbsp; 주석을 빼면 짧은 코드로 순열 계산이 가능합니다.

```cpp
#include <array>
#include <deque>
#include <iostream>
#include <sstream>
#include <fstream>

#define SET_IO(INPUT_DATA) std::ios::sync_with_stdio(false);std::cin.tie(nullptr);std::cout.tie(nullptr);std::ifstream fs(INPUT_DATA);std::stringstream ss(INPUT_DATA);if(fs.is_open())std::cin.rdbuf(fs.rdbuf());else std::cin.rdbuf(ss.rdbuf())

using namespace std;

int main() {
  SET_IO("5 2");

  int N;
  int R;
  int count;
  int *origin;

  cin >> N;
  cin >> R;
  count = 0;
  origin = new int[N];
  for (int n = 1; n <= N; n++) origin[n - 1] = n;

  cout << "[CASES]:\n";

  {
    // ### 3. Inline Solution - Stack & Bitmask Based
    int* select = new int[R]();

    deque<array<int, 3>> task = {{0, 0, 0}}; // data, size, curr

    while (!task.empty()) {
      int data = task.back()[0];
      int size = task.back()[1];
      int curr = task.back()[2];
      task.pop_back();

      if (size == R) {
        count++;
        for (int r = 0; r < R; r++) cout << select[r] << ' ';
        cout << '\n';
        continue;
      }

      if (curr == N) continue;

      task.emplace_back(array<int, 3>({data, size, curr + 1}));
      select[size] = origin[curr];
      task.emplace_back(array<int, 3>({data, size + 1, curr + 1}));
    }

    delete[] select;
  }

  delete[] origin;

  cout << "\n";
  cout << "[NUMBER]: " << count << "\n";

  return 0;
}
```

### 조합 > 구현 4：재귀적 풀이 - 깊이우선탐색：Recursive Solution - DFS

&nbsp; 지역적인 풀이와 다르게 중간에 값에 접근이 불가능하고 전역적인 변수를 필요로 합니다.

&nbsp; 재귀적함수로 DFS 알고리즘을 구현하면 Stack 구조보다도 단순해지고 직관적이라는 장점이 있습니다.

&nbsp; 이는 조합의 구현에서 가장 정석적인 알고리즘 입니다.

#### 조합 > 구현 4 > C++

```cpp
#include <array>
#include <deque>
#include <iostream>
#include <sstream>
#include <fstream>

#define SET_IO(INPUT_DATA) std::ios::sync_with_stdio(false);std::cin.tie(nullptr);std::cout.tie(nullptr);std::ifstream fs(INPUT_DATA);std::stringstream ss(INPUT_DATA);if(fs.is_open())std::cin.rdbuf(fs.rdbuf());else std::cin.rdbuf(ss.rdbuf())

using namespace std;

// ## Global Variable & Constant =====

int N;
int R;
int count;
int *origin;
int *select;

// ## Prototype Declaration ==========

void combRecur(int size, int curr);

// ## Implements Definition ==========

int main() {
  SET_IO("5 2");

  cin >> N;
  cin >> R;
  count = 0;
  origin = new int[N];
  for (int n = 1; n <= N; n++) origin[n - 1] = n;

  cout << "[CASES]:\n";

  {
    // ### 4. Recursive Solution - DFS
    select = new int[R]();
    combRecur(0, 0);
    delete[] select;
  }

  delete[] origin;

  cout << "\n";
  cout << "[NUMBER]: " << count << "\n";

  return 0;
}

void combRecur(int size, int curr) {
  if (size == R) {
    count++;
    for (int r = 0; r < R; r++) cout << select[r] << ' ';
    cout << '\n';
    return;
  }

  if (curr == N) return;

  for (int i = curr; i < N; i++) {
    select[size] = origin[i];
    combRecur(size + 1, i + 1);
  }
}
```

#### 조합 > 구현 4 > C++ - 폐쇄화

&nbsp; 위의 풀이는 가장 정석적이며 구현하기에 가장 간편한 구조입니다. 하지만 재귀되는 함수 combRecur 의 전역적인 변수 활용을 위해서 많은 데이터가 글로벌 스코프에 노출되어 있습니다.

&nbsp; 다음과 같이 포인터로 변수의 주소를 전달하는 방법으로 전역 변수의 사용을 피하고 폐쇄적인 함수로 만들 수 있습니다. 이제 main 함수 측이 폐쇄적인 함수 comb(원본 배열, 전체 수, 선택할 수) 만 호출하면 순열을 구할 수 있습니다.

```cpp
#include <array>
#include <deque>
#include <iostream>
#include <sstream>
#include <fstream>

#define SET_IO(INPUT_DATA) std::ios::sync_with_stdio(false);std::cin.tie(nullptr);std::cout.tie(nullptr);std::ifstream fs(INPUT_DATA);std::stringstream ss(INPUT_DATA);if(fs.is_open())std::cin.rdbuf(fs.rdbuf());else std::cin.rdbuf(ss.rdbuf())

using namespace std;

// ## Global Variable & Constant =====

// ## Prototype Declaration ==========

int comb(int* origin, int N, int R);
void combRecur(int* origin, int* select, int* ptrCount, int N, int R, int size, int curr);

// ## Implements Definition ==========

int main() {
  SET_IO("5 2");

  int N;
  int R;
  int count;
  int *origin;

  cin >> N;
  cin >> R;
  count = 0;
  origin = new int[N];
  for (int n = 1; n <= N; n++) origin[n - 1] = n;

  cout << "[CASES]:\n";

  {
    // ### 4. Recursive Solution - DFS Closed
    count = comb(origin, N, R);
  }

  delete[] origin;

  cout << "\n";
  cout << "[NUMBER]: " << count << "\n";

  return 0;
}

int comb(int* origin, int N, int R) {
  int count = 0;
  int* select = new int[R]();
  combRecur(origin, select, &count, N, R, 0, 0);
  delete[] select;
  return count;
}

void combRecur(int* origin, int* select, int* ptrCount, int N, int R, int size, int curr) {
  if (size == R) {
    (*ptrCount)++;
    for (int r = 0; r < R; r++) cout << select[r] << ' ';
    cout << '\n';
    return;
  }

  if (curr == N) return;

  for (int i = curr; i < N; i++) {
    select[size] = origin[i];
    combRecur(origin, select, ptrCount, N, R, size + 1, i + 1);
  }
}
```

#### 조합 > 구현 4 > Java

```java
public class Main {
	static int N, R;
	static int[] data;
	static int[] sel; // 선택된 것

	public static void main(String[] args) {
		N = 6;
		R = 3;
		data = new int[] {1, 2, 3, 4, 5, 6};
		sel = new int[R];

		comb(0, 0);
	}


	private static void comb(int cnt, int start) {
		if(cnt == R) {
			System.out.println(Arrays.toString(sel).replaceAll("[\\,\\[\\]]", ""));
			return;
		}
		for(int i = start; i < N; i++) {
			sel[cnt] = data[i];
			comb(cnt + 1, i + 1);
		}
	}
}
```

#### 조합 > 구현 4 > Java - 폐쇄화

```java
import java.util.Arrays;

class Combination {

  // -- Methods ====================

  public static void comb(int[] arr, int selectNumber) {
    combRecur(arr, selectNumber, -1, new int[selectNumber], 0);
    return;
  }

  public static void combRecur(
    int[] origin,
    int selectNumber,
    int selectIndex,
    int[] fixed,
    int index
  ) {
    // 전부 선택했으니 출력
    if (index == selectNumber) {
      System.out.println(Arrays.toString(fixed));
      return;
    }

    for (int i = selectIndex + 1; i < origin.length; i++) {
      fixed[index] = origin[i];
      combRecur(origin, selectNumber, i, fixed, index + 1);
    }
    return;
  }

  // -- Run ====================
  public static void main(String[] args) {
    int[] arr = { 1, 2, 3 };
    comb(arr, 3);
    return;
  }
}
```

### 조합 > 구현 5：재귀적 풀이 - 스택：Recursive Solution - Stack

&nbsp; 구현 3 번의 예시와 같이 스택이나 논리적인 연산 순서가 쌓이는 것을 다룰 수 있다면 식이 매우 단순해 집니다. 여러 조건문의 탐색없이 현재 인덱스의 요소를 선택하는 경우 -> 선택하지않는 경우의 순서만 지키게 되면 모든 조합의 값에 도달하게 됩니다.

#### 조합 > 구현 5 > C++

```cpp
#include <array>
#include <deque>
#include <iostream>
#include <sstream>
#include <fstream>

#define SET_IO(INPUT_DATA) std::ios::sync_with_stdio(false);std::cin.tie(nullptr);std::cout.tie(nullptr);std::ifstream fs(INPUT_DATA);std::stringstream ss(INPUT_DATA);if(fs.is_open())std::cin.rdbuf(fs.rdbuf());else std::cin.rdbuf(ss.rdbuf())

using namespace std;

// ## Global Variable & Constant =====

int N;
int R;
int count;
int *origin;
int *select;

// ## Prototype Declaration ==========

void combRecur(int size, int curr);

// ## Implements Definition ==========

int main() {
  SET_IO("5 2");

  cin >> N;
  cin >> R;
  count = 0;
  origin = new int[N];
  for (int n = 1; n <= N; n++) origin[n - 1] = n;

  cout << "[CASES]:\n";

  {
    // ### 5. Recursive Solution - Stack
    select = new int[R]();
    combRecur(0, 0);
    delete[] select;
  }

  delete[] origin;

  cout << "\n";
  cout << "[NUMBER]: " << count << "\n";

  return 0;
}

void combRecur(int size, int curr) {
  if (size == R) {
    count++;
    for (int r = 0; r < R; r++) cout << select[r] << ' ';
    cout << '\n';
    return;
  }

  if (curr == N) return;

  select[size] = origin[curr];
  combRecur(size + 1, curr + 1);
  combRecur(size, curr + 1);
}
```

#### 조합 > 구현 5 > C++ - 폐쇄화

&nbsp; 위의 풀이는 가장 정석적이며 구현하기에 가장 간편한 구조입니다. 하지만 재귀되는 함수 combRecur 의 전역적인 변수 활용을 위해서 많은 데이터가 글로벌 스코프에 노출되어 있습니다.

&nbsp; 다음과 같이 포인터로 변수의 주소를 전달하는 방법으로 전역 변수의 사용을 피하고 폐쇄적인 함수로 만들 수 있습니다. 이제 main 함수 측이 폐쇄적인 함수 comb(원본 배열, 전체 수, 선택할 수) 만 호출하면 순열을 구할 수 있습니다.

```cpp
#include <array>
#include <deque>
#include <iostream>
#include <sstream>
#include <fstream>

#define SET_IO(INPUT_DATA) std::ios::sync_with_stdio(false);std::cin.tie(nullptr);std::cout.tie(nullptr);std::ifstream fs(INPUT_DATA);std::stringstream ss(INPUT_DATA);if(fs.is_open())std::cin.rdbuf(fs.rdbuf());else std::cin.rdbuf(ss.rdbuf())

using namespace std;

int comb(int* origin, int N, int R);
void combRecur(int* origin, int* select, int* ptrCount, int N, int R, int size, int curr);

int main() {
  SET_IO("5 2");

  int N;
  int R;
  int count;
  int *origin;

  cin >> N;
  cin >> R;
  count = 0;
  origin = new int[N];
  for (int n = 1; n <= N; n++) origin[n - 1] = n;

  cout << "[CASES]:\n";

  {
    // ### 5. Recursive Solution - Stack
    count = comb(origin, N, R);
  }

  delete[] origin;

  cout << "\n";
  cout << "[NUMBER]: " << count << "\n";

  return 0;
}

int comb(int* origin, int N, int R) {
  int count = 0;
  int* select = new int[R]();
  combRecur(origin, select, &count, N, R, 0, 0);
  delete[] select;

  return count;
}

void combRecur(int* origin, int* select, int* ptrCount, int N, int R, int size, int curr) {
  if (size == R) {
    (*ptrCount)++;
    for (int r = 0; r < R; r++) cout << select[r] << ' ';
    cout << '\n';
    return;
  }

  if (curr == N) return;

  select[size] = origin[curr];
  combRecur(origin, select, ptrCount, N, R, size + 1, curr + 1);
  combRecur(origin, select, ptrCount, N, R, size, curr + 1);
}
```

#### 조합 > 구현 5 > Java

```java
public class Main {
	static int N, R;
	static int[] data;
	static int[] sel; // 선택된 것

	public static void main(String[] args) {
		N = 6;
		R = 3;
		data = new int[] {1, 2, 3, 4, 5, 6};
		sel = new int[R];

		comb();
	}

	private static void comb(int depth, int idx) {
		if(depth == R) {
			System.out.println(Arrays.toString(sel));
			return;
		}
		if(idx == N) {
			return;
		}

		sel[depth] = data[idx];
		comb(depth + 1, idx + 1);
		comb(depth, idx + 1);
	}
}
```

### 조합 > 구현 6：반복자 풀이：Iterator Solution

&nbsp; 1 ~ 3 번의 출력값들을 자세히 보면 선택된 원소를 1, 선택되지 못한 원소를 0이라고 할 경우에 1100 부터 시작하여 1010 ... 0101, 0011 까지 내림차순 정렬되는 과정과 일치합니다.

&nbsp; 이를 응용하여 내림차순 순열 알고리즘 만으로 모든 조합 경우를 얻을 수 있습니다.

```cpp
#include <algorithm>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

#define SET_IO(INPUT_DATA) std::ios::sync_with_stdio(false);std::cin.tie(nullptr);std::cout.tie(nullptr);std::ifstream fs(INPUT_DATA);std::stringstream ss(INPUT_DATA);if(fs.is_open())std::cin.rdbuf(fs.rdbuf());else std::cin.rdbuf(ss.rdbuf())

using namespace std;

template <typename It>
bool prev_perm(It begin, It end) {
  if (begin == end) return false;

  It i = end;
  if (begin == --i) return false;

  while (true) {
    It i1, i2;

    i1 = i;

    if (*i1 < *--i) {
      i2 = end;
      while (!(*--i2 < *i));
      iter_swap(i2, i);
      reverse(i1, end);
      return true;
    }
    if (i == begin) {
      reverse(begin, end);
      return false;
    }
  }
}

int main() {
  SET_IO("5 2");

  int N;
  int R;
  int count = 0;
  vector<int> origin;

  cin >> N;
  cin >> R;
  origin = vector<int>(N);
  for (int n = 0; n < N; n++) origin[n] = n + 1;

  cout << "[CASES]:\n";

  {
    // ### 6. Iterator Solution

    // 선택할 범위까지 1로 안하는 범위를 0으로 채웁니다.
    vector<int> select(N);
    fill(select.begin(), select.begin() + R, 1);
    fill(select.begin() + R, select.end() + R, 0);

    do {
      count++;
      for (int n = 0; n < N; n++) if (select[n]) cout << origin[n] << ' ';
      cout << '\n';
    } while (prev_perm(select.begin(), select.end()));

  }

  cout << "\n";
  cout << "[NUMBER]: " << count << "\n";

  return 0;
}

```

### 조합 > 구현 7： 스프레드 연산자 풀이：Spread Solution

- javascript 의 map 함수와 스프레드 연산자 Spread Operator 를 활용하면 식이 엄청나게 단순해 집니다.

```js
// -- Methods ====================

const comb = function (arr, selectNumber) {
  const results = [];

  // n개중에서 1개 선택할 때(nC1), 바로 모든 배열의 원소 return
  if (selectNumber === 1) return arr.map((el) => [el]);

  arr.forEach((fixed, index, origin) => {
    // 해당하는 fixed를 제외한 나머지 뒷 부분
    const rest = origin.slice(index + 1);

    // 나머지에 대해서 조합을 구한다.
    const combArr = comb(rest, selectNumber - 1);

    //  돌아온 조합에 떼 놓은(fixed) 값 붙이기
    const attached = combArr.map((el) => [fixed, ...el]);

    // 배열 spread syntax 로 모두다 push
    results.push(...attached);
  });

  // 결과 담긴 results return
  return results;
};

// -- Run ====================

let arr = [1, 2, 3];
console.log(comb(arr, 2));
```
