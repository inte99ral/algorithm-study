# 순열：Permutation

## 정의

&nbsp; 서로 다른 n개의 원소에서 r (단, 0 < r ≤ n)개를 중복없이 순서에 상관있게 일렬로 배열하는 것을 순열(permutation)이라고 합니다.

&nbsp; 위와 같은 조건하에 원형으로 나열하는 원순열과 대칭을 불허하는 염주순열도 있지만 이중에서 통상적인 표현으로 순열이라 함은 일렬로 나열하는 직순열을 말합니다.

## 구현 0：수학적 경우의 수 계산：Mathematical Calculation

&nbsp; N 개를 순서대로 나열하는 모든 경우의 수 N! 에서 R 개만을 본다면, 뽑지 않은 것 N-R 개들이 나열된 (N - R)! 만큼이 중복되므로 나누어 해당 경우의 가짓수를 제거해주면 됩니다.

&nbsp; 최종적으로 다음과 같은 수식으로 계산됩니다.

<center>

${n}P{r} = \frac{n!}{(n-r)!}$

</center>

&nbsp; 코드로의 구현은 다음과 같이 이루어집니다.

```cpp
#include <iostream>
#include <sstream>
#include <fstream>

#define SET_IO(INPUT_DATA) std::ios::sync_with_stdio(false);std::cin.tie(nullptr);std::cout.tie(nullptr);std::ifstream fs(INPUT_DATA);std::stringstream ss(INPUT_DATA);if(fs.is_open())std::cin.rdbuf(fs.rdbuf());else std::cin.rdbuf(ss.rdbuf())

using namespace std;

int factorial(int x) { return (x == 1) || (x == 0) ? 1 : x * factorial(x - 1); }

int main() {
  SET_IO("5");

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
    count = factorial(N) / factorial(N - R);
  }

  delete[] origin;

  cout << "\n";
  cout << "[NUMBER]: " << count << "\n";

  return 0;
}
```

## 구현 1：지역적 풀이 - For 루프：Local Solution - For Loop Based

&nbsp; 지역적으로 뽑을 수 만큼 직접 For 루프 코드를 작성하여 중복되지 않는 경우의 수를 모두 구현합니다.

&nbsp; 예를 들어 3번 뽑는다면 for 루프를 3중으로 만들면 됩니다.

&nbsp; 일일히 만들어줘야 하는 구조상, 뽑는 수 R 을 유동적으로 변경할 수 없습니다.

&nbsp; 코드로는 다음과 같이 만들 수 있습니다.

```cpp
#include <iostream>
#include <sstream>
#include <fstream>

#define SET_IO(INPUT_DATA) std::ios::sync_with_stdio(false);std::cin.tie(nullptr);std::cout.tie(nullptr);std::ifstream fs(INPUT_DATA);std::stringstream ss(INPUT_DATA);if(fs.is_open())std::cin.rdbuf(fs.rdbuf());else std::cin.rdbuf(ss.rdbuf())

using namespace std;

int factorial(int x) { return (x == 1) || (x == 0) ? 1 : x * factorial(x - 1); }

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

    for (int i = 0; i < N; i++) {
      select[0] = origin[i];

      for (int j = 0; j < N; j++) {
        if (j == i) continue;
        select[1] = origin[j];

        for (int k = 0; k < N; k++) {
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

## 구현 2：지역적 풀이 - While 루프：Local Solution - While Loop Based

&nbsp; 알고리즘은 For 루프와 완벽히 똑같습니다. i 루프, j 루프... 루프 안으로 들어가는 상황과 루프 밖으로 나오는 상황을 if 문으로 구현하기 때문에 전체 원소 수 N 값과 뽑을 수 R 값을 유동적으로 바꿀 수 있다.

&nbsp; data[] 배열은 for 루프의 각 i, j, ... 깊이 마다의 변수에 해당하는 값입니다.

&nbsp; size 값은 select 된 배열의 크기이면서 동시에 for 루프의 깊이를 의미합니다.

&nbsp; for(int 변수 = 0 ... ) 를 `data[size]` 값을 확인하면서 체크하는 것으로 구현합니다.

&nbsp; 코드로는 다음과 같이 만들 수 있습니다.

```cpp
#include <iostream>
#include <sstream>
#include <fstream>

#define SET_IO(INPUT_DATA) std::ios::sync_with_stdio(false);std::cin.tie(nullptr);std::cout.tie(nullptr);std::ifstream fs(INPUT_DATA);std::stringstream ss(INPUT_DATA);if(fs.is_open())std::cin.rdbuf(fs.rdbuf());else std::cin.rdbuf(ss.rdbuf())

using namespace std;

int factorial(int x) { return (x == 1) || (x == 0) ? 1 : x * factorial(x - 1); }

int main() {
  SET_IO("3 2");

  int N;
  int R;
  int count;
  int* origin;

  cin >> N;
  cin >> R;
  count = 0;
  origin = new int[N];
  for (int n = 1; n <= N; n++) origin[n - 1] = n;

  cout << "[CASES]:\n";

  {
    // ### 2. Local Solution - While Loop Based
    int* select = new int[R]();
    int* data = new int[R](); // loop counter
    int size = 0; // loop depth

    while (data[0] != N) {
      if (size == R) {
        count++;
        for (int r = 0; r < R; r++) cout << select[r] << ' ';
        cout << '\n';

        // * print & loop depth out
        size--;
        data[size]++;
        continue;
      }

      if(data[size] == N) {
        // * loop depth out
        data[size] = 0;
        size--;
        data[size]++;
        continue;
      }

      // * isSelected Check
      bool isSelected = false;
      for (int i = 0; i < size; i++) {
        if (data[i] == data[size]) {
          isSelected = true;
          continue;
        }
      }

      if (isSelected) {
        // * loop go next
        data[size]++;
      }
      else {
        // * select & loop depth in
        select[size] = origin[data[size]];
        size++;
      }
    }

    delete[] select;
    delete[] data;
  }

  delete[] origin;

  cout << "\n";
  cout << "[NUMBER]: " << count << "\n";

  return 0;
}
```

## 구현 3：지역적 풀이 - 스택 & 비트연산자：Local Solution - Stack & Bitmask Based

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
#include <fstream>
#include <sstream>

#define SET_IO(INPUT_DATA) std::ios::sync_with_stdio(false);std::cin.tie(nullptr);std::cout.tie(nullptr);std::ifstream fs(INPUT_DATA);std::stringstream ss(INPUT_DATA);if(fs.is_open())std::cin.rdbuf(fs.rdbuf());else std::cin.rdbuf(ss.rdbuf())

using namespace std;

int factorial(int x) { return (x == 1) || (x == 0) ? 1 : x * factorial(x - 1); }

int main() {
  SET_IO("3 2");

  int N;
  int R;
  int count;
  int* origin;

  cin >> N;
  cin >> R;
  count = 0;
  origin = new int[N];
  for (int n = 1; n <= N; n++) origin[n - 1] = n;

  cout << "[CASES]:\n";

  {
    // ### 3. Local Solution - Stack & Bitmask Based
    int* select = new int[R]();
    deque<array<int, 3>> task = {{0, 0, 0}};

    while(!task.empty()) {
      int data = task.back()[0]; // isSelected array
      int size = task.back()[1]; // select index
      int curr = task.back()[2]; // origin index
      task.pop_back();

      if (size == R) {
        // * print out
        count++;
        for (int r = 0; r < R; r++) cout << select[r] << ' ';
        cout << '\n';
        continue;
      }

      if (curr == N) continue;

      // 선택하지 않은 경우의 수를 지금 넣어둡니다.
      // stack 구조상 선택한 경우의 수가 전부 끝나야 이 밑에 쌓인 이 상황에 도달합니다.
      task.push_back({data, size, curr + 1});

      // 지금의 curr (=origin index) 를 이전에 선택한 적이 있다면?
      // 선택한 경우의 수는 stack 에 추가할 수 없습니다.
      if (data & (1 << curr)) continue;

      // 선택한 경우의 수에 대한 정보를 stack 추가합니다.
      select[size] = origin[curr];
      task.push_back({data | (1 << curr), size + 1, 0});
    }
  }

  delete[] origin;

  cout << "\n";
  cout << "[NUMBER]: " << count << "\n";

  return 0;
}
```

## 구현 4：재귀적 풀이：Recursive Solution

&nbsp; 지역적인 풀이와 다르게 중간에 값에 접근이 불가능하고 전역적인 변수를 필요로 합니다.

&nbsp; 재귀적함수로 DFS 알고리즘을 구현하면 Stack 구조보다도 단순해지고 직관적이라는 장점이 있습니다.

&nbsp; 후에 서술할 swap 을 이용한 풀이와 더불어 가장 정석적인 알고리즘 입니다.

```cpp
#include <iostream>
#include <fstream>
#include <sstream>

#define SET_IO(INPUT_DATA) std::ios::sync_with_stdio(false);std::cin.tie(nullptr);std::cout.tie(nullptr);std::ifstream fs(INPUT_DATA);std::stringstream ss(INPUT_DATA);if(fs.is_open())std::cin.rdbuf(fs.rdbuf());else std::cin.rdbuf(ss.rdbuf())

using namespace std;

void permRecur(int data, int size);

int N;
int R;
int *origin;
int *select;
int count;

int main() {
  SET_IO("3 2");

  cin >> N;
  cin >> R;
  count = 0;
  origin = new int[N]();
  for (int n = 1; n <= N; n++) origin[n - 1] = n;

  cout << "[CASES]:\n";

  {
    // ### 4. Recursive Solution - Bitmask
    select = new int[R]();
    permRecur(0, 0);
    delete[] select;
  }

  delete[] origin;

  cout << "\n";
  cout << "[NUMBER]: " << count << "\n";

  return 0;
}

void permRecur(int data, int size) {
  if (size == R) {
    count++;
    for (int r = 0; r < R; r++) cout << select[r] << ' ';
    cout << '\n';
    return;
  }

  for (int i = 0; i < N; i++) {
    // 지금의 i번째 값 (=origin index) 을 이전에 선택한 적이 있다면? continue
    if(data & (1 << i)) continue;

    select[size] = origin[i];
    permRecur(data | (1 << i), size + 1);
  }
  return;
}
```

&nbsp; 위의 풀이는 가장 정석적이며 구현하기에 가장 간편한 구조입니다. 하지만 재귀되는 함수 permRecur 의 전역적인 변수 활용을 위해서 많은 데이터가 main 함수에 노출되어 있습니다.

&nbsp; 다음과 같이 포인터로 변수의 주소를 전달하는 방법으로 전역 변수의 사용을 피하고 폐쇄적인 함수로 만들 수 있습니다. 이제 main 함수 측이 perm(원본 배열, 전체 수, 선택할 수) 만 호출하면 순열을 구할 수 있습니다.

```cpp
#include <iostream>
#include <fstream>
#include <sstream>

#define SET_IO(INPUT_DATA) std::ios::sync_with_stdio(false);std::cin.tie(nullptr);std::cout.tie(nullptr);std::ifstream fs(INPUT_DATA);std::stringstream ss(INPUT_DATA);if(fs.is_open())std::cin.rdbuf(fs.rdbuf());else std::cin.rdbuf(ss.rdbuf())

using namespace std;

int perm(int* origin, int N, int R);
void permRecur(int* origin, int* select, int N, int R, int data, int size, int* count);

int main() {
  SET_IO("3 2");

  int N;
  int R;
  int count;
  int* origin;

  cin >> N;
  cin >> R;
  count = 0;
  origin = new int[N];
  for (int n = 1; n <= N; n++) origin[n - 1] = n;

  cout << "[CASES]:\n";

  {
    // ### 4. Recursive Solution - Bitmask
    count = perm(origin, N, R);
  }

  delete[] origin;

  cout << "\n";
  cout << "[NUMBER]: " << count << "\n";

  return 0;
}


int perm(int* origin, int N, int R) {
  int count = 0;
  int* select = new int[R]();
  permRecur(origin, select, N, R, 0, 0, &count);
  cout << '\n';
  return count;
}

void permRecur(int* origin, int* select, int N, int R, int data, int size, int* count) {
  if (size == R) {
    (*count)++;
    for (int r = 0; r < R; r++) cout << select[r] << ' ';
    cout << '\n';
    return;
  }

  for (int i = 0; i < N; i++) {
    // 지금의 i번째 값 (=origin index) 을 이전에 선택한 적이 있다면? continue
    if(data & (1 << i)) continue;

    select[size] = origin[i];
    permRecur(origin, select, N, R, data | (1 << i), size + 1, count);
  }
  return;
}
```

## 구현 5：재귀적 풀이 - Swap 알고리즘：Recursive Solution - Swap

&nbsp; 1 ~ 4 까지의 결과값을 유심히 관찰하면 다음과 같은 사실을 알 수 있습니다. 각 원소가 이전의 결과와 중복되지 않는 조건을 지키며 본래 있던 위치가 아닌 곳으로 이동시키고 출력하면 순열의 결과값과 일치합니다. 여기서 두 원소의 위치를 바꾸고 출력한 뒤에 원 위치로 돌려준다면 별도의 체크 없이도 논리상 중복이 없게 됩니다. (원본 그대로 출력되는 경우는 자기와 자기의 위치를 바꾼 상태로 출력될 것 입니다.) 이것이 Swap 알고리즘 입니다.

&nbsp; 두 원소의 위치만 바꿔주는 것으로 구현이 되므로 가장 단순하고 보편적인 순열 출력 방법입니다. 다만 단점 두 가지가 있습니다.

&nbsp; 첫번째 단점은 Swap 알고리즘은 오름차순 정렬을 보장하지 않습니다. 요소들을 교환하면서 순열을 만들기 때문에, <b>결과물이 무작위적인 순서</b>로 나오게 됩니다.

&nbsp; 두번째 단점은 <b>원본 배열 origin에 접근하여</b> 의 두 요소의 위치를 직접 조작하기 때문에 연산 도중에 origin 에 접근할 경우 문제가 발생할 수 있다는 점 입니다.

&nbsp; 코드로는 다음과 같이 구현됩니다.

```cpp
#include <iostream>
#include <fstream>
#include <sstream>

#define SET_IO(INPUT_DATA) std::ios::sync_with_stdio(false);std::cin.tie(nullptr);std::cout.tie(nullptr);std::ifstream fs(INPUT_DATA);std::stringstream ss(INPUT_DATA);if(fs.is_open())std::cin.rdbuf(fs.rdbuf());else std::cin.rdbuf(ss.rdbuf())

using namespace std;

void swap(int* swapArr, int x, int y);
void permRecur(int* origin, int* countPtr, int N, int R, int size);

int main() {
  SET_IO("4 2");

  int N;
  int R;
  int count = 0;
  int *origin;

  cin >> N;
  cin >> R;
  origin = new int[N]();
  for (int n = 0; n < N; n++) origin[n] = n + 1;

  cout << "[CASES]:\n";

  {
    // ### 5. Recursive Solution - Swap
    permRecur(origin, &count, N, R, 0);
  }

  delete[] origin;

  cout << "\n";
  cout << "[NUMBER]: " << count << "\n";

  return 0;
}

void swap(int* swapArr, int x, int y) {
  int temp = swapArr[x];
  swapArr[x] = swapArr[y];
  swapArr[y] = temp;
}

void permRecur(int* origin, int* countPtr, int N, int R, int size) {
  if (size == R) {
    (*countPtr)++;
    for (int r = 0; r < R; r++) cout << origin[r] << ' ';
    cout << '\n';
    return;
  }

  for (int i = size; i < N; i++) {
    swap(origin, size, i);
    permRecur(origin, countPtr, N, R, size + 1);
    swap(origin, size, i);
  }
}
```

## 구현 6：반복자 풀이：Iterator Solution

&nbsp; 1 ~ 3 번의 출력값들을 자세히 보면 순열 데이터의 오름차순 출력 과정은 원본 배열이 오름차순 배열에서 시작하여 내림차순으로 정렬되는 과정과 같다는 것을 눈치챌 수 있습니다.
&nbsp; (시작은 오름차순) 1 - 2 - 3 >>> (끝은 내림차순) 3 - 2 - 1
&nbsp; 이를 응용하여 오름차순 정렬이 확실하다면 내림차순으로 바꾸는 알고리즘 만으로 모든 순열 경우를 얻을 수 있다.
