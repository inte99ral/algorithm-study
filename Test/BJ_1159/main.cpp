#include <bits/stdc++.h>

using namespace std;
int N;
int alpCnt[26] = {};
bool isPredaja = true;

int main() {
    freopen("input.txt", "rt", stdin); // <- local input
    cin >> N;

    while(N--) {
        string name;
        cin >> name;
        alpCnt[name[0] - 'a']++;
    }

    for (int i = 0; i < 26; i++) {
        if (alpCnt[i] > 4) {
            cout << (char)('a' + i);
            isPredaja = false;
        }
    }

    if (isPredaja) cout << "PREDAJA";
    return 0;
}