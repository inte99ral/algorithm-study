#include <bits/stdc++.h>
using namespace std;
int main() {
    // --------------------------------

    freopen("_INPUT_.txt", "rt", stdin); // <-- LOCAL INPUT

    // --------------------------------
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    long long n;
    while(cin >> n) {
        // * n 의 곱셈 패턴 읽기
        vector<int> data(10, -1);
        long long temp = n;
        while (data[temp % 10] != -1) {
            data[temp % 10] = temp;
        }

        
    }
    return 0;
}