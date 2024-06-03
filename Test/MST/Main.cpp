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

  // 1. 시작하면서 시작 정점을 비어있는 정점 집합에 추가합니다.
  // 2. 앞에서 만들어진 정점 집합에 인접한 정점들 중에서 가장 낮은 가중치의 간선으로 연결된 정점을 선택하여 정점 집합에 추가합니다.
  // 3. 2번 과정을 가능하다면 V-1 번 반복합니다.
  
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

  sort(edges, edges + E,[](int* o1, int* o2) -> bool { return o1[2] < o2[2]; });

  // 자기 자신을 뿌리로 가리키도록 초기화
  for (int v = 0; v < V; v++) makeSet(v);

  for (int e = 0; e < E; e++) {
    int nodeX = findSet(edges[e][0]);
    int nodeY = findSet(edges[e][1]);

    // 뿌리가 같은 노드끼리 연결하는 간선이다 = 사이클을 형성하는 간선
    if (nodeX == nodeY) continue;

    unionSet(nodeX, nodeY);
    size += edges[e][2];
  }

  cout << "[MST SIZE] : " << size;

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