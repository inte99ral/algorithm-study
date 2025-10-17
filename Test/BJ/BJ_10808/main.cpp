#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("input.txt", "rt", stdin); // <-- local input
    string str;
    vector<int> v(26);
    cin >> str;
    for (char c : str) v[c - 'a']++;
    for (int i : v) cout << i << " ";
    return 0;
}