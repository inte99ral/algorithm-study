-   ~ ~볼 힌트~~
-   ~~최소 10까진 진행해봐야 패턴이 보이는 미친 문제~~

```cpp
#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    //n = 4;
    int ans[4] = {0,1,3,10};
    if(n <= 3) return ans[n];

    vector<long long> dp(n+1,0);
    vector<long long> dpA(n+1,0);
    vector<long long> dpB(n+1,0);
    dp[0] = 1; dpA[0] = 1; dpB[0] = 1;
    dp[1] =1; dp[2] = 3; dp[3] = 10;
    dpA[1] = 0; dpA[2] = 0; dpA[3] = 1;
    dpB[1] = 0; dpB[2] = 0; dpB[3] = 1;

    for(int i=4; i<=n;i++){
        dpA[i] = (dp[i-3] + dpB[i-2]) % 1000000007 ;
        dpB[i] = (dp[i-3] + dpA[i-1]) % 1000000007 ;
        dp[i] = (dp[i-3] + dp[i-2]*2 + dp[i-1] + dpA[i]*2 + dpB[i]*2) % 1000000007 ;
    }

    long long answer = dp[n];
    return answer;
}
```
