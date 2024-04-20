
/**
 * 1 → 2 → 3 → 4
 *  ↘       ↙
 *     5 → 6 → 7
*/

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

      graph[backward].push_back(forward);
      indegree[backward]++;
    }

    cin.clear();
    cin.rdbuf(backup);
  }

  for (int n = 1; n <= N; n++) if(indegree[n] == 0) task.push_back(n);

  while (task.size() != 0) {
    int target = task.front();
    task.pop_front();


  }

  delete[] indegree;
  return 0;
}