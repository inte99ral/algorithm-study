#include <iostream>
#include <map>
#include <sstream>
#include <vector>

using namespace std;

// # Prototype Declaration ====================
void makeSet(int x);
int findSet(int x);
void unionSet(int x, int y);

// # Global Variable & Constant================
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
  
// # Implements Definition ====================
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int V;
  int E;

  // * INPUT
  {
    stringbuf inputbuf(input);
    streambuf *backup = cin.rdbuf(&inputbuf);

    cin >> V >> E;

    nodes = new int[V + 1]();

    for (int v = 1; v <= V; v++) {
      makeSet(v);
    }

    for (int e = 0; e < E; e++) {
      int x, y;
      cin >> x >> y;

      unionSet(x, y);
    }

    cin.clear();
    cin.rdbuf(backup);
  }

  // * OUTPUT_1
  {
    cout << "[NODE NUM] : ";
    for (int v = 1; v <= V; v++) {
      cout << v << ", ";
    }
    cout << "\b\b \n";

    cout << "[ROOT NUM] : ";
    for (int v = 1; v <= V; v++) {
      cout << nodes[v] << ", ";
    }
    cout << "\b\b \n\n";
  }

  // * OUTPUT_2
  {
    map<int, vector<int>> sets;

    for (int v = 1; v <= V; v++) {
      sets[nodes[v]].push_back(v);
    }

    for (pair<int, vector<int>> set : sets) {
      cout << "[ROOT NUM " << set.first << "] : {";
      for (int i : set.second) {
        cout << i << ", ";
      }
      cout << "\b\b}\n";
    }
    cout << "\b\b \n";

  }

  delete[] nodes;
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