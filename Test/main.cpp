#include <bits/stdc++.h>
using namespace std;
int main() {
    vector<int> v = { 50, 10, 10, 20, 30, 40, 30, 30, 50 };

    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());

    for(int i : v) cout << i << " ";
    cout << '\n';
    return 0;
}