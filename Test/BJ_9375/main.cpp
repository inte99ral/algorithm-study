#include <bits/stdc++.h>
using namespace std;
int T, N, ans;
string temp;
unordered_map<string, int> iMap;
int main() {
    freopen("input.txt", "rt", stdin); // <- local input

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> T;
    for (int t = 0; t < T; t++) {
        cin >> N;
        ans = 1;
        iMap.clear();
        for (int n = 0; n < N; n++) {
            cin >> temp >> temp;
            iMap[temp]++;
        }

        for (auto p : iMap) {
            ans *= p.second + 1;
        }
        cout << ans - 1 << "\n";
    }

    return 0;
}