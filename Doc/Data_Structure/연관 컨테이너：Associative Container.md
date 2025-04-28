# 연관 컨테이너：Associative Container

## 목차

<br />

## 개요

<br />

- 컨테이너란 C++에서 자주 사용되는 구조들을 미리 라이브러리화 시켜놓아 직접 구현하지 않아도 활용할 수 있도록 제공하는 표준 템플릿 라이브러리(STL, Standard Template Libaray) 중 하나 입니다.

- 컨테이너는 객체 컬렉션(collection)을 관리하는데 사용됩니다.

<center>
<img src=".\asset\연관 컨테이너\0.png" alt="0" style="width:50vw; aspect-ratio: 5 / 3"/>
</center>

- 연관 컨테이너 (associative containers)

연관 컨테이너는 키(key)와 값(value) 쌍처럼

관련된(연관된) 데이터를 하나의 쌍 형태로 저장합니다.

키와 값을 이용하여 요소들에 대한 빠른 접근을 제공해줍니다.

균형 이진탐색 트리 기반인 집합(set), 맵(map),

해시 테이블 기반인 해시집합(unordered set), 해시맵(unordered map),

중복을 허용하는 멀티세트(multiset), 멀티맵(multimap) 들이 이에 속합니다.

​

## 집합：Set

### Set

- set 컨테이너는 균형 이진탐색 트리(Balanced Binary Search Tree)인 Red-Black 트리를 기반으로 합니다.

- set 컨테이너가 구현하는 집합의 내부는 다음의 규칙을 유지합니다.

  1. 내부 원소들은 중복되지 않는다.
  2. 삽입하는 순서에 상관없이 정렬되서 입력이 된다.

#### 집합：Set > Create

- `set<T>`

- `set<int, compare> sets; `

```cpp
set<int, compare> sets;

auto cmp = [](int a, int b) { return a > b; };
// set 선언 시 Compare 타입을 decltype(cmp)로 지정
std::set<int, decltype(cmp)> s(cmp);
```

#### 집합：Set > Read

- `find`

```cpp
set <int>s;


// 전체 출력
for (it = s.begin(); it != s.end(); ++it){
      cout << *it << " ";
  }
  cout << endl;

// 찾기
if(s.find(n)==s.end())
cout << "내가 찾는 원소가 없습니다" <<endl;
else
cout << "내가 찾는 원소가 있습니다" <<endl;
```

#### 집합：Set > Update

- Update：`insert & emplace`

- 언급했듯 균형 이진 트리 기반이기에 insert를 한 값들이 정렬 되어서 들어갑니다.

C++에서는 모든 컨테이너( vector , stack , queue , set , map 등)가 insert 및 emplace 작업을 모두 지원합니다.

둘 다 컨테이너에 요소를 추가하는 데 사용됩니다.
emplace의 장점은 내부 삽입을 수행하고 불필요한 객체 복사본을 방지한다는 것입니다. 원시 데이터 유형의 경우 어떤 유형을 사용하는지는 중요하지 않습니다. 그러나 객체의 경우 효율성을 위해 emplace()를 사용하는 것이 좋습니다.

```cpp


// C++ code to demonstrate difference between
// emplace and insert
#include<bits/stdc++.h>
using namespace std;

int main()
{
    // declaring map
    multiset<pair<char, int>> ms;

    // using emplace() to insert pair in-place
    ms.emplace('a', 24);

    // Below line would not compile
    // ms.insert('b', 25);

    // using insert() to insert pair in-place
    ms.insert(make_pair('b', 25));

    // printing the multiset
    for (auto it = ms.begin(); it != ms.end(); ++it)
        cout << " " << (*it).first << " "
             << (*it).second << endl;

    return 0;
}
```

```cpp
#include<iostream>
#include<set>
using namespace std;

int main()
{
  set<int> iSet;

  iSet.insert(5);
  iSet.insert(7);

  set<int>::iterator it;
  for(it = is.begin(); it != is.end(); it++) {
    cout << *it << " ";
  }
  cout << endl;

  return 0;
}
```

#### 집합：Set：Delete

- Delete：`erase`

```cpp
#include <set>
#include <iostream>
#include <algorithm>

using namespace std;

int main(void) {

    set<int> s = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

    pair<set<int>::iterator, set<int>::iterator> itr = s.equal_range(4);

    cout <<*itr.first << " " << *itr.second << endl;    //output : 4, 5



    set<int>::iterator low_itr, up_itr;

    low_itr = s.lower_bound(3);
    up_itr = s.upper_bound(7);

    s.erase(low_itr, up_itr);

    for_each(s.begin(), s.end(), [](int n) {
        cout << n << endl;        //output : 1, 2, 8, 9, 10
        });


    // 단일 제거
    it = s.find(30);
    s.erase(it);

    return 0;
}​
```

### Multiset：중복 허용 집합

## Map Container：맵 컨테이너

### Map：맵

#### Map > Create

```cpp
std::map<int, std::string> iMap;

iMap.insert({1, "first"});
```

#### 맵 > 맵 > Read

https://www.techiedelight.com/ko/determine-if-a-key-exists-in-a-map-in-cpp/

```cpp
std::map<int, int> m;
std::vector<int> key, value;
for(std::map<int,int>::iterator it = m.begin(); it != m.end(); ++it) {
  key.push_back(it->first);
  value.push_back(it->second);
  std::cout << "Key: " << it->first << std::endl;
  std::cout << "Value: " << it->second << std::endl;
}

for(auto itr : map) {
  cout << p->first << " " << p->second << '\n';
}

for(pair<string, int> p : map) {
  cout << p.first << " " << p.second << '\n';
}

// * 존재 판별
if(map.find("Pig") != map.end()) {
  // 존재 O
} else {
  // 존재 X
}
```

#### 맵 > 맵 > Delete

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

### 맵 > 정렬없는 맵：Unordered Map

[참고링크](https://math-coding.tistory.com/31)
[참고링크](https://blog.naver.com/PostView.naver?blogId=do9562&logNo=221754890348)

- #include <unordered_map>

map보다 더 빠른 탐색을 하기 위한 자료구조입니다.

unordered_map은 해쉬테이블로 구현한 자료구조로 탐색 시간복잡도는 O(1)입니다.

map은 Binary Search Tree로 탐색 시간 복잡도는 O(log n)입니다.

unordered_map을 사용하기 위해서는 #include< unordered_map > 을 선언해야 합니다.

unordered_map은 중복된 데이터를 허용하지 않고 map에 비해 데이터가 많을 시 월등히 좋은 성능을 보입니다.

하지만, key가 유사한 데이터가 많을 시 해시 충돌로 인해 성능이 떨어질 수도 있습니다.

### 맵 > 중복허용 맵：Multimap

https://learn.microsoft.com/ko-kr/cpp/standard-library/multiset-class?view=msvc-170&viewFallbackFrom=vs-2019
