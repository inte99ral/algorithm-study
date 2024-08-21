# 순차 컨테이너：Sequence Container

## 목차

<br />

## 개요

- 컨테이너란 C++에서 자주 사용되는 구조들을 미리 라이브러리화 시켜놓아 직접 구현하지 않아도 활용할 수 있도록 제공하는 표준 템플릿 라이브러리(STL, Standard Template Libaray) 중 하나 입니다.

- 컨테이너는 객체 컬렉션(collection)을 관리하는데 사용됩니다.

<center>
<img src=".\asset\연관 컨테이너\0.png" alt="0" style="width:50vw; aspect-ratio: 5 / 3"/>
</center>

- 순차 컨테이너, sequence containers

순차 컨테이너는 모든 요소들을 선형적인 순차열로 저장하는 형태입니다.

순차라고해서 값이 순서대로 정렬된 형태를 말하는 것이 아닙니다.

원소들이 규칙에따라 저장한 순서대로 배열됩니다.

대표적인 예로, 벡터(vector), 데큐(deque), 리스트(list)가 있습니다.

## Vector

```cpp
vector<vector<int>> matrix(y, vector<int> (x));
```

## List

## 덱：Deque

### 덱 > 덱：Deque (Double-Ended Queue)

- [참고링크](https://blockdmask.tistory.com/73)
- queue 클래스의 내부의 컨테이너에 해당합니다.
- deque도 vector와 마찬가지로 배열기반의 구조입니다.
- deque는 vector의 단점을 보완하기 위해서 만들어진 container 입니다.
- vector는 새로운 원소가 추가 될때 메모리 재할당 후 이전 원소를 복사하는 방식으로 인하여,  삽입시에 성능이 저하 하는 단점이 있습니다.
- deque는 이러한 vector의 단점을 보완하기 위해서 여러개의 메모리 블록을 할당하고하나의 블록처럼 여기는 기능을 제공합니다.deque는 메모리가 부족할때 마다 일정한 크기의 새로운 메모리 블록을 할당합니다. 그럼으로써, 이전 원소를 복사하지 않습니다.

## 큐：Queue

### 큐 > 큐：Queue

### 큐 > 우선순위 큐：Priority Queue

- `#include <queue>` 라이브러리에서 지원
- 힙정렬
- 디폴트는 우선 순위가 높은 순서대로 정리되며 하나씩 빼면 맨 앞으로 내림차순 정렬된다.
- Sort 디폴트는 오름차순이므로 햇갈림에 주의하세요
- 선언 방법

#### 큐 > 우선순위 큐 > Create

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
