#include <bits/stdc++.h>
using namespace std;
int ans, A, B, C;
int a[101];
int main() {
    freopen("input.txt", "rt", stdin); // <-- local input
    cin >> A >> B >> C;
    B *= 2;
    C *= 3;

    for (int i = 0; i < 3; i++) {
        int in, out;
        cin >> in >> out;
        for (int j = in; j < out; j++) a[j]++;
    }

    ans = 0;
    for (int i = 0; i < 101; i++) {
        switch (a[i]) {
        case 1:
            ans += A;
            break;
        case 2:
            ans += B;
            break;
        case 3:
            ans += C;
            break;
        }
    }
    cout << ans;
    return 0;
}