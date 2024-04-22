# 위상정렬：Topological Sort

- 위상정렬이란?
- 람다식의 구성
- 람다식의 활용

<br />

## 위상정렬이란?

- DAG(Directed Acyclic Graph, 사이클이 없고 방향성을 가진 그래프) 에서만 사용가능한 알고리즘
- 정렬해야 하는 원소 간에 위상(방향성)이 존재하고 이것이 역전되는 경우가 없을 경우 빠르게 정렬하는 방법
- 시간복잡도 : O(V + E) `V : 정점의 개수`, `E: 간선의 개수`

## 위상정렬의 원리

1. 입력을 받으면서 진입차수(indegree, 다른 노드로부터 들어오는 간선의 개수, 해당 원소보다 위상이 낮은 원소들의 수)와 그래프 간선 정보를 입력합니다.
2. 진입차수가 0 인 노드들을 대기열에 넣습니다.
3. 대기열에서 들어온 순서에 맞게 원소 하나를 꺼내어 방문 노드로 설정합니다.
4. 방문 노드와 인접한 정점들의 진입차수를 낮춘다. 이후 진입차수가 0이 된 노드는 대기열에 넣습니다.
5. 3 ~ 4의 과정을 대기열이 없을 때까지 반복합니다.

```cpp
#include <deque>
#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int N;
  int M;
  vector<vector<int>> graph;
  int* indegree;
  deque<int> task;

  { //_INPUT
    /**
     * 1 → 2 → 3 → 4
     *  ↘       ↙
     *     5 → 6 → 7
     */

    string input =
        "7 7\n"
        "1 2 "
        "1 5 "
        "2 3 "
        "5 6 "
        "3 4 "
        "4 6 "
        "6 7";

    stringbuf sb(input);
    streambuf *backup = cin.rdbuf(&sb);

    cin >> N >> M;

    indegree = new int[N + 1]();

    for (int n = 0; n < N; n++) {
      graph.push_back({});
    }

    for (int m = 0; m < M; m++) {
      int forward;
      int backward;

      cin >> forward >> backward;

      graph[forward].push_back(backward);
      indegree[backward]++;
    }

    cin.clear();
    cin.rdbuf(backup);
  }

  for (int n = 1; n <= N; n++) if(indegree[n] == 0) task.push_back(n);

  while (task.size() != 0) {
    int target = task.front();
    cout << target << " : ";
    task.pop_front();

    for(const auto& a : graph[target]) {
      if(--indegree[a] == 0) {
        task.push_back(a);
      }
    }
  }

  delete[] indegree;
  return 0;
}
```
