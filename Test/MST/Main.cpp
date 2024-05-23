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
  "7 11\n"
  "0 1 32\n" 
  "0 2 31\n"
  "0 5 60\n"
  "0 6 51\n"
  "1 2 21\n"
  "2 4 46\n"
  "2 6 25\n"
  "3 4 34\n"
  "4 6 51\n"
  "5 3 18\n"
  "5 4 40";

int* nodes;
int** edges;

// Implements Definition ====================
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int sum = 0;

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

  sort(edges, edges + E,[](int* o1, int* o2) -> bool { return o1[2] < o2[2]; });

  // 자기 자신으로 초기화
  for (int v = 0; v < V; v++) makeSet(v);

  cout << findSet(999) << "--\n";

  cout << nodes[0];

  delete[] nodes;
  delete[] edges;
  return 0;
}

void makeSet(int x) { 
  nodes[x] = x; 
}

int findSet(int x) {
  if (x == nodes[x]) return x;
  return nodes[x] = findSet(nodes[x]);
}

void unionSet(int x, int y) { 
  nodes[findSet(y)] = findSet(x); 
}