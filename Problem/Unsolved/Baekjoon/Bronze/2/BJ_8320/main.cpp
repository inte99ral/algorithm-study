#include <bits/stdc++.h>

using namespace std;

int main() {
    // freopen("_INPUT_.txt", "rt", stdin);
    int answer = 0;
    int N;
    cin >> N;

    for (int n = 1; n <= N; n++) for (int i = floor(sqrt(n)); i > 0; i--) if (n % i == 0) answer++;
    cout << answer;

    return 0;
}