#include <bits/stdc++.h>

using namespace std;
int ans = 0;
int N;
int M;
vector<int> v;

int main() {
    freopen("input.txt", "rt", stdin); // <- local input

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N >> M;
    v = vector<int>(N);
    for (int n = 0; n < N; n++) {
        cin >> v[n];
    }
    
    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            if (v[i] + v[j] == M) ans++;
        }
    }

    cout << ans;
    return 0;
}