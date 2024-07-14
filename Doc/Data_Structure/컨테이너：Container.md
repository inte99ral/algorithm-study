# 컨테이너：Container

</br>

## 큐：Queue

</br>

### 우선순위 큐：Priority Queue

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

</br>

### 덱：Deque (Double-Ended Queue)

- [참고링크](https://blockdmask.tistory.com/73)
- queue 클래스의 내부의 컨테이너에 해당합니다.
- deque도 vector와 마찬가지로 배열기반의 구조입니다.
- deque는 vector의 단점을 보완하기 위해서 만들어진 container 입니다.
- vector는 새로운 원소가 추가 될때 메모리 재할당 후 이전 원소를 복사하는 방식으로 인하여,  삽입시에 성능이 저하 하는 단점이 있습니다.
- deque는 이러한 vector의 단점을 보완하기 위해서 여러개의 메모리 블록을 할당하고하나의 블록처럼 여기는 기능을 제공합니다.deque는 메모리가 부족할때 마다 일정한 크기의 새로운 메모리 블록을 할당합니다. 그럼으로써, 이전 원소를 복사하지 않습니다.

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

### 원소 키, 값 집합

```cpp
std::map<int, int> m;
std::vector<int> key, value;
for(std::map<int,int>::iterator it = m.begin(); it != m.end(); ++it) {
  key.push_back(it->first);
  value.push_back(it->second);
  std::cout << "Key: " << it->first << std::endl;
  std::cout << "Value: " << it->second << std::endl;
}
```

### 원소 존재 유무

https://www.techiedelight.com/ko/determine-if-a-key-exists-in-a-map-in-cpp/

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

## 정렬 없는 맵：Unordered Map

[참고링크](https://math-coding.tistory.com/31)
[참고링크](https://blog.naver.com/PostView.naver?blogId=do9562&logNo=221754890348)

- #include <unordered_map>

map보다 더 빠른 탐색을 하기 위한 자료구조입니다.

unordered_map은 해쉬테이블로 구현한 자료구조로 탐색 시간복잡도는 O(1)입니다.

map은 Binary Search Tree로 탐색 시간 복잡도는 O(log n)입니다.

unordered_map을 사용하기 위해서는 #include< unordered_map > 을 선언해야 합니다.

unordered_map은 중복된 데이터를 허용하지 않고 map에 비해 데이터가 많을 시 월등히 좋은 성능을 보입니다.

하지만, key가 유사한 데이터가 많을 시 해시 충돌로 인해 성능이 떨어질 수도 있습니다.
