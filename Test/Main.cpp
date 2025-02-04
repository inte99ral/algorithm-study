#include <bits/stdc++.h>
using namespace std;

int main() {
  { // * list iter insert return
    std::list<int> l = {1, 2, 3, 4, 5};
    std::list<int>::iterator iter = next(l.begin(), 2);
    iter = l.insert(iter, 10);
    iter = l.insert(iter, 20);
    iter = l.insert(iter, 30);

    for (int i : l) cout << i << " ";
    cout << "\n";
  }

  { // * list iter insert 
    std::list<int> l = {1, 2, 3, 4, 5};
    auto iter = l.begin();
    ++iter;
    iter++;
    l.insert(iter, 10);
    l.insert(iter, 20);
    l.insert(iter, 30);

    for (int i : l) cout << i << " ";
    cout << "\n";
  }
}