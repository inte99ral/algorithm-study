# 자료구조：Data Structure

## 목차

<br />

## 개요

<br />

## 함수：Function

### C++

- `#include <functional>`

<br />

## 맵：Map

### 원소 삭제 map.erase

```cpp
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  map<int, int> iMap;

  iMap[2] = 5;
  iMap[2] = -5;

  iMap[2]++;

  vector<string> t = {"1", "2", "3", "4", "5", "6"};

  t.erase(t.begin() + 2, t.begin() + 4);

  for (string s : t) {
    cout << s << " ";
  }

  return 0;
}
```

## 큐 queue

### 덱：Deque (Double-Ended Queue)

### 우선순위 큐

https://learn.microsoft.com/ko-kr/cpp/standard-library/priority-queue-class?view=msvc-170

- `#include <queue>` 라이브러리에서 지원
- 힙정렬
- 디폴트는 우선 순위가 높은 순서대로 정리되며 하나씩 빼면 맨 앞으로 내림차순 정렬된다.
- Sort 디폴트는 오름차순이므로 햇갈림에 주의하세요
- 선언 방법

  ```cpp
  // priority_queue<자료형> 변수명
  // priority_queue<자료형, 컨테이너, 비교함수> 변수명
  priority_queue<int,vector<int>,less<int> > pq


  // priority_queue<자료형, 컨테이너, 비교함수타입> 변수명(커스텀비교함수)

  // 타입추론 decltype, auto 활용예
  auto comp = []( int a, int b ) { return a > b; };
  priority_queue<int, vector<int>, decltype(comp)> task(comp);

  // 람다식으로 비교함수를 넣은 예
  priority_queue<int, vector<int>, function<bool(int, int)>> task([]( int a, int b ) { return a < b; });

  ```

- 함수

  ```cpp
  push();
  pop();
  ```
