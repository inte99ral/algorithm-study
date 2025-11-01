#include <bits/stdc++.h>
using namespace std;

long long A, B, C;

long long divConq(int len) {
    if (len == 1) return (A % C);

    long long dc = divConq(len / 2);
    long long ans = (dc * dc) % C;

    return (len % 2 == 0) ? ans : (ans * A) % C;
}

int main() {
    // ----------------------------------------------------------------

    freopen("_INPUT_.txt", "rt", stdin); // <-- LOCAL INPUT

    // ----------------------------------------------------------------
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> A >> B >> C;
    cout << divConq(B);

    return 0;
}