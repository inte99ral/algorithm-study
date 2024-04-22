#include <deque>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  freopen("Problem\\Failed\\Baekjoon\\Gold\\3\\BJ_2252\\question\\input.txt", "rt", stdin);
  
  int N;
  int M;
  int front;
  int* data;
  int* indegree;
  vector<vector<int>> graph;
  deque<int> task;

  cin >> N >> M;

  indegree = new int[N + 1]();
  for(int n = 0; n <= N; n++) graph.push_back({});

  for(int m = 0; m < M; m++) {
    int tail;
    int head;

    cin >> tail >> head;

    graph[tail].push_back(head);
    indegree[head]++;
  }

  for(int n = 1; n <= N; n++) if(indegree[n] == 0) task.push_back(n);

  while(!task.empty()) {
    cout << task.front() << " ";

    for(const auto& i : graph[task.front()]) {
      if(--indegree[i] == 0) task.push_back(i);
    }
 
    task.pop_front();
  }

  delete[] indegree;
  return 0;
}