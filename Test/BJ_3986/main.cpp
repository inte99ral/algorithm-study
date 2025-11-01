#include <bits/stdc++.h>
using namespace std;
int main() {


    freopen("_INPUT_.txt", "rt", stdin); // <- LOCAL INPUT


    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int ans = 0;
    int N;
    string str;
    stack<char> st;

    cin >> N;
    while(N--) {
        cin >> str;
        st = stack<char>();
        for (char c : str) {
            // * 하나씩 집어넣을 때, 스택 맨 위와 동일하면 둘 다 제거, 다를 경우 스택에 추가
            if (!st.empty() && st.top() == c) st.pop();
            else st.push(c);
        }
        if (st.empty()) ans++;
    }

    cout << ans;
    return 0;
}