#include <bits/stdc++.h>
using namespace std;
string str;
int oddAlp = -1;
vector<int> v = vector<int>(26);
int main() {
    freopen("input.txt", "rt", stdin); // <- local input

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> str;
    for (char c : str) {
        v[c - 'A']++;
    }
    str = "";

    for (int i = 0; i < 26; i++) {
        if(v[i] % 2 != 0) {
            if (oddAlp != -1) {
                cout << "I'm Sorry Hansoo";
                exit(0);
            }
            oddAlp = i;
            v[i]--;
        }
        v[i] /= 2;
        while(v[i]--) {
            str += (i + 'A');
        }
    }

    string strRev = str;
    reverse(strRev.begin(), strRev.end());
    if (oddAlp != -1) str += char(oddAlp + 'A');
    str += strRev;
    cout << str;

    return 0;
}