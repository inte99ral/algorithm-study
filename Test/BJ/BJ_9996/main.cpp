#include <bits/stdc++.h>
using namespace std;
int N;
int astIdx;
string pattern;
string prefix;
string suffix;
string temp;

int main() {
    freopen("input.txt", "rt", stdin); // <- local input
    cin >> N >> pattern;
    astIdx = pattern.find('*');
    prefix = pattern.substr(0, astIdx);
    suffix = pattern.substr(astIdx + 1, pattern.size());

    for (int n = 0; n < N; n++) {
        cin >> temp;
        if ((temp.size() >= (prefix.size() + suffix.size())) && (temp.substr(0, prefix.size()) == prefix) && (temp.substr(temp.size() - suffix.size()) == suffix)) cout << "DA\n";
        else cout << "NE\n";
    }
    return 0;
}