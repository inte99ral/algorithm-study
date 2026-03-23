#include <bits/stdc++.h>
using namespace std;

int N;
int R;
vector<int> origin;
vector<bool> select;

int main() {
    N = 4;
    R = 2;
    origin = vector<int>(N);
    select = vector<bool>(N);

    for (int n = 0; n < N; n++) origin[n] = n + 10;
    for (int r = 0; r < R; r++) select[r] = 1;

    do {
        for (int n = 0; n < N; n++) if (select[n]) cout << origin[n] << ' ';
        cout << '\n';

    } while (prev_permutation(select.begin(), select.end()));

    
    return 0;
}