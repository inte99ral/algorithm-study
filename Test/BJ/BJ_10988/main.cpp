#include <bits/stdc++.h>
using namespace std;
int main() {
    freopen("input.txt", "rt", stdin); // <- local input
    string str;
    cin >> str;
    int strSize = str.size() - 1;
    int halfSize = str.size() / 2;
    for (int i = 0; i < halfSize; i++) {
        if (str[i] != str[strSize - i]) {
            cout << 0;
            exit(0);
        }
    }
    cout << 1;
    return 0;
}