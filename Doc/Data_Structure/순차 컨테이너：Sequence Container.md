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

## Deque
