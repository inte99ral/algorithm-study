#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    freopen("_INPUT_.txt", "rt", stdin); // <================

    int n;

    while (cin >> n) {
        int cnt = 1;
        int sum = n;
        int iArr[10] = {};
        for (int i = 0; i < 9; i++) {
            iArr[sum % 10] = sum;
            sum += n;
        }

        sum = iArr[1];

        while (sum != 1) {
            if(sum % 10 != 1) {
                sum += iArr[(11 - sum % 10) % 10];
            }

            sum /= 10;
            cnt++;
        }

        cout << cnt << '\n';
    }

    return 0;
}