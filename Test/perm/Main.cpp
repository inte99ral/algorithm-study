#include <bits/stdc++.h>
using namespace std;

int N;
int R;
vector<int> origin;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N >> R;
    origin = vector<int>(N);
    for (int i = 0; i < N; i++) origin[i] = i + 1;

    do {
        for (int i = 0; i < R; i++) cout << origin[i] << ' ';
        cout << '\n';

        reverse(origin.begin() + R, origin.end());
    } while (next_permutation(origin.begin(), origin.end()));

    return 0;
}