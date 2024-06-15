# 자료구조：Data Structure

## 큐 queue

### 덱：Deque (Double-Ended Queue)

### 우선순위 큐

https://learn.microsoft.com/ko-kr/cpp/standard-library/priority-queue-class?view=msvc-170

- #include <queue> 라이브러리에서 지원
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
