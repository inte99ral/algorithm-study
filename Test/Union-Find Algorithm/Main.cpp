#include <iostream>
#include <sstream>

using namespace std;

// Prototype Declaration ====================
void makeSet(int x);
int findSet(int x);
void unionSet(int x, int y);

// Global Variable & Constant================
const string input =
  "9 8\n"
  "1 2\n"
  "1 4\n"
  "2 4\n"
  "3 5\n"
  "5 7\n"
  "6 8\n"
  "6 9\n"
  "8 9\n";

int *nodes;
int **edges;
  
// Implements Definition ====================
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int V;
  int E;

  {
    stringbuf inputbuf(input);
    streambuf *backup = cin.rdbuf(&inputbuf);

    cin >> V >> E;

    nodes = new int[V];
    edges = new int*[E];

    for (int e = 0; e < E; e++) {
      cin >> edges[e][0] >> edges[e][1] >> edges[e][2];
    }

    cin.clear();
    cin.rdbuf(backup);
  }

  

  return 0;
}

void makeSet(int x) {
  nodes[x] = x;
}

int findSet(int x) {
  if (nodes[x] == x) return x;
  return nodes[x] = findSet(nodes[x]); // Path Compression
}

void unionSet(int x, int y) {
  nodes[findSet(y)] = findSet(x);
}