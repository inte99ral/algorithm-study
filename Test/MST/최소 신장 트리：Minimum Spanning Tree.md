# 최소 신장 트리：Minimum Spanning Tree

## 개념정리

- <b>신장 트리(Spanning Tree)</b>란, 그래프 내의 모든 정점을 포함하는 트리를 말합니다.
- 이산수학에서 그래프이론으로 접근할 때는 그래프의 모든 간선 중에서 모든 정점들이 연결되는 최소한의 간선만 선택한 부분그래프(Subgraph)로 볼 수 있습니다. 따라서, 신장 부분 그래프(Spanning Subgraph)라고도 부릅니다.
- 필연적으로 모든 정점이 연결되어 있는 n 개의 정점을 가지는 신장 트리의 간선의 수는 n-1 개 입니다. <br/> <center>`(정점1) <-(간선1)-> (정점2) ... <-(간선 N-1)-> (정점 N)`</center>
- 필연적으로 순환(循環, Cycle)이 존재하지 않습니다. 여기서 사이클이란 임의의 정점를 시작점으로 두고 간선을 따라 일방향으로 이동할 때, 시작점으로 다시 돌아올 수 있는 경우를 의미합니다.
- 하나의 그래프에는 여러 개의 신장 트리가 존재할 수 있습니다.<br/><center><img src="./asset/MST/0.svg" title="From https://ko.wikipedia.org/wiki/%EC%8B%A0%EC%9E%A5_%EB%B6%80%EB%B6%84_%EA%B7%B8%EB%9E%98%ED%94%84 By Quartl CC BY-SA 3.0" style="width:50vw; aspect-ratio: 2 / 1"/><br/>다음의 그래프 조건은 8개의 신장부분그래프를 가집니다.</center>

<br/>

- <b>최소 신장 트리(Minimum Spanning Tree)</b>란, 각 간선 마다 비용, 시간, 길이 등의 가중치 값이 존재할 경우, 신장 트리 중에서 가장 가중치 합계를 가진 신장 트리를 말한다.<br/><center><img src="./asset/MST/1.svg" title="From https://ko.wikipedia.org/wiki/%EC%8B%A0%EC%9E%A5_%EB%B6%80%EB%B6%84_%EA%B7%B8%EB%9E%98%ED%94%84 By No machine-readable author provided" style="width:50vw; aspect-ratio: 2 / 1"/><br/>다음의 그래프 조건에서 신장 트리의 최소 비용은 38 이다.</center>

<br/>

- <b>Kruskal 알고리즘</b>과 <b>Prim 알고리즘</b>을 이용하여 구할 수 있다.

## 사용예시

- 통신망, 도로망, 유통망에서 길이, 구축 비용, 전송 시간 등을 최소로 구축하려는 경우

## 구현방법

### 1. Kruskal 알고리즘

- 간선 선택을 기반으로 하는 알고리즘
- 탐욕법(Greedy Algorithm)을 이용하여, MST는 최소 비용의 간선 집합이며 사이클이 포함되어 있지 않으므로, 반대로 모든 간선 중에 최소 비용 순서대로 연결해보고 사이클을 형성하는 지 확인하는 것으로 MST의 속하는 간선인 지를 판단합니다.
- Kruskal 알고리즘은 다음과 같은 순서로 작동합니다.
  1. 간선들을 비용에 따라 오름차순으로 정렬합니다.
  2. 간선을 순서대로 하나씩 확인하며 현재의 간선을 MST의 경로로 포함시킬 때 서로소 알고리즘(Union-find Algorithm)을 토대로 사이클을 발생시키는지 확인합니다.
  3. 사이클 발생이 없다면 해당 간선을 MST에 추가합니다.
  4. 모든 간선을 돌아보고 나면 MST를 얻을 수 있습니다.

https://gmlwjd9405.github.io/2018/08/29/algorithm-kruskal-mst.html

#### C++

```cpp

```

#### Java

```java

```

### 2. Prim 알고리즘
