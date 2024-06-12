#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int arr[5] = {5, 4, 6, 2, 1};

  priority_queue<int> pq;

  for (int i : arr) {
    pq.push(i);
  }

  while (!pq.empty()) {
    cout << pq.top();
    pq.pop();
  }

  // sort(arr, arr + 5, [](int o1, int o2) -> bool { return o1 < o2; });

  // for (int i : arr) {
  //   cout << i << "\n";
  // }

  

  return 0;
}