#include <climits>
#include <iostream>
#include <deque>

using namespace std;

const int dy[4] = {-1, 0, 0, 1};
const int dx[4] = {0, -1, 1, 0};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  #ifndef ONLINE_JUDGE
  freopen("Problem/Failed/Baekjoon/Gold/1/BJ_17472/question/input.txt", "rt", stdin);
  #endif

  int answer = 0;

  int N; 
  int M;
  int V = 0; // 섬의 수

  int** matrix;
  int** graph;

  // * INPUT
  {
    cin >> N >> M;

    matrix = new int*[N + 2]{};

    matrix[0] = new int[M + 2]{};
    fill(matrix[0], matrix[0] + M + 2, -1);

    for (int y = 1; y < N + 1; y++) {
      matrix[y] = new int[M + 2]{};
      matrix[y][0] = -1;

      for (int x = 1; x < M + 1; x++) {
        int buffer;
        cin >> buffer;
        matrix[y][x] = (buffer == 0) ? -1 : -2;
      }

      matrix[y][M + 1] = -1;
    }

    matrix[N + 1] = new int[M + 2]{};
    fill(matrix[N + 1], matrix[N + 1] + M + 2, -1);
  }

  // * 정점 체크
  {
    for (int y = 1; y < N + 1; y++) {
      for (int x = 1; x < M + 1; x++) {
        if (matrix[y][x] > -2) continue;

        deque<pair<int, int>> dq;
        dq.push_back(make_pair(y, x));

        while (!dq.empty()) {
          int currY = dq[0].first;
          int currX = dq[0].second;
          matrix[currY][currX] = V;

          for (int i = 0; i < 4; i++) {
            int nextY = currY + dy[i];
            int nextX = currX + dx[i];
            if (matrix[nextY][nextX] > -2) continue;
            dq.push_back(make_pair(nextY, nextX));
          }

          dq.pop_front();
        }

        V++;
      }
    }
  }

  // * 간선 체크
  {
    graph = new int*[V];
    for (int v = 0; v < V; v++) {
      graph[v] = new int[V];
      fill(graph[v], graph[v] + V, INT_MAX);
    }

    for (int y = 1; y < N + 1; y++) {
      int x1 = -1;
      int x2 = -1;

      for (int x = 1; x < M + 1; x++) {
        if (matrix[y][x] == -1) continue;

        x2 = x;
        if ((x1 != -1) && (x2 - x1 > 2) && (matrix[y][x1] != matrix[y][x2]) && (graph[matrix[y][x1]][matrix[y][x2]] > x2 - x1 - 1)) graph[matrix[y][x1]][matrix[y][x2]] = graph[matrix[y][x2]][matrix[y][x1]] = x2 - x1 - 1;
        x1 = x;
      }
    }

    for (int x = 1; x < M + 1; x++) {
      int y1 = -1;
      int y2 = -1;

      for (int y = 1; y < N + 1; y++) {
        if (matrix[y][x] == -1) continue;
        
        y2 = y;
        if ((y1 != -1) && (y2 - y1 > 2) && (matrix[y1][x] != matrix[y2][x]) && (graph[matrix[y1][x]][matrix[y2][x]] > y2 - y1 - 1)) graph[matrix[y1][x]][matrix[y2][x]] = graph[matrix[y2][x]][matrix[y1][x]] = y2 - y1 - 1;
        y1 = y;
      }
    }
  }

  // * MST PRIM
  {
    int w[V];
    bool selected[V] = {};

    fill(w, w + V, INT_MAX);

    w[0] = 0;

    for (int i = 0; i < V; i++) {
      int v1 = -1;
      int min = INT_MAX;

      for (int v = 0; v < V; v++) {
        if (selected[v]) continue;
        if (min <= w[v]) continue;

        v1 = v;
        min = w[v];
      }

      if (v1 == -1) {
        answer = -1;
        break;
      }

      selected[v1] = true;

      for (int v2 = 0; v2 < V; v2++) {
        if (selected[v2]) continue;
        if (w[v2] <= graph[v1][v2]) continue;

        w[v2] = graph[v1][v2];
      }
    }

    if (answer != -1) {
      for (int v = 0; v < V; v++) {
        answer += w[v];
      }
    }
  }

  // * OUTPUT
  {
    cout << answer;
  }
  
  // * UNINITIALIZE
  {
    for (int y = 0; y < N + 2; y++) delete[] matrix[y];
    delete[] matrix;

    for (int y = 0; y < V; y++) delete[] graph[y];
    delete[] graph;
  }
  return 0;
}
