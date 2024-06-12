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