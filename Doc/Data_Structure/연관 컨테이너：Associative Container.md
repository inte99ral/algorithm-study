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

대표적인 예로, 세트(set), 멀티세트(multiset), 맵(map), 멀티맵(multimap) 가 있습니다.
​

## Set

### 집합：Set

- set 컨테이너는 밸런스 트리로 Red-Black 트리를 기반으로 합니다.

- set 컨테이너가 구현하는 집합의 내부는 다음의 규칙을 유지합니다.

  1. 내부 원소들은 중복되지 않는다.
  2. 삽입하는 순서에 상관없이 정렬되서 입력이 된다.

#### 집합：Create

- `set<T>`

#### 집합：Read

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

- Update：`insert & emplace`

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

- Delete：`insert & emplace`

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

### Multiset

## Map

### Map

### Multimap
