# 최소 신장 트리：Minimum Spanning Tree

## 개념정리

- <b>신장 트리(Spanning Tree)</b>란, 그래프 내의 모든 정점을 포함하는 트리를 말합니다.
- 이산수학에서 그래프이론으로 접근할 때는 그래프의 모든 간선 중에서 모든 정점들이 연결되는 최소한의 간선만 선택한 부분그래프(Subgraph)로 볼 수 있습니다. 따라서, 신장 부분 그래프(Spanning Subgraph)라고도 부릅니다.
- 필연적으로 모든 정점이 연결되어 있는 n 개의 정점을 가지는 신장 트리의 간선의 수는 n-1 개 입니다. <br/> <center>`(정점1) <-(간선1)-> (정점2) ... <-(간선 N-1)-> (정점 N)`</center>
- 필연적으로 순환(循環, Cycle)이 존재하지 않습니다. 여기서 사이클이란 임의의 정점를 시작점으로 두고 간선을 따라 일방향으로 이동할 때, 시작점으로 다시 돌아올 수 있는 경우를 의미합니다.
- 하나의 그래프에는 여러 개의 신장 트리가 존재할 수 있습니다.<br/><center><img src="../asset/Graph/Minimum Spanning Tree/0.svg" title="From https://ko.wikipedia.org/wiki/%EC%8B%A0%EC%9E%A5_%EB%B6%80%EB%B6%84_%EA%B7%B8%EB%9E%98%ED%94%84 By Quartl CC BY-SA 3.0" style="width:50vw; aspect-ratio: 2 / 1"/><br/>다음의 그래프 조건은 8개의 신장부분그래프를 가집니다.</center>

<br/>

- <b>최소 신장 트리(Minimum Spanning Tree)</b>란, 각 간선 마다 비용, 시간, 길이 등의 가중치 값이 존재할 경우, 신장 트리 중에서 가장 가중치 합계를 가진 신장 트리를 말합니다.<br/><center><img src="../asset/Graph/Minimum Spanning Tree/1.svg" title="From https://ko.wikipedia.org/wiki/%EC%8B%A0%EC%9E%A5_%EB%B6%80%EB%B6%84_%EA%B7%B8%EB%9E%98%ED%94%84 By No machine-readable author provided" style="width:50vw; aspect-ratio: 2 / 1"/><br/>다음의 그래프 조건에서 신장 트리의 최소 비용은 38 입니다.</center>

<br/>

- <b>Kruskal 알고리즘</b>과 <b>Prim 알고리즘</b>을 이용하여 구할 수 있습니다.

<br/>

## 사용예시

- 통신망, 도로망, 유통망에서 길이, 구축 비용, 전송 시간 등을 최소로 구축하려는 경우

<br/>

## 구현방법

### 1. Kruskal 알고리즘

- 간선 선택을 기반으로 하는 알고리즘
- 탐욕법(Greedy Algorithm)을 이용하여, MST는 최소 비용의 간선 집합이며 사이클이 포함되어 있지 않으므로, 반대로 모든 간선 중에 최소 비용 순서대로 연결해보고 사이클을 형성하는 지 확인하는 것으로 MST의 속하는 간선인 지를 판단합니다.
- Kruskal 알고리즘은 다음과 같은 순서로 작동합니다.

  1. 간선들을 비용에 따라 오름차순으로 정렬합니다.
  2. 간선을 순서대로 하나씩 확인하며 현재의 간선을 MST의 경로로 포함시킬 때 서로소 알고리즘(Union-find Algorithm)을 토대로 사이클을 발생시키는지 확인합니다.
  3. 사이클 발생이 없다면 해당 간선을 MST에 추가합니다.
  4. 모든 간선을 돌아보고 나면 MST를 얻을 수 있습니다.

- Kruskal 알고리즘의 시간 복잡도는 간선들을 정렬하는 시간에 영향을 받습니다. 퀵 정렬같은 효율적인 알고리즘이 사용되었다면 간선의 수 E에 대한 시간 복잡도는 O(Elog₂E) 가 됩니다.
- 오름차순 정렬시 Sort 뿐 아니라 Priority Queue 등을 활용한 힙 정렬을 사용해도 좋습니다.
- 백트래킹으로 V개의 노드가 모두 연결되었다면 즉시 연산을 종료해도 좋습니다.
- 그래프 내에 적은 숫자의 간선만을 가지는 희소 그래프(Sparse Graph)의 경우 Kruskal 알고리즘이 적합합니다.

#### C++

```cpp
#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

// Prototype Declaration ====================
void makeSet(int x);
int findSet(int x);
void unionSet(int x, int y);

// Global Variable & Constant================
const string input =
  "10 21\n"
  "0 1 9\n"
  "0 2 9\n"
  "0 9 8\n"
  "0 8 18\n"
  "1 2 3\n"
  "1 4 6\n"
  "2 3 2\n"
  "2 4 4\n"
  "2 9 9\n"
  "3 4 2\n"
  "3 5 9\n"
  "3 9 8\n"
  "4 5 9\n"
  "5 6 4\n"
  "5 7 5\n"
  "5 9 7\n"
  "6 7 1\n"
  "6 8 4\n"
  "7 8 3\n"
  "7 9 9\n"
  "8 9 10\n"
  "8 10 18\n"
  "9 10 8\n";

int* nodes;
int** edges;

// Implements Definition ====================
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int size = 0;

  int V; // The Number of Vertices(Nodes)
  int E; // The Number of Edges

  // INPUT
  {
    stringbuf inputbuf(input);
    streambuf *backup = cin.rdbuf(&inputbuf);

    cin >> V >> E;
    nodes = new int[V];
    edges = new int*[E];

    for (int e = 0; e < E; e++) {
      edges[e] = new int[3];
      cin >> edges[e][0] >> edges[e][1] >> edges[e][2];
    }

    cin.clear();
    cin.rdbuf(backup);
  }

  // 1. 간선들을 비용에 따라 오름차순으로 정렬합니다.
  sort(edges, edges + E,[](int* o1, int* o2) -> bool { return o1[2] < o2[2]; });

  // 자기 자신을 뿌리로 가리키도록 초기화
  for (int v = 0; v < V; v++) makeSet(v);

  cout << "[MST EDGE] :\n";
  for (int e = 0; e < E; e++) {
    int nodeX = findSet(edges[e][0]);
    int nodeY = findSet(edges[e][1]);

    // 2. 간선을 순서대로 하나씩 확인하며 현재의 간선을 MST의 경로로 포함시킬 때 서로소 알고리즘(Union-find Algorithm)을 토대로 사이클을 발생시키는지 확인합니다.
    // 뿌리가 같은 노드끼리 연결하는 간선이다 = 사이클을 형성하는 간선
    if (nodeX == nodeY) continue;

    // 3. 사이클 발생이 없다면 해당 간선을 MST에 추가합니다.
    unionSet(nodeX, nodeY);
    cout << edges[e][0] << " <--" << edges[e][2] << "--> " << edges[e][1] << "\n";
    size += edges[e][2];
  }

  // 4. 모든 간선을 돌아보고 나면 MST를 얻을 수 있습니다.
  cout << "\n[MST SIZE] : " << size << endl;

  delete[] nodes;
  delete[] edges;
  return 0;
}

void makeSet(int x) {
  nodes[x] = x;
}

int findSet(int x) {
  if (x == nodes[x]) return x;
  return nodes[x] = findSet(nodes[x]); // Path compression
}

void unionSet(int x, int y) {
  nodes[findSet(y)] = findSet(x);
}
```

<br/>

#### Java

```java
import java.util.Arrays;
import java.util.Comparator;
import java.util.Scanner;

public class Main {
  // # Global Variable & Constant================
  private static String input =
    "10 21\n" +
    "0 1 9\n" +
    "0 2 9\n" +
    "0 9 8\n" +
    "0 8 18\n" +
    "1 2 3\n" +
    "1 4 6\n" +
    "2 3 2\n" +
    "2 4 4\n" +
    "2 9 9\n" +
    "3 4 2\n" +
    "3 5 9\n" +
    "3 9 8\n" +
    "4 5 9\n" +
    "5 6 4\n" +
    "5 7 5\n" +
    "5 9 7\n" +
    "6 7 1\n" +
    "6 8 4\n" +
    "7 8 3\n" +
    "7 9 9\n" +
    "8 9 10\n" +
    "8 10 18\n" +
    "9 10 8\n";

  static int[] nodes;
  static int[][] edges;

  // # Implements Definition ====================
  public static void main(String[] args) {
    Main mainInstance = new Main();
    int V;
    int E;

    int size = 0;

    // * INPUT
    {
      Scanner sc = new Scanner(input);
      V = sc.nextInt(); // 정점의 갯수 0부터 시작
      E = sc.nextInt(); // 간선 갯수

      nodes = new int[V];
      edges = new int[E][3];

      for(int i = 0; i < E; i++) {
        edges[i][0] = sc.nextInt();
        edges[i][1] = sc.nextInt();
        edges[i][2] = sc.nextInt();
      }
      sc.close();
    }

    Arrays.sort(edges, new Comparator<int[]>() {
      @Override
      public int compare(int[] o1, int[] o2) {
        return o1[2] - o2[2];
      }
    });

    for(int i = 0; i < V; i++) {
      mainInstance.makeSet(i);
    }

    for(int i = 0; i < E; i++) {
      int rootX = mainInstance.findSet(edges[i][0]);
      int rootY = mainInstance.findSet(edges[i][1]);

      if(rootX != rootY) {
        mainInstance.unionSet(rootX, rootY);
        size += edges[i][2];
      }
    }

    // * OUTPUR
    {
      System.out.printf("[MST SIZE] : %d",size);
    }

    return;
  }

  void makeSet(int x) {
    nodes[x] = x;
  }

  int findSet(int x) {
    if(x == nodes[x]) return x;
    return nodes[x] = findSet(nodes[x]); // Path compression
  }

  void unionSet(int x, int y) {
    nodes[findSet(y)] = findSet(x);
  }
}
```

<br/>

### 2. Prim 알고리즘

- 정점 집합의 확장을 기반으로 하는 알고리즘
- Prim 알고리즘은 다음과 같은 순서로 작동합니다.

  1. 시작하면서 시작 정점을 비어있는 정점 집합에 추가합니다.
  2. 3번 과정을 가능하다면 V-1 번 반복합니다.
  3. 앞에서 만들어진 정점 집합에 인접한 정점들 중에서 가장 낮은 가중치의 간선으로 연결된 정점을 선택하여 정점 집합에 추가합니다.

- 반복문이 정점의 수 V 만큼 반복하고, 다시 내부의 반복문이 V 만큼 반복하기 때문에 정점의 수 V에 대한 시간 복잡도는 O(V²) 입니다.
- 그래프에 정점의 수보다 간선이 매우 많이 존재하는 밀집 그래프(Dense Graph)의 경우는 Prim 알고리즘이 적합합니다.

<br/>

#### C++

```cpp
#include <iostream>
#include <sstream>

using namespace std;

// # Global Variable & Constant================
const string input =
  "10 21\n"
  "0 1 9\n"
  "0 2 9\n"
  "0 9 8\n"
  "0 8 18\n"
  "1 2 3\n"
  "1 4 6\n"
  "2 3 2\n"
  "2 4 4\n"
  "2 9 9\n"
  "3 4 2\n"
  "3 5 9\n"
  "3 9 8\n"
  "4 5 9\n"
  "5 6 4\n"
  "5 7 5\n"
  "5 9 7\n"
  "6 7 1\n"
  "6 8 4\n"
  "7 8 3\n"
  "7 9 9\n"
  "8 9 10\n"
  "8 10 18\n"
  "9 10 8\n";

int** graph;

// # Implements Definition ====================
// ## Main
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int size = 0;

  int V; // The Number of Vertices(Nodes)
  int E; // The Number of Edges

  // ### INPUT
  {
    stringbuf inputbuf(input);
    streambuf *backup = cin.rdbuf(&inputbuf);

    cin >> V >> E;
    graph = new int*[V]{};
    for(int v = 0; v < V; v++) graph[v] = new int[V]{};

    for (int e = 0; e < E; e++) {
      int v1, v2, w;
      cin >> v1 >> v2 >> w;
      graph[v1][v2] = graph[v2][v1] = w;
    }

    cin.clear();
    cin.rdbuf(backup);
  }

  // 1. MST를 이루는 정점들의 집합을 만듭니다. 이 집합은 아직은 비어있습니다.
  bool selected[V] = {};
  int mstW[V] = {};
  int mstV2[V] = {};

  // 1. 비어있는 MST 집합과 정점 사이의 거리는 무한 = 연결되지 않았다고 취급합니다.
  fill(mstW, mstW + V, INT_MAX);

  // 2. 임의의 정점을 시작점으로 고르고 MST 정점 집합과의 거리가 0 = 붙어있다고 취급합니다.
  mstW[0] = 0;

  // 3. 4번 과정을 가능하다면 V-1 번 반복합니다.
  for (int i = 0; i < V - 1; i++) {
    int min = INT_MAX;
    int v2 = -1;

    // 4. MST 집합에 인접한 정점들 중에서 가장 가까운 정점을 찾습니다.
    for (int v = 0; v < V; v++) {
      if (selected[v]) continue;
      if (min <= mstW[v]) continue;

      min = mstW[v];
      v2 = v;
    }

    // 5. 찾은 정점을 MST 집합에 추가합니다.
    selected[v2] = true;

    // 6. MST 집합이 변했으므로 집합과 정점들 사이의 거리 정보를 갱신합니다.
    for (int v1 = 0; v1 < V; v1++) {
      if (selected[v1]) continue;
      if (graph[v1][v2] == 0) continue;
      if (mstW[v1] <= graph[v1][v2]) continue;

      // 현재 v1 정점과 MST에 가장 가까운 간선은 v1 <-w-> v2 임을 기록합니다.
      mstW[v1] = graph[v1][v2];
      mstV2[v1] = v2;
    }
  }

  // ### OUTPUT
  {
    cout << "[MST EDGE] :\n";
    for (int v1 = 1; v1 < V; v1++) {
      size += mstW[v1];
      cout << v1 << " <--" << mstW[v1] << "--> " << mstV2[v1] << "\n";
    }

    cout << "\n[MST SIZE] : " << size << endl;
  }

  delete[] graph;
  return 0;
}
```

<br/>

#### Java

```java
import java.util.Arrays;
import java.util.Scanner;

public class Main {
  // # Global Variable & Constant================
  private static String input =
    "10 21\n" +
    "0 1 9\n" +
    "0 2 9\n" +
    "0 9 8\n" +
    "0 8 18\n" +
    "1 2 3\n" +
    "1 4 6\n" +
    "2 3 2\n" +
    "2 4 4\n" +
    "2 9 9\n" +
    "3 4 2\n" +
    "3 5 9\n" +
    "3 9 8\n" +
    "4 5 9\n" +
    "5 6 4\n" +
    "5 7 5\n" +
    "5 9 7\n" +
    "6 7 1\n" +
    "6 8 4\n" +
    "7 8 3\n" +
    "7 9 9\n" +
    "8 9 10\n" +
    "8 10 18\n" +
    "9 10 8\n";

    private static int[][] graph;

  // # Implements Definition ====================
  public static void main(String[] args) {
    int V;
    int E;

    int size = 0;

    // * INPUT
    {
      Scanner sc = new Scanner(input);
      V = sc.nextInt(); // 정점의 갯수 0부터 시작
      E = sc.nextInt(); // 간선 갯수
      graph = new int[V][V]; // 양방향으로 접근가능한 V² 크기 데이터

      for(int e = 0; e < E; e++) {
        int v1 = sc.nextInt();
        int v2 = sc.nextInt();
        int w = sc.nextInt();

        graph[v1][v2] = graph[v2][v1] = w;
      }

      sc.close();
    }

    boolean[] selected = new boolean[V];
    int[] dist = new int[V]; // 키
    int[] p = new int[V]; // 부모

    // 1. 시작하면서 임의의 시작 정점을 비어있는 정점 집합에 추가합니다.
    // 연결되어 있지 않은 노드는 무한거리 만큼 떨어졌다고 취급합니다.
    Arrays.fill(dist, Integer.MAX_VALUE);
    dist[0] = 0;

    // 2. 3번 과정을 가능하다면 V-1 번 반복합니다.
    for (int i = 0; i < V - 1; i++) {
      int min = Integer.MAX_VALUE;
      int idx = -1;

      // 3. 정점 집합에 인접한 정점들 중에서 가장 가까운 정점을 집합에 추가합니다.
      for(int j = 0; j < V; j++) {
        if(!selected[j] && (dist[j] < min)) {
          min = dist[j];
          idx = j;
        }
      }

      selected[idx] = true;

      // 인접한 노드들의 정점 집합과의 거리를 갱신합니다.
      for(int j = 0; j < V; j++) {
        if(!selected[j] && (graph[idx][j] != 0) && (dist[j] > graph[idx][j])) {
          p[j] = idx;
          dist[j] = graph[idx][j];
        }
      }
    }

    // * OUTPUT
    {
      System.out.println("[MST EDGE] :");
      for(int v1 = 0; v1 < V; v1++) {
        System.out.printf("%d <--%d--> %d\n", v1, dist[v1], p[v1]);
        size += dist[v1];
      }
      System.out.printf("\n[MST SIZE] : %d",size);
    }

    return;
  }
}
```

<br/>

### 3. Prim 알고리즘 + Priority Queue

- Priority Queue를 사용하면 알고리즘 개선이 가능합니다.
- 우선순위 큐(Priority Queue) 란 기존의 큐와 같이 선형 자료구조를 따르지 않고 비선형 자료 구조입니다. 우선순위 큐 안에서 데이터들은 들어가는 순서대로 배열되지 않으며 사전에 정해둔 우선순위에 조건에 맞춰서 큐에서 꺼내집니다.
- 예를들어 A,B,C가 있을 때, A < B < C 로 우선순위를 정했다면 B, C, A 순으로 넣어도 A, B, C 오름차순으로 나오게 됩니다.
- 기존의 큐나 배열, 리스트는 순서대로 나열되어 있기 때문에 데이터 삽입은 즉시 가능하나, 데이터 탐색 시 최악의 경우 n 개 원소를 전부 읽어야 데이터를 찾을 수 있습니다. 따라서 데이터 삽입의 시간복잡도는 O(1), 데이터 탐색의 시간복잡도는 O(n) 입니다.
- 우선순위 큐는 트리구조를 응용한 힙 구조를 통해 구현되며 힙은 이진탐색트리 구조에 기반하기 때문에 데이터 삽입할 때와 탐색할 때 모두 해당 데이터의 우선순위를 큐 안에서 추적하는 과정을 거칩니다. 따라서 큐 안의 원소 n개에 대하여 데이터 삽입과 탐색 모두 시간복잡도는 O(log₂n) 이 됩니다.
- 2차원 배열을 통해 정점간의 연결상태와 정점 집합와 정점 사이 거리를 확인했던 기존 Prim 과 다르게 Kruskal 처럼 간선 정보를 다룹니다.
- Priority Queue를 이용한 Prim 알고리즘은 다음과 같은 순서로 작동합니다.

  1. 간선의 우선순위 큐를 생성합니다. 우선순위는 간선들의 가중치 오름차순으로 지정합니다.
  2. 임의의 정점을 시작점으로 고르고 우선순위 큐에 정점의 간선을 모두 집어넣습니다.
  3. 4~5 번 과정을 가능하다면 V-1 번 반복합니다.
  4. MST 집합에 인접한 정점들 중에서 가장 가까운 정점은 우선순위 큐 맨 앞의 원소입니다.
  5. 가장 가까운 정점의 간선을 모두 큐에 집어넣습니다.

- 우선순위 큐의 힙정렬 덕분에 V 만큼 탐색하지 않아도 ElogE 안에 가장 짧은 간선을 찾아냅니다.

<br/>

#### C++

```cpp
#include <array>
#include <functional>
#include <iostream>
#include <queue>
#include <sstream>

using namespace std;

// # Global Variable & Constant================
const string input =
  "10 21\n"
  "0 1 9\n"
  "0 2 9\n"
  "0 9 8\n"
  "0 8 18\n"
  "1 2 3\n"
  "1 4 6\n"
  "2 3 2\n"
  "2 4 4\n"
  "2 9 9\n"
  "3 4 2\n"
  "3 5 9\n"
  "3 9 8\n"
  "4 5 9\n"
  "5 6 4\n"
  "5 7 5\n"
  "5 9 7\n"
  "6 7 1\n"
  "6 8 4\n"
  "7 8 3\n"
  "7 9 9\n"
  "8 9 10\n"
  "8 10 18\n"
  "9 10 8\n";

vector<vector<array<int, 3>>> edges;
vector<array<int, 3>> mstEdges;

// # Implements Definition ====================
// ## Main
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int size = 0;

  int V; // The Number of Vertices(Nodes)
  int E; // The Number of Edges

  // ### INPUT
  {
    stringbuf inputbuf(input);
    streambuf *backup = cin.rdbuf(&inputbuf);

    cin >> V >> E;

    for (int v = 0; v < V; v++) {
      vector<array<int, 3>> temp;
      edges.push_back(temp);
    }

    for (int e = 0; e < E; e++) {
      int v1, v2, w;
      cin >> v1 >> v2 >> w;

      edges[v1].push_back({v1, v2, w});
      edges[v2].push_back({v2, v1, w});
    }

    cin.clear();
    cin.rdbuf(backup);
  }

  // ### CALCULATE
  {
    // 1. 간선의 우선순위 큐를 생성합니다. 우선순위는 간선들의 가중치 오름차순으로 지정합니다.
    // c++ 우선순위 큐는 우선순위가 "높은" 순서대로 내림차순 힙정렬합니다. 주의하세요.
    priority_queue<array<int, 3>, vector<array<int, 3>>, function<bool(array<int, 3>, array<int, 3>)>> task([](array<int, 3> o1, array<int, 3> o2) -> bool { return o1[2] > o2[2];});
    int selected[V] = {};

    // 2. 임의의 정점을 시작점으로 고르고 우선순위 큐에 정점의 간선을 모두 집어넣습니다.
    selected[0] = true;
    for (const auto& arr : edges[0]) task.push(arr);

    // 3. 4~5 번 과정을 가능하다면 V-1 번 반복합니다.
    int cnt = 1;
    while (cnt < V) {
      // 4. MST 집합에 인접한 정점들 중에서 가장 가까운 정점은 우선순위 큐 맨 앞의 원소입니다.
      int v1 = task.top()[0];
      int v2 = task.top()[1];
      int w = task.top()[2];
      task.pop();

      // 이미 연결되어 있는 정점일 경우 넘깁니다.
      if (selected[v2]) continue;

      // 5. 가장 가까운 정점의 간선을 모두 큐에 집어넣습니다.
      selected[v2] = true;
      for (const auto& arr : edges[v2]) task.push(arr);

      mstEdges.push_back({v1, v2, w});
      size += w;
      cnt++;
    }
  }

  // ### OUTPUT
  {
    cout << "\n[MST EDGE] :\n";
    for (const auto& mstEdge : mstEdges) {
      cout << mstEdge[0] << " <--" << mstEdge[2] << "--> " << mstEdge[1] << "\n";
    }
    cout << "\n[MST SIZE] : " << size << endl;
  }
  return 0;
}
```

<br/>

#### Java

```java
import java.util.ArrayList;
import java.util.PriorityQueue;
import java.util.Scanner;

public class Main {
  // # Global Variable & Constant================
  private static String input =
    "10 21\n" +
    "0 1 9\n" +
    "0 2 9\n" +
    "0 9 8\n" +
    "0 8 18\n" +
    "1 2 3\n" +
    "1 4 6\n" +
    "2 3 2\n" +
    "2 4 4\n" +
    "2 9 9\n" +
    "3 4 2\n" +
    "3 5 9\n" +
    "3 9 8\n" +
    "4 5 9\n" +
    "5 6 4\n" +
    "5 7 5\n" +
    "5 9 7\n" +
    "6 7 1\n" +
    "6 8 4\n" +
    "7 8 3\n" +
    "7 9 9\n" +
    "8 9 10\n" +
    "8 10 18\n" +
    "9 10 8\n";

  private static class Edge implements Comparable<Edge>{
    int v1;
    int v2;
    int w;

    public Edge(int v1, int v2, int w) {
      this.v1 = v1;
      this.v2 = v2;
      this.w = w;
    }

    @Override
    public int compareTo(Edge o) {
      return this.w - o.w;
    }
  }

  // # Implements Definition ====================
  public static void main(String[] args) {
    int V;
    int E;

    int size = 0;

    boolean[] selected;
    ArrayList<ArrayList<Edge>> edges;
    PriorityQueue<Edge> task;

    // * INPUT
    {
      Scanner sc = new Scanner(input);
      V = sc.nextInt(); // 정점의 갯수 0부터 시작
      E = sc.nextInt(); // 간선 갯수

      selected = new boolean[V];
      edges = new ArrayList<>();

      for (int v = 0; v < V; v++) {
        edges.add(new ArrayList<>());
      }

      for (int e = 0; e < E; e++) {
        int v1 = sc.nextInt();
        int v2 = sc.nextInt();
        int w = sc.nextInt();

        // System.out.printf("%d <--%d--> %d\n", v1, w, v2);

        // 양방향에서 접근
        edges.get(v1).add(new Edge(v1, v2, w));
        edges.get(v2).add(new Edge(v2, v1, w));
      }

      sc.close();
    }

    selected = new boolean[V];
    task = new PriorityQueue<>();

    // 1. 시작하면서 임의의 정점(여기선 0번) 정점 집합에 추가합니다.
    selected[0] = true;
    task.addAll(edges.get(0));

    System.out.println("[MST EDGE] :");

    // 2. 3번 과정을 가능하다면 V-1 개의 간선을 찾을 때까지 반복합니다.
    int count = 1;
    while (count < V) {
      // 3. 앞에서 만들어진 정점 집합에 인접한 정점들 중에서 가장 낮은 가중치의 간선으로 연결된 정점을 선택하여 정점 집합에 추가합니다.
      // 우선순위 큐(Priority Queue)에선 자동으로 가중치순으로 정렬됩니다.
      Edge target = task.poll();

      if (selected[target.v2]) continue;

      System.out.printf("%d <--%d--> %d\n", target.v1, target.w, target.v2);

      size += target.w;
      selected[target.v2] = true;
      task.addAll(edges.get(target.v2));
      count++;
    }

    // * OUTPUT
    {
      System.out.printf("\n[MST SIZE] : %d",size);
    }

    return;
  }
}
```
